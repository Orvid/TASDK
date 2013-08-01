#pragma once
namespace UnrealScript
{
	enum SceneCaptureComponent__ESceneCaptureViewMode : byte
	{
		SceneCapView_Lit = 0,
		SceneCapView_Unlit = 1,
		SceneCapView_LitNoShadows = 2,
		SceneCapView_Wire = 3,
		SceneCapView_MAX = 4,
	};
}
