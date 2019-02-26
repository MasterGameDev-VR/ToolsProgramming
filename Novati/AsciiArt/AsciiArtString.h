#pragma once
#include "stdafx.h"
#include "Letter.h"

namespace AsciiArt {

	class AsciiArtString {
	protected:
		Letter a;
		Letter b;
		Letter c;
		Letter d;
		Letter e;
		Letter f;
		Letter g;
		Letter h;
		Letter i;
		Letter j;
		Letter k;
		Letter l;
		Letter m;
		Letter n;
		Letter o;
		Letter p;
		Letter q;
		Letter r;
		Letter s;
		Letter t;
		Letter u;
		Letter v;
		Letter w;
		Letter x;
		Letter y;
		Letter z;
		Letter qm;
		int _L;
		int _H;
		std::string _T;
		std::vector<std::string> _INPUT_ROWS;

	public:
		AsciiArtString(int L, int H, std::string T, std::vector<std::string> value);
		virtual ~AsciiArtString();
		virtual void print();
		virtual void parse();
	};
}
