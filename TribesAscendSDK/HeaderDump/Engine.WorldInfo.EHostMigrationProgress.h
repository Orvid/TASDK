#pragma once
namespace UnrealScript
{
	enum WorldInfo__EHostMigrationProgress : byte
	{
		HostMigration_None = 0,
		HostMigration_FindingNewHost = 1,
		HostMigration_MigratingAsHost = 2,
		HostMigration_MigratingAsClient = 3,
		HostMigration_HostReadyToTravel = 4,
		HostMigration_MAX = 5,
	};
}
