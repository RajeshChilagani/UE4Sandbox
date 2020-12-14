// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AON/AN_Item.h"
#include "AN_InventorySystem.generated.h"

/**
 * 
 */
UCLASS()
class UE4SANDBOX_API UAN_InventorySystem : public UObject
{
	GENERATED_BODY()
public:
	UAN_InventorySystem();
	~UAN_InventorySystem();
	UFUNCTION()
	void LoadItemsData();

	UFUNCTION(BlueprintCallable)
	void AddItem(const FString& ItemName);
	
	UPROPERTY(BlueprintReadOnly)
	TMap<FString, FAN_InventoryItem> m_Items;

private:
	
	class UDataTable* m_ItemsData;
};
