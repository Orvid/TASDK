#pragma once
namespace UnrealScript
{
	class LineBatchComponent;
}
#include "Core.Object.Pointer.h"
#include "Engine.PrimitiveComponent.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class LineBatchComponent : public PrimitiveComponent
	{
	public:
		ADD_STRUCT(ScriptArray<Object__Pointer>, BatchedLines, 496)
		ADD_STRUCT(ScriptArray<Object__Pointer>, BatchedPoints, 508)
		ADD_STRUCT(float, DefaultLifeTime, 520)
		ADD_STRUCT(Object__Pointer, FPrimitiveDrawInterfaceView, 492)
		ADD_STRUCT(Object__Pointer, FPrimitiveDrawInterfaceVfTable, 488)
	};
}
#undef ADD_STRUCT
