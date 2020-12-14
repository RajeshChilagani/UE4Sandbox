// Fill out your copyright notice in the Description page of Project Settings.

#include "AON/AN_GameInstance.h"
#include "AON/Systems/AN_InventorySystem.h"

void UAN_GameInstance::Init()
{
	m_InventorySystem = NewObject<UAN_InventorySystem>();
	m_InventorySystem->LoadItemsData();
}

void UAN_GameInstance::Shutdown()
{

}