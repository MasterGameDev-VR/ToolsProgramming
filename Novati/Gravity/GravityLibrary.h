#pragma once
#include <string>

using namespace std;

#ifdef GRAVITY_EXPORTS
#define GRAVITY_API __declspec(dllexport)
#else
#define GRAVITY_API __declspec(dllimport)
#endif

extern "C" GRAVITY_API void ConstructTest(const string INPUT_FILENAME);
//extern "C" GAMEOFLIFE_API void ConstructTest(const char* INPUT_FILENAME);
extern "C" GRAVITY_API void ExecuteTest();
extern "C"  GRAVITY_API void ReleaseTest();