#pragma once
namespace UnrealScript
{
	struct Object__UntypedBulkData_Mirror;
}
#include "Core.Object.Pointer.h"
#define ADD_STRUCT(x, y, offset) \
x get_##y() { return *(x*)(this + offset); } \
void set_##y(x val) { *(x*)(this + offset) = val; } \
__declspec(property(get=get_##y, put=set_##y)) x y;
namespace UnrealScript
{
	struct Object__UntypedBulkData_Mirror
	{
	public:
		ADD_STRUCT(Object__Pointer, VfTable, 0)
		ADD_STRUCT(int, BulkDataFlags, 4)
		ADD_STRUCT(int, ElementCount, 8)
		ADD_STRUCT(int, BulkDataOffsetInFile, 12)
		ADD_STRUCT(int, BulkDataSizeOnDisk, 16)
		ADD_STRUCT(int, SavedBulkDataFlags, 20)
		ADD_STRUCT(int, SavedElementCount, 24)
		ADD_STRUCT(int, SavedBulkDataOffsetInFile, 28)
		ADD_STRUCT(int, SavedBulkDataSizeOnDisk, 32)
		ADD_STRUCT(Object__Pointer, BulkData, 36)
		ADD_STRUCT(int, LockStatus, 40)
		ADD_STRUCT(Object__Pointer, AttachedAr, 44)
		ADD_STRUCT(int, bShouldFreeOnEmpty, 48)
	};
}
#undef ADD_STRUCT
