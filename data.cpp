#include "data.h"

SellWidget * Data::sellWidget_;
BuyWidget * Data::buyWidget_;
vector <InventoryItem> Data::bag;

void Data::init ()
{
	sellWidget_ = new SellWidget ();
	buyWidget_ = new BuyWidget ();
	Dat::init ();
}

SellWidget * Data::sellWidget ()
{
	return sellWidget_;
}

BuyWidget * Data::buyWidget ()
{
	return buyWidget_;
}


