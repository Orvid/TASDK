#pragma once
namespace UnrealScript
{
	class UDKAnimNodeCopyBoneTranslation;
}
#include "Engine.AnimNodeAimOffset.h"
#include "Engine.AnimNodeBlendBase.h"
#include "UDKBase.UDKAnimBlendByWeapType.h"
#include "UDKBase.UDKAnimNodeCopyBoneTranslation.BoneCopyInfo.h"
#include "UDKBase.UDKAnimNodeSeqWeap.h"
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
	class UDKAnimNodeCopyBoneTranslation : public AnimNodeBlendBase
	{
	public:
		typedef UDKAnimNodeCopyBoneTranslation__BoneCopyInfo BoneCopyInfo;
		ADD_STRUCT(ScriptArray<UDKAnimNodeCopyBoneTranslation__BoneCopyInfo>, DefaultBoneCopyArray, 256)
		ADD_STRUCT(ScriptArray<UDKAnimNodeCopyBoneTranslation__BoneCopyInfo>, DualWieldBoneCopyArray, 268)
		ADD_STRUCT(ScriptArray<UDKAnimNodeCopyBoneTranslation__BoneCopyInfo>, ActiveBoneCopyArray, 280)
		ADD_STRUCT(ScriptArray<byte>, RequiredBones, 292)
		ADD_STRUCT(ScriptArray<class UDKAnimNodeSeqWeap*>, SeqWeaps, 304)
		ADD_STRUCT(ScriptArray<class UDKAnimBlendByWeapType*>, WeapTypeBlends, 316)
		ADD_STRUCT(ScriptName, OldAimProfileName, 248)
		ADD_OBJECT(AnimNodeAimOffset, CachedAimNode, 244)
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
