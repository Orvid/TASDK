#pragma once
namespace UnrealScript
{
	struct TrSeekingMissileManager__TargetingSaberLauncherInfo;
}
#include "TribesGame.TrDevice_SaberLauncher.h"
#include "TribesGame.TrPlayerController.h"
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
	struct TrSeekingMissileManager__TargetingSaberLauncherInfo
	{
	public:
		ADD_OBJECT(TrDevice_SaberLauncher, SaberLauncher, 0)
		ADD_STRUCT(float, RemainingClientNotificationTime, 8)
		ADD_OBJECT(TrPlayerController, VictimController, 4)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
