#pragma once
#include "Engine.AnimationCompressionAlgorithm.h"
#include "Engine.AnimSequence.AnimNotifyEvent.h"
#include "Core.Object.h"
#include "Engine.AnimMetaData.h"
#include "Engine.AnimSequence.SkelControlModifier.h"
#include "Engine.AnimSequence.TranslationTrack.h"
#include "Engine.AnimSequence.RawAnimSequenceTrack.h"
#include "Engine.AnimSequence.CurveTrack.h"
#include "Engine.AnimSequence.RotationTrack.h"
#include "Engine.AnimSequence.AnimationCompressionFormat.h"
#include "Engine.AnimSequence.AnimationKeyFormat.h"
#include "Core.Object.Pointer.h"
#include "Core.Object.BoneAtom.h"
#include "Engine.AnimSequence.AnimTag.h"
#include "Engine.AnimNotify.h"
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
	class AnimSequence : public Object
	{
	public:
		ADD_STRUCT(float, SequenceLength, 104)
		ADD_STRUCT(float, RateScale, 112)
		ADD_STRUCT(ScriptName, SequenceName, 60)
		ADD_STRUCT(ScriptArray<AnimSequence__AnimNotifyEvent>, Notifies, 68)
		ADD_STRUCT(ScriptArray<class AnimMetaData*>, MetaData, 80)
		ADD_STRUCT(ScriptArray<AnimSequence__SkelControlModifier>, BoneControlModifiers, 92)
		ADD_STRUCT(int, NumFrames, 108)
		ADD_BOOL(bNoLoopingInterpolation, 116, 0x1)
		ADD_BOOL(bIsAdditive, 116, 0x2)
		ADD_BOOL(bAdditiveBuiltLooping, 116, 0x4)
		ADD_BOOL(bDoNotOverrideCompression, 116, 0x8)
		ADD_BOOL(bHasBeenUsed, 116, 0x10)
		ADD_STRUCT(ScriptArray<AnimSequence__RawAnimSequenceTrack>, RawAnimData, 120)
		ADD_STRUCT(ScriptArray<AnimSequence__RawAnimSequenceTrack>, RawAnimationData, 132)
		ADD_STRUCT(ScriptArray<AnimSequence__TranslationTrack>, TranslationData, 144)
		ADD_STRUCT(ScriptArray<AnimSequence__RotationTrack>, RotationData, 156)
		ADD_STRUCT(ScriptArray<AnimSequence__CurveTrack>, CurveData, 168)
		ADD_OBJECT(AnimationCompressionAlgorithm, CompressionScheme, 180)
		ADD_STRUCT(AnimSequence__AnimationCompressionFormat, TranslationCompressionFormat, 184)
		ADD_STRUCT(AnimSequence__AnimationCompressionFormat, RotationCompressionFormat, 185)
		ADD_STRUCT(AnimSequence__AnimationKeyFormat, KeyEncodingFormat, 186)
		ADD_STRUCT(ScriptArray<int>, CompressedTrackOffsets, 188)
		ADD_STRUCT(ScriptArray<byte>, CompressedByteStream, 200)
		ADD_STRUCT(Object__Pointer, TranslationCodec, 212)
		ADD_STRUCT(Object__Pointer, RotationCodec, 216)
		ADD_STRUCT(ScriptArray<Object__BoneAtom>, AdditiveRefPose, 220)
		ADD_STRUCT(ScriptArray<AnimSequence__RawAnimSequenceTrack>, AdditiveBasePose, 232)
		ADD_STRUCT(ScriptName, AdditiveRefName, 244)
		ADD_STRUCT(ScriptArray<class AnimSequence*>, AdditiveBasePoseAnimSeq, 252)
		ADD_STRUCT(ScriptArray<class AnimSequence*>, AdditiveTargetPoseAnimSeq, 264)
		ADD_STRUCT(ScriptArray<class AnimSequence*>, RelatedAdditiveAnimSeqs, 276)
		ADD_STRUCT(int, EncodingPkgVersion, 288)
		ADD_STRUCT(int, CompressCommandletVersion, 292)
		ADD_STRUCT(float, UseScore, 296)
		ADD_STRUCT(ScriptArray<AnimSequence__AnimTag>, AnimTags, 300)
		float GetNotifyTimeByClass(ScriptClass* NotifyClass, float PlayRate, float StartPosition, class AnimNotify*& out_Notify, float& out_Duration)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(10514);
			byte params[24] = { NULL };
			*(ScriptClass**)params = NotifyClass;
			*(float*)&params[4] = PlayRate;
			*(float*)&params[8] = StartPosition;
			*(class AnimNotify**)&params[12] = out_Notify;
			*(float*)&params[16] = out_Duration;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			out_Notify = *(class AnimNotify**)&params[12];
			out_Duration = *(float*)&params[16];
			return *(float*)&params[20];
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
