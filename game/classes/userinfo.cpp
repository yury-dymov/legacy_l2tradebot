#include "gamefunc.h"

User GameF::userInfo (const string & pck)
{
	User ret;
	// 0 - packet id
	// 1 - x
	// 5 - y
	// 9 - z
	// 13 - heading
	// 17 - object id
	// 21 - name
	ret.setPos (CatXPoint (DataFunc::stringToInt (pck, 1), DataFunc::stringToInt (pck, 5), DataFunc::stringToInt (pck, 9)));
	ret.setObjectId (DataFunc::stringToInt (pck, 17));
	int length = 2;
	string name;
	for (unsigned int i = 21; pck [i] != 0x00; i += 2)
	{
		length += 2;
		name += pck[i];
	}
	ret.setName (name);
	ret.setSpeed (DataFunc::stringToInt (pck, 353 + length));
	ret.setWalkSpeed (DataFunc::stringToInt (pck, 357 + length));
	ret.setIsRun (pck[length + 529]);
	return ret;
}
