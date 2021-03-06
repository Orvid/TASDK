#pragma once
namespace UnrealScript
{
	struct MaterialInstanceConstant__TextureParameterValue;
}
#include "Core.Object.Guid.h"
#include "Engine.Texture.h"
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
	struct MaterialInstanceConstant__TextureParameterValue
	{
	public:
		ADD_STRUCT(Object__Guid, ExpressionGUID, 12)
		ADD_OBJECT(Texture, ParameterValue, 8)
		ADD_STRUCT(ScriptName, ParameterName, 0)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
