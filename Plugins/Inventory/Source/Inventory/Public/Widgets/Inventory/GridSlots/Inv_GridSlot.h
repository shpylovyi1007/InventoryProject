
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_GridSlot.generated.h"

class UInv_ItemPopUp;
class UInv_InventoryItem;
class UImage;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FGridSlotEvent, int32, GridIndex, const FPointerEvent&, MouseEvent);


UENUM(BlueprintType)
enum class EInv_GridSlotState : uint8 
{
	Unoccupied,
	Occupied,
	Selected, 
	GrayedOut
};
/**
 * 
 */
UCLASS()
class INVENTORY_API UInv_GridSlot : public UUserWidget
{
	GENERATED_BODY()
	
public:
	EInv_GridSlotState GetGridSlotState() const { return GridSlotState; }
	int32 GetTileIndex() const { return TileIndex; }
	int32 GetStackCount() const { return StackCount; }
	int32 GetUpperLeftIndex() const { return UpperLeftIndex; }
	bool IsAvailable() const { return bAvailable; }
	TWeakObjectPtr<UInv_InventoryItem> GetInventoryItem() const { return InventoryItem; }
	UInv_ItemPopUp* GetItemPopUp() const { return ItemPopUp.Get(); }
	
	void SetTileIndex(int32 Index) { TileIndex = Index; }
	void SetStackCount(int32 InStackCount) { StackCount = InStackCount; }
	void SetUpperLeftIndex(int32 Index) { UpperLeftIndex = Index; }
	void SetInventoryItem(UInv_InventoryItem* Item);
	void SetIsAvailable(bool bIsAvailable) { bAvailable = bIsAvailable; }
	void SetItemPopUp(UInv_ItemPopUp* PopUp);
	
	void SetUnoccupiedTexture();
	void SetOccupiedTexture();
	void SetSelectedTexture();
	void SetGrayedOutTexture();
	
	FGridSlotEvent GridSlotClicked;
	FGridSlotEvent GridSlotHovered;
	FGridSlotEvent GridSlotUnhovered;
	
protected:
	virtual void NativeOnMouseEnter(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual void NativeOnMouseLeave(const FPointerEvent& InMouseEvent) override;
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	
	
private:
	int32 StackCount{0};
	int32 TileIndex{INDEX_NONE};
	int32 UpperLeftIndex{INDEX_NONE};
	bool bAvailable = true;
	
	TWeakObjectPtr<UInv_InventoryItem> InventoryItem;
	TWeakObjectPtr<UInv_ItemPopUp> ItemPopUp;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_GridSlot;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FSlateBrush Brush_Unoccupied;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FSlateBrush Brush_Occupied;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FSlateBrush Brush_Selected;
	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	FSlateBrush Brush_GrayedOut;
	
	EInv_GridSlotState GridSlotState;
	
	UFUNCTION()
	void OnItemPopUpDestruct(UUserWidget* Menu);
};
