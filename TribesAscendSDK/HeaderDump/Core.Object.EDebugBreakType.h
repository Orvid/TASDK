#pragma once
namespace UnrealScript
{
	enum Object__EDebugBreakType : byte
	{
		DEBUGGER_NativeOnly = 0,
		DEBUGGER_ScriptOnly = 1,
		DEBUGGER_Both = 2,
		DEBUGGER_MAX = 3,
	};
}
