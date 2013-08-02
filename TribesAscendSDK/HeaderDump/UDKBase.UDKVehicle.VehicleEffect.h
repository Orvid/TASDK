#pragma once
namespace UnrealScript
{
	struct UDKVehicle__VehicleEffect;
}
#include "Engine.ParticleSystem.h"
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
	struct UDKVehicle__VehicleEffect
	{
	public:
		ADD_STRUCT(ScriptName, EffectSocket, 28)
		ADD_OBJECT(ParticleSystem, EffectTemplate_Blue, 24)
		ADD_OBJECT(ParticleSystem, EffectTemplate, 20)
		ADD_BOOL(bHighDetailOnly, 16, 0x2)
		ADD_BOOL(bRestartRunning, 16, 0x1)
		ADD_STRUCT(ScriptName, EffectEndTag, 8)
		ADD_STRUCT(ScriptName, EffectStartTag, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
