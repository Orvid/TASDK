#pragma once
namespace UnrealScript
{
	class FileWriter;
}
#include "Core.Object.Pointer.h"
#include "Engine.FileWriter.FWFileType.h"
#include "Engine.Info.h"
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
namespace UnrealScript
{
	class FileWriter : public Info
	{
	public:
		typedef FileWriter__FWFileType FWFileType;
		ADD_STRUCT(Object__Pointer, ArchivePtr, 476)
		ADD_STRUCT(ScriptString*, Filename, 480)
		ADD_STRUCT(FileWriter__FWFileType, FileType, 492)
		ADD_BOOL(bFlushEachWrite, 496, 0x1)
		ADD_BOOL(bWantsAsyncWrites, 496, 0x2)
		bool OpenFile(ScriptString* InFilename, FileWriter__FWFileType InFileType, ScriptString* InExtension, bool bUnique, bool bIncludeTimeStamp)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15707);
			byte params[37] = { NULL };
			*(ScriptString**)params = InFilename;
			*(FileWriter__FWFileType*)&params[12] = InFileType;
			*(ScriptString**)&params[16] = InExtension;
			*(bool*)&params[28] = bUnique;
			*(bool*)&params[32] = bIncludeTimeStamp;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
			return *(bool*)&params[36];
		}
		void CloseFile()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15714);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Logf(ScriptString* logString)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15715);
			byte params[12] = { NULL };
			*(ScriptString**)params = logString;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
		void Destroyed()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(15717);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
	};
}
#undef ADD_BOOL
#undef ADD_STRUCT
