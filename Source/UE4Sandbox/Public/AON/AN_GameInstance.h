// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AN_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE4SANDBOX_API UAN_GameInstance : public UGameInstance
{
	GENERATED_BODY()
public:

	void Init() override;
	void Shutdown() override;
	UPROPERTY(BlueprintReadOnly)
	class UAN_InventorySystem* m_InventorySystem;
private:
	//class UAN_CraftingSystem* m_CraftingSystem;
};
