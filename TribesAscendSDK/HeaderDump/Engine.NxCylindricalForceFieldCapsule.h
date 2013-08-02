#pragma once
namespace UnrealScript
{
	class NxCylindricalForceFieldCapsule;
}
#include "Engine.NxCylindricalForceField.h"
namespace UnrealScript
{
	class NxCylindricalForceFieldCapsule : public NxCylindricalForceField
	{
	public:
		void DoInitRBPhys()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(21147);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
