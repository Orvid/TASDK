#pragma once
#include "Engine__SequenceVariable.h"
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.SeqVar_Object." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.SeqVar_Object." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class SeqVar_Object : public SequenceVariable
	{
	public:
		ADD_STRUCT(::VectorProperty, ActorLocation, 0xFFFFFFFF
		ADD_OBJECT(Object, ObjValue)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
