#pragma once
namespace UnrealScript
{
	class SceneCaptureReflectActor;
}
#include "Engine.MaterialInstanceConstant.h"
#include "Engine.SceneCaptureActor.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SceneCaptureReflectActor : public SceneCaptureActor
	{
	public:
		ADD_OBJECT(MaterialInstanceConstant, ReflectMaterialInst, 484)
	};
}
#undef ADD_OBJECT
