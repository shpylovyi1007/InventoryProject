
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/Inv_GridTypes.h"
#include "Inv_InventoryGrid.generated.h"

struct FInv_ItemManifest;
class UInv_ItemComponent;
class UInv_InventoryComponent;
class UCanvasPanel;
class UInv_GridSlot;
/**
 * 
 */
UCLASS()
class INVENTORY_API UInv_InventoryGrid : public UUserWidget
{
	GENERATED_BODY()
	
public:
	
	EInv_ItemCategory GetItemCategory() const { return ItemCategory; }
	FInv_SlotAvailabilityResult HasRoomForItemComponent(const UInv_ItemComponent* ItemComponent);
	
	
	UFUNCTION()
	void AddItem(UInv_InventoryItem* Item);
	
protected:
	
	virtual void NativeOnInitialized() override;
	
	
private:
	
	TWeakObjectPtr<UInv_InventoryComponent> InventoryComponent;
	void ConstructGrid();
	FInv_SlotAvailabilityResult HasRoomForItem(const UInv_InventoryItem* Item);
	FInv_SlotAvailabilityResult HasRoomForItem(const FInv_ItemManifest& Manifest);
	
	void AddItemToIndices(const FInv_SlotAvailabilityResult& Result, UInv_InventoryItem* NewItem);
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Inventory")
	EInv_ItemCategory ItemCategory;
	
	UPROPERTY()
	TArray<TObjectPtr<UInv_GridSlot>> GridSlots;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<UInv_GridSlot> GridSlotClass;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCanvasPanel> CanvasPanel;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 Rows;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 Columns;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	float TileSize;
	
	bool MatchesCategory(const UInv_InventoryItem* Item) const;
};
