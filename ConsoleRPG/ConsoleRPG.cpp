#include <iostream>
#include "GameManager.h"
#include "Character.h"

int main()
{
    Character* character = new Character("한정혁");

    character->DisplayStatus();

    HealPotion* itemHeal = new HealPotion("하급 힐 포션", 30);
    AttackPowerUp* itemPowerUp = new AttackPowerUp("하급 공격력 업 포션", 30);

    character->TakeItem(itemHeal);
    character->TakeItem(itemHeal);

    character->TakeItem(itemPowerUp);
    //HealPotion* itemHeal2 = new HealPotion("중급 힐 포션", 50);
    //HealPotion* itemHeal3 = new HealPotion("상급 힐 포션", 50);
    delete itemHeal;
    delete itemPowerUp;

    return 0;
}

