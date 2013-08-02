#pragma once
namespace UnrealScript
{
	class SkeletalMeshActorBasedOnExtremeContent;
}
#include "Engine.SkeletalMeshActor.h"
#include "Engine.SkeletalMeshActorBasedOnExtremeContent.SkelMaterialSetterDatum.h"
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
	class SkeletalMeshActorBasedOnExtremeContent : public SkeletalMeshActor
	{
	public:
		typedef SkeletalMeshActorBasedOnExtremeContent__SkelMaterialSetterDatum SkelMaterialSetterDatum;
		ADD_STRUCT(ScriptArray<SkeletalMeshActorBasedOnExtremeContent__SkelMaterialSetterDatum>, ExtremeContent, 536)
		ADD_STRUCT(ScriptArray<SkeletalMeshActorBasedOnExtremeContent__SkelMaterialSetterDatum>, NonExtremeContent, 548)
		void PostBeginPlay()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26749);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetMaterialBasedOnExtremeContent()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(26750);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
