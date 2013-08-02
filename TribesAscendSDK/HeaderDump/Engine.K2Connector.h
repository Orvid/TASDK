#pragma once
namespace UnrealScript
{
	class K2Connector;
}
#include "Core.Object.h"
#include "Engine.K2Connector.EK2ConnectorDirection.h"
#include "Engine.K2Connector.EK2ConnectorType.h"
#include "Engine.K2NodeBase.h"
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
	class K2Connector : public Object
	{
	public:
		typedef K2Connector__EK2ConnectorType EK2ConnectorType;
		typedef K2Connector__EK2ConnectorDirection EK2ConnectorDirection;
		ADD_STRUCT(K2Connector__EK2ConnectorType, Type, 76)
		ADD_STRUCT(ScriptString*, ConnName, 64)
		ADD_OBJECT(K2NodeBase, OwningNode, 60)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
