#pragma once
#include "Core.Object.Pointer.h"
#include "Engine.PrimitiveComponent.h"
#include "Engine.EngineTypes.LightMapRef.h"
#include "Core.Object.Vector.h"
#include "Engine.Actor.h"
#include "Engine.MaterialInterface.h"
#include "Engine.EngineTypes.LightmassPrimitiveSettings.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.FluidSurfaceComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.FluidSurfaceComponent." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.FluidSurfaceComponent." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class FluidSurfaceComponent : public PrimitiveComponent
	{
	public:
		ADD_VAR(::FloatProperty, ForceImpact, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, FluidSimulation, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<LightMapRef>, LightMap, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, EditorViewPosition, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, DetailPosition, 0xFFFFFFFF)
		ADD_STRUCT(::VectorProperty, SimulationPosition, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ViewDistance, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeactivationTimer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TestRippleAngle, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TestRippleTime, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FluidHeight, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FluidWidth, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TestRippleRadius, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TestRippleFrequency, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, TestRippleSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, NormalLength, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DetailUpdateRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DetailHeightScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DetailTransfer, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DetailTravelSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DetailDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DetailSize, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, DetailResolution, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, DeactivationDistance, 0xFFFFFFFF)
		ADD_OBJECT(Actor, TargetDetail)
		ADD_VAR(::FloatProperty, LightingContrast, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, ForceContinuous, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FluidUpdateRate, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FluidHeightScale, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FluidTravelSpeed, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, FluidDamping, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GPUTessellationFactor, 0xFFFFFFFF)
		ADD_OBJECT(Actor, TargetSimulation)
		ADD_VAR(::FloatProperty, GridSpacingLowRes, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, GridSpacing, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SimulationQuadsY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, SimulationQuadsX, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bTestRippleCenterOnDetail, 0x400)
		ADD_VAR(::BoolProperty, bTestRipple, 0x200)
		ADD_VAR(::BoolProperty, bShowFluidDetail, 0x100)
		ADD_VAR(::BoolProperty, bShowFluidSimulation, 0x80)
		ADD_VAR(::BoolProperty, bShowDetailPosition, 0x40)
		ADD_VAR(::BoolProperty, bShowDetailNormals, 0x20)
		ADD_VAR(::BoolProperty, bShowSimulationPosition, 0x10)
		ADD_VAR(::BoolProperty, bShowSimulationNormals, 0x8)
		ADD_VAR(::BoolProperty, bPause, 0x4)
		ADD_VAR(::BoolProperty, EnableDetail, 0x2)
		ADD_VAR(::BoolProperty, EnableSimulation, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<LightmassPrimitiveSettings>, LightmassSettings, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, LightMapResolution, 0xFFFFFFFF)
		ADD_OBJECT(MaterialInterface, FluidMaterial)
		void ApplyForce(Vector WorldPos, float Strength, float Radius, bool bImpulse)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FluidSurfaceComponent.ApplyForce");
			byte* params = (byte*)malloc(24);
			*(Vector*)params = WorldPos;
			*(float*)(params + 12) = Strength;
			*(float*)(params + 16) = Radius;
			*(bool*)(params + 20) = bImpulse;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetDetailPosition(Vector WorldPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FluidSurfaceComponent.SetDetailPosition");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = WorldPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
		void SetSimulationPosition(Vector WorldPos)
		{
			static ScriptFunction* function = ScriptObject::Find<ScriptFunction>("Function Engine.FluidSurfaceComponent.SetSimulationPosition");
			byte* params = (byte*)malloc(12);
			*(Vector*)params = WorldPos;
			((ScriptObject*)this)->ProcessEvent(function, params, NULL);
			free(params);
		}
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
