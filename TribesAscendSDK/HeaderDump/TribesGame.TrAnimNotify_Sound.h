#pragma once
#include "Engine.AnimNotify_Sound.h"
#include "TribesGame.TrAnimNotify_Sound.DeviceOverride.h"
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
	class TrAnimNotify_Sound : public AnimNotify_Sound
	{
	public:
		ADD_STRUCT(ScriptArray<TrAnimNotify_Sound__DeviceOverride>, m_DeviceOverrides, 92)
		ADD_OBJECT(ScriptClass, m_PreviewDeviceClass, 104)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
