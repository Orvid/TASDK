#pragma once
#include "Core.Object.h"
#include "TribesGame.TrSkin.SkinStruct.h"
#include "TribesGame.TrSkin.VehicleSkinStruct.h"
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
	class TrSkin : public Object
	{
	public:
		ADD_STRUCT(ScriptString*, ItemName, 64)
		ADD_STRUCT(ScriptString*, InfoPanelDescription, 76)
		ADD_STRUCT(int, TranslucencySortPriority, 88)
		ADD_STRUCT(ScriptArray<TrSkin__SkinStruct>, Skins, 96)
		ADD_STRUCT(int, ItemId, 60)
		ADD_OBJECT(ScriptClass, SkinMeleeDevice, 92)
		ADD_STRUCT(ScriptArray<TrSkin__VehicleSkinStruct>, VehicleSkins, 108)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
