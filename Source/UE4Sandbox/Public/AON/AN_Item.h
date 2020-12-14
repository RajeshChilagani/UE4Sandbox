// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Engine/DataTable.h>
#include "AN_Item.generated.h"

/**
 * A representation of an Item in AON.
 */
USTRUCT(BlueprintType)
struct FAN_Item : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere)
	FString Name;

	UPROPERTY(EditAnyWhere)
	FString Description;
};

/**
 * An Item in the game that can be added to inventory.
 */
USTRUCT(BlueprintType)
struct FAN_InventoryItem
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnyWhere)
	FString Name;

	UPROPERTY(VisibleAnyWhere)
	FString Description;

	UPROPERTY(VisibleAnyWhere)
	uint16 Count;
};

/**
 * An Item that can be crafted.
 */
USTRUCT(BlueprintType)
struct FAN_CraftItem : public FAN_Item
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	uint8 AmountToCraft;

	UPROPERTY(VisibleAnywhere)
	FString Receipe;
};

