#pragma once
#include "IpDrv__MCPBase.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " IpDrv.OnlineEventsInterfaceMcp." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
namespace UnrealScript
{
	class OnlineEventsInterfaceMcp : public MCPBase
	{
	public:
		ADD_VAR(::BoolProperty, bBinaryStats, 0x1)
	};
}
#undef ADD_VAR
