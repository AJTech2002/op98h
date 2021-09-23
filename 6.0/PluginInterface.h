#pragma once

#define CLO_SDK_VERSION "3.0.2"

#ifdef BOMAPIDLL_EXPORTS

#if defined(__APPLE__)
#define CLO_PLUGIN_SPECIFIER
#else
#define CLO_PLUGIN_SPECIFIER __declspec(dllexport)
#endif

#else

#if defined(__APPLE__)
#define CLO_PLUGIN_SPECIFIER
#else
#define CLO_PLUGIN_SPECIFIER __declspec(dllimport)
#endif

#endif

extern "C"
{
	extern CLO_PLUGIN_SPECIFIER void DoFunction();
    extern CLO_PLUGIN_SPECIFIER void DoFunctionStartUp();
	extern CLO_PLUGIN_SPECIFIER void DoFunctionAfterLoadingCLOFile(const char* fileExtenstion); // ascii
	extern CLO_PLUGIN_SPECIFIER const char* GetActionName();
	extern CLO_PLUGIN_SPECIFIER const char* GetObjectNameTreeToAddAction();
	extern CLO_PLUGIN_SPECIFIER int GetPositionIndexToAddAction();

	extern CLO_PLUGIN_SPECIFIER void CallbackFromWebKit(int argc, char** argv); // ?
}
