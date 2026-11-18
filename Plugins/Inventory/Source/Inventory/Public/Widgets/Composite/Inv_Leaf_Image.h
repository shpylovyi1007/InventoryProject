
#pragma once

#include "CoreMinimal.h"
#include "Inv_Leaf.h"
#include "Inv_Leaf_Image.generated.h"

class USizeBox;
class UImage;
/**
 * 
 */
UCLASS()
class INVENTORY_API UInv_Leaf_Image : public UInv_Leaf
{
	GENERATED_BODY()
public:
	FVector2D GetImageSize() const;
	
	void SetImage(UTexture2D* Texture) const;
	void SetBoxSize(const FVector2D& BoxSize) const;
	void SetImageSize(const FVector2D& ImageSize) const;
	
private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage> Image_Icon;
	
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<USizeBox> SizeBox_Icon;
};
