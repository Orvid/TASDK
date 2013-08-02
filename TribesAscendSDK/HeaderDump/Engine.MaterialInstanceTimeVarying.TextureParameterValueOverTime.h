#pragma once
namespace UnrealScript
{
	struct MaterialInstanceTimeVarying__TextureParameterValueOverTime;
}
#include "Engine.MaterialInstanceTimeVarying.ParameterValueOverTime.h"
#include "Engine.Texture.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	struct MaterialInstanceTimeVarying__TextureParameterValueOverTime : public MaterialInstanceTimeVarying__ParameterValueOverTime
	{
	public:
		ADD_OBJECT(Texture, ParameterValue, 48)
	};
}
#undef ADD_OBJECT
