#pragma once
#include "Engine.MaterialInstanceTimeVarying.ParameterValueOverTime.h"
#include "Engine.Font.h"
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
	struct MaterialInstanceTimeVarying__FontParameterValueOverTime : public MaterialInstanceTimeVarying__ParameterValueOverTime
	{
	public:
		ADD_STRUCT(int, FontPage, 52)
		ADD_OBJECT(Font, FontValue, 48)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
