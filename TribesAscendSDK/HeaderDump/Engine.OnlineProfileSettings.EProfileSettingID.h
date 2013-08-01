#pragma once
namespace UnrealScript
{
	enum OnlineProfileSettings__EProfileSettingID : byte
	{
		PSI_Unknown = 0,
		PSI_ControllerVibration = 1,
		PSI_YInversion = 2,
		PSI_GamerCred = 3,
		PSI_GamerRep = 4,
		PSI_VoiceMuted = 5,
		PSI_VoiceThruSpeakers = 6,
		PSI_VoiceVolume = 7,
		PSI_GamerPictureKey = 8,
		PSI_GamerMotto = 9,
		PSI_GamerTitlesPlayed = 10,
		PSI_GamerAchievementsEarned = 11,
		PSI_GameDifficulty = 12,
		PSI_ControllerSensitivity = 13,
		PSI_PreferredColor1 = 14,
		PSI_PreferredColor2 = 15,
		PSI_AutoAim = 16,
		PSI_AutoCenter = 17,
		PSI_MovementControl = 18,
		PSI_RaceTransmission = 19,
		PSI_RaceCameraLocation = 20,
		PSI_RaceBrakeControl = 21,
		PSI_RaceAcceleratorControl = 22,
		PSI_GameCredEarned = 23,
		PSI_GameAchievementsEarned = 24,
		PSI_EndLiveIds = 25,
		PSI_ProfileVersionNum = 26,
		PSI_ProfileSaveCount = 27,
		PSI_MAX = 28,
	};
}
