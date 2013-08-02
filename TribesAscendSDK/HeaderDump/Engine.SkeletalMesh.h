#pragma once
namespace UnrealScript
{
	class SkeletalMesh;
}
#include "Core.Object.h"
#include "Core.Object.BoneAtom.h"
#include "Core.Object.BoxSphereBounds.h"
#include "Core.Object.EAxis.h"
#include "Core.Object.IndirectArray_Mirror.h"
#include "Core.Object.Map_Mirror.h"
#include "Core.Object.Pointer.h"
#include "Engine.ApexClothingAsset.h"
#include "Engine.FaceFXAsset.h"
#include "Engine.MaterialInterface.h"
#include "Engine.MorphTargetSet.h"
#include "Engine.PhysicsAsset.h"
#include "Engine.SkeletalMesh.BoneBreakOption.h"
#include "Engine.SkeletalMesh.BoneMirrorExport.h"
#include "Engine.SkeletalMesh.BoneMirrorInfo.h"
#include "Engine.SkeletalMesh.ClothBoneType.h"
#include "Engine.SkeletalMesh.ClothMovementScaleGen.h"
#include "Engine.SkeletalMesh.ClothSpecialBoneInfo.h"
#include "Engine.SkeletalMesh.SkeletalMeshLODInfo.h"
#include "Engine.SkeletalMesh.SoftBodyBoneType.h"
#include "Engine.SkeletalMesh.SoftBodySpecialBoneInfo.h"
#include "Engine.SkeletalMesh.SoftBodyTetraLink.h"
#include "Engine.SkeletalMesh.TriangleSortAxis.h"
#include "Engine.SkeletalMesh.TriangleSortOption.h"
#include "Engine.SkeletalMesh.TriangleSortSettings.h"
#include "Engine.SkeletalMeshSocket.h"
#define ADD_BOOL(name, offset, mask) \
bool get_##name() { return (*(DWORD*)(this + offset) & mask) != 0; } \
void set_##name(bool val) \
{ \
	if (val) \
		*(DWORD*)(this + offset) |= mask; \
	else \
		*(DWORD*)(this + offset) &= ~mask; \
} \
__declspec(property(get=get_##name, put=set_##name)) bool name;
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
#define ADD_OBJECT(x, y, offset) \
class x* get_##y() { return *(class x**)(this + offset); } \
void set_##y(x* val) { *(class x**)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) class x* y;
namespace UnrealScript
{
	class SkeletalMesh : public Object
	{
	public:
		typedef SkeletalMesh__SoftBodyBoneType SoftBodyBoneType;
		typedef SkeletalMesh__ClothBoneType ClothBoneType;
		typedef SkeletalMesh__TriangleSortOption TriangleSortOption;
		typedef SkeletalMesh__BoneBreakOption BoneBreakOption;
		typedef SkeletalMesh__TriangleSortAxis TriangleSortAxis;
		typedef SkeletalMesh__ClothMovementScaleGen ClothMovementScaleGen;
		typedef SkeletalMesh__SoftBodyTetraLink SoftBodyTetraLink;
		typedef SkeletalMesh__SoftBodySpecialBoneInfo SoftBodySpecialBoneInfo;
		typedef SkeletalMesh__ClothSpecialBoneInfo ClothSpecialBoneInfo;
		typedef SkeletalMesh__SkeletalMeshLODInfo SkeletalMeshLODInfo;
		typedef SkeletalMesh__TriangleSortSettings TriangleSortSettings;
		typedef SkeletalMesh__BoneMirrorExport BoneMirrorExport;
		typedef SkeletalMesh__BoneMirrorInfo BoneMirrorInfo;
		ADD_OBJECT(FaceFXAsset, FaceFXAsset, 340)
		ADD_STRUCT(Object__BoxSphereBounds, Bounds, 60)
		ADD_STRUCT(ScriptArray<class MaterialInterface*>, Materials, 88)
		ADD_STRUCT(ScriptArray<class ApexClothingAsset*>, ClothingAssets, 100)
		ADD_STRUCT(Vector, Origin, 112)
		ADD_STRUCT(Rotator, RotOrigin, 124)
		ADD_STRUCT(ScriptArray<int>, RefSkeleton, 136)
		ADD_STRUCT(int, SkeletalDepth, 148)
		ADD_STRUCT(Object__IndirectArray_Mirror, LODModels, 212)
		ADD_STRUCT(ScriptArray<Object__BoneAtom>, RefBasesInvMatrix, 224)
		ADD_STRUCT(ScriptArray<SkeletalMesh__BoneMirrorInfo>, SkelMirrorTable, 236)
		ADD_STRUCT(Object__EAxis, SkelMirrorAxis, 248)
		ADD_STRUCT(Object__EAxis, SkelMirrorFlipAxis, 249)
		ADD_STRUCT(ScriptArray<class SkeletalMeshSocket*>, Sockets, 252)
		ADD_STRUCT(ScriptArray<ScriptString*>, BoneBreakNames, 264)
		ADD_STRUCT(ScriptArray<SkeletalMesh__BoneBreakOption>, BoneBreakOptions, 276)
		ADD_STRUCT(ScriptArray<SkeletalMesh__SkeletalMeshLODInfo>, LODInfo, 288)
		ADD_STRUCT(ScriptArray<ScriptName>, PerPolyCollisionBones, 300)
		ADD_STRUCT(ScriptArray<ScriptName>, AddToParentPerPolyCollisionBone, 312)
		ADD_STRUCT(ScriptArray<int>, PerPolyBoneKDOPs, 324)
		ADD_BOOL(bPerPolyUseSoftWeighting, 336, 0x1)
		ADD_BOOL(bUseSimpleLineCollision, 336, 0x2)
		ADD_BOOL(bUseSimpleBoxCollision, 336, 0x4)
		ADD_BOOL(bForceCPUSkinning, 336, 0x8)
		ADD_BOOL(bUseFullPrecisionUVs, 336, 0x10)
		ADD_BOOL(bUsePackedPosition, 336, 0x20)
		ADD_OBJECT(PhysicsAsset, BoundsPreviewAsset, 344)
		ADD_STRUCT(ScriptArray<class MorphTargetSet*>, PreviewMorphSets, 348)
		ADD_STRUCT(int, LODBiasPC, 360)
		ADD_STRUCT(int, LODBiasPS3, 364)
		ADD_STRUCT(int, LODBiasXbox360, 368)
		ADD_STRUCT(ScriptString*, SourceFilePath, 372)
		ADD_STRUCT(ScriptString*, SourceFileTimestamp, 384)
		ADD_STRUCT(ScriptArray<Object__Pointer>, ClothMesh, 396)
		ADD_STRUCT(ScriptArray<float>, ClothMeshScale, 408)
		ADD_STRUCT(ScriptArray<int>, ClothToGraphicsVertMap, 420)
		ADD_STRUCT(ScriptArray<float>, ClothMovementScale, 432)
		ADD_STRUCT(SkeletalMesh__ClothMovementScaleGen, ClothMovementScaleGenMode, 444)
		ADD_STRUCT(float, ClothToAnimMeshMaxDist, 448)
		ADD_BOOL(bLimitClothToAnimMesh, 452, 0x1)
		ADD_STRUCT(ScriptArray<int>, ClothWeldingMap, 456)
		ADD_STRUCT(int, ClothWeldingDomain, 468)
		ADD_STRUCT(ScriptArray<int>, ClothWeldedIndices, 472)
		ADD_BOOL(bForceNoWelding, 484, 0x1)
		ADD_STRUCT(int, NumFreeClothVerts, 488)
		ADD_STRUCT(ScriptArray<int>, ClothIndexBuffer, 492)
		ADD_STRUCT(ScriptArray<ScriptName>, ClothBones, 504)
		ADD_STRUCT(int, ClothHierarchyLevels, 516)
		ADD_BOOL(bEnableClothBendConstraints, 520, 0x1)
		ADD_BOOL(bEnableClothDamping, 520, 0x2)
		ADD_BOOL(bUseClothCOMDamping, 520, 0x4)
		ADD_STRUCT(float, ClothStretchStiffness, 524)
		ADD_STRUCT(float, ClothBendStiffness, 528)
		ADD_STRUCT(float, ClothDensity, 532)
		ADD_STRUCT(float, ClothThickness, 536)
		ADD_STRUCT(float, ClothDamping, 540)
		ADD_STRUCT(int, ClothIterations, 544)
		ADD_STRUCT(int, ClothHierarchicalIterations, 548)
		ADD_STRUCT(float, ClothFriction, 552)
		ADD_STRUCT(float, ClothRelativeGridSpacing, 556)
		ADD_STRUCT(float, ClothPressure, 560)
		ADD_STRUCT(float, ClothCollisionResponseCoefficient, 564)
		ADD_STRUCT(float, ClothAttachmentResponseCoefficient, 568)
		ADD_STRUCT(float, ClothAttachmentTearFactor, 572)
		ADD_STRUCT(float, ClothSleepLinearVelocity, 576)
		ADD_STRUCT(float, HardStretchLimitFactor, 580)
		ADD_BOOL(bHardStretchLimit, 584, 0x1)
		ADD_BOOL(bEnableClothOrthoBendConstraints, 584, 0x2)
		ADD_BOOL(bEnableClothSelfCollision, 584, 0x4)
		ADD_BOOL(bEnableClothPressure, 584, 0x8)
		ADD_BOOL(bEnableClothTwoWayCollision, 584, 0x10)
		ADD_STRUCT(ScriptArray<SkeletalMesh__ClothSpecialBoneInfo>, ClothSpecialBones, 588)
		ADD_BOOL(bEnableClothLineChecks, 600, 0x1)
		ADD_BOOL(bClothMetal, 600, 0x2)
		ADD_STRUCT(float, ClothMetalImpulseThreshold, 604)
		ADD_STRUCT(float, ClothMetalPenetrationDepth, 608)
		ADD_STRUCT(float, ClothMetalMaxDeformationDistance, 612)
		ADD_BOOL(bEnableClothTearing, 616, 0x1)
		ADD_STRUCT(float, ClothTearFactor, 620)
		ADD_STRUCT(int, ClothTearReserve, 624)
		ADD_BOOL(bEnableValidBounds, 628, 0x1)
		ADD_STRUCT(Vector, ValidBoundsMin, 632)
		ADD_STRUCT(Vector, ValidBoundsMax, 644)
		ADD_STRUCT(Object__Map_Mirror, ClothTornTriMap, 656)
		ADD_STRUCT(ScriptArray<int>, SoftBodySurfaceToGraphicsVertMap, 716)
		ADD_STRUCT(ScriptArray<int>, SoftBodySurfaceIndices, 728)
		ADD_STRUCT(ScriptArray<Vector>, SoftBodyTetraVertsUnscaled, 740)
		ADD_STRUCT(ScriptArray<int>, SoftBodyTetraIndices, 752)
		ADD_STRUCT(ScriptArray<SkeletalMesh__SoftBodyTetraLink>, SoftBodyTetraLinks, 764)
		ADD_STRUCT(ScriptArray<Object__Pointer>, CachedSoftBodyMeshes, 776)
		ADD_STRUCT(ScriptArray<float>, CachedSoftBodyMeshScales, 788)
		ADD_STRUCT(ScriptArray<ScriptName>, SoftBodyBones, 800)
		ADD_STRUCT(ScriptArray<SkeletalMesh__SoftBodySpecialBoneInfo>, SoftBodySpecialBones, 812)
		ADD_STRUCT(float, SoftBodyVolumeStiffness, 824)
		ADD_STRUCT(float, SoftBodyStretchingStiffness, 828)
		ADD_STRUCT(float, SoftBodyDensity, 832)
		ADD_STRUCT(float, SoftBodyParticleRadius, 836)
		ADD_STRUCT(float, SoftBodyDamping, 840)
		ADD_STRUCT(int, SoftBodySolverIterations, 844)
		ADD_STRUCT(float, SoftBodyFriction, 848)
		ADD_STRUCT(float, SoftBodyRelativeGridSpacing, 852)
		ADD_STRUCT(float, SoftBodySleepLinearVelocity, 856)
		ADD_BOOL(bEnableSoftBodySelfCollision, 860, 0x1)
		ADD_STRUCT(float, SoftBodyAttachmentResponse, 864)
		ADD_STRUCT(float, SoftBodyCollisionResponse, 868)
		ADD_STRUCT(float, SoftBodyDetailLevel, 872)
		ADD_STRUCT(int, SoftBodySubdivisionLevel, 876)
		ADD_BOOL(bSoftBodyIsoSurface, 880, 0x1)
		ADD_BOOL(bEnableSoftBodyDamping, 880, 0x2)
		ADD_BOOL(bUseSoftBodyCOMDamping, 880, 0x4)
		ADD_STRUCT(float, SoftBodyAttachmentThreshold, 884)
		ADD_BOOL(bEnableSoftBodyTwoWayCollision, 888, 0x1)
		ADD_STRUCT(float, SoftBodyAttachmentTearFactor, 892)
		ADD_BOOL(bEnableSoftBodyLineChecks, 896, 0x1)
		ADD_BOOL(bHasVertexColors, 896, 0x2)
		ADD_STRUCT(ScriptArray<bool>, GraphicsIndexIsCloth, 900)
		ADD_STRUCT(ScriptArray<float>, CachedStreamingTextureFactors, 912)
		ADD_STRUCT(float, StreamingDistanceMultiplier, 924)
		ADD_STRUCT(int, ReleaseResourcesFence, 928)
		ADD_STRUCT(QWord, SkelMeshRUID, 932)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
