#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <string>
#include <vector>
#include "Item.h"
#include <map>

using namespace std;

enum EquipmentType
{
	Weapone = 0,
	Armor,
};

enum ItemType
{
	None = 0,
	Equipable,
	Consumable,
	Passive,
};

class Inventory
{
public:
	Inventory() : Item(nullptr), Count(0) {}
	Inventory(class Item* item, int count) : Item(item), Count(count) {}

	class Item* Item = nullptr;
	enum ItemType ItemType;
	int Count = 0;
};

class Character
{
	//friend class Item;
public:
	//Character();
	Character(const string& name);
	~Character();

	void DisplayStatus();
	string GetName();
	string GetCharacterStatusString();

	const int& GetAcctackPower();
	const int& GetGold();
	map<string, class Inventory> GetInventory();

	//map<EquipmentType, int> GetEquipmentItems();

	void UseItem(const string& itemKey);

	void TakeExp(const int& exp);
	void TakeGold(const int& gold);
	
	void TakeItem(class Item* item);
	//void TakeItem(const int& equipmentKey);

	void TakeDamage(const int& damage);

	int attackPower = 10;
	int currentHP = 100;

private:
	string name = "";
	int level = 1;
	int maxHP = 100;
	int gold = 0;
	int currentExp = 0;
	int requiredLevelUpExp = 100;

	int maxLevel = 10;

	map<EquipmentType, int> equipmentItems;
	map<string, class Inventory> inventory;
	vector<class Item> itemInventory;

	void LevelUp();
	void IncreaseMaxHP(const int& level);
	void IncreaseAttackPower(const int& level);
	void IncreaseRequireLevelUpExp(const int& level);
};


#endif // !CHARACTER_H_