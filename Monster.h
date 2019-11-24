#ifndef MONSTER_HPP
#define MONSTER_HPP
#include <iostream>
#include <string>
using namespace std;
class Monster
{
    public:
        Monster(int num);
        //Getters
        string getMonsterName(){return monster_name;}
        int getHp(){return hp;}
        int getAttack(){return attack;}
        int getDefense(){return defense;}
        int getMagicRes(){return magicRes;}
        //Setters
        void setMonsterName(string monster_name){this -> monster_name = monster_name;}
        void setHp(int hp){this-> hp = hp;}
        void setAttack(int attack){this-> attack = attack;}
        void setDefense(int defense){this-> defense = defense;}
        void setMagicRes(int magicRes){this-> magicRes = magicRes;}
        //Other Functions
        void TakeDamage(int PlayerATK);
        void TakeMagicDamage(int PlayerATK);
        void DisplayMonster();
        void playerRun();
    private:
        string monster_name;
        int hp, attack, defense, magicRes;
};

#endif // MONSTER_HPP
