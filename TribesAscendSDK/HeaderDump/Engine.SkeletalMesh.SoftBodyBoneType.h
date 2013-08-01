#pragma once
namespace UnrealScript
{
	enum SkeletalMesh__SoftBodyBoneType : byte
	{
		SOFTBODYBONE_Fixed = 0,
		SOFTBODYBONE_BreakableAttachment = 1,
		SOFTBODYBONE_TwoWayAttachment = 2,
		SOFTBODYBONE_MAX = 3,
	};
}
