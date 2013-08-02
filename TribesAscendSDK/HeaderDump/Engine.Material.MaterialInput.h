#pragma once
namespace UnrealScript
{
	struct Material__MaterialInput;
}
#include "Engine.MaterialExpression.h"
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
	struct Material__MaterialInput
	{
	public:
		ADD_STRUCT(int, GCC64_Padding, 24)
		ADD_STRUCT(int, MaskA, 20)
		ADD_STRUCT(int, MaskB, 16)
		ADD_STRUCT(int, MaskG, 12)
		ADD_STRUCT(int, MaskR, 8)
		ADD_STRUCT(int, Mask, 4)
		ADD_OBJECT(MaterialExpression, Expression, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
