// Fill out your copyright notice in the Description page of Project Settings.


#include "AON/Systems/AN_InventorySystem.h"
#include "UObject/ConstructorHelpers.h"

UAN_InventorySystem::UAN_InventorySystem()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> ItemsDataTable(TEXT("DataTable'/Game/Data/AN_ItemTable.AN_ItemTable'"));
	if (ItemsDataTable.Succeeded())
	{
		m_ItemsData = ItemsDataTable.Object;
	}
}

UAN_InventorySystem::~UAN_InventorySystem()
{

}

void UAN_InventorySystem::LoadItemsData()
{
	
}

void UAN_InventorySystem::AddItem(const FString& ItemName)
{
	if (!m_Items.Contains(ItemName))
	{
		if (!m_ItemsData)
		{
			UE_LOG(LogTemp, Error, TEXT("ItemsDataTable Not Found. Please add a Data Table"));
			return;

		}
		static const FString ContextString("Item Context String");
		FAN_Item* ItemData = m_ItemsData->FindRow<FAN_Item>(FName(FString("RN_").Append(ItemName)), ContextString, true);
		if (!ItemData)
		{
			UE_LOG(LogTemp, Error, TEXT("Adding InValid Item. There is no item with the name %s"), *ItemName);
			return;
		}
		FAN_InventoryItem Item;
		Item.Description = ItemData->Description;
		Item.Name = ItemData->Name;
		m_Items.Add(ItemName, Item);
	}
	m_Items[ItemName].Count++;
}

