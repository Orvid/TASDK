#pragma once
#include "Core.Object.Vector.h"
#include "TribesGame.TrDevice.h"
#include "Engine.Actor.ImpactInfo.h"
namespace UnrealScript
{
	class TrSubDevice : public TrDevice
	{
	public:
		void Reset()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112994);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		Actor__ImpactInfo CalcWeaponFire(Vector StartTrace, Vector EndTrace, ScriptArray<Actor__ImpactInfo>& ImpactList, Vector Extent)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(112995);
			byte params[128] = { NULL };
			*(Vector*)params = StartTrace;
			*(Vector*)&params[12] = EndTrace;
			*(ScriptArray<Actor__ImpactInfo>*)&params[24] = ImpactList;
			*(Vector*)&params[36] = Extent;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			ImpactList = *(ScriptArray<Actor__ImpactInfo>*)&params[24];
			return *(Actor__ImpactInfo*)&params[48];
		}
	};
}
