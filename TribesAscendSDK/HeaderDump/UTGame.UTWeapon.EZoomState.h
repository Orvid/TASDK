#pragma once
namespace UnrealScript
{
	enum UTWeapon__EZoomState : byte
	{
		ZST_NotZoomed = 0,
		ZST_ZoomingOut = 1,
		ZST_ZoomingIn = 2,
		ZST_Zoomed = 3,
		ZST_MAX = 4,
	};
}
