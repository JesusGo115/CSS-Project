#include "Monster.h"

using namespace std;

Monster::Monster(int num)
{
    if(num == 1)
    {
        setMonsterName("Slime");
        setHp(10);
        setAttack(2);
        setDefense(1);
        setMagicRes(0);
    }
    if(num == 2)
    {
        setMonsterName("Goblin");
        setHp(15);
        setAttack(10);
        setDefense(4);
        setMagicRes(2);
    }
    if(num == 3)
    {
        setMonsterName("Wolf");
        setHp(25);
        setAttack(15);
        setDefense(5);
        setMagicRes(1);
    }
    if(num == 4)
    {
        setMonsterName("Golem");
        setHp(30);
        setAttack(20);
        setDefense(8);
        setMagicRes(15);
    }
    if(num == 5)
    {
        setMonsterName("Dire Wolf");
        setHp(25);
        setAttack(22);
        setDefense(6);
        setMagicRes(3);
    }
    if(num ==  6)
    {
        setMonsterName("Hobgoblin");
        setHp(35);
        setAttack(24);
        setDefense(6);
        setMagicRes(4);
    }
    if(num == 7)
    {
        setMonsterName("Zombie");
        setHp(20);
        setAttack(15);
        setDefense(0);
        setMagicRes(0);
    }
}
void Monster::TakeDamage(int playerATK)
{
    hp -= (playerATK - defense);
    if(hp <= 0)
        cout << "\n*******The " << getMonsterName() << " has died!*******\n" << endl;
    else
        cout << "Remaining Monster hp: " << hp << endl;
}
void Monster::TakeMagicDamage(int PlayerATK)
{
    hp -= (PlayerATK - magicRes);
    if(hp <= 0)
        cout << "\n*******The " << getMonsterName() << " has died!*******\n" << endl;
    else
        cout << "Remaining Monster hp: " << hp << endl;
}
void Monster::DisplayMonster()
{
    cout << "\nYou encountered a " << getMonsterName() << "!\nThe " << getMonsterName() << " has " << getHp() << " hit points." << endl;
}
void Monster::playerRun()
{
    hp = 0;
}
