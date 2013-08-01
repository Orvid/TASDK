#pragma once
namespace UnrealScript
{
	enum DecalComponent__EDecalTransform : byte
	{
		DecalTransform_OwnerAbsolute = 0,
		DecalTransform_OwnerRelative = 1,
		DecalTransform_SpawnRelative = 2,
		DecalTransform_MAX = 3,
	};
}
