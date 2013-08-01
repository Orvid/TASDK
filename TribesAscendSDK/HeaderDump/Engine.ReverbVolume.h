#pragma once
#include "Engine.Volume.h"
#include "Engine.ReverbVolume.InteriorSettings.h"
#include "Engine.ReverbVolume.ReverbSettings.h"
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
	class ReverbVolume : public Volume
	{
	public:
		ADD_OBJECT(ReverbVolume, NextLowerPriorityVolume, 580)
		ADD_STRUCT(ReverbVolume__InteriorSettings, AmbientZoneSettings, 544)
		ADD_STRUCT(ReverbVolume__ReverbSettings, Settings, 528)
		ADD_BOOL(bEnabled, 524, 0x1)
		ADD_STRUCT(float, Priority, 520)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
