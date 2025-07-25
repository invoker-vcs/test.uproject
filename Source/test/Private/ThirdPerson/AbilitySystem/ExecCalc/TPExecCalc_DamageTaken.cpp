// © 2025 1nvoker - MIT License


#include "ThirdPerson/AbilitySystem/ExecCalc/TPExecCalc_DamageTaken.h"
#include "ThirdPerson/AbilitySystem/TPAttributeSet.h"
#include "ThirdPerson/TPGameplayTags.h"

#include "ThirdPerson/TPDebugHelper.h"

struct FTPDamageCapture
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower)
	DECLARE_ATTRIBUTE_CAPTUREDEF(DamageTaken)

	FTPDamageCapture()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UTPAttributeSet, AttackPower, Source, false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UTPAttributeSet, DefensePower, Target, false)
		DEFINE_ATTRIBUTE_CAPTUREDEF(UTPAttributeSet, DamageTaken, Target, false)
	}
};

static const FTPDamageCapture& GetTPDamageCapture()
{
	static FTPDamageCapture TPDamageCapture;
	return TPDamageCapture;
}
UTPExecCalc_DamageTaken::UTPExecCalc_DamageTaken()
{
	//? slow way of doing capture
	/*
	FProperty* AttackPowerProperty = FindFieldChecked<FProperty>(UTPAttributeSet::StaticClass(), GET_MEMBER_NAME_CHECKED(UTPAttributeSet, AttackPower));
	FGameplayEffectAttributeCaptureDefinition AttackPowerCaptureDefinition(AttackPowerProperty, EGameplayEffectAttributeCaptureSource::Source, false);
	RelevantAttributesToCapture.Add(AttackPowerCaptureDefinition);
	*/

	RelevantAttributesToCapture.Add(GetTPDamageCapture().AttackPowerDef);
	RelevantAttributesToCapture.Add(GetTPDamageCapture().DefensePowerDef);
	RelevantAttributesToCapture.Add(GetTPDamageCapture().DamageTakenDef);

}

void UTPExecCalc_DamageTaken::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	const FGameplayEffectSpec& EffectSpec = ExecutionParams.GetOwningSpec();

	//? gameplay effect spec data collection
	/*
	EffectSpec.GetContext().GetSourceObject();
	EffectSpec.GetContext().GetSourceObject();
	EffectSpec.GetContext().GetInstigator();
	EffectSpec.GetContext().GetEffectCauser();
	*/

	//! variables and data points for damage calculation
	FAggregatorEvaluateParameters EvaluateParameters;
	EvaluateParameters.SourceTags = EffectSpec.CapturedSourceTags.GetAggregatedTags();
	EvaluateParameters.TargetTags = EffectSpec.CapturedTargetTags.GetAggregatedTags();

	//* source attack power attribute initialized
	float SourceAttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetTPDamageCapture().AttackPowerDef, EvaluateParameters, SourceAttackPower);
	// Debug::Print(TEXT("SourceAttackPower"), SourceAttackPower);

	//* base damage and combo count variables initialized
	float BaseDamage = 0.f;
	int32 UsedLightAttackComboCount = 0;
	int32 UsedHeavyAttackComboCount = 0;
	for (const TPair<FGameplayTag, float>& TagMagnitude : EffectSpec.SetByCallerTagMagnitudes)
	{
		if (TagMagnitude.Key.MatchesTagExact(TPGameplayTags::Shared_SetByCaller_BaseDamage))
		{
			BaseDamage = TagMagnitude.Value;
			// Debug::Print(TEXT("BaseDamage"), BaseDamage);

		}

		if (TagMagnitude.Key.MatchesTagExact(TPGameplayTags::Player_SetByCaller_AttackType_Light))
		{
			UsedLightAttackComboCount = TagMagnitude.Value;
			// Debug::Print(TEXT("UsedLightAttackComboCount"), UsedLightAttackComboCount);
		}

		if (TagMagnitude.Key.MatchesTagExact(TPGameplayTags::Player_SetByCaller_AttackType_Heavy))
		{
			UsedHeavyAttackComboCount = TagMagnitude.Value;
			// Debug::Print(TEXT("UsedHeavyAttackComboCount"), UsedHeavyAttackComboCount);
		}
	}

	//* target defenser power attribute initialized
	float TargetDefensePower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(GetTPDamageCapture().DefensePowerDef, EvaluateParameters, TargetDefensePower);
	// Debug::Print(TEXT("TargetDefensePower"), TargetDefensePower);

	//! calculating final damage
	//* light attack combo
	if (UsedLightAttackComboCount != 0)
	{
		const float LightAttackDamageIncrease = 0.05f;
		const float DamageIncreasePercentLight = (UsedLightAttackComboCount - 1) * LightAttackDamageIncrease + 1.f;

		BaseDamage *= DamageIncreasePercentLight;
		// Debug::Print(TEXT("ScaledBaseDamageLight"), BaseDamage);

	}

	//* heavy attack combo
	if (UsedHeavyAttackComboCount != 0)
	{
		const float HeavyAttackDamageIncrease = 0.15f;
		const float DamageIncreasePercentHeavy = UsedHeavyAttackComboCount * HeavyAttackDamageIncrease + 1.f;

		BaseDamage *= DamageIncreasePercentHeavy;
		// Debug::Print(TEXT("ScaledBaseDamageHeavy"), BaseDamage);
	}

	//* final damage output
	const float FinalDamageDone = BaseDamage * SourceAttackPower / TargetDefensePower;
	// Debug::Print(TEXT("FinalDamageDone"), FinalDamageDone);


	//* placeholder attribute change
	if (FinalDamageDone > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(GetTPDamageCapture().DamageTakenProperty, EGameplayModOp::Override, FinalDamageDone));
	}

}