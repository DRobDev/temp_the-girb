#include "elements\Drawer.h"

#include "TheGirb.h"

//static variables
std::list<int*> Drawer::top = std::list<int*>();
std::list<int*> Drawer::mid = std::list<int*>();
std::list<int*> Drawer::back = std::list<int*>();

//single instance
Drawer::Drawer()
{

}

void Drawer::DrawGame()
{
	//clears last screen
	ClearScreen();

	//draws sprites in order of thier priority group (top drawn on top)
	for(auto i = back.begin(); i != back.end(); i++)
	{
		DrawSprite(**i);
	}
	for(auto i = mid.begin(); i != mid.end(); i++)
	{
		DrawSprite(**i);
	}
	for(auto i = top.begin(); i != top.end(); i++)
	{
		DrawSprite(**i);
	}
}


//static
void Drawer::AddSpriteToDraw(int& a_idR, DrawPriority a_priority)
{
	switch (a_priority)
	{
	case Drawer::TOP:
		top.push_back(&a_idR);
		break;
	case Drawer::MID:
		mid.push_back(&a_idR);
		break;
	case Drawer::BACK:
		back.push_back(&a_idR);
		break;
	}
}

void Drawer::RemoveSpriteFromDrawer(int& a_idR, DrawPriority a_spritePriority)
{
	switch (a_spritePriority)
	{
	case Drawer::TOP:
		top.remove(&a_idR);
		break;
	case Drawer::MID:
		mid.remove(&a_idR);
		break;
	case Drawer::BACK:
		back.remove(&a_idR);
		break;
	}
}

Drawer::~Drawer()
{
}