#pragma once
#include "Engine.BroadcastHandler.h"
#include "Engine.PlayerReplicationInfo.h"
#include "TribesGame.TrSpottedTarget.h"
#include "TribesGame.TrVGSCommandList.VGSCommandType.h"
#include "Engine.Actor.h"
#include "TribesGame.TrVGSCommandList.EVGSContextActor.h"
#include "TribesGame.TrVGSCommandList.EVGSContextLocation.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrBroadcastHandler : public BroadcastHandler
	{
	public:
		ADD_STRUCT(ScriptArray<class TrSpottedTarget*>, m_SpottedTargets, 484)
		ADD_STRUCT(float, m_fSpottedActorsUpdateFrequency, 496)
		void TeamBroadcastVGSCommand(class PlayerReplicationInfo* SenderPRI, TrVGSCommandList__VGSCommandType VGSCommandIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73676);
			byte params[5] = { NULL };
			*(class PlayerReplicationInfo**)params = SenderPRI;
			*(TrVGSCommandList__VGSCommandType*)&params[4] = VGSCommandIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void GlobalBroadcastVGSCommand(class PlayerReplicationInfo* SenderPRI, TrVGSCommandList__VGSCommandType VGSCommandIndex)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73680);
			byte params[5] = { NULL };
			*(class PlayerReplicationInfo**)params = SenderPRI;
			*(TrVGSCommandList__VGSCommandType*)&params[4] = VGSCommandIndex;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void TeamBroadcastVGSContextCommand(class PlayerReplicationInfo* SenderPRI, TrVGSCommandList__EVGSContextActor ContextActor, TrVGSCommandList__EVGSContextLocation ContextLocation, bool bEnemyLocation)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73684);
			byte params[10] = { NULL };
			*(class PlayerReplicationInfo**)params = SenderPRI;
			*(TrVGSCommandList__EVGSContextActor*)&params[4] = ContextActor;
			*(TrVGSCommandList__EVGSContextLocation*)&params[5] = ContextLocation;
			*(bool*)&params[8] = bEnemyLocation;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OnActorSpotted(class Actor* SpottedActor, ScriptClass* SpottedTargetClass)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73690);
			byte params[8] = { NULL };
			*(class Actor**)params = SpottedActor;
			*(ScriptClass**)&params[4] = SpottedTargetClass;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateSpottedActorsTimer()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(73698);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_STRUCT
