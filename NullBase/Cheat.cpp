////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Copyright 2018 Null Terminator																								  //
//
Permission is hereby granted, free of charge, to any person																		  //
obtaining a copy of this software and associated documentation                                                                    //
files(the "Software"), to deal in the Software without restriction,                                                               //
including without limitation the rights to use, copy, modify, merge,                                                              //
publish, distribute, sublicense, and/or sell copies of the Software,                                                              //
and to permit persons to whom the Software is furnished to do so,                                                                 //
subject to the following conditions :                                                                                             //
																																  //
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.    //
																																  //
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,																	  //
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF																  //
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.                                                            //
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,                                                       //
DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR                                                             //
OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR                                                             //
THE USE OR OTHER DEALINGS IN THE SOFTWARE.																						  //
*/																																  //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
This base is meant to be used to learn and not for use in CS : GO. This is most likely detected and will get you banned.
*/

#include "Includes.h"

//Flags
#define FL_ON_GROUND                     257
#define FL_ON_GROUND_CROUCHED             263
#define FL_IN_AIR_STAND                    256
#define FL_IN_AIR_MOVING_TO_STAND         258
#define FL_ON_GROUND_MOVING_TO_STAND     259
#define FL_IN_AIR_MOVING_TO_CROUCH         260
#define FL_ON_GROUND_MOVING_TO_CROUCH     261
#define FL_IN_AIR_CROUCHED                 262
#define FL_IN_WATER                     1280
#define FL_IN_PUDDLE                     1281
#define FL_IN_WATER_CROUCHED             1286
#define FL_IN_PUDDLE_CROUCHED             1287
#define FL_PARTIALGROUND (1 << 18)

//Team IDs
#define TEAM_ID_GOTV 1
#define TEAM_ID_T 2
#define TEAM_ID_CT 3

void glowESP(int idx)
{
	auto plr = Entity::getEntBase(idx);

	if (Entity::getEntTeam(plr) != LocalPlayer::getLocalTeam())
	{
		auto gObj = Entity::getGlowObj();
		auto gIdx = Entity::getGlowIndex(plr);

		Entity::glowEsp(gObj, gIdx, 255, 0, 0, 255);
	}
}

void bhop()
{
	//If we're holding space and the we're on the ground
	if (GetAsyncKeyState(VK_SPACE) && LocalPlayer::getLocalFlags() & 0x1)
	{
		//Jump!
		LocalPlayer::forceJump();
	}
}



void trigger()
{
	auto xhair = LocalPlayer::getLocalCrossID();
	if (xhair > -1)
	{
		auto inCross = Entity::getEntBase(xhair - 1);

		if (Entity::getEntTeam(inCross) != LocalPlayer::getLocalTeam())
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			Sleep(25);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
	}
}


int main()
{
	init();
	LocalPlayer::setLocalPlayer();
	
	while (!GetAsyncKeyState(VK_INSERT))
	{
		bhop();
		
		for (int i = 0; i <= 32; i++)
		{
			glowESP(i);
		}
		
		trigger();


	
		Sleep(1);

	}
	
	
	CloseHandle(hProc);
	}

	//Close handle to csgo.exe to prevent memory leaks
	
