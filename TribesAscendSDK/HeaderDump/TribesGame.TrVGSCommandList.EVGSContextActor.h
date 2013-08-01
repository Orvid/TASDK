#pragma once
namespace UnrealScript
{
	enum TrVGSCommandList__EVGSContextActor : byte
	{
		VGSContextActors_None = 0,
		VGSContextActors_ActorLightPawn = 1,
		VGSContextActors_ActorMediumPawn = 2,
		VGSContextActors_ActorHeavyPawn = 3,
		VGSContextActors_ActorTurret = 4,
		VGSContextActors_ActorSensor = 5,
		VGSContextActors_ActorVehicle = 6,
		VGSContextActors_ActorDeployable = 7,
		VGSContextActors_MAX = 8,
	};
}
