#pragma once
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct OnlinePlaylistManager__PlaylistPopulation
	{
	public:
		ADD_STRUCT(int, RegionTotal, 8)
		ADD_STRUCT(int, WorldwideTotal, 4)
		ADD_STRUCT(int, PlaylistId, 0)
	};
}
#undef ADD_STRUCT
