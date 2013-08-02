#pragma once
namespace UnrealScript
{
	class ParticleModuleBeamBase;
}
#include "Engine.ParticleModule.h"
#include "Engine.ParticleModuleBeamBase.Beam2SourceTargetMethod.h"
#include "Engine.ParticleModuleBeamBase.Beam2SourceTargetTangentMethod.h"
namespace UnrealScript
{
	class ParticleModuleBeamBase : public ParticleModule
	{
		typedef ParticleModuleBeamBase__Beam2SourceTargetMethod Beam2SourceTargetMethod;
		typedef ParticleModuleBeamBase__Beam2SourceTargetTangentMethod Beam2SourceTargetTangentMethod;
	};
}
