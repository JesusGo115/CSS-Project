#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

using namespace std;

class Item
{
    public:
        Item(); //initializes variables with nothing, the default constructor on player class will initialize the chosen class's items (warrior with armor)
        //Setters
        void setArmor(string armor) {this->armor = armor;}
        void setWeapon(string weapon) {this->weapon = weapon;}
        void setPassiveItem(string item) {this->passiveItem = item;}
        void setNumOfPotions(unsigned int potionAmount) {this->numOfPotions = potionAmount;}
        void setMaxPotionAmount(unsigned int potionMax) {this->maxPotions = potionMax;}

        //Getters
        string getArmor()const {return armor;}
        string getWeapon()const {return weapon;}
        string getPassiveItem()const {return passiveItem;}
        unsigned int getNumOfPotions()const {return numOfPotions;}
        unsigned int getMaxPotionAmount()const {return maxPotions;}

        //Other
        void exchangeArmor(string newArmor);
        void exchangeWeapon(string newWeapon);
        void exchangePassiveItem(string newItem);
        void decreasePotionAmount();
        void increasePotionAmount(unsigned int morePotions);
        void DisplayItems();


    private:
        string armor; //(gives bonus stats to player's def and res' depending if player has armor equipment)
        string weapon; //(depending on your class, it gives weapon appropriate to your class and gives stats to atk and spd (spd is a big maybe))
        string passiveItem; //(this item gives a certain stat(s) such as an item increasing maxHP or increase spd)
        unsigned int numOfPotions; //(basically is the amount of potions you have with you)
        unsigned int maxPotions; //Maximum amount of potions the player can have
};

#endif // ITEM_HPP
