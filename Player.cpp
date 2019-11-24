#include <iostream>
#include <cstdlib>
#include <string>

#include "Player.h"
#include "Item.h"

 Player::Player(std::string name, int clas)
{
    //ctor

    if(clas == 1)//Warrior
    {
        setName(name);
        setHP(100);
        setMaxHP(100);
        setATK(8);// Plus 2 stat due to weapon
        setDEF(2);//Plus 12 stat due to armor
        setRES(5);
        setLVL(1);
        exp = 0;
        equipment.setArmor("Iron Armor");
        equipment.setWeapon("Iron Sword");
        equipment.setNumOfPotions(9);
        equipment.setMaxPotionAmount(10);
        givenStats();
    }
    else if(clas == 2)//Wizard
    {
        setName(name);
        setHP(100);
        setMaxHP(100);
        setATK(4);// Plus 10 stat due to weapon
        setDEF(2);//Plus 2 stat due to armor
        setRES(12);
        setLVL(1);
        setEXP(0);
        equipment.setArmor("Magic Robe");
        equipment.setWeapon("Amateur Staff");
        equipment.setNumOfPotions(10);
        equipment.setMaxPotionAmount(10);
        givenStats();
    }
    else if(clas == 3)//Ranger
    {
        setName(name);
        setHP(100);
        setMaxHP(100);
        setATK(2);// Plus 7 stat due to weapon
        setDEF(3);//Plus 3 stat due to armor
        setRES(3);
        setLVL(1);
        setEXP(0);
        equipment.setArmor("Common Cloak");
        equipment.setWeapon("Hunting Bow");
        equipment.setNumOfPotions(10);
        equipment.setMaxPotionAmount(10);
        givenStats();
    }
    else//Thief
    {
        setName(name);
        setHP(100);
        setMaxHP(100);
        setATK(3);// Plus 5 stat due to weapon
        setDEF(2);//Plus 2 stat due to armor
        setRES(3);
        setLVL(1);
        setEXP(0);
        equipment.setArmor("Chain mail");
        equipment.setWeapon("Short sword");
        equipment.setNumOfPotions(10);
        equipment.setMaxPotionAmount(10);
        givenStats();
    }

}
void Player::takeDMG(int monsterATK)
{
    int totalDMG = monsterATK - def;
    if(totalDMG <= 0)
        totalDMG = 0;
    hp -= totalDMG;
    if(hp <= 0)
    {
        cout << "\n*******You died!*******\n";
        cout << "**********\nCreated by: Chuy, Efrain, Julio (If you want dragons, buy the the DLC)\n**********\n";
    }
    else
        cout << "Remaining Player hp: " << hp << endl;
}
void Player::takeMagDMG(int monsterATK)
{
    int totalDMG = monsterATK - res;
    if(totalDMG <= 0)
        totalDMG = 0;
    hp -= totalDMG;
    if(hp <= 0)
    {
        cout << "\n*******You died!*******\n";
        cout << "**********\nCreated by: Chuy, Efrain, Julio (If you want dragons, buy the the DLC)\n**********\n";
    }
    else
        cout << "Remaining Player hp: " << hp << endl;
}
void Player::heal()
{
    if(equipment.getNumOfPotions() == 0)
    {
        cout << "\nYou don't have any potions!\n";
    }
    else
    {
        int totalHeal = hp + 50;

        if(totalHeal > maxHP)
        {
            hp = maxHP;
            equipment.decreasePotionAmount();
        }
        else
        {
            hp = totalHeal;
            equipment.decreasePotionAmount();
        }
    }
}
void Player::displayPlayer()
{
    cout << "Player name: " << name << endl;
    cout << "Player hit points: " << hp << endl;
    cout << "Player max hit point: " << maxHP << endl;
    cout << "Player attack: " << atk << endl;
    cout << "Player defense: " << def << endl;
    cout << "Player magic resistance: " << res << endl;
    cout << "Player level: " << level << endl;
    cout << "Player experience points: " << exp << endl;
    cout << "Player potion amount: " << equipment.getNumOfPotions() << endl;
    cout << "Player's armor: " << equipment.getArmor() << endl;
    cout << "Player's weapon: " << equipment.getWeapon() << endl;
}
void Player::displayStats()
{
    cout << "Player attack: " << atk << endl;
    cout << "Player defense: " << def << endl;
    cout << "Player magic resistance: " << res << endl;
}
void Player::levelUP()
{
    srand(static_cast<unsigned int>(time(NULL)));

    atk += rand()%3 + 1;
    def += rand()%3 + 1;
    res += rand()%3 + 1;
    level += 1;
}
void Player::givenEXP()
{
    cout << endl;
    srand(static_cast<unsigned int>(time(NULL)));
    int xpCollected = rand()% 99;
    exp += xpCollected;
    cout << "Gained " << xpCollected << " exp!" << endl;

    if(exp >= 100)
    {
        exp -= 100;
        levelUP();
        cout << "You leveled up! You are level " << level << endl;
        cout << "Here's your updated stats: \n";
        displayStats();
        cout << endl;
    }
}
void Player::givenStats()
{
    //Armor section
    if("Chain mail")
    {
        def += 2;
    }
    else if("Iron Armor")
    {void IncresePotion(int num);
        def += 12;
    }
    else if("Magic Robe")
    {
        def += 2;
    }
    else if("Common Cloak")
    {
        def += 3;
    }

    //Weapon section
    if("Short sword")
    {
        atk += 5;
    }
    else if("Iron Sword")
    {
        atk += 2;
    }
    else if("Amateur Staff")
    {
        atk += 10;
    }
    else if("Hunting Bow")
    {
        atk += 7;
    }
}
void Player::displayEquipment()
{
    equipment.DisplayItems();
}
void Player::IncresePotion(int potion)
{
    equipment.increasePotionAmount(potion);
}
