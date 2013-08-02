#pragma once
namespace UnrealScript
{
	class Scene;
}
#include "Core.Object.h"
#include "Engine.Scene.EDetailMode.h"
#include "Engine.Scene.ESceneDepthPriorityGroup.h"
namespace UnrealScript
{
	class Scene : public Object
	{
		typedef Scene__EDetailMode EDetailMode;
		typedef Scene__ESceneDepthPriorityGroup ESceneDepthPriorityGroup;
		static const auto SDPG_NumBits = 3;
	};
}
