#pragma once
namespace UnrealScript
{
	enum UIDataProvider__EProviderAccessType : byte
	{
		ACCESS_ReadOnly = 0,
		ACCESS_PerField = 1,
		ACCESS_WriteAll = 2,
		ACCESS_MAX = 3,
	};
}
