#ifndef ENUM_COLLECTION_H
#define ENUM_COLLECTION_H

namespace Enums
{
	enum LogEnum { Menu, Start, GameOver, GameEnd };
	enum PrintEnum { BattlePrint, StatusPrint, ShopRoomPrint, RestRoomPrint, BuffDebuffRoomPrint };

	enum ItemType
	{
		None = 0,
		Equipable,
		Consumable,
		Passive,
	};

}

#endif