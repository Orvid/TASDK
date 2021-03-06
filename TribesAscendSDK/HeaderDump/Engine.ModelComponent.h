#pragma once
namespace UnrealScript
{
	class ModelComponent;
}
#include "Core.Object.h"
#include "Core.Object.Pointer.h"
#include "Engine.PrimitiveComponent.h"
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
	class ModelComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(ScriptArray<Object__Pointer>, Nodes, 500)
		ADD_STRUCT(ScriptArray<Object__Pointer>, Elements, 512)
		ADD_STRUCT(int, ComponentIndex, 496)
		ADD_STRUCT(int, ZoneIndex, 492)
		ADD_OBJECT(Object, Model, 488)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
