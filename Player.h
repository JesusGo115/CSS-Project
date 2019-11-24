#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

#include "Item.h"
#include "Dice.h"

using namespace std;


class Player
{
    public:
        Player(string name, int clas);
        //Getters
        string getName()const {return this->name;}
        int getHP()const {return this->hp;}
        int getMaxHP()const {return this->maxHP;}
        int getATK()const {return this->atk;}
        int getDEF()const {return this->def;}
        int getRES()const {return this->res;}
        int getLVL()const {return this->level;}
        int getEXP()const {return this->exp;}
        //Setters
        void setName(string name) {this->name = name;}
        void setHP(int hp) {this->hp = hp;}
        void setMaxHP(int hp) {this->maxHP = hp;}
        void setATK(int atk) {this->atk = atk;}
        void setDEF(int def) {this->def = def;}
        void setRES(int res) {this->res = res;}
        void setLVL(int level) {this->level = level;}
        void setEXP(int xp) {this->exp = xp;}
        //Functions
        //NOT USED FOR NOW void changeMaxHP(int change); // Changes the max hp the player has by reducing it or increasing it
        void takeDMG(int dmg); // Depending on the player's defense, the player takes damage
        void takeMagDMG(int dmg); // Depending on the player's magic resistance, the player takes damage
        void heal(); //Heals up the player
        void displayPlayer(); //Displays the player's stats and current held equipment
        void displayStats(); //Displays player's stats
        void levelUP(); //Mostly used inside the "getEXP" function, increases player level by 1 and takes out 100 off exp
        void givenEXP(); //Gives player exp from killed monsters and uses levelUP function
        void givenStats(); //Gets stats based on the weapon, armor, and passive item the player has
        void displayEquipment();//Displays players items
        void IncresePotion(int potion);

    private:
        string name;
        Item equipment;
        Dice dice;
        int hp, atk, def, res;
        int level, exp;
        int maxHP;
};

#endif // PLAYER_HPP
