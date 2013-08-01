#pragma once
#include "Core.Object.h"
#include "UTGame.UTCharInfo.CharacterInfo.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class UTCharInfo : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<UTCharInfo__CharacterInfo>, Characters, 60)
		ADD_STRUCT(ScriptArray<ScriptClass*>, Families, 72)
		ADD_STRUCT(float, LOD3DisplayFactor, 92)
		ADD_STRUCT(float, LOD2DisplayFactor, 88)
		ADD_STRUCT(float, LOD1DisplayFactor, 84)
		ScriptClass* FindFamilyInfo(ScriptString* InFamilyID)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(42761);
			byte params[16] = { NULL };
			*(ScriptString**)params = InFamilyID;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptClass**)&params[12];
		}
		ScriptString* GetRandomCharClassName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(43892);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
}
#undef ADD_STRUCT
