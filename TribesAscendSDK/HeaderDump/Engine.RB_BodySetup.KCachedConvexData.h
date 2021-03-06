#pragma once
namespace UnrealScript
{
	struct RB_BodySetup__KCachedConvexData;
}
#include "Engine.RB_BodySetup.KCachedConvexDataElement.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct RB_BodySetup__KCachedConvexData
	{
	public:
		ADD_STRUCT(ScriptArray<RB_BodySetup__KCachedConvexDataElement>, CachedConvexElements, 0)
	};
}
#undef ADD_STRUCT
