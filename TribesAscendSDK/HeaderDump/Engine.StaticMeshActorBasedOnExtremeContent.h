#pragma once
namespace UnrealScript
{
	class StaticMeshActorBasedOnExtremeContent;
}
#include "Engine.Actor.h"
#include "Engine.StaticMeshActorBasedOnExtremeContent.SMMaterialSetterDatum.h"
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
	class StaticMeshActorBasedOnExtremeContent : public Actor
	{
	public:
		typedef StaticMeshActorBasedOnExtremeContent__SMMaterialSetterDatum SMMaterialSetterDatum;
		ADD_STRUCT(ScriptArray<StaticMeshActorBasedOnExtremeContent__SMMaterialSetterDatum>, ExtremeContent, 480)
		ADD_STRUCT(ScriptArray<StaticMeshActorBasedOnExtremeContent__SMMaterialSetterDatum>, NonExtremeContent, 492)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27212);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMaterialBasedOnExtremeContent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(27213);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
