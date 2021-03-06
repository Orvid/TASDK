#pragma once
namespace UnrealScript
{
	class TrCTFMessage;
}
#include "Core.Object.h"
#include "Engine.PlayerController.h"
#include "Engine.PlayerReplicationInfo.h"
#include "Engine.SoundCue.h"
#include "Engine.SoundNodeWave.h"
#include "UTGame.UTLocalMessage.h"
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
	class TrCTFMessage : public UTLocalMessage
	{
	public:
		static const auto THR_SPINFUSOR = 1;
		static const auto THR_SMG = 2;
		static const auto THR_RIFLE = 3;
		static const auto THR_LOCKED_ON = 4;
		static const auto THR_CROSSBOW = 5;
		static const auto THR_FLAME_THROWER = 6;
		static const auto THR_CHAIN_GUN = 7;
		static const auto THR_MISSILE = 8;
		static const auto THR_NANITE = 9;
		static const auto THR_SHOTGUN = 10;
		static const auto THR_UNKNOWN = 11;
		static const auto THR_LASER = 12;
		static const auto THR_CH_V13 = 13;
		static const auto THR_SCOPE = 14;
		static const auto THR_STANDARD = 15;
		static const auto THR_GRENADE_LAUNCHER = 16;
		static const auto THR_MELEE = 17;
		static const auto THR_SHRIKE = 18;
		static const auto THR_FREE_SPECTATOR = 19;
		static const auto THR_RED_DOT = 20;
		static const auto THR_BXT1 = 21;
		static const auto THR_PHASERIFLE = 22;
		static const auto THR_SAP20 = 23;
		static const auto THR_PLASMAGUN = 24;
		static const auto HAE_KILL_STREAK_LEVEL_1 = 1;
		static const auto HAE_KILL_STREAK_LEVEL_2 = 2;
		static const auto HAE_KILL_STREAK_LEVEL_3 = 3;
		static const auto HAE_KILL_STREAK_LEVEL_4 = 4;
		static const auto HAE_KILL_STREAK_LEVEL_5 = 5;
		static const auto TRHUD_PACK_STEALTH = 1;
		static const auto TRHUD_PACK_DAMAGE = 2;
		static const auto TRHUD_PACK_OMNI = 3;
		static const auto TRHUD_PACK_ERECHARGE = 4;
		static const auto TRHUD_PACK_AIRTURRET = 5;
		static const auto TRHUD_PACK_BLINK = 6;
		static const auto TRHUD_PACK_ENERGY = 7;
		static const auto TRHUD_PACK_SHIELD = 8;
		static const auto TRHUD_PACK_JAMMER = 9;
		static const auto TRHUD_PACK_LIGHTTURRET = 10;
		static const auto TRHUD_PACK_FORCEFIELD = 11;
		static const auto TRHUD_PACK_WALLTURRET = 12;
		static const auto TRHUD_PACK_REGEN = 13;
		static const auto TRHUD_PACK_DROPJAMMER = 14;
		static const auto TRHUD_TBD1 = 15;
		static const auto TRHUD_TBD2 = 16;
		static const auto TRHUD_TBD3 = 17;
		static const auto TRHUD_BELT_STICKYGREN = 18;
		static const auto TRHUD_BELT_FRAG = 19;
		static const auto TRHUD_BELT_CLAYMORE = 20;
		static const auto TRHUD_BELT_NITRON = 21;
		static const auto TRHUD_BELT_MOTIONALARM = 22;
		static const auto TRHUD_BELT_SPIKEGREN = 23;
		static const auto TRHUD_BELT_WHITEOUT = 24;
		static const auto TRHUD_BELT_APGREN = 25;
		static const auto TRHUD_BELT_STGREN = 26;
		static const auto TRHUD_BELT_PRISMMINES = 27;
		static const auto TRHUD_BELT_FLARE = 28;
		static const auto TRHUD_BELT_EMPGREN = 29;
		static const auto TRHUD_BELT_MINES = 30;
		static const auto TRHUD_BELT_DISKTOSS = 31;
		static const auto TRHUD_TBD4 = 32;
		static const auto TRHUD_TBD5 = 33;
		static const auto TRHUD_MEDAL_ASSIST = 34;
		static const auto TRHUD_CLAYMOREMINE = 35;
		static const auto TRHUD_PRISMMINE = 36;
		static const auto TRHUD_LIGHTTURRET = 37;
		static const auto TRHUD_AATURRET = 38;
		static const auto TRHUD_MOTIONSENSOR = 39;
		static const auto TRHUD_MINES = 40;
		static const auto TRHUD_FORCESHIELD = 41;
		static const auto TRHUD_DROPJAMMER = 42;
		static const auto TRHUD_GENERATOR = 43;
		static const auto TRHUD_SKIING = 44;
		static const auto TRHUD_MEDAL_KILLINGSPREE = 45;
		static const auto TRHUD_MEDAL_KILLINGRAMPAGE = 46;
		static const auto TRHUD_MEDAL_UNSTOPPABLE = 47;
		static const auto TRHUD_MEDAL_RELENTLESS = 48;
		static const auto TRHUD_MEDAL_THESLAYER = 49;
		static const auto TRHUD_MEDAL_SNIPINGSPREE = 50;
		static const auto TRHUD_MEDAL_MARKSMAN = 51;
		static const auto TRHUD_MEDAL_SHARPSHOOTER = 52;
		static const auto TRHUD_MEDAL_AIRMAIL = 53;
		static const auto TRHUD_MEDAL_DEMOLITIONSEXPERT = 54;
		static const auto TRHUD_MEDAL_HURTLOCKER = 55;
		static const auto TRHUD_MEDAL_CLASSICSPREE = 56;
		static const auto TRHUD_MEDAL_DISKJOCKEY = 57;
		static const auto TRHUD_MEDAL_TRIBALFANATIC = 58;
		static const auto TRHUD_MEDAL_DOUBLEKILL = 59;
		static const auto TRHUD_MEDAL_TRIPLEKILL = 60;
		static const auto TRHUD_MEDAL_QUATRAKILL = 61;
		static const auto TRHUD_MEDAL_ULTRAKILL = 62;
		static const auto TRHUD_MEDAL_TEAMKILL = 63;
		static const auto TRHUD_MEDAL_NOJOY = 64;
		static const auto TRHUD_MEDAL_REVENGE = 65;
		static const auto TRHUD_MEDAL_AFTERMATH = 66;
		static const auto TRHUD_MEDAL_FIRSTBLOOD = 67;
		static const auto TRHUD_MEDAL_BLUEPLATE = 68;
		static const auto TRHUD_MEDAL_STICKYKILL = 69;
		static const auto TRHUD_MEDAL_HEADSHOT = 70;
		static const auto TRHUD_MEDAL_ARTILLERYSHOT = 71;
		static const auto TRHUD_MEDAL_MARTIALART = 72;
		static const auto TRHUD_MEDAL_SQUISH = 73;
		static const auto TRHUD_MEDAL_FLAGGOLD = 74;
		static const auto TRHUD_MEDAL_FLAGSILVER = 75;
		static const auto TRHUD_MEDAL_FLAGBRONZE = 75;
		static const auto TRHUD_MEDAL_FLAGLLAMA = 75;
		static const auto TRHUD_MEDAL_GENERHATER = 76;
		static const auto TRHUD_MEDAL_RABBITHUNTER = 77;
		static const auto TRHUD_MEDAL_CAERBANNOG = 78;
		static const auto TRHUD_MEDAL_FINALBLOW = 79;
		static const auto TRHUD_MEDAL_GENDEFENSE = 76;
		static const auto TRHUD_MEDAL_FLAGDEFENSE = 75;
		static const auto TRHUD_MEDAL_VDESTROY = 73;
		static const auto TRHUD_MEDAL_HOTAIR = 284;
		static const auto TRICON_RANK_1 = 80;
		static const auto TRICON_RANK_2 = 81;
		static const auto TRICON_RANK_3 = 82;
		static const auto TRICON_RANK_4 = 83;
		static const auto TRICON_RANK_5 = 84;
		static const auto TRICON_RANK_6 = 85;
		static const auto TRICON_RANK_7 = 86;
		static const auto TRICON_RANK_8 = 87;
		static const auto TRICON_RANK_9 = 88;
		static const auto TRICON_RANK_10 = 89;
		static const auto TRICON_RANK_11 = 90;
		static const auto TRICON_RANK_12 = 91;
		static const auto TRICON_RANK_13 = 92;
		static const auto TRICON_RANK_14 = 93;
		static const auto TRICON_RANK_15 = 94;
		static const auto TRICON_RANK_16 = 95;
		static const auto TRICON_RANK_17 = 96;
		static const auto TRICON_RANK_18 = 97;
		static const auto TRICON_RANK_19 = 98;
		static const auto TRICON_RANK_20 = 99;
		static const auto TRICON_RANK_21 = 100;
		static const auto TRICON_RANK_22 = 101;
		static const auto TRICON_RANK_23 = 102;
		static const auto TRICON_RANK_24 = 103;
		static const auto TRICON_RANK_25 = 104;
		static const auto TRICON_RANK_26 = 105;
		static const auto TRICON_RANK_27 = 106;
		static const auto TRICON_RANK_28 = 107;
		static const auto TRICON_RANK_29 = 108;
		static const auto TRICON_RANK_30 = 109;
		static const auto TRICON_RANK_31 = 110;
		static const auto TRICON_RANK_32 = 111;
		static const auto TRICON_RANK_33 = 112;
		static const auto TRICON_RANK_34 = 113;
		static const auto TRICON_RANK_35 = 114;
		static const auto TRICON_RANK_36 = 115;
		static const auto TRICON_RANK_37 = 116;
		static const auto TRICON_RANK_38 = 117;
		static const auto TRICON_RANK_39 = 118;
		static const auto TRICON_RANK_40 = 119;
		static const auto TRICON_RANK_41 = 120;
		static const auto TRICON_RANK_42 = 121;
		static const auto TRICON_RANK_43 = 122;
		static const auto TRICON_RANK_44 = 123;
		static const auto TRICON_RANK_45 = 124;
		static const auto TRICON_RANK_46 = 125;
		static const auto TRICON_RANK_47 = 126;
		static const auto TRICON_RANK_48 = 127;
		static const auto TRICON_RANK_49 = 128;
		static const auto TRICON_RANK_50 = 129;
		static const auto TRICON_KILLTYPE_EXPLOSIVE = 130;
		static const auto TRICON_KILLTYPE_STICKY = 131;
		static const auto TRICON_KILLTYPE_SQUISH = 132;
		static const auto TRICON_KILLTYPE_MELEE = 133;
		static const auto TRICON_KILLTYPE_FALLING = 134;
		static const auto TRICON_KILLTYPE_VEHICLE = 135;
		static const auto TRICON_KILLTYPE_BULLET = 136;
		static const auto TRICON_KILLTYPE_SNIPER = 137;
		static const auto TRICON_KILLTYPE_BASE_TURRET = 138;
		static const auto TRICON_KILLTYPE_HEADSHOT = 139;
		static const auto TRICON_KILLTYPE_GENERIC = 140;
		static const auto TRICON_KILLTYPE_SPINFUSOR = 141;
		static const auto TRICON_KILLTYPE_TURRET = 142;
		static const auto TRICON_ACCOLADE_BASE_DESTROY = 143;
		static const auto TRICON_ACCOLADE_BASE_REPAIR = 144;
		static const auto TRICON_ACCOLADE_MIRACLE = 145;
		static const auto TRICON_ACCOLADE_ULTRAKILLNORED = 146;
		static const auto TRICON_ACCOLADE_NOTAMONGEQUALS = 147;
		static const auto TRICON_ACCOLADE_EXPLOSIVESPREE = 148;
		static const auto TRICON_ACCOLADE_ULTRAFASTGRAB = 149;
		static const auto TRICON_ACCOLADE_ONEMANARMY = 150;
		static const auto TRICON_ACCOLADE_GAMEWINNER = 151;
		static const auto TRICON_ACCOLADE_UNITEDWESTAND = 152;
		static const auto TRICON_ACCOLADE_DOUBLEDOWN = 153;
		static const auto TRICON_ACCOLADE_FASTFLAGGRAB = 154;
		static const auto TRICON_ACCOLADE_SHRIKEDOWN = 155;
		static const auto TRICON_ACCOLADE_GRAVCYCLEDOWN = 156;
		static const auto TRICON_ACCOLADE_BEOWULFDOWN = 157;
		static const auto TRICON_ACCOLADE_FINALBLOW = 158;
		static const auto TRICON_ACCOLADE_BENCHEM = 159;
		static const auto TRICON_ACCOLADE_LASTMANSTANDING = 160;
		static const auto TRICON_ACCOLADE_TRIBALHONOR = 161;
		static const auto TRICON_ACCOLADE_FLAGKILLER = 162;
		static const auto TRICON_ACCOLADE_GAMECOMPLETE = 163;
		static const auto TRICON_ACCOLADE_FLAGDEFENSE = 164;
		static const auto TRICON_ACCOLADE_GENERATORDEFENSE = 165;
		static const auto TRICON_ACCOLADE_LLAMAGRAB = 166;
		static const auto TRICON_ACCOLADE_EGRAB = 167;
		static const auto TRICON_ACCOLADE_TURRETDESTROYED = 168;
		static const auto TRICON_ACCOLADE_ALTFLAGCARRY = 169;
		static const auto TRICON_ACCOLADE_HOLDTHELINE = 281;
		static const auto TRICON_ACCOLADE_CAPTUREANDHOLD = 282;
		static const auto TRICON_BADGE_FLAGDEFENSE_4 = 170;
		static const auto TRICON_BADGE_FLAGDEFENSE_3 = 171;
		static const auto TRICON_BADGE_FLAGDEFENSE_2 = 172;
		static const auto TRICON_BADGE_FLAGDEFENSE_1 = 173;
		static const auto TRICON_BADGE_OPERATOR_4 = 174;
		static const auto TRICON_BADGE_OPERATOR_3 = 175;
		static const auto TRICON_BADGE_OPERATOR_2 = 176;
		static const auto TRICON_BADGE_OPERATOR_1 = 177;
		static const auto TRICON_BADGE_CALLINKILLS_4 = 178;
		static const auto TRICON_BADGE_CALLINKILLS_3 = 179;
		static const auto TRICON_BADGE_CALLINKILLS_2 = 180;
		static const auto TRICON_BADGE_CALLINKILLS_1 = 181;
		static const auto TRICON_BADGE_MELEEKILLS_4 = 182;
		static const auto TRICON_BADGE_MELEEKILLS_3 = 183;
		static const auto TRICON_BADGE_MELEEKILLS_2 = 184;
		static const auto TRICON_BADGE_MELEEKILLS_1 = 185;
		static const auto TRICON_BADGE_ONEMANARMY_4 = 186;
		static const auto TRICON_BADGE_ONEMANARMY_3 = 187;
		static const auto TRICON_BADGE_ONEMANARMY_2 = 188;
		static const auto TRICON_BADGE_ONEMANARMY_1 = 189;
		static const auto TRICON_BADGE_FLAGCAPPER_4 = 190;
		static const auto TRICON_BADGE_FLAGCAPPER_3 = 191;
		static const auto TRICON_BADGE_FLAGCAPPER_2 = 192;
		static const auto TRICON_BADGE_FLAGCAPPER_1 = 193;
		static const auto TRICON_BADGE_TOUROFDUTY_4 = 194;
		static const auto TRICON_BADGE_TOUROFDUTY_3 = 195;
		static const auto TRICON_BADGE_TOUROFDUTY_2 = 196;
		static const auto TRICON_BADGE_TOUROFDUTY_1 = 197;
		static const auto TRICON_BADGE_MULTIKILL_4 = 198;
		static const auto TRICON_BADGE_MULTIKILL_3 = 199;
		static const auto TRICON_BADGE_MULTIKILL_2 = 200;
		static const auto TRICON_BADGE_MULTIKILL_1 = 201;
		static const auto TRICON_BADGE_COMBATSTAR_4 = 202;
		static const auto TRICON_BADGE_COMBATSTAR_3 = 203;
		static const auto TRICON_BADGE_COMBATSTAR_2 = 204;
		static const auto TRICON_BADGE_COMBATSTAR_1 = 205;
		static const auto TRICON_BADGE_CROSSCOUNTRY_4 = 206;
		static const auto TRICON_BADGE_CROSSCOUNTRY_3 = 207;
		static const auto TRICON_BADGE_CROSSCOUNTRY_2 = 208;
		static const auto TRICON_BADGE_CROSSCOUNTRY_1 = 209;
		static const auto TRICON_BADGE_POWERPLAYER_4 = 210;
		static const auto TRICON_BADGE_POWERPLAYER_3 = 211;
		static const auto TRICON_BADGE_POWERPLAYER_2 = 212;
		static const auto TRICON_BADGE_POWERPLAYER_1 = 213;
		static const auto TRICON_BADGE_DEMOMAN_4 = 214;
		static const auto TRICON_BADGE_DEMOMAN_3 = 215;
		static const auto TRICON_BADGE_DEMOMAN_2 = 216;
		static const auto TRICON_BADGE_DEMOMAN_1 = 217;
		static const auto TRICON_BADGE_SPEEDRUNNER_4 = 218;
		static const auto TRICON_BADGE_SPEEDRUNNER_3 = 219;
		static const auto TRICON_BADGE_SPEEDRUNNER_2 = 220;
		static const auto TRICON_BADGE_SPEEDRUNNER_1 = 221;
		static const auto TRICON_BADGE_GOODDRIVER_4 = 222;
		static const auto TRICON_BADGE_GOODDRIVER_3 = 223;
		static const auto TRICON_BADGE_GOODDRIVER_2 = 224;
		static const auto TRICON_BADGE_GOODDRIVER_1 = 225;
		static const auto TRICON_BADGE_PURPLEHEART_4 = 226;
		static const auto TRICON_BADGE_PURPLEHEART_3 = 227;
		static const auto TRICON_BADGE_PURPLEHEART_2 = 228;
		static const auto TRICON_BADGE_PURPLEHEART_1 = 229;
		static const auto TRICON_BADGE_HAPPENSTOUSALL = 230;
		static const auto TRICON_BADGE_INVSTATION = 231;
		static const auto TRICON_BADGE_ANTIVEHICLE_4 = 232;
		static const auto TRICON_BADGE_ANTIVEHICLE_3 = 233;
		static const auto TRICON_BADGE_ANTIVEHICLE_2 = 234;
		static const auto TRICON_BADGE_ANTIVEHICLE_1 = 235;
		static const auto TRICON_BADGE_UTILITYBELT_4 = 236;
		static const auto TRICON_BADGE_UTILITYBELT_3 = 237;
		static const auto TRICON_BADGE_UTILITYBELT_2 = 238;
		static const auto TRICON_BADGE_UTILITYBELT_1 = 239;
		static const auto TRICON_BADGE_ONCALL_4 = 240;
		static const auto TRICON_BADGE_ONCALL_3 = 241;
		static const auto TRICON_BADGE_ONCALL_2 = 242;
		static const auto TRICON_BADGE_ONCALL_1 = 243;
		static const auto TRICON_BADGE_SUPPORT_4 = 244;
		static const auto TRICON_BADGE_SUPPORT_3 = 245;
		static const auto TRICON_BADGE_SUPPORT_2 = 246;
		static const auto TRICON_BADGE_SUPPORT_1 = 247;
		static const auto TRICON_BADGE_MARKSMAN_4 = 248;
		static const auto TRICON_BADGE_MARKSMAN_3 = 249;
		static const auto TRICON_BADGE_MARKSMAN_2 = 250;
		static const auto TRICON_BADGE_MARKSMAN_1 = 251;
		static const auto TRICON_BADGE_ASSISTOR_4 = 252;
		static const auto TRICON_BADGE_ASSISTOR_3 = 253;
		static const auto TRICON_BADGE_ASSISTOR_2 = 254;
		static const auto TRICON_BADGE_ASSISTOR_1 = 255;
		static const auto TRICON_BADGE_BUILDER_4 = 256;
		static const auto TRICON_BADGE_BUILDER_3 = 257;
		static const auto TRICON_BADGE_BUILDER_2 = 258;
		static const auto TRICON_BADGE_BUILDER_1 = 259;
		static const auto TRICON_BADGE_GOINGFAST_4 = 260;
		static const auto TRICON_BADGE_GOINGFAST_3 = 261;
		static const auto TRICON_BADGE_GOINGFAST_2 = 262;
		static const auto TRICON_BADGE_GOINGFAST_1 = 263;
		static const auto RANK_XP_1 = 0;
		static const auto RANK_XP_2 = 1350;
		static const auto RANK_XP_3 = 2781;
		static const auto RANK_XP_4 = 4298;
		static const auto RANK_XP_5 = 5906;
		static const auto RANK_XP_6 = 11212;
		static const auto RANK_XP_7 = 16836;
		static const auto RANK_XP_8 = 22798;
		static const auto RANK_XP_9 = 31741;
		static const auto RANK_XP_10 = 41130;
		static const auto RANK_XP_11 = 50990;
		static const auto RANK_XP_12 = 61342;
		static const auto RANK_XP_13 = 76870;
		static const auto RANK_XP_14 = 93020;
		static const auto RANK_XP_15 = 109815;
		static const auto RANK_XP_16 = 127283;
		static const auto RANK_XP_17 = 145449;
		static const auto RANK_XP_18 = 172698;
		static const auto RANK_XP_19 = 200765;
		static const auto RANK_XP_20 = 229673;
		static const auto RANK_XP_21 = 259449;
		static const auto RANK_XP_22 = 290118;
		static const auto RANK_XP_23 = 321707;
		static const auto RANK_XP_24 = 369091;
		static const auto RANK_XP_25 = 417896;
		static const auto RANK_XP_26 = 468166;
		static const auto RANK_XP_27 = 519943;
		static const auto RANK_XP_28 = 573274;
		static const auto RANK_XP_29 = 628205;
		static const auto RANK_XP_30 = 684783;
		static const auto RANK_XP_31 = 743059;
		static const auto RANK_XP_32 = 803084;
		static const auto RANK_XP_33 = 864909;
		static const auto RANK_XP_34 = 928589;
		static const auto RANK_XP_35 = 994179;
		static const auto RANK_XP_36 = 1061737;
		static const auto RANK_XP_37 = 1131321;
		static const auto RANK_XP_38 = 1202994;
		static const auto RANK_XP_39 = 1276816;
		static const auto RANK_XP_40 = 1352853;
		static const auto RANK_XP_41 = 1431171;
		static const auto RANK_XP_42 = 1511839;
		static const auto RANK_XP_43 = 1594926;
		static const auto RANK_XP_44 = 1680507;
		static const auto RANK_XP_45 = 1768654;
		static const auto RANK_XP_46 = 1859447;
		static const auto RANK_XP_47 = 1952963;
		static const auto RANK_XP_48 = 2049284;
		static const auto RANK_XP_49 = 2148495;
		static const auto RANK_XP_50 = 2250682;
		static const auto ACCOLADE_TYPE_MISC = 0;
		static const auto ACCOLADE_TYPE_MULTIKILL = 1;
		static const auto ACCOLADE_TYPE_KILLSTREAK = 2;
		static const auto TRICON_PERK_ICON_WIP = 1;
		static const auto TRICON_PERK_BONUS_KILL_CREDITS = 1;
		static const auto TRICON_PERK_STICKY_HANDS = 2;
		static const auto TRICON_PERK_REDUCED_VEHICLE_COST = 3;
		static const auto TRICON_PERK_REDUCED_SELF_DAMAGE = 4;
		static const auto TRICON_PERK_REDUCED_RUN_OVER = 5;
		static const auto TRICON_PERK_REDUCED_BASE_UPGRADE_COST = 6;
		static const auto TRICON_PERK_REDUCED_FALL_DMG = 7;
		static const auto TRICON_PERK_REDUCED_AIR_VEHICLE_COST = 8;
		static const auto TRICON_PERK_TRAP_DETECTION = 9;
		static const auto TRICON_PERK_PICKUP_ENERGY_HEALTH = 10;
		static const auto TRICON_PERK_MELEE_FLAG_DROP = 11;
		static const auto TRICON_PERK_EXTRA_MINES = 12;
		static const auto TRICON_PERK_EXTRA_ENERGY = 13;
		static const auto TRICON_PERK_EXTRA_GRENADE_PICKUP = 14;
		static const auto TRICON_PERK_EXTRA_AMMO = 15;
		static const auto TRICON_PERK_EXTRA_GRENADE = 16;
		static const auto TRICON_PERK_BEOWULF_HEALTH_INCREASE = 17;
		static const auto TRICON_PERK_EJECTION_SEAT = 18;
		static const auto TRICON_PERK_ORBITAL_STRIKE = 19;
		static const auto TRICON_PERK_REDUCED_MELEE_DAMAGE = 20;
		static const auto TRICON_PERK_MELEE_BACKSTAB = 21;
		static const auto TRICON_PERK_DEMOLITIONS = 22;
		static const auto TRICON_PERK_SQUIRRELLY = 23;
		static const auto TRICON_PERK_STEALTHY = 24;
		static const auto TRICON_PERK_ULTRA_CAPACITOR = 25;
		static const auto TRICON_PERK_DETERMINATION = 26;
		static const auto TRICON_SKILL_SPEED = 1;
		static const auto TRICON_SKILL_ENERGY = 2;
		static const auto TRICON_SKILL_PING = 3;
		static const auto TRICON_SKILL_AMMO = 4;
		static const auto TRICON_SKILL_ANTI_ARMOR = 5;
		static const auto TRICON_SKILL_GRENADE = 6;
		static const auto TRICON_SKILL_RADIUS = 7;
		static const auto TRICON_SKILL_HEALTH = 8;
		static const auto TRICON_SKILL_BOOT = 9;
		static const auto TRICON_SKILL_TIMER = 10;
		static const auto TRICON_CLASS_SENTINEL = 1;
		static const auto TRICON_CLASS_PATHFINDER = 2;
		static const auto TRICON_CLASS_JUMPER = 3;
		static const auto TRICON_CLASS_INFILTRATOR = 4;
		static const auto TRICON_CLASS_WARDER = 30;
		static const auto TRICON_CLASS_TECHNICIAN = 31;
		static const auto TRICON_CLASS_SOLDIER = 32;
		static const auto TRICON_CLASS_SCRAMBLER = 33;
		static const auto TRICON_CLASS_RANGER = 34;
		static const auto TRICON_CLASS_RAIDER = 35;
		static const auto TRICON_CLASS_ENGINEER = 36;
		static const auto TRICON_CLASS_ROOK = 60;
		static const auto TRICON_CLASS_MARAUDER = 61;
		static const auto TRICON_CLASS_JUGGERNAUT = 62;
		static const auto TRICON_CLASS_DOOMBRINGER = 63;
		static const auto TRICON_CLASS_BRUTE = 64;
		static const auto TRICON_CLASS_WIP = 88;
		static const auto ICON_UPGRADE_NONE = 0;
		static const auto MOD_TYPE_NONE = 1;
		static const auto MOD_TYPE_HEALTH = 2;
		static const auto MOD_TYPE_MASSPCT = 3;
		static const auto MOD_TYPE_RADARLINK = 4;
		static const auto MOD_TYPE_FLAGREACH = 5;
		static const auto MOD_TYPE_BUILDUPPCT = 6;
		static const auto MOD_TYPE_CLOTHESLINE = 7;
		static const auto MOD_TYPE_STICKYHANDS = 8;
		static const auto MOD_TYPE_MAXSKISPEED = 9;
		static const auto MOD_TYPE_EXTRAENERGY = 10;
		static const auto MOD_TYPE_EJECTIONSEAT = 11;
		static const auto MOD_TYPE_SELFDAMAGEPCT = 12;
		static const auto MOD_TYPE_REPAIRRATEPCT = 13;
		static const auto MOD_TYPE_EXTRAMINESOUT = 14;
		static const auto MOD_TYPE_VEHICLEEXTRAHEALTH = 15;
		static const auto MOD_TYPE_GROUNDSPEEDPCT = 16;
		static const auto MOD_TYPE_ENERGYDRAINPCT = 17;
		static const auto MOD_TYPE_UPGRADECOSTPCT = 18;
		static const auto MOD_TYPE_CANDETECTTRAPS = 19;
		static const auto MOD_TYPE_SPLATDAMAGEPCT = 20;
		static const auto MOD_TYPE_WEAPONSWITCHPCT = 21;
		static const auto MOD_TYPE_POTENTIALENERGY = 22;
		static const auto MOD_TYPE_MAXJETTINGSPEED = 23;
		static const auto MOD_TYPE_CREDITSFROMKILLS = 24;
		static const auto MOD_TYPE_TERMINALSKISPEED = 25;
		static const auto MOD_TYPE_MAXSKICONTROLPCT = 26;
		static const auto MOD_TYPE_HASDETERMINATION = 27;
		static const auto MOD_TYPE_DEPLOYABLEHEALTH = 28;
		static const auto MOD_TYPE_EXTRAOFFHANDAMMO = 29;
		static const auto MOD_TYPE_EXTRAPRIMARYAMMO = 30;
		static const auto MOD_TYPE_PRIMARYRELOADPCT = 31;
		static const auto MOD_TYPE_SENSORDISTANCEPCT = 32;
		static const auto MOD_TYPE_PACKENERGYCOSTPCT = 33;
		static const auto MOD_TYPE_AMMOFROMPICKUPPCT = 34;
		static const auto MOD_TYPE_TIMETOREGENENERGY = 35;
		static const auto MOD_TYPE_SECONDARYRELOADPCT = 36;
		static const auto MOD_TYPE_EXTRASECONDARYAMMO = 37;
		static const auto MOD_TYPE_ENERGYREGENRATEPCT = 38;
		static const auto MOD_TYPE_HEALTHREGENRATEPCT = 39;
		static const auto MOD_TYPE_DEPLOYABLERANGEPCT = 40;
		static const auto MOD_TYPE_JAMMERPACKRADIUSPCT = 41;
		static const auto MOD_TYPE_BLINKPACKPOTENCYPCT = 42;
		static const auto MOD_TYPE_PEAKSKICONTROLSPEED = 43;
		static const auto MOD_TYPE_CANCALLINSUPPLYDROP = 44;
		static const auto MOD_TYPE_EXTRADEPLOYABLESOUT = 45;
		static const auto MOD_TYPE_HEALTHFROMPICKUPPCT = 46;
		static const auto MOD_TYPE_ENERGYFROMPICKUPPCT = 47;
		static const auto MOD_TYPE_TERMINALJETTINGSPEED = 48;
		static const auto MOD_TYPE_TIMETOREGENHEALTHPCT = 49;
		static const auto MOD_TYPE_VEHICLECOSTPCT = 50;
		static const auto MOD_TYPE_SKICONTROLSIGMASQUARE = 51;
		static const auto MOD_TYPE_RECEIVEMELEEDAMAGEPCT = 52;
		static const auto MOD_TYPE_VICTIMDROPFLAGONMELEE = 53;
		static const auto MOD_TYPE_PRIMARYWEAPONRANGEPCT = 54;
		static const auto MOD_TYPE_OFFHANDDAMAGERADIUSPCT = 55;
		static const auto MOD_TYPE_TURRETACQUIRETARGETPCT = 56;
		static const auto MOD_TYPE_WHITEOUTINTERPSPEEDPCT = 57;
		static const auto MOD_TYPE_BACKSTABMELEEDAMAGEPCT = 58;
		static const auto MOD_TYPE_MAXSTOPPINGDISTANCEPCT = 59;
		static const auto MOD_TYPE_SECONDARYWEAPONRANGEPCT = 60;
		static const auto MOD_TYPE_EXTRAGRENADESFROMPICKUP = 61;
		static const auto MOD_TYPE_SHIELDPACKEFFECTIVENESS = 62;
		static const auto MOD_TYPE_STEALTHPACKPULSETIMEPCT = 63;
		static const auto MOD_TYPE_PRIMARYINCREASEDCLIPSIZE = 64;
		static const auto MOD_TYPE_EXTRACREDITSFROMBELTKILLS = 65;
		static const auto MOD_TYPE_TURRETARMORPENETRATIONPCT = 66;
		static const auto MOD_TYPE_SECONDARYINCREASEDCLIPSIZE = 67;
		static const auto MOD_TYPE_OFFHANDARMORPENETRATIONPCT = 68;
		static const auto MOD_TYPE_PRIMARYARMORPENETRATIONPCT = 69;
		static const auto MOD_TYPE_RUNOVERDAMAGEPROTECTIONPCT = 70;
		static const auto MOD_TYPE_PRIMARYWEAPONENERGYCOSTPCT = 71;
		static const auto MOD_TYPE_ACQUIRETIMEBYENEMYTURRETPCT = 72;
		static const auto MOD_TYPE_SECONDARYARMORPENETRATIONPCT = 73;
		static const auto MOD_TYPE_VEHICLEEXTRAENERGY = 74;
		static const auto MOD_TYPE_AMMOPICKUPREACH = 75;
		static const auto MOD_TYPE_VEHICLEPASSENGERDMGPROTPCT = 76;
		static const auto MOD_TYPE_DAMAGEREPAIRENEMYOBJECTIVES = 77;
		static const auto MOD_TYPE_POTENTIALENERGYFALLDAMAGE = 78;
		static const auto MOD_TYPE_FASTERTHROWBELTBUFFPCT = 79;
		static const auto MOD_TYPE_IGNOREGRENADESECONDARYONSELF = 80;
		static const auto MOD_TYPE_POTENTIALENERGYDMGTRANSFERPCT = 81;
		static const auto MOD_TYPE_FLAGREACHTIER = 82;
		static const auto MOD_TYPE_SONICPUNCH = 83;
		static const auto MOD_TYPE_SONICPUNCHDIST = 84;
		static const auto MOD_TYPE_SONICPUNCHKNOCKBACK = 85;
		static const auto MOD_TYPE_RAGE = 86;
		static const auto MOD_TYPE_RAGEENERGYREGEN = 87;
		static const auto MOD_TYPE_RAGETIMELENGTH = 88;
		static const auto MOD_TYPE_RAGEHEALTHRESTOREPCT = 89;
		static const auto MOD_TYPE_IGNOREPULSESTEALTHTIME = 90;
		static const auto MOD_TYPE_RAGEMASSREDUCTION = 91;
		static const auto MOD_TYPE_REPAIRDEPLOYABLERATEPCT = 92;
		ADD_STRUCT(ScriptString*, DiamondSwordFlagAbandoned, 472)
		ADD_STRUCT(ScriptString*, BloodEagleFlagAbandoned, 460)
		ADD_STRUCT(ScriptString*, DiamondSwordFlagDropped, 448)
		ADD_STRUCT(ScriptString*, BloodEagleFlagDropped, 436)
		ADD_STRUCT(ScriptString*, DiamondSwordFlagReturned, 424)
		ADD_STRUCT(ScriptString*, BloodEagleFlagReturned, 412)
		ADD_STRUCT(ScriptString*, DiamondSwordFlagCaptured, 400)
		ADD_STRUCT(ScriptString*, BloodEagleFlagCaptured, 388)
		ADD_STRUCT(ScriptString*, DiamondSwordFlagPickupAwayFromBase, 376)
		ADD_STRUCT(ScriptString*, BloodEagleFlagPickupAwayFromBase, 364)
		ADD_STRUCT(ScriptString*, DiamondSwordFlagTaken, 352)
		ADD_STRUCT(ScriptString*, BloodEagleFlagTaken, 340)
		ADD_STRUCT(ScriptString*, FriendlyFlagAbandoned, 328)
		ADD_STRUCT(ScriptString*, EnemyFlagAbandoned, 316)
		ADD_STRUCT(ScriptString*, FriendlyFlagDropped, 304)
		ADD_STRUCT(ScriptString*, EnemyFlagDropped, 292)
		ADD_STRUCT(ScriptString*, FriendlyFlagReturned, 280)
		ADD_STRUCT(ScriptString*, EnemyFlagReturned, 268)
		ADD_STRUCT(ScriptString*, FriendlyFlagCaptured, 256)
		ADD_STRUCT(ScriptString*, EnemyFlagCaptured, 244)
		ADD_STRUCT(ScriptString*, FriendlyFlagPickupAwayFromBase, 232)
		ADD_STRUCT(ScriptString*, EnemyFlagPickupAwayFromBase, 220)
		ADD_STRUCT(ScriptString*, FriendlyFlagTaken, 208)
		ADD_STRUCT(ScriptString*, EnemyFlagTaken, 196)
		ADD_OBJECT(SoundCue, m_sBECapturedDSFlag, 192)
		ADD_OBJECT(SoundCue, m_sDSCapturedBEFlag, 188)
		ADD_OBJECT(SoundCue, m_sBETookDSFlag, 184)
		ADD_OBJECT(SoundCue, m_sDSTookBEFlag, 180)
		ADD_OBJECT(SoundCue, m_sBEFlagSecured, 176)
		ADD_OBJECT(SoundCue, m_sDSFlagSecured, 172)
		ADD_OBJECT(SoundCue, m_sBELostDSFlag, 168)
		ADD_OBJECT(SoundCue, m_sDSLostBEFlag, 164)
		ADD_OBJECT(SoundCue, m_sDSFlagCaptured, 160)
		ADD_OBJECT(SoundCue, m_sDSFlagTaken, 156)
		ADD_OBJECT(SoundCue, m_sBEFlagCaptured, 152)
		ADD_OBJECT(SoundCue, m_sBEFlagTaken, 148)
		ADD_OBJECT(SoundNodeWave, m_CapturedSounds, 136)
		ADD_OBJECT(SoundNodeWave, m_TakenSounds, 124)
		ADD_OBJECT(SoundNodeWave, m_DroppedSounds, 112)
		ADD_OBJECT(SoundNodeWave, m_ReturnSounds, 100)
		ScriptString* GetString(int Switch, bool bPRI1HUD, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78867);
			byte params[32] = { NULL };
			*(int*)params = Switch;
			*(bool*)&params[4] = bPRI1HUD;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)&params[20];
		}
		void ClientReceive(class PlayerController* P, int Switch, class PlayerReplicationInfo* RelatedPRI_1, class PlayerReplicationInfo* RelatedPRI_2, class Object* OptionalObject)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(78876);
			byte params[20] = { NULL };
			*(class PlayerController**)params = P;
			*(int*)&params[4] = Switch;
			*(class PlayerReplicationInfo**)&params[8] = RelatedPRI_1;
			*(class PlayerReplicationInfo**)&params[12] = RelatedPRI_2;
			*(class Object**)&params[16] = OptionalObject;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
#undef ADD_STRUCT
#undef ADD_OBJECT
