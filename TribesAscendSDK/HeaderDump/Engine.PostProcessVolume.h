#pragma once
namespace UnrealScript
{
	class PostProcessVolume;
}
#include "Engine.PostProcessVolume.LUTBlender.h"
#include "Engine.PostProcessVolume.PostProcessSettings.h"
#include "Engine.SeqAct_Toggle.h"
#include "Engine.Volume.h"
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
	class PostProcessVolume : public Volume
	{
	public:
		typedef PostProcessVolume__LUTBlender LUTBlender;
		typedef PostProcessVolume__PostProcessSettings PostProcessSettings;
		ADD_BOOL(bEnabled, 748, 0x1)
		ADD_OBJECT(PostProcessVolume, NextLowerPriorityVolume, 744)
		ADD_STRUCT(PostProcessVolume__PostProcessSettings, Settings, 524)
		ADD_STRUCT(float, Priority, 520)
		void OnToggle(class SeqAct_Toggle* Action)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(24755);
			byte params[4] = { NULL };
			*(class SeqAct_Toggle**)params = Action;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
