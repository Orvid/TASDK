#pragma once
namespace UnrealScript
{
	enum TrProj_TrackingMissile__ETrackingMissileStage : byte
	{
		ETrackingMissileStage_JustFired = 0,
		ETrackingMissileStage_AdjustingForGoodLOS = 1,
		ETrackingMissileStage_HomingInOnTarget = 2,
		ETrackingMissileStage_MAX = 3,
	};
}
