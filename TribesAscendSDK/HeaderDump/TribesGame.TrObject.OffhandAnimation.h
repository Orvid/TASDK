#pragma once
namespace UnrealScript
{
	struct TrObject__OffhandAnimation;
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
	struct TrObject__OffhandAnimation
	{
	public:
		ADD_STRUCT(ScriptName, m_OffhandUseType, 0)
		ADD_STRUCT(ScriptName, m_AnimName, 8)
		ADD_BOOL(m_bFullBody, 16, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
