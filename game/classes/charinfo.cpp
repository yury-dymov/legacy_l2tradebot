#include "gamefunc.h"

Char GameF::charInfo (const string & pck)
{
	Char ret;
	// 0 - packet id
	// 1 - x
	// 5 - y
	// 9 - z
	// 13 - heading
	// 17 - object id
	// 21 - name
	// x + 21 - race
	// x + 25 - sex
	// x + 29 - classid
	// x + 33 - hair
	// x + 37 - head
	// x + 41 - rhand
	// x + 45 - lhand
	// x + 49 - gloves
	// x + 53 - chest
	// x + 57 - legs
	// x + 61 - feet
	// x + 65 - back
	// x + 69 - lrhand
	// x + 73 - hair
	// x + 77 - face
	// x + 81 - z
	// x + 129 - pvpflag
	// x + 133 - karma
	// x + 137 - mspeed
	// x + 141 - pspeed
	// x + 145 - pvpflag
	// x + 149 - karma
	// x + 153 - speed
	// x + 157 - walk speed
	// x + 252 - isrun
	int x = DataFunc::stringToInt (pck, 1);
	int y = DataFunc::stringToInt (pck, 5);
	int z = DataFunc::stringToInt (pck, 9);
	ret.setPos (CatXPoint (x, y, z));
	ret.setObjectId (DataFunc::stringToInt (pck, 17));
	int length = 2;
	string name;
	for (unsigned int i = 21; pck [i] != 0x00; i += 2)
	{
		length += 2;
		name += pck[i];
	}
	ret.setName (name);
	ret.setSpeed (DataFunc::stringToInt (pck, 153 + length));
	ret.setIsRun (pck [252 + length]);
	ret.setShop (pck [257 + length]);
	return ret;
}
