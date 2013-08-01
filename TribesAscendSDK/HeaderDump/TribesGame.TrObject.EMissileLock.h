#pragma once
namespace UnrealScript
{
	enum TrObject__EMissileLock : byte
	{
		EMissileLockNone = 0,
		EMissileLocking = 1,
		EMissileLocked = 2,
		EMissileFired = 3,
		EMissilePotentialTarget = 4,
		EMissileLock_MAX = 5,
	};
}
