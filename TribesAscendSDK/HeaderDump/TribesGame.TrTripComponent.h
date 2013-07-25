#pragma once
#include "Engine.PrimitiveComponent.h"
#include "TribesGame.TrTripActor.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " TribesGame.TrTripComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty TribesGame.TrTripComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class TrTripComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::FloatProperty, m_fCachedX, 0xFFFFFFFF)
		ADD_OBJECT(TrTripActor, m_TripActor)
	};
}
#undef ADD_VAR
#undef ADD_OBJECT