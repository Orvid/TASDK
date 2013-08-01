#pragma once
namespace UnrealScript
{
	enum TrObject__DeployModeStatus : byte
	{
		DMS_None = 0,
		DMS_CannotFire = 1,
		DMS_CannotPlace = 2,
		DMS_OK = 3,
		DMS_MAX = 4,
	};
}
