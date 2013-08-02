#pragma once
namespace UnrealScript
{
	class dsWebAdmin;
}
#include "IpDrv.WebApplication.h"
#include "IpDrv.WebRequest.h"
#include "IpDrv.WebResponse.h"
namespace UnrealScript
{
	class dsWebAdmin : public WebApplication
	{
	public:
		void Init()
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(51012);
			((ScriptObject*)this)->ProcessEvent(function, NULL, NULL);
		}
		void Query(class WebRequest* Request, class WebResponse* Response)
		{
			static ScriptFunction* function = (ScriptFunction*)(*ScriptObject::object_array())(51013);
			byte params[8] = { NULL };
			*(class WebRequest**)params = Request;
			*(class WebResponse**)&params[4] = Response;
			((ScriptObject*)this)->ProcessEvent(function, &params, NULL);
		}
	};
}
