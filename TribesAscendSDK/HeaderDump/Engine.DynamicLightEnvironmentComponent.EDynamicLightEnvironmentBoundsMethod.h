#pragma once
namespace UnrealScript
{
	enum DynamicLightEnvironmentComponent__EDynamicLightEnvironmentBoundsMethod : byte
	{
		DLEB_OwnerComponents = 0,
		DLEB_ManualOverride = 1,
		DLEB_ActiveComponents = 2,
		DLEB_MAX = 3,
	};
}
