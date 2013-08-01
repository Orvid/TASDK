#pragma once
#include "Engine.OnlineSubsystem.OnlineRegistrant.h"
#include "Engine.OnlineGameSettings.h"
#include "Engine.OnlineSubsystem.OnlineArbitrationRegistrant.h"
#include "Core.Object.Pointer.h"
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
	struct OnlineSubsystem__NamedSession
	{
	public:
		ADD_OBJECT(OnlineGameSettings, GameSettings, 12)
		ADD_STRUCT(ScriptArray<OnlineSubsystem__OnlineRegistrant>, Registrants, 16)
		ADD_STRUCT(ScriptArray<OnlineSubsystem__OnlineArbitrationRegistrant>, ArbitrationRegistrants, 28)
		ADD_STRUCT(ScriptName, SessionName, 0)
		ADD_STRUCT(Object__Pointer, SessionInfo, 8)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
