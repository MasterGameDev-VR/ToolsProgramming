#pragma once
#include <string>

using namespace std;

#ifdef GAMEOFLIFE_EXPORTS
#define GAMEOFLIFE_API __declspec(dllexport)
#else
#define GAMEOFLIFE_API __declspec(dllimport)
#endif

extern "C" GAMEOFLIFE_API void ConstructTest(const string INPUT_FILENAME);
//extern "C" GAMEOFLIFE_API void ConstructTest(const char* INPUT_FILENAME);
extern "C" GAMEOFLIFE_API void ExecuteTest();
extern "C"  GAMEOFLIFE_API void ReleaseTest();