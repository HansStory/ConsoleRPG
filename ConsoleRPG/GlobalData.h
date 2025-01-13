#pragma once

enum ECharacterClass
{
	Warrior = 0,
	Knight,
	Mage,
	Rogue,
};

enum EItem
{
	LowPotion = 0,
	HalfPotion,
	FullPotion,

	LowElixir,
	MiddleElixir,
	HightElixir,
	
	LowDamageBuff,
	MiddleDamageBuff,
	HighDamageBuff,
};

enum EquipmentType
{
	Weapone = 0,
	Armor,
};

#include "Singleton.h"
class GlobalData : public Singleton<GlobalData>
{
public:

	EItem EItem;
	ECharacterClass ECharacterClass;
private:
	friend class Singleton<GlobalData>;
	GlobalData();
	~GlobalData();

};
