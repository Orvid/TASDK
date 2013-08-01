#pragma once
namespace UnrealScript
{
	enum TrSeekingMissileManager__ETrackingMissileEvent : byte
	{
		MissileEvent_NewMissileTracking = 0,
		MissileEvent_MissileStoppedTracking = 1,
		MissileEvent_NewSaberLauncherTargeting = 2,
		MissileEvent_SaberLauncherStoppedTargeting = 3,
		MissileEvent_NotifyClientAboutSaberLauncher = 4,
		MissileEvent_MAX = 5,
	};
}
