
#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Blueprint/UserWidget.h"
#include "Inv_HoverItem.generated.h"

class UTextBlock;
class UInv_InventoryItem;
class UImage;
/**
 * 
 */
UCLASS()
class INVENTORY_API UInv_HoverItem : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void SetImageBrush(const FSlateBrush& Brush) const;
	void UpdateStackCount(const int32 Count) const;
	
	FGameplayTag GetItemType() const;
	int32 GetPreviousGridIndex() const { return PreviousGridIndex; }
	FIntPoint GetGridDimensions() const { return GridDimensions; }
	bool IsStackable() const { return bIsStackable; }
	int32 GetStackCount() const { return StackCount; }
	UInv_InventoryItem* GetInventoryItem() const;
	
	void SetPreviousGridIndex(int32 Index) { PreviousGridIndex = Index; }
	void SetGridDimensions(const FIntPoint& NewGridDimensions) { GridDimensions = NewGridDimensions; }
	void SetIsStackable(bool bStacks);
	void SetInventoryItem(UInv_InventoryItem* Item);
	
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_Icon;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock> Text_StackCount;
	
	int32 PreviousGridIndex;
	FIntPoint GridDimensions;
	bool bIsStackable = false;
	int32 StackCount = 0;
	TWeakObjectPtr<UInv_InventoryItem> InventoryItem;
	
};
