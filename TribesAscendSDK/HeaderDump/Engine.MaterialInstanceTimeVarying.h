#pragma once
namespace UnrealScript
{
	class MaterialInstanceTimeVarying;
}
#include "Core.Object.InterpCurveFloat.h"
#include "Core.Object.InterpCurveVector.h"
#include "Core.Object.LinearColor.h"
#include "Engine.Font.h"
#include "Engine.MaterialInstance.h"
#include "Engine.MaterialInstanceTimeVarying.FontParameterValueOverTime.h"
#include "Engine.MaterialInstanceTimeVarying.ParameterValueOverTime.h"
#include "Engine.MaterialInstanceTimeVarying.ScalarParameterValueOverTime.h"
#include "Engine.MaterialInstanceTimeVarying.TextureParameterValueOverTime.h"
#include "Engine.MaterialInstanceTimeVarying.VectorParameterValueOverTime.h"
#include "Engine.MaterialInterface.h"
#include "Engine.Texture.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
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
	class MaterialInstanceTimeVarying : public MaterialInstance
	{
	public:
		typedef MaterialInstanceTimeVarying__ParameterValueOverTime ParameterValueOverTime;
		typedef MaterialInstanceTimeVarying__FontParameterValueOverTime FontParameterValueOverTime;
		typedef MaterialInstanceTimeVarying__ScalarParameterValueOverTime ScalarParameterValueOverTime;
		typedef MaterialInstanceTimeVarying__TextureParameterValueOverTime TextureParameterValueOverTime;
		typedef MaterialInstanceTimeVarying__VectorParameterValueOverTime VectorParameterValueOverTime;
		ADD_STRUCT(ScriptArray<MaterialInstanceTimeVarying__FontParameterValueOverTime>, FontParameterValues, 440)
		ADD_STRUCT(ScriptArray<MaterialInstanceTimeVarying__ScalarParameterValueOverTime>, ScalarParameterValues, 452)
		ADD_STRUCT(ScriptArray<MaterialInstanceTimeVarying__TextureParameterValueOverTime>, TextureParameterValues, 464)
		ADD_STRUCT(ScriptArray<MaterialInstanceTimeVarying__VectorParameterValueOverTime>, VectorParameterValues, 476)
		ADD_STRUCT(float, Duration, 436)
		ADD_BOOL(bAutoActivateAll, 432, 0x1)
		void SetParent(class MaterialInterface* NewParent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19883);
			byte params[4] = { NULL };
			*(class MaterialInterface**)params = NewParent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetScalarParameterValue(ScriptName ParameterName, float Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19885);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(float*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetScalarCurveParameterValue(ScriptName ParameterName, Object__InterpCurveFloat& Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19888);
			byte params[24] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Object__InterpCurveFloat*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(Object__InterpCurveFloat*)&params[8];
		}
		void SetScalarStartTime(ScriptName ParameterName, float Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19891);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(float*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetDuration(float Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19894);
			byte params[4] = { NULL };
			*(float*)params = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetTextureParameterValue(ScriptName ParameterName, class Texture* Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19896);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(class Texture**)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetVectorParameterValue(ScriptName ParameterName, Object__LinearColor& Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19899);
			byte params[24] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Object__LinearColor*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(Object__LinearColor*)&params[8];
		}
		void SetVectorCurveParameterValue(ScriptName ParameterName, Object__InterpCurveVector& Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19902);
			byte params[24] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(Object__InterpCurveVector*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			Value = *(Object__InterpCurveVector*)&params[8];
		}
		void SetVectorStartTime(ScriptName ParameterName, float Value)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19905);
			byte params[12] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(float*)&params[8] = Value;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetFontParameterValue(ScriptName ParameterName, class Font* FontValue, int FontPage)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19908);
			byte params[16] = { NULL };
			*(ScriptName*)params = ParameterName;
			*(class Font**)&params[8] = FontValue;
			*(int*)&params[12] = FontPage;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearParameterValues()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19912);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		float GetMaxDurationFromAllParameters()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(19913);
			byte params[4] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(float*)params;
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
