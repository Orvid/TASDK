#pragma once
namespace UnrealScript
{
	class ActorFactoryArchetype;
}
#include "Engine.Actor.h"
#include "Engine.ActorFactory.h"
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class ActorFactoryArchetype : public ActorFactory
	{
	public:
		ADD_OBJECT(Actor, ArchetypeActor, 92)
	};
}
#undef ADD_OBJECT
