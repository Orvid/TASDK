#pragma once
#include "UTGame__UTGameViewportClient.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrGameViewportClient." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrGameViewportClient : public UTGameViewportClient
	{
	public:
		ADD_OBJECT(TrChatConsole, ChatConsole)
	};
}
#undef ADD_OBJECT
