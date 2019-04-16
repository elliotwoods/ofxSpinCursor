#pragma once

#include "ofMain.h"

#define OFXSPINCURSOR_PETAL_COUNT 8
#define OFXSPINCURSOR_PERIOD 10.0f

class ofxSpinCursor {
public:
	static void draw(const glm::vec2 &);
	static void draw(float x, float y);
};