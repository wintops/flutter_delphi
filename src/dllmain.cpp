// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"

#define MY_DLL
#include "MyDll.h"
#include <windows.h>
#undef CreateWindow

#include <iostream>
#include <string>
#include <vector>

#include "flutter_window_controller.h"
// Include windows.h last, to minimize potential conflicts. The CreateWindow
// macro needs to be undefined because it prevents calling
// FlutterWindowController's method.


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

// namespace {

// Returns the path of the directory containing this executable, or an empty
// string if the directory cannot be found.
std::string GetExecutableDirectory() {
  char buffer[MAX_PATH];
  if (GetModuleFileName(nullptr, buffer, MAX_PATH) == 0) {
    std::cerr << "Couldn't locate executable" << std::endl;
    return "";
  }
  std::string executable_path(buffer);
  size_t last_separator_position = executable_path.find_last_of('\\');
  if (last_separator_position == std::string::npos) {
    std::cerr << "Unabled to find parent directory of " << executable_path
              << std::endl;
    return "";
  }
  return executable_path.substr(0, last_separator_position);
}

//}  // namespace




MYDLL_API int start() 
{ 
	  // Resources are located relative to the executable.
  std::string base_directory = GetExecutableDirectory();
  if (base_directory.empty()) {
    base_directory = ".";
  }
  std::string data_directory = base_directory + "\\data";
  std::string assets_path = data_directory + "\\flutter_assets";
  std::string icu_data_path = data_directory + "\\icudtl.dat";

  // Arguments for the Flutter Engine.
  std::vector<std::string> arguments;

  flutter::FlutterWindowController flutter_controller(icu_data_path);

  // Start the engine.
  if (!flutter_controller.CreateWindow(800, 600, "Flutter Desktop Example",
                                       assets_path, arguments)) {
    return EXIT_FAILURE;
  }

  // Run until the window is closed.
  flutter_controller.RunEventLoop();
  return EXIT_SUCCESS;
}




