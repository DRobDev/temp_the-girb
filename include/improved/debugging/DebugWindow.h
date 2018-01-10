////////////////////////////
// debug window
// displays float... on screen
///////////////////////////

#pragma once
#include "tools\vec2.h"
#include <vector>

class DebugWindow
{
private:
	//debug window accessor
	static DebugWindow* debugWindowInstance;


	//c	ounts number of watched floats
	static int watchedCounterFloat;
	//watched floats
	static std::vector<float*> watchedFloats;
	//watched names
	static std::vector<const char*> watchedFloatNames;

	//count the number of watched bools
	static int watchedCounterBool;
	//watched bools
	static std::vector<bool*> watchedBools;
	//watched bool names
	static std::vector<const char*> watchedBoolNames;


	//text position in debug window
	const float lineHeight; const float margin; const float valueOffset;
	//width of debug window
	const float windowWidth;
	//bottom left position
	Vec2 position;
	//siez in pixels
	Vec2 size;

	//constructor
	DebugWindow();

	//get's top right position of window
	Vec2 GetTopRight();


public:
	//draws line
	void DrawLine(Vec2 a_start, Vec2 a_end);
	//draws box out of lines
	void DrawBox(Vec2 a_lowerLeft, Vec2 a_upperRight);

	//get instance of window
	static DebugWindow* GetInstance();

	//adds an element to watch in the debug window
	static void AddAWatcher(float* a_watchFloat, const char* a_name);
	//adds a bool element to watch in debug
	static void AddAWatcher(bool* a_watchBool, const char* a_name);

	//set position of lower left corner
	void SetPosition(Vec2 a_pos);
	//draws debug window to screen
	void DrawWindow();
};


