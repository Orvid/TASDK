#pragma once
namespace UnrealScript
{
	struct UTGFxTweenableMoviePlayer__GFxTween;
}
#include "GFxUI.GFxObject.h"
#include "GFxUI.GFxObject.ASDisplayInfo.h"
#include "UTGame.UTGFxTweenableMoviePlayer.TweenType.h"
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
	struct UTGFxTweenableMoviePlayer__GFxTween
	{
	public:
		ADD_STRUCT(UTGFxTweenableMoviePlayer__TweenType, ThisTweenType, 96)
		ADD_BOOL(bFinished, 92, 0x1)
		ADD_STRUCT(GFxObject__ASDisplayInfo, displayInfo, 48)
		ADD_STRUCT(ScriptString*, Callback, 36)
		ADD_STRUCT(ScriptString*, MemberName, 24)
		ADD_STRUCT(float, DesiredValue, 20)
		ADD_STRUCT(float, Delta, 16)
		ADD_STRUCT(float, StartValue, 12)
		ADD_STRUCT(float, Duration, 8)
		ADD_STRUCT(float, TweenTime, 4)
		ADD_OBJECT(GFxObject, TargetMC, 0)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
