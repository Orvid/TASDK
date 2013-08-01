#pragma once
namespace UnrealScript
{
	enum SkeletalMesh__BoneBreakOption : byte
	{
		BONEBREAK_SoftPreferred = 0,
		BONEBREAK_AutoDetect = 1,
		BONEBREAK_RigidPreferred = 2,
		BONEBREAK_MAX = 3,
	};
}
