#pragma once
namespace UnrealScript
{
	enum OnlineSubsystem__EOnlineAccountCreateStatus : byte
	{
		OACS_CreateSuccessful = 0,
		OACS_UnknownError = 1,
		OACS_InvalidUserName = 2,
		OACS_InvalidPassword = 3,
		OACS_InvalidUniqueUserName = 4,
		OACS_UniqueUserNameInUse = 5,
		OACS_ServiceUnavailable = 6,
		OACS_MAX = 7,
	};
}
