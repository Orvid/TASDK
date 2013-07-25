#pragma once
#include "Engine__K2Connector.h"
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.K2Input." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class K2Input : public K2Connector
	{
	public:
		ADD_OBJECT(K2Output, FromOutput)
	};
}
#undef ADD_OBJECT
