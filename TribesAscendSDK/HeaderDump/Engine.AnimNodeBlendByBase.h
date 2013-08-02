#pragma once
namespace UnrealScript
{
	class AnimNodeBlendByBase;
}
#include "Engine.Actor.h"
#include "Engine.AnimNodeBlendByBase.EBaseBlendType.h"
#include "Engine.AnimNodeBlendList.h"
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
	class AnimNodeBlendByBase : public AnimNodeBlendList
	{
	public:
		typedef AnimNodeBlendByBase__EBaseBlendType EBaseBlendType;
		ADD_OBJECT(Actor, CachedBase, 296)
		ADD_STRUCT(float, BlendTime, 292)
		ADD_OBJECT(ScriptClass, ActorClass, 288)
		ADD_STRUCT(ScriptName, ActorTag, 280)
		ADD_STRUCT(AnimNodeBlendByBase__EBaseBlendType, Type, 276)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
