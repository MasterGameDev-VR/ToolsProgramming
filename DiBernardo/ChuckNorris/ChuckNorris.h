#pragma once

#pragma once

#pragma once
#include <string>

#ifdef CHUCKNORRIS_EXPORTS
#define DLLDIR  __declspec(dllexport) 

#else
#define DLLDIR  __declspec(dllimport) 

#endif

class DLLDIR ChuckNorris {

public:
	ChuckNorris(std::string fileName);

	void Execute();

private:

	std::string m_fileName;
};