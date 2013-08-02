#pragma once
namespace UnrealScript
{
	class EngineTypes;
}
#include "Core.Object.h"
#include "Engine.EngineTypes.DominantShadowInfo.h"
#include "Engine.EngineTypes.EBlendMode.h"
#include "Engine.EngineTypes.ELightingBuildQuality.h"
#include "Engine.EngineTypes.EMaterialLightingModel.h"
#include "Engine.EngineTypes.EMaterialTessellationMode.h"
#include "Engine.EngineTypes.EMobileAmbientOcclusionSource.h"
#include "Engine.EngineTypes.EMobileEmissiveColorSource.h"
#include "Engine.EngineTypes.EMobileEnvironmentBlendMode.h"
#include "Engine.EngineTypes.EMobileSpecularMask.h"
#include "Engine.EngineTypes.EMobileTexCoordsSource.h"
#include "Engine.EngineTypes.EMobileTextureBlendFactorSource.h"
#include "Engine.EngineTypes.EMobileTextureTransformTarget.h"
#include "Engine.EngineTypes.EMobileValueSource.h"
#include "Engine.EngineTypes.EPathFindingError.h"
#include "Engine.EngineTypes.LightMapRef.h"
#include "Engine.EngineTypes.LightmassDebugOptions.h"
#include "Engine.EngineTypes.LightmassDirectionalLightSettings.h"
#include "Engine.EngineTypes.LightmassLightSettings.h"
#include "Engine.EngineTypes.LightmassPointLightSettings.h"
#include "Engine.EngineTypes.LightmassPrimitiveSettings.h"
#include "Engine.EngineTypes.LocalizedSubtitle.h"
#include "Engine.EngineTypes.MaterialReferenceList.h"
#include "Engine.EngineTypes.PrimitiveMaterialRef.h"
#include "Engine.EngineTypes.RootMotionCurve.h"
#include "Engine.EngineTypes.SubtitleCue.h"
#include "Engine.EngineTypes.SwarmDebugOptions.h"
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
	class EngineTypes : public Object
	{
	public:
		typedef EngineTypes__EPathFindingError EPathFindingError;
		typedef EngineTypes__EBlendMode EBlendMode;
		typedef EngineTypes__EMaterialLightingModel EMaterialLightingModel;
		typedef EngineTypes__EMaterialTessellationMode EMaterialTessellationMode;
		typedef EngineTypes__EMobileTextureTransformTarget EMobileTextureTransformTarget;
		typedef EngineTypes__EMobileValueSource EMobileValueSource;
		typedef EngineTypes__EMobileTextureBlendFactorSource EMobileTextureBlendFactorSource;
		typedef EngineTypes__EMobileTexCoordsSource EMobileTexCoordsSource;
		typedef EngineTypes__EMobileEmissiveColorSource EMobileEmissiveColorSource;
		typedef EngineTypes__EMobileEnvironmentBlendMode EMobileEnvironmentBlendMode;
		typedef EngineTypes__EMobileSpecularMask EMobileSpecularMask;
		typedef EngineTypes__EMobileAmbientOcclusionSource EMobileAmbientOcclusionSource;
		typedef EngineTypes__ELightingBuildQuality ELightingBuildQuality;
		typedef EngineTypes__SubtitleCue SubtitleCue;
		typedef EngineTypes__LocalizedSubtitle LocalizedSubtitle;
		typedef EngineTypes__LightMapRef LightMapRef;
		typedef EngineTypes__DominantShadowInfo DominantShadowInfo;
		typedef EngineTypes__LightmassLightSettings LightmassLightSettings;
		typedef EngineTypes__LightmassPointLightSettings LightmassPointLightSettings;
		typedef EngineTypes__LightmassDirectionalLightSettings LightmassDirectionalLightSettings;
		typedef EngineTypes__LightmassPrimitiveSettings LightmassPrimitiveSettings;
		typedef EngineTypes__LightmassDebugOptions LightmassDebugOptions;
		typedef EngineTypes__SwarmDebugOptions SwarmDebugOptions;
		typedef EngineTypes__RootMotionCurve RootMotionCurve;
		typedef EngineTypes__PrimitiveMaterialRef PrimitiveMaterialRef;
		typedef EngineTypes__MaterialReferenceList MaterialReferenceList;
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
