#pragma once
namespace UnrealScript
{
	struct GameEngine__FullyLoadedPackagesInfo;
}
#include "Core.Object.h"
#include "Engine.GameEngine.EFullyLoadPackageType.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct GameEngine__FullyLoadedPackagesInfo
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptName>, PackagesToLoad, 16)
		ADD_STRUCT(ScriptArray<class Object*>, LoadedObjects, 28)
		ADD_STRUCT(ScriptString*, Tag, 4)
		ADD_STRUCT(GameEngine__EFullyLoadPackageType, FullyLoadType, 0)
	};
}
#undef ADD_STRUCT
