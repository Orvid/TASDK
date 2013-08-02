#pragma once
namespace UnrealScript
{
	class TrObject;
}
#include "Core.Object.h"
#include "TribesGame.TrObject.CaHCapturePointLabel.h"
#include "TribesGame.TrObject.DAMAGE_INFO_TYPE.h"
#include "TribesGame.TrObject.DeployModeStatus.h"
#include "TribesGame.TrObject.DeviceAttackType.h"
#include "TribesGame.TrObject.DeviceTargeterType.h"
#include "TribesGame.TrObject.EArmorType.h"
#include "TribesGame.TrObject.EContentDataType.h"
#include "TribesGame.TrObject.EMissileLock.h"
#include "TribesGame.TrObject.ESettingsList.h"
#include "TribesGame.TrObject.ETrPlayerCallIns.h"
#include "TribesGame.TrObject.EVehicleTypes.h"
#include "TribesGame.TrObject.EWeaponTracerType.h"
#include "TribesGame.TrObject.EffectCalcMethod.h"
#include "TribesGame.TrObject.EffectFormMatTypes.h"
#include "TribesGame.TrObject.EffectFormOverwrite.h"
#include "TribesGame.TrObject.EffectFormPriority.h"
#include "TribesGame.TrObject.EffectType.h"
#include "TribesGame.TrObject.GAME_TYPE.h"
#include "TribesGame.TrObject.GAME_WIN_STATE.h"
#include "TribesGame.TrObject.LoadoutSlotTypes.h"
#include "TribesGame.TrObject.ObjectiveMICInfo.h"
#include "TribesGame.TrObject.OffhandAnimation.h"
#include "TribesGame.TrObject.OverlayType.h"
#include "TribesGame.TrObject.PaperDollInfo.h"
#include "TribesGame.TrObject.ReticuleDataType.h"
#include "TribesGame.TrObject.ServerPropType.h"
#include "TribesGame.TrObject.SpawnTypes.h"
#include "TribesGame.TrObject.TR_EQUIP_POINT.h"
#include "TribesGame.TrObject.TR_HIDEABLE_HUD_ELEMENT.h"
#include "TribesGame.TrObject.TR_HUD_INFO.h"
#include "TribesGame.TrObject.TR_WIDGET_SUBTYPES.h"
#include "TribesGame.TrObject.TeamAssignTypes.h"
#include "TribesGame.TrObject.TgSupportedAspectRatios.h"
#include "TribesGame.TrObject.TrClassType.h"
#include "TribesGame.TrObject.TrCreditEventType.h"
#include "TribesGame.TrObject.TrEventCredits.h"
#include "TribesGame.TrObject.TrMiscMessages.h"
#include "TribesGame.TrObject.TrTakeEffectInfo.h"
#include "TribesGame.TrObject.TrTakeHitInfo.h"
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
	class TrObject : public Object
	{
	public:
		typedef TrObject__EffectFormMatTypes EffectFormMatTypes;
		typedef TrObject__TeamAssignTypes TeamAssignTypes;
		typedef TrObject__TrMiscMessages TrMiscMessages;
		typedef TrObject__EArmorType EArmorType;
		typedef TrObject__ETrPlayerCallIns ETrPlayerCallIns;
		typedef TrObject__ESettingsList ESettingsList;
		typedef TrObject__CaHCapturePointLabel CaHCapturePointLabel;
		typedef TrObject__ServerPropType ServerPropType;
		typedef TrObject__TrClassType TrClassType;
		typedef TrObject__LoadoutSlotTypes LoadoutSlotTypes;
		typedef TrObject__SpawnTypes SpawnTypes;
		typedef TrObject__EContentDataType EContentDataType;
		typedef TrObject__ReticuleDataType ReticuleDataType;
		typedef TrObject__EVehicleTypes EVehicleTypes;
		typedef TrObject__EWeaponTracerType EWeaponTracerType;
		typedef TrObject__DeployModeStatus DeployModeStatus;
		typedef TrObject__EffectCalcMethod EffectCalcMethod;
		typedef TrObject__EffectFormPriority EffectFormPriority;
		typedef TrObject__DeviceAttackType DeviceAttackType;
		typedef TrObject__DeviceTargeterType DeviceTargeterType;
		typedef TrObject__TR_WIDGET_SUBTYPES TR_WIDGET_SUBTYPES;
		typedef TrObject__EMissileLock EMissileLock;
		typedef TrObject__TR_EQUIP_POINT TR_EQUIP_POINT;
		typedef TrObject__TgSupportedAspectRatios TgSupportedAspectRatios;
		typedef TrObject__TrCreditEventType TrCreditEventType;
		typedef TrObject__OverlayType OverlayType;
		typedef TrObject__EffectType EffectType;
		typedef TrObject__DAMAGE_INFO_TYPE DAMAGE_INFO_TYPE;
		typedef TrObject__TR_HIDEABLE_HUD_ELEMENT TR_HIDEABLE_HUD_ELEMENT;
		typedef TrObject__GAME_TYPE GAME_TYPE;
		typedef TrObject__GAME_WIN_STATE GAME_WIN_STATE;
		typedef TrObject__EffectFormOverwrite EffectFormOverwrite;
		typedef TrObject__PaperDollInfo PaperDollInfo;
		typedef TrObject__TrTakeEffectInfo TrTakeEffectInfo;
		typedef TrObject__TrTakeHitInfo TrTakeHitInfo;
		typedef TrObject__OffhandAnimation OffhandAnimation;
		typedef TrObject__TrEventCredits TrEventCredits;
		typedef TrObject__TR_HUD_INFO TR_HUD_INFO;
		typedef TrObject__ObjectiveMICInfo ObjectiveMICInfo;
		static const auto FEET_TO_UNREAL_UNITS = 16;
		static const auto INDEX_DISPLAY_TARGET_INGAME = 0;
		static const auto INDEX_DISPLAY_TARGET_FOREGROUND = 1;
		static const auto INDEX_SEE_NORMAL_ENEMY = 0;
		static const auto INDEX_SEE_STEALTHED_ENEMY = 1;
		static const auto INDEX_SEE_LOW_HEALTH_ENEMY = 2;
		static const auto TR_TASKFORCE_NONE = 0;
		static const auto TR_TASKFORCE_BLOODEAGLE = 1;
		static const auto TR_TASKFORCE_DIAMONDSWORD = 2;
		static const float FADE_TIME;
		static const auto MAX_HEARING_DISTANCE = 1300;
		static const auto TR_MAX_SLOTS_TO_EQUIP = 5;
		static const float UnrealUnitsToKM;
	};
	const float TrObject::FADE_TIME = 1.0f;
	const float TrObject::UnrealUnitsToKM = 0.072f;
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
