#pragma once
namespace UnrealScript
{
	class RenderTargetCubeExporterTGA;
}
#include "Core.Exporter.h"
#include "UnrealEd.RenderTargetCubeExporterTGA.CubeFace.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class RenderTargetCubeExporterTGA : public Exporter
	{
	public:
		typedef RenderTargetCubeExporterTGA__CubeFace CubeFace;
		ADD_STRUCT(RenderTargetCubeExporterTGA__CubeFace, CubeFace, 100)
	};
}
#undef ADD_STRUCT
