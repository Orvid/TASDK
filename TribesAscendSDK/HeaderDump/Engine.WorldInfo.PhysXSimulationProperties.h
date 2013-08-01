#pragma once
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
	struct WorldInfo__PhysXSimulationProperties
	{
	public:
		ADD_BOOL(bUseHardware, 0, 0x1)
		ADD_BOOL(bFixedTimeStep, 0, 0x2)
		ADD_STRUCT(float, TimeStep, 4)
		ADD_STRUCT(int, MaxSubSteps, 8)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
