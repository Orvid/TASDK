#pragma once
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
namespace UnrealScript
{
	struct EngineTypes__LightmassDebugOptions
	{
	public:
		ADD_BOOL(bInitialized, 16, 0x1)
		ADD_STRUCT(float, ExecutionTimeDivisor, 12)
		ADD_BOOL(bColorByExecutionTime, 8, 0x800)
		ADD_BOOL(bColorBordersGreen, 8, 0x400)
		ADD_BOOL(bUseRandomColors, 8, 0x200)
		ADD_BOOL(bOnlyCalcDebugTexelMappings, 8, 0x100)
		ADD_BOOL(bDebugPaddings, 8, 0x80)
		ADD_BOOL(bPadMappings, 8, 0x40)
		ADD_BOOL(bDebugMaterials, 8, 0x20)
		ADD_BOOL(bDumpBinaryFiles, 8, 0x10)
		ADD_BOOL(bSortMappings, 8, 0x8)
		ADD_BOOL(bImmediateProcessMappings, 8, 0x4)
		ADD_BOOL(bUseImmediateImport, 8, 0x2)
		ADD_BOOL(bUseDeterministicLighting, 8, 0x1)
		ADD_STRUCT(float, CoplanarTolerance, 4)
		ADD_BOOL(bGatherBSPSurfacesAcrossComponents, 0, 0x4)
		ADD_BOOL(bStatsEnabled, 0, 0x2)
		ADD_BOOL(bDebugMode, 0, 0x1)
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
