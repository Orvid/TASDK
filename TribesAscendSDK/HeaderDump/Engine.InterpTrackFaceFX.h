#pragma once
#include "Engine.InterpTrack.h"
#include "Engine.FaceFXAnimSet.h"
#include "Engine.InterpTrackFaceFX.FaceFXTrackKey.h"
#include "Engine.InterpTrackFaceFX.FaceFXSoundCueKey.h"
#include "Engine.FaceFXAsset.h"
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
	class InterpTrackFaceFX : public InterpTrack
	{
	public:
		ADD_STRUCT(ScriptArray<class FaceFXAnimSet*>, FaceFXAnimSets, 128)
		ADD_STRUCT(ScriptArray<InterpTrackFaceFX__FaceFXTrackKey>, FaceFXSeqs, 140)
		ADD_STRUCT(ScriptArray<InterpTrackFaceFX__FaceFXSoundCueKey>, FaceFXSoundCueKeys, 156)
		ADD_OBJECT(FaceFXAsset, CachedActorFXAsset, 152)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
