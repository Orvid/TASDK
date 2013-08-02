#pragma once
namespace UnrealScript
{
	struct UDKVehicle__VehicleAnim;
}
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
namespace UnrealScript
{
	struct UDKVehicle__VehicleAnim
	{
	public:
		ADD_STRUCT(ScriptArray<ScriptName>, AnimSeqs, 8)
		ADD_STRUCT(ScriptName, AnimPlayerName, 28)
		ADD_BOOL(bAnimLoopLastSeq, 24, 0x1)
		ADD_STRUCT(float, AnimRate, 20)
		ADD_STRUCT(ScriptName, AnimTag, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
