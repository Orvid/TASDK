#pragma once
namespace UnrealScript
{
	struct GameEngine__LevelStreamingStatus;
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
	struct GameEngine__LevelStreamingStatus
	{
	public:
		ADD_STRUCT(ScriptName, PackageName, 0)
		ADD_BOOL(bShouldBeLoaded, 8, 0x1)
		ADD_BOOL(bShouldBeVisible, 8, 0x2)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
