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
	struct ReverbVolume__InteriorSettings
	{
	public:
		ADD_BOOL(bIsWorldInfo, 0, 0x1)
		ADD_STRUCT(float, ExteriorVolume, 4)
		ADD_STRUCT(float, ExteriorTime, 8)
		ADD_STRUCT(float, ExteriorLPF, 12)
		ADD_STRUCT(float, ExteriorLPFTime, 16)
		ADD_STRUCT(float, InteriorVolume, 20)
		ADD_STRUCT(float, InteriorTime, 24)
		ADD_STRUCT(float, InteriorLPF, 28)
		ADD_STRUCT(float, InteriorLPFTime, 32)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
