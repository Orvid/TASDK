#pragma once
namespace UnrealScript
{
	class MaterialExpressionVectorParameter;
}
#include "Core.Object.LinearColor.h"
#include "Engine.MaterialExpressionParameter.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class MaterialExpressionVectorParameter : public MaterialExpressionParameter
	{
	public:
		ADD_STRUCT(Object__LinearColor, DefaultValue, 132)
	};
}
#undef ADD_STRUCT
