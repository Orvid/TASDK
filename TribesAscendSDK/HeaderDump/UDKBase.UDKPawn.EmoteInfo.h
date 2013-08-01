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
	struct UDKPawn__EmoteInfo
	{
	public:
		ADD_BOOL(bRequiresPlayer, 48, 0x1)
		ADD_STRUCT(ScriptName, Command, 40)
		ADD_BOOL(bTopHalfEmote, 36, 0x2)
		ADD_BOOL(bVictoryEmote, 36, 0x1)
		ADD_STRUCT(ScriptName, EmoteAnim, 28)
		ADD_STRUCT(ScriptString*, EmoteName, 16)
		ADD_STRUCT(ScriptName, EmoteTag, 8)
		ADD_STRUCT(ScriptName, CategoryName, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
