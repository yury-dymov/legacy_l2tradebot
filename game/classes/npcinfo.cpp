#include "gamefunc.h"

Npc GameF::npcInfo (const string & str)
{
	// 0 - packet id
	// 1 - object id
	// 5 - npc id
	// 9 - attackable
	// 13 - x
	// 17 - y
	// 21 - z
	// 41 - run speed
	// 45 - walk speed
	// 118 - isRun
	Npc ret;
	ret.setObjectId (DataFunc::stringToInt (str, 1));
	ret.setNpcId (DataFunc::stringToInt (str, 5));
	ret.setAttackable (DataFunc::stringToInt (str, 9));
	ret.setPos (CatXPoint (DataFunc::stringToInt (str, 13), DataFunc::stringToInt (str, 17), DataFunc::stringToInt (str, 21)));
	ret.setSpeed (DataFunc::stringToInt (str, 41));
	ret.setWalkSpeed (DataFunc::stringToInt (str, 45));
	ret.setIsRun (str [118]);
	return ret;
}
