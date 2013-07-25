#pragma once
#include "GameFramework__SeqEvent_MobileRawInput.h"
#include "Core__Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " GameFramework.SeqEvent_MobileObjectPicker." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty GameFramework.SeqEvent_MobileObjectPicker." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty GameFramework.SeqEvent_MobileObjectPicker." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqEvent_MobileObjectPicker : public SeqEvent_MobileRawInput
	{
	public:
		ADD_OBJECT(Object, FinalTouchObject)
		ADD_STRUCT(::VectorProperty, FinalTouchNormal, 0xFFFFFFFF
		ADD_STRUCT(::VectorProperty, FinalTouchLocation, 0xFFFFFFFF
		ADD_VAR(::FloatProperty, TraceDistance, 0xFFFFFFFF)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
