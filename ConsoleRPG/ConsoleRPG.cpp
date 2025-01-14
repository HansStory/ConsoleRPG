#include <iostream>
#include "GameManager.h"
#include "Character.h"

int main()
{
    Character* character = new Character("������");

    character->DisplayStatus();

    HealPotion* itemHeal = new HealPotion("�ϱ� �� ����", 30);
    AttackPowerUp* itemPowerUp = new AttackPowerUp("�ϱ� ���ݷ� �� ����", 30);

    character->TakeItem(itemHeal);
    character->TakeItem(itemHeal);

    character->TakeItem(itemPowerUp);
    //HealPotion* itemHeal2 = new HealPotion("�߱� �� ����", 50);
    //HealPotion* itemHeal3 = new HealPotion("��� �� ����", 50);
    delete itemHeal;
    delete itemPowerUp;

    return 0;
}

