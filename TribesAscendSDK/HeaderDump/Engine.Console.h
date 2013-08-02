#pragma once
namespace UnrealScript
{
	class Console;
}
#include "Core.Object.Color.h"
#include "Core.Object.EInputEvent.h"
#include "Engine.Canvas.h"
#include "Engine.Console.AutoCompleteCommand.h"
#include "Engine.Console.AutoCompleteNode.h"
#include "Engine.Console.scrollbackData.h"
#include "Engine.Interaction.h"
#include "Engine.LocalPlayer.h"
#include "Engine.Texture2D.h"
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
	class Console : public Interaction
	{
	public:
		typedef Console__scrollbackData scrollbackData;
		typedef Console__AutoCompleteCommand AutoCompleteCommand;
		typedef Console__AutoCompleteNode AutoCompleteNode;
		static const auto MaxHistory = 16;
		ADD_STRUCT(ScriptArray<Console__scrollbackData>, Scrollback, 140)
		ADD_STRUCT(ScriptArray<Console__AutoCompleteCommand>, ManualAutoCompleteList, 384)
		ADD_STRUCT(ScriptArray<Console__AutoCompleteCommand>, AutoCompleteList, 396)
		ADD_STRUCT(ScriptArray<int>, AutoCompleteIndices, 440)
		ADD_STRUCT(Console__AutoCompleteNode, AutoCompleteTree, 412)
		ADD_STRUCT(int, AutoCompleteIndex, 408)
		ADD_STRUCT(int, TypedStrPos, 380)
		ADD_STRUCT(ScriptString*, TypedStr, 368)
		ADD_BOOL(bIsRuntimeAutoCompleteUpToDate, 364, 0x40)
		ADD_BOOL(bRequireCtrlToNavigateAutoComplete, 364, 0x20)
		ADD_BOOL(bAutoCompleteLocked, 364, 0x10)
		ADD_BOOL(bEnableUI, 364, 0x8)
		ADD_BOOL(bCtrl, 364, 0x4)
		ADD_BOOL(bCaptureKeyInput, 364, 0x2)
		ADD_BOOL(bNavigatingHistory, 364, 0x1)
		ADD_STRUCT(ScriptString*, History, 172)
		ADD_STRUCT(int, HistoryCur, 168)
		ADD_STRUCT(int, HistoryBot, 164)
		ADD_STRUCT(int, HistoryTop, 160)
		ADD_STRUCT(int, SBPos, 156)
		ADD_STRUCT(int, SBHead, 152)
		ADD_STRUCT(int, MaxScrollbackSize, 136)
		ADD_STRUCT(ScriptName, TypeKey, 128)
		ADD_STRUCT(ScriptName, ConsoleKey, 120)
		ADD_OBJECT(Texture2D, DefaultTexture_White, 116)
		ADD_OBJECT(Texture2D, DefaultTexture_Black, 112)
		ADD_OBJECT(LocalPlayer, ConsoleTargetPlayer, 108)
		void Initialized()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12982);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void SetInputText(ScriptString* Text)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12983);
			byte params[12] = { NULL };
			*(ScriptString**)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void SetCursorPos(int Position)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12985);
			byte params[4] = { NULL };
			*(int*)params = Position;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PurgeCommandFromHistory(ScriptString* Command)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12987);
			byte params[12] = { NULL };
			*(ScriptString**)params = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ConsoleCommand(ScriptString* Command)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12992);
			byte params[12] = { NULL };
			*(ScriptString**)params = Command;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void ClearOutput()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12996);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void OutputTextLine(ScriptString* Text, Object__Color OverrideColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(12997);
			byte params[16] = { NULL };
			*(ScriptString**)params = Text;
			*(Object__Color*)&params[12] = OverrideColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void OutputText(ScriptString* Text, Object__Color OverrideColor)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13001);
			byte params[16] = { NULL };
			*(ScriptString**)params = Text;
			*(Object__Color*)&params[12] = OverrideColor;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void StartTyping(ScriptString* Text)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13007);
			byte params[12] = { NULL };
			*(ScriptString**)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void PostRender_Console(class Canvas* Canvas)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13009);
			byte params[4] = { NULL };
			*(class Canvas**)params = Canvas;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		bool InputKey(int ControllerId, ScriptName Key, Object__EInputEvent Event, float AmountDepressed, bool bGamepad)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13011);
			byte params[25] = { NULL };
			*(int*)params = ControllerId;
			*(ScriptName*)&params[4] = Key;
			*(Object__EInputEvent*)&params[12] = Event;
			*(float*)&params[16] = AmountDepressed;
			*(bool*)&params[20] = bGamepad;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[24];
		}
		bool InputChar(int ControllerId, ScriptString* Unicode)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13018);
			byte params[20] = { NULL };
			*(int*)params = ControllerId;
			*(ScriptString**)&params[4] = Unicode;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[16];
		}
		void FlushPlayerInput()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13022);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		bool ProcessControlKey(ScriptName Key, Object__EInputEvent Event)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13024);
			byte params[13] = { NULL };
			*(ScriptName*)params = Key;
			*(Object__EInputEvent*)&params[8] = Event;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[12];
		}
		void AppendInputText(ScriptString* Text)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13028);
			byte params[12] = { NULL };
			*(ScriptString**)params = Text;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void BuildRuntimeAutoCompleteList(bool bForce)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13031);
			byte params[4] = { NULL };
			*(bool*)params = bForce;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void UpdateCompleteIndices()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(13033);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
#undef ADD_OBJECT
