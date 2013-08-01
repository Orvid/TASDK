#pragma once
#include "Core.Object.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class TrObject : public Object
	{
	public:
		static const auto FEET_TO_UNREAL_UNITS = 16;
		static const auto INDEX_DISPLAY_TARGET_INGAME = 0;
		static const auto INDEX_DISPLAY_TARGET_FOREGROUND = 1;
		static const auto INDEX_SEE_NORMAL_ENEMY = 0;
		static const auto INDEX_SEE_STEALTHED_ENEMY = 1;
		static const auto INDEX_SEE_LOW_HEALTH_ENEMY = 2;
		static const auto TR_TASKFORCE_NONE = 0;
		static const auto TR_TASKFORCE_BLOODEAGLE = 1;
		static const auto TR_TASKFORCE_DIAMONDSWORD = 2;
		static const float FADE_TIME;
		static const auto MAX_HEARING_DISTANCE = 1300;
		static const auto TR_MAX_SLOTS_TO_EQUIP = 5;
		static const float UnrealUnitsToKM;
	};
	const float TrObject::FADE_TIME = 1.0f;
	const float TrObject::UnrealUnitsToKM = 0.072f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
