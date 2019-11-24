#include <iostream>
#include <cstdlib>
#include <string>
#include <cctype>

#include "Item.h"

using namespace std;

Item::Item()
{
    armor = "";
    weapon = "";
    passiveItem = "";
    numOfPotions = 5;
}
//initializes variables with nothing, the default constructor on player class will initialize the chosen class's items (warrior with armor)

void Item::exchangeArmor(string newArmor)
{
    char choice = 'H';

    if(armor == "")
    {
        armor = newArmor;
        cout << "You got " << newArmor << "!";
    }
    else
    {
        cout << "You already have " << armor << ". Do you want to exchange " << armor << " for " << newArmor << "? Y - Yes";
        cin >> choice;
        cin.ignore();
        choice = toupper(choice);
        if(choice == 'Y')
        {
            armor = newArmor;
            cout << "You got " << newArmor << " equipped.";
        }
        else
        {
            cout << "You have discarded " << newArmor << ".";
        }
    }
}
void Item::exchangeWeapon(string newWeapon)
{
    char choice = 'H';

    if(weapon == "")
    {
        weapon = newWeapon;
        cout << "You got " << newWeapon << "!";
    }
    else
    {
        cout << "You already have " << weapon << ". Do you want to exchange " << weapon << " for " << newWeapon << "? Y - Yes";
        cin >> choice;
        cin.ignore();
        choice = toupper(choice);
        if(choice == 'Y')
        {
            weapon = newWeapon;
            cout << "You got " << newWeapon << " equipped.";
        }
        else
        {
            cout << "You have discarded " << newWeapon << ".";
        }
    }
}
void Item::exchangePassiveItem(string newItem)
{
    char choice = 'H';

    if(passiveItem == "")
    {
        passiveItem = newItem;
        cout << "You got " << newItem << "!";
    }
    else
    {
        cout << "You already have " << passiveItem << ". Do you want to exchange " << passiveItem << " for " << newItem << "? Y - Yes";
        cin >> choice;
        cin.ignore();
        choice = toupper(choice);
        if(choice == 'Y')
        {
            passiveItem = newItem;
            cout << "You got " << newItem << " equipped.";
        }
        else
        {
            cout << "You have discarded " << newItem << ".";
        }
    }
}
void Item::decreasePotionAmount()
{
    numOfPotions--;
    cout << "You have " << numOfPotions << " potion(s) left in your inventory.";
}
void Item::increasePotionAmount(unsigned int morePotions)
{
    unsigned int totalPotions = numOfPotions + morePotions;

    if(totalPotions > maxPotions)
    {
        numOfPotions = maxPotions;
    }
    else
    {
        numOfPotions = totalPotions;
    }
}
void Item::DisplayItems()
{
    cout << "Player Armor: " << getArmor() << "\nPlayer Weapon: " <<
        getWeapon() << "\nPlayer passive Item: " <<
        getPassiveItem() << "\nPlayer's amount of potion: " <<
        getNumOfPotions() << "\nPlayer's maximum capacity of potions: " <<
        getMaxPotionAmount() << "\n" << endl;

}
