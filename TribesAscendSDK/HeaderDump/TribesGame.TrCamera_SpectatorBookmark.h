#pragma once
#include "Engine.CameraActor.h"
#include "TribesGame.TrCamera_SpectatorBookmark.ESpectatorBookmark.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	class TrCamera_SpectatorBookmark : public CameraActor
	{
	public:
		ADD_STRUCT(TrCamera_SpectatorBookmark__ESpectatorBookmark, m_BookmarkDescription, 1416)
		ADD_STRUCT(ScriptString*, BEBase, 720)
		ADD_STRUCT(ScriptString*, GenericCamera, 1404)
		ADD_STRUCT(ScriptString*, BTTunnelWest, 1392)
		ADD_STRUCT(ScriptString*, BTTunnelEast, 1380)
		ADD_STRUCT(ScriptString*, BTBaseInterior, 1368)
		ADD_STRUCT(ScriptString*, BTBase, 1356)
		ADD_STRUCT(ScriptString*, NKMountainSide, 1344)
		ADD_STRUCT(ScriptString*, NKMountainView, 1332)
		ADD_STRUCT(ScriptString*, NKWhalebones, 1320)
		ADD_STRUCT(ScriptString*, NKTunnel, 1308)
		ADD_STRUCT(ScriptString*, NKTower, 1296)
		ADD_STRUCT(ScriptString*, XFDSCRoom, 1284)
		ADD_STRUCT(ScriptString*, XFBECRoom, 1272)
		ADD_STRUCT(ScriptString*, XFDSBackstop, 1260)
		ADD_STRUCT(ScriptString*, XFBEBackstop, 1248)
		ADD_STRUCT(ScriptString*, XFDSBlue, 1236)
		ADD_STRUCT(ScriptString*, XFBEBlue, 1224)
		ADD_STRUCT(ScriptString*, XFDSRed, 1212)
		ADD_STRUCT(ScriptString*, XFBERed, 1200)
		ADD_STRUCT(ScriptString*, XFRSW, 1188)
		ADD_STRUCT(ScriptString*, XFBSW, 1176)
		ADD_STRUCT(ScriptString*, DNFish, 1164)
		ADD_STRUCT(ScriptString*, DdDSBackEntrance, 1152)
		ADD_STRUCT(ScriptString*, DdBEBackEntrance, 1140)
		ADD_STRUCT(ScriptString*, DdDSBunker, 1128)
		ADD_STRUCT(ScriptString*, DdBEBunker, 1116)
		ADD_STRUCT(ScriptString*, DdDockLow, 1104)
		ADD_STRUCT(ScriptString*, DdDockHigh, 1092)
		ADD_STRUCT(ScriptString*, DdDSWide, 1080)
		ADD_STRUCT(ScriptString*, DdBEWide, 1068)
		ADD_STRUCT(ScriptString*, DdDryLow, 1056)
		ADD_STRUCT(ScriptString*, DdDryHigh, 1044)
		ADD_STRUCT(ScriptString*, TDMMapOverhead, 1032)
		ADD_STRUCT(ScriptString*, TDMCenter, 1020)
		ADD_STRUCT(ScriptString*, TDMSouth, 1008)
		ADD_STRUCT(ScriptString*, TDMNorth, 996)
		ADD_STRUCT(ScriptString*, TDMWest, 984)
		ADD_STRUCT(ScriptString*, TDMEast, 972)
		ADD_STRUCT(ScriptString*, CTFDSBackRoute, 960)
		ADD_STRUCT(ScriptString*, CTFBEBackRoute, 948)
		ADD_STRUCT(ScriptString*, CTFDSTurretC, 936)
		ADD_STRUCT(ScriptString*, CTFDSTurretB, 924)
		ADD_STRUCT(ScriptString*, CTFDSTurretA, 912)
		ADD_STRUCT(ScriptString*, CTFBETurretC, 900)
		ADD_STRUCT(ScriptString*, CTFBETurretB, 888)
		ADD_STRUCT(ScriptString*, CTFBETurretA, 876)
		ADD_STRUCT(ScriptString*, CTFDSSensor, 864)
		ADD_STRUCT(ScriptString*, CTFBESensor, 852)
		ADD_STRUCT(ScriptString*, CTFDSSpawn, 840)
		ADD_STRUCT(ScriptString*, CTFBESpawn, 828)
		ADD_STRUCT(ScriptString*, CTFDSVehiclePad, 816)
		ADD_STRUCT(ScriptString*, CTFBEVehiclePad, 804)
		ADD_STRUCT(ScriptString*, CTFDSMidfield, 792)
		ADD_STRUCT(ScriptString*, CTFBEMidfield, 780)
		ADD_STRUCT(ScriptString*, CTFMapOverhead, 768)
		ADD_STRUCT(ScriptString*, CTFDSGeneratorRoom, 756)
		ADD_STRUCT(ScriptString*, CTFBEGeneratorRoom, 744)
		ADD_STRUCT(ScriptString*, DSBase, 732)
		ScriptString* GetDescription()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74224);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
		ScriptString* GetSpectatorName()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(74226);
			byte params[12] = { NULL };
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(ScriptString**)params;
		}
	};
}
#undef ADD_STRUCT
