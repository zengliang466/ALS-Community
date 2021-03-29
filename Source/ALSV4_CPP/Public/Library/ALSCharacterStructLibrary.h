// Project:         Advanced Locomotion System V4 on C++
// Copyright:       Copyright (C) 2021 Doğa Can Yanıkoğlu
// License:         MIT License (http://www.opensource.org/licenses/mit-license.php)
// Source Code:     https://github.com/dyanikoglu/ALSV4_CPP
// Original Author: Doğa Can Yanıkoğlu
// Contributors:

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Library/ALSCharacterEnumLibrary.h"

#include "ALSCharacterStructLibrary.generated.h"

class UCurveVector;
class UAnimMontage;
class UAnimSequenceBase;
class UCurveFloat;
class UNiagaraSystem;

USTRUCT(BlueprintType)
struct FALSComponentAndTransform
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "ALS|Character Struct Library")
	FTransform Transform;

	UPROPERTY(EditAnywhere, Category = "ALS|Character Struct Library")
	class UPrimitiveComponent *Component = nullptr;
};

USTRUCT(BlueprintType)
struct FALSCameraSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "ALS|Camera")
	float TargetArmLength = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Camera")
	FVector SocketOffset;

	UPROPERTY(EditAnywhere, Category = "ALS|Camera")
	float LagSpeed = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Camera")
	float RotationLagSpeed = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Camera")
	bool bDoCollisionTest = true;
};

USTRUCT(BlueprintType)
struct FALSCameraGaitSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "ALS|Camera")
	FALSCameraSettings Walking;

	UPROPERTY(EditAnywhere, Category = "ALS|Camera")
	FALSCameraSettings Running;

	UPROPERTY(EditAnywhere, Category = "ALS|Camera")
	FALSCameraSettings Sprinting;

	UPROPERTY(EditAnywhere, Category = "ALS|Camera")
	FALSCameraSettings Crouching;
};

USTRUCT(BlueprintType)
struct FALSCameraStateSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "ALS|Camera")
	FALSCameraGaitSettings VelocityDirection;

	UPROPERTY(EditAnywhere, Category = "ALS|Camera")
	FALSCameraGaitSettings LookingDirection;

	UPROPERTY(EditAnywhere, Category = "ALS|Camera")
	FALSCameraGaitSettings Aiming;
};

USTRUCT(BlueprintType)
struct FALSMantleAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	UAnimMontage *AnimMontage = nullptr;

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	UCurveVector *PositionCorrectionCurve = nullptr;

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	FVector StartingOffset;

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	float LowHeight = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	float LowPlayRate = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	float LowStartPosition = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	float HighHeight = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	float HighPlayRate = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	float HighStartPosition = 0.0f;
};

USTRUCT(BlueprintType)
struct FALSMantleParams
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	UAnimMontage *AnimMontage = nullptr;

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	UCurveVector *PositionCorrectionCurve = nullptr;

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	float StartingPosition = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	float PlayRate = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	FVector StartingOffset;
};

USTRUCT(BlueprintType)
struct FALSMantleTraceSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	float MaxLedgeHeight = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	float MinLedgeHeight = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	float ReachDistance = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	float ForwardTraceRadius = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Mantle System")
	float DownwardTraceRadius = 0.0f;
};

USTRUCT(BlueprintType)
struct FALSMovementSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "ALS|Movement Settings")
	float WalkSpeed = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Movement Settings")
	float RunSpeed = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Movement Settings")
	float SprintSpeed = 0.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Movement Settings")
	UCurveVector *MovementCurve = nullptr;

	UPROPERTY(EditAnywhere, Category = "ALS|Movement Settings")
	UCurveFloat *RotationRateCurve = nullptr;

	float GetSpeedForGait(const EALSGait Gait) const
	{
		switch (Gait)
		{
		case EALSGait::Running:
			return RunSpeed;
		case EALSGait::Sprinting:
			return SprintSpeed;
		case EALSGait::Walking:
			return WalkSpeed;
		default:
			return RunSpeed;
		}
	}
};

USTRUCT(BlueprintType)
struct FALSMovementStanceSettings
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "ALS|Movement Settings")
	FALSMovementSettings Standing;

	UPROPERTY(EditAnywhere, Category = "ALS|Movement Settings")
	FALSMovementSettings Crouching;
};

USTRUCT(BlueprintType)
struct FALSMovementStateSettings : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "ALS|Movement Settings")
	FALSMovementStanceSettings VelocityDirection;

	UPROPERTY(EditAnywhere, Category = "ALS|Movement Settings")
	FALSMovementStanceSettings LookingDirection;

	UPROPERTY(EditAnywhere, Category = "ALS|Movement Settings")
	FALSMovementStanceSettings Aiming;
};

USTRUCT(BlueprintType)
struct FALSRotateInPlaceAsset
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "ALS|Rotation System")
	UAnimSequenceBase *Animation = nullptr;

	UPROPERTY(EditAnywhere, Category = "ALS|Rotation System")
	FName SlotName;

	UPROPERTY(EditAnywhere, Category = "ALS|Rotation System")
	float SlowTurnRate = 90.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Rotation System")
	float FastTurnRate = 90.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Rotation System")
	float SlowPlayRate = 1.0f;

	UPROPERTY(EditAnywhere, Category = "ALS|Rotation System")
	float FastPlayRate = 1.0f;
};

USTRUCT(BlueprintType)
struct FALSHitFX : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Surface")
	TEnumAsByte<EPhysicalSurface> SurfaceType;

	UPROPERTY(EditAnywhere, Category = "Sound")
	TSoftObjectPtr<USoundBase> Sound;

	UPROPERTY(EditAnywhere, Category = "Sound")
	EALSSpawnType SoundSpawnType;

	UPROPERTY(EditAnywhere, Category = "Sound", meta = (EditCondition = "SoundSpawnType == EALSSpawnType::Attached"))
	TEnumAsByte<EAttachLocation::Type> SoundAttachmentType;

	UPROPERTY(EditAnywhere, Category = "Sound")
	FVector SoundLocationOffset;

	UPROPERTY(EditAnywhere, Category = "Sound")
	FRotator SoundRotationOffset;

	UPROPERTY(EditAnywhere, Category = "Decal")
	TSoftObjectPtr<UMaterialInterface> DecalMaterial;

	UPROPERTY(EditAnywhere, Category = "Decal")
	EALSSpawnType DecalSpawnType;

	UPROPERTY(EditAnywhere, Category = "Decal", meta = (EditCondition = "DecalSpawnType == EALSSpawnType::Attached"))
	TEnumAsByte<EAttachLocation::Type> DecalAttachmentType;

	UPROPERTY(EditAnywhere, Category = "Decal")
	float DecalLifeSpan = 10.0f;

	UPROPERTY(EditAnywhere, Category = "Decal")
	FVector DecalSize;

	UPROPERTY(EditAnywhere, Category = "Decal")
	FVector DecalLocationOffset;

	UPROPERTY(EditAnywhere, Category = "Decal")
	FRotator DecalRotationOffset;

	UPROPERTY(EditAnywhere, Category = "Niagara")
	TSoftObjectPtr<class UNiagaraSystem> NiagaraSystem;

	UPROPERTY(EditAnywhere, Category = "Niagara")
	EALSSpawnType NiagaraSpawnType;

	UPROPERTY(EditAnywhere, Category = "Niagara", meta = (EditCondition = "NiagaraSpawnType == EALSSpawnType::Attached"))
	TEnumAsByte<EAttachLocation::Type> NiagaraAttachmentType;

	UPROPERTY(EditAnywhere, Category = "Niagara")
	FVector NiagaraLocationOffset;

	UPROPERTY(EditAnywhere, Category = "Niagara")
	FRotator NiagaraRotationOffset;
};
