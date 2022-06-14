#pragma once
#include"CheckArrow.h"
#include"Namespace.h"
using namespace std;
class Jump {
	int fpscouter = 0;
	bool check = 1;
public:
	
	void GetObject(Arrows &object)
	{
		//object.Hero_obj_right.HeroPos = object.Hero_obj_left.HeroPos;
		if (object.UpHero and object.LeftHero)
		{
			
			if (object.Hero_obj_left.HeroPos.y >= object.state - 60 and check)
			{
				object.Hero_obj_left.HeroPos.y -= 1;
				object.Hero_obj_right.HeroPos = object.Hero_obj_left.HeroPos;
				object.Hero_obj_left.DrawLeft();
			}
			else{
				check = 0;
				if (!(object.Hero_obj_left.HeroPos.y == object.state))
				{
					object.Hero_obj_left.HeroPos.y += 1;
					object.Hero_obj_right.HeroPos = object.Hero_obj_left.HeroPos;
					object.Hero_obj_left.DrawLeft();
				}
				else {
					object.UpHero = 0;
					check = 1;
					help::finish = 0;
					object.Hero_obj_right.HeroPos = object.Hero_obj_left.HeroPos;
				}
			}
			
				
			
			
		}
		else if (object.UpHero and object.RightHero)
		{

			if (object.Hero_obj_right.HeroPos.y >= object.state - 60 and check)
			{
				object.Hero_obj_right.HeroPos.y -= 1;
				object.Hero_obj_left.HeroPos = object.Hero_obj_right.HeroPos;
				object.Hero_obj_right.DrawRight();
			}
			else {
				check = 0;
				if (!(object.Hero_obj_right.HeroPos.y == object.state))
				{
					object.Hero_obj_right.HeroPos.y += 1;
					object.Hero_obj_left.HeroPos = object.Hero_obj_right.HeroPos;
					object.Hero_obj_right.DrawRight();
				}
				else {
					object.UpHero = 0;
					check = 1;
					help::finish = 0;
					object.Hero_obj_left.HeroPos = object.Hero_obj_right.HeroPos;
				}
			}
		}
	}
};