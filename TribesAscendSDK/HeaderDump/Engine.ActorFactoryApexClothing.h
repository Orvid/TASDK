#pragma once
namespace UnrealScript
{
	class ActorFactoryApexClothing;
}
#include "Engine.ActorFactorySkeletalMesh.h"
#include "Engine.ApexClothingAsset.h"
#include "Engine.PrimitiveComponent.ERBCollisionChannel.h"
#include "Engine.PrimitiveComponent.RBCollisionChannelContainer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class ActorFactoryApexClothing : public ActorFactorySkeletalMesh
	{
	public:
		ADD_STRUCT(ScriptArray<class ApexClothingAsset*>, ClothingAssets, 108)
		ADD_STRUCT(PrimitiveComponent__RBCollisionChannelContainer, ClothingRBCollideWithChannels, 124)
		ADD_STRUCT(PrimitiveComponent__ERBCollisionChannel, ClothingRBChannel, 120)
	};
}
#undef ADD_STRUCT
