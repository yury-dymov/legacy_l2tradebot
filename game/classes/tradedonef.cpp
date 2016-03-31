#include "gamefunc.h"

void GameF::tradeDone (const string & pck, int * ret)
{
	*ret = DataFunc::stringToInt (pck, 1);
}
