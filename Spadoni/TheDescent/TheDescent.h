#pragma once

#include <string>
#include <vector>
#include "../CodinGameMain/IGame.h"

class TheDescent : public IGame
{
public:
	__declspec(dllexport) TheDescent(std::string filePath);
	__declspec(dllexport) void Execute() override;
	__declspec(dllexport) virtual ~TheDescent();
private:
	std::vector<int> _mountains;
};

