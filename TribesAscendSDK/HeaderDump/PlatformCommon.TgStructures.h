#pragma once
namespace UnrealScript
{
	class TgStructures;
}
#include "Core.Object.h"
#include "PlatformCommon.TgStructures.CMTargetType.h"
#include "PlatformCommon.TgStructures.CombatMessageInfo.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TgStructures : public Object
	{
	public:
		typedef TgStructures__CMTargetType CMTargetType;
		typedef TgStructures__CombatMessageInfo CombatMessageInfo;
	};
}
#undef ADD_STRUCT
