#pragma once
#include "Core.Object.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.NavMeshPathGoalEvaluator." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.NavMeshPathGoalEvaluator." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class NavMeshPathGoalEvaluator : public Object
	{
	public:
		ADD_VAR(::IntProperty, NumNodesProcessed, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, NumNodesThrownOut, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bAlwaysCallEvaluateGoal, 0x1)
		ADD_VAR(::IntProperty, MaxPathVisits, 0xFFFFFFFF)
		ADD_OBJECT(NavMeshPathGoalEvaluator, NextEvaluator)
		void Recycle()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPathGoalEvaluator.Recycle");
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		ScriptArray<wchar_t> GetDumpString()
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.NavMeshPathGoalEvaluator.GetDumpString");
			byte* params = (byte*)malloc(12);
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			auto returnVal = *(ScriptArray<wchar_t>*)params;
			free(params);
			return returnVal;
		}
	};
}
#undef ADD_VAR
#undef ADD_OBJECT