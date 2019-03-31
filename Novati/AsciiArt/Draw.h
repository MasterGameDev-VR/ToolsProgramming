#pragma once
#include "stdafx.h"

namespace AsciiArt {

	class Draw {
	protected:
		int _W;
		int _H;
	public:
		Draw();
		virtual ~Draw();

		int getWidth() const { return _W; }
		int getHeight() const { return _H; }

		void setWidth(int W) {
			_W = W;
		}

		void setHeight(int H) {
			_H = H;
		}
	};
}