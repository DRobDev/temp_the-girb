#include "debugging/DebugWindow.h"
#include "TheGirb.h"

#include <string>
#include <sstream>

DebugWindow* DebugWindow::debugWindowInstance = nullptr;

int DebugWindow::watchedCounterFloat = 0;
int DebugWindow::watchedCounterBool = 0;

std::vector<float*> DebugWindow::watchedFloats = std::vector<float*>();
std::vector<bool*> DebugWindow::watchedBools = std::vector<bool*>();

std::vector<const char*> DebugWindow::watchedFloatNames = std::vector<const char*>();
std::vector<const char*> DebugWindow::watchedBoolNames = std::vector<const char*>();

DebugWindow::DebugWindow()
	: lineHeight(30), windowWidth(400), margin(5), valueOffset(180)
{
	position = Vec2(10,10);
	size = Vec2();
	AddFont("./fonts/arial.fnt");
	SetFont("./fonts/arial.fnt");
}

Vec2 DebugWindow::GetTopRight()
{
	return Vec2(position + size);
}

void DebugWindow::DrawLine(Vec2 a_start, Vec2 a_end)
{
	_AIE_H_::DrawLine(static_cast<int>(a_start.x), static_cast<int>(a_start.y), static_cast<int>(a_end.x), static_cast<int>(a_end.y));
}

void DebugWindow::DrawBox(Vec2 a_lowerLeft, Vec2 a_upperRight)
{
	DrawLine(a_lowerLeft, Vec2(a_lowerLeft.x, a_upperRight.y)); //left line
	DrawLine(Vec2(a_lowerLeft.x,  a_upperRight.y), a_upperRight); //top line
	DrawLine(a_upperRight, Vec2(a_upperRight.x, a_lowerLeft.y)); //right line
	DrawLine(Vec2(a_upperRight.x, a_lowerLeft.y), a_lowerLeft);//bottom line
}



//public

DebugWindow* DebugWindow::GetInstance()
{
	if(debugWindowInstance == nullptr)
	{ debugWindowInstance = new DebugWindow(); }
	return debugWindowInstance;
}

void DebugWindow::AddAWatcher(float* a_watchFloat, const char* a_name)
{
	watchedCounterFloat++;
	watchedFloats.push_back(a_watchFloat);
	watchedFloatNames.push_back(a_name);
}

void DebugWindow::AddAWatcher(bool* a_watchBool, const char* a_name)
{
	watchedCounterBool++;
	watchedBools.push_back(a_watchBool);
	watchedBoolNames.push_back(a_name);
}

void DebugWindow::SetPosition(Vec2 a_pos)
{
	position = a_pos;
}

void DebugWindow::DrawWindow()
{
	//draw window based on watcher size
	size.y = (watchedCounterFloat * lineHeight) + (watchedCounterBool * lineHeight);
	size.x = windowWidth;
	DrawBox(position, position + size);
	DrawLine(Vec2(position.x + size.x - valueOffset,  position.y), Vec2(position.x + size.x - valueOffset, position.y + size.y));

	std::string m_watch;

	float m_lastLineHight = position.y + lineHeight;
	float m_startTextX = position.x + margin;
	float m_startValueX = position.x + margin + size.x - valueOffset;

	//populate window with float watchers
	for (int i = 0; i < watchedCounterFloat; i++)
	{
		std::stringstream ss = std::stringstream();
		DrawString(watchedFloatNames[i],m_startTextX, m_lastLineHight);//draw text for watcher
		ss << *watchedFloats[i];
		m_watch = ss.str();
		DrawString(m_watch.c_str(), m_startValueX, m_lastLineHight); 
		DrawLine(Vec2(position.x, m_lastLineHight), Vec2(position.x + size.x, m_lastLineHight)); //underline for clarity
		m_lastLineHight += lineHeight;
	}

	//populate window with bool watchers
	for (int i = 0; i < watchedCounterBool; i++)
	{
		std::stringstream ss = std::stringstream();
		DrawString(watchedBoolNames[i],m_startTextX, m_lastLineHight);//draw text for watcher
		ss << *watchedBools[i];
		m_watch = ss.str();
		DrawString(m_watch.c_str(), m_startValueX, m_lastLineHight); 
		DrawLine(Vec2(position.x, m_lastLineHight), Vec2(position.x + size.x, m_lastLineHight)); //underline for clarity
		m_lastLineHight += lineHeight;
	}
}


