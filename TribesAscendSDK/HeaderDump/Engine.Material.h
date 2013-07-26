#pragma once
#include "Engine.MaterialInterface.h"
#include "Engine.Texture2D.h"
#include "Core.Object.Pointer.h"
#include "Engine.Material.ColorMaterialInput.h"
#include "Engine.Material.ScalarMaterialInput.h"
#include "Engine.Material.Vector2MaterialInput.h"
#include "Engine.Material.VectorMaterialInput.h"
#include "Engine.PhysicalMaterial.h"
#define ADD_VAR(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>(#x " Engine.Material." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_STRUCT(x, y, z) (x) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("StructProperty Engine.Material." #y); \
	return (##x(this, script_property->offset, z)); \
} \
__declspec(property(get=get_##y)) x y;
#define ADD_OBJECT(x, y) (class x*) get_##y() \
{ \
	static ScriptProperty* script_property = ScriptObject::Find<ScriptProperty>("ObjectProperty Engine.Material." #y); \
	return *(x**)(this + script_property->offset); \
} \
__declspec(property(get=get_##y)) class x* y;
namespace UnrealScript
{
	class Material : public MaterialInterface
	{
	public:
		ADD_VAR(::IntProperty, EditorYaw, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EditorPitch, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EditorY, 0xFFFFFFFF)
		ADD_VAR(::IntProperty, EditorX, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, DefaultMaterialInstances, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Pointer>, MaterialResources, 0xFFFFFFFF)
		ADD_VAR(::BoolProperty, bIsPreviewMaterial, 0x1000)
		ADD_VAR(::BoolProperty, bIsMasked, 0x800)
		ADD_VAR(::BoolProperty, bUsesDistortion, 0x400)
		ADD_VAR(::BoolProperty, bIsFallbackMaterial, 0x200)
		ADD_VAR(::BoolProperty, bAllowLightmapSpecular, 0x100)
		ADD_VAR(::BoolProperty, bPerPixelCameraVector, 0x80)
		ADD_VAR(::BoolProperty, Wireframe, 0x40)
		ADD_VAR(::BoolProperty, bUseImageBasedReflections, 0x20)
		ADD_VAR(::BoolProperty, bUsedWithScreenDoorFade, 0x10)
		ADD_VAR(::BoolProperty, bUsedWithAPEXMeshes, 0x8)
		ADD_VAR(::BoolProperty, bUsedWithSplineMeshes, 0x4)
		ADD_VAR(::BoolProperty, bUsedWithInstancedMeshes, 0x2)
		ADD_VAR(::BoolProperty, bUsedWithRadialBlur, 0x1)
		ADD_VAR(::BoolProperty, bUsedWithMorphTargets, 0x80000000)
		ADD_VAR(::BoolProperty, bUsedWithMaterialEffect, 0x40000000)
		ADD_VAR(::BoolProperty, bUsedWithDecals, 0x20000000)
		ADD_VAR(::BoolProperty, bUsedWithFluidSurfaces, 0x10000000)
		ADD_VAR(::BoolProperty, bUsedWithInstancedMeshParticles, 0x8000000)
		ADD_VAR(::BoolProperty, bUsedWithGammaCorrection, 0x4000000)
		ADD_VAR(::BoolProperty, bUsedWithLensFlare, 0x2000000)
		ADD_VAR(::BoolProperty, bUsedWithStaticLighting, 0x1000000)
		ADD_VAR(::BoolProperty, bUsedWithSpeedTree, 0x800000)
		ADD_VAR(::BoolProperty, bUsedWithParticleSubUV, 0x400000)
		ADD_VAR(::BoolProperty, bUsedWithBeamTrails, 0x200000)
		ADD_VAR(::BoolProperty, bUsedWithParticleSprites, 0x100000)
		ADD_VAR(::BoolProperty, bUsedWithParticleSystem, 0x80000)
		ADD_VAR(::BoolProperty, bUsedWithFracturedMeshes, 0x40000)
		ADD_VAR(::BoolProperty, bUsedWithLandscape, 0x20000)
		ADD_VAR(::BoolProperty, bUsedWithTerrain, 0x10000)
		ADD_VAR(::BoolProperty, bUsedWithSkeletalMesh, 0x8000)
		ADD_VAR(::BoolProperty, bUsedAsSpecialEngineMaterial, 0x4000)
		ADD_VAR(::BoolProperty, bUsedWithFogVolumes, 0x2000)
		ADD_VAR(::BoolProperty, bUsedAsLightFunction, 0x1000)
		ADD_VAR(::BoolProperty, bCastLitTranslucencyShadowAsMasked, 0x800)
		ADD_VAR(::BoolProperty, bUseLitTranslucencyPostRenderDepthPass, 0x400)
		ADD_VAR(::BoolProperty, bUseLitTranslucencyDepthPass, 0x200)
		ADD_VAR(::BoolProperty, bUseOneLayerDistortion, 0x100)
		ADD_VAR(::BoolProperty, bAllowTranslucencyDoF, 0x80)
		ADD_VAR(::BoolProperty, bTranslucencyInheritDominantShadowsFromOpaque, 0x40)
		ADD_VAR(::BoolProperty, bTranslucencyReceiveDominantShadowsFromStatic, 0x20)
		ADD_VAR(::BoolProperty, bAllowFog, 0x10)
		ADD_VAR(::BoolProperty, bDisableDepthTest, 0x8)
		ADD_VAR(::BoolProperty, TwoSidedSeparatePass, 0x4)
		ADD_VAR(::BoolProperty, TwoSided, 0x2)
		ADD_VAR(::BoolProperty, EnableSubsurfaceScattering, 0x1)
		ADD_STRUCT(::NonArithmeticProperty<ScalarMaterialInput>, SubsurfaceScatteringRadius, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ColorMaterialInput>, SubsurfaceAbsorptionColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ColorMaterialInput>, SubsurfaceInscatteringColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2MaterialInput>, TessellationFactors, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<VectorMaterialInput>, WorldDisplacement, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<VectorMaterialInput>, WorldPositionOffset, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ColorMaterialInput>, TwoSidedLightingColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ScalarMaterialInput>, TwoSidedLightingMask, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<VectorMaterialInput>, AnisotropicDirection, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ColorMaterialInput>, CustomSkylightDiffuse, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ColorMaterialInput>, CustomLighting, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, D3D11TessellationMode, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, LightingModel, 0xFFFFFFFF)
		ADD_VAR(::ByteProperty, BlendMode, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<Vector2MaterialInput>, Distortion, 0xFFFFFFFF)
		ADD_VAR(::FloatProperty, OpacityMaskClipValue, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ScalarMaterialInput>, OpacityMask, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ScalarMaterialInput>, Opacity, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ColorMaterialInput>, EmissiveColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<VectorMaterialInput>, Normal, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ScalarMaterialInput>, SpecularPower, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ColorMaterialInput>, SpecularColor, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ScalarMaterialInput>, DiffusePower, 0xFFFFFFFF)
		ADD_STRUCT(::NonArithmeticProperty<ColorMaterialInput>, DiffuseColor, 0xFFFFFFFF)
		ADD_OBJECT(PhysicalMaterial, WhitePhysicalMaterial)
		ADD_OBJECT(PhysicalMaterial, BlackPhysicalMaterial)
		ADD_VAR(::IntProperty, PhysMaterialMaskUVChannel, 0xFFFFFFFF)
		ADD_OBJECT(Texture2D, PhysMaterialMask)
		ADD_OBJECT(ScriptClass, PhysicalMaterial)
		ADD_OBJECT(PhysicalMaterial, PhysMaterial)
	};
}
#undef ADD_VAR
#undef ADD_STRUCT
#undef ADD_OBJECT
