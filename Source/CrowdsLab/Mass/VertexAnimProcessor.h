// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AnimToTextureDataAsset.h"
#include "CoreMinimal.h"
#include "MassProcessor.h"
#include "MassRepresentationTypes.h"

#include "VertexAnimProcessor.generated.h"

// Holds simple animation data
USTRUCT()
struct CROWDSLAB_API FVertexAnimInfoFragment : public FMassFragment
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UAnimToTextureDataAsset> AnimToTextureData;

	UPROPERTY(EditAnywhere)
	int IdleAnimIndex = 0;

	UPROPERTY(EditAnywhere)
	int RunAnimIndex = 0;

	// Speed threshhold for swapping between idle/run
	UPROPERTY(EditAnywhere)
	float SpeedThreshhold = 50.f;

	float GlobalStartTime = 0.0f;
	float PlayRate = 1.0f;
	int32 AnimationStateIndex = 0;
	bool bSwappedThisFrame = false;
	bool bCustomAnimation = false;
	int AnimPosition = 0;
};

/**
 * Vertex Animation processor for handling vertex animation changes. Simply updates meshes data based on FVertexAnimInfoFragment
 */
UCLASS()
class CROWDSLAB_API UVertexAnimProcessor : public UMassProcessor
{
	GENERATED_BODY()
public:
	UVertexAnimProcessor();

	virtual void ConfigureQueries() override;
	virtual void Execute(FMassEntityManager& EntityManager, FMassExecutionContext& Context) override;

	UFUNCTION()
	void UpdateISMVertexAnimation(FMassInstancedStaticMeshInfo& ISMInfo, FVertexAnimInfoFragment& AnimationData, float LODSignificance, float PrevLODSignificance, int32 NumFloatsToPad);

protected:
	FMassEntityQuery EntityQuery;
};
