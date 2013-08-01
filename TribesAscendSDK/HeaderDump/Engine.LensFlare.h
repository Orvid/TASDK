#pragma once
#include "Engine.LensFlare.LensFlareElement.h"
#include "Core.Object.h"
#include "Engine.Texture2D.h"
#include "Engine.InterpCurveEdSetup.h"
#include "Core.Object.Rotator.h"
#include "Core.Object.Box.h"
#include "Core.DistributionFloat.RawDistributionFloat.h"
#include "Engine.Scene.ESceneDepthPriorityGroup.h"
#include "Engine.StaticMesh.h"
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
	class LensFlare : public Object
	{
	public:
		ADD_STRUCT(ScriptArray<LensFlare__LensFlareElement>, Reflections, 392)
		ADD_OBJECT(Texture2D, ThumbnailImage, 504)
		ADD_STRUCT(float, ThumbnailDistance, 500)
		ADD_STRUCT(Rotator, ThumbnailAngle, 488)
		ADD_STRUCT(int, ReflectionCount, 484)
		ADD_OBJECT(InterpCurveEdSetup, CurveEdSetup, 480)
		ADD_STRUCT(Object__Box, FixedRelativeBoundingBox, 452)
		ADD_BOOL(ThumbnailImageOutOfDate, 448, 0x4)
		ADD_BOOL(bRenderDebugLines, 448, 0x2)
		ADD_BOOL(bUseFixedRelativeBoundingBox, 448, 0x1)
		ADD_STRUCT(DistributionFloat__RawDistributionFloat, ScreenPercentageMap, 420)
		ADD_STRUCT(float, Radius, 416)
		ADD_STRUCT(float, ConeFudgeFactor, 412)
		ADD_STRUCT(float, InnerCone, 408)
		ADD_STRUCT(float, OuterCone, 404)
		ADD_STRUCT(Scene__ESceneDepthPriorityGroup, ReflectionsDPG, 389)
		ADD_STRUCT(Scene__ESceneDepthPriorityGroup, SourceDPG, 388)
		ADD_OBJECT(StaticMesh, SourceMesh, 384)
		ADD_STRUCT(LensFlare__LensFlareElement, SourceElement, 60)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
