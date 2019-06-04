#pragma once
#ifndef _MY_DLL_H_
#define _MY_DLL_H_

#if defined MY_DLL
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif

extern "C" {
MYDLL_API int start();
}
#endif