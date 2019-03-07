#pragma once
#include "stdafx.h"
#include "Letter.h"

using namespace std;

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
		string _T;
		vector<string> _INPUT_ROWS;

	public:
		AsciiArtString(int L, int H, string T, vector<string> INPUT_ROWS);
		virtual ~AsciiArtString();
		virtual void print();
		virtual void parse();
	};
}
