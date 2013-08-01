#pragma once
namespace UnrealScript
{
	enum EngineTypes__ELightingBuildQuality : byte
	{
		Quality_Preview = 0,
		Quality_Medium = 1,
		Quality_High = 2,
		Quality_Production = 3,
		Quality_NoGlobalIllumination = 4,
		Quality_MAX = 5,
	};
}
