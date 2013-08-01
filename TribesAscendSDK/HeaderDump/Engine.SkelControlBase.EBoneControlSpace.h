#pragma once
namespace UnrealScript
{
	enum SkelControlBase__EBoneControlSpace : byte
	{
		BCS_WorldSpace = 0,
		BCS_ActorSpace = 1,
		BCS_ComponentSpace = 2,
		BCS_ParentBoneSpace = 3,
		BCS_BoneSpace = 4,
		BCS_OtherBoneSpace = 5,
		BCS_BaseMeshSpace = 6,
		BCS_MAX = 7,
	};
}
