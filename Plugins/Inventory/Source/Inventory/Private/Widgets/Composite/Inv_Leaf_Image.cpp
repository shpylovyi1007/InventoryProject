

#include "Widgets/Composite/Inv_Leaf_Image.h"

#include "Components/Image.h"
#include "Components/SizeBox.h"

FVector2D UInv_Leaf_Image::GetImageSize() const
{
	return Image_Icon->GetDesiredSize();
}

void UInv_Leaf_Image::SetImage(UTexture2D* Texture) const
{
	Image_Icon->SetBrushFromTexture(Texture);
}

void UInv_Leaf_Image::SetBoxSize(const FVector2D& BoxSize) const
{
	SizeBox_Icon->SetWidthOverride(BoxSize.X);
	SizeBox_Icon->SetHeightOverride(BoxSize.Y);
}

void UInv_Leaf_Image::SetImageSize(const FVector2D& ImageSize) const
{
	Image_Icon->SetDesiredSizeOverride(ImageSize);
}
