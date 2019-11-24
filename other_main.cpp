//*****************************
//Names: Julio Aguirre, Jesus 'Chuy' Gomez, Efrain Pamatz
//Date: 5/15/2019
//Description: An app created to simulate a Dungeons-and-Dragons-like game that is open world and uses SFML to accomplish this
//Youtube Video: https://youtu.be/vN08hv7vUNo
//*****************************



#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cassert>
#include <cctype>

#include "Monster.h"
#include "Dice.h"
#include "Player.h"
#include "Item.h"
using namespace sf;
using namespace std;
const int num=8; //checkpoints
int points[num][2] = {400, 810,
                    1270,430,
                      1380,2380,
                      1900,2460,
                      1970,1700,
                      2550,1680,
                      2560,3150,
                      500, 3300};



struct Human
{
  float x,y,speed,angle; int n;

  Human() {speed=2; angle=0; n=0;}

  void move()
   {
    x += sin(angle) *speed;
    y -= cos(angle) *speed;
   }

  void findTarget()
  {
    float tx=points[n][0];
    float ty=points[n][1];
    float beta = angle-atan2(tx-x,-ty+y);
    if (sin(beta)<0) angle+=0.005*speed; else angle-=0.005*speed;
    if ((x-tx)*(x-tx)+(y-ty)*(y-ty)<25*25) n=(n+1)%num;
}

};
int main()
{
   system("color 0d");
    int potion = 1;
    Dice D;
    string name;
    int clas;
    int choice;

    RenderWindow app(VideoMode(640, 480), "Adventure");

	app.setFramerateLimit(90);

    Texture t1,t2, t3, t4, t5, t6, t7, t8, t9, t10;
    t1.loadFromFile("Full_Map.png");
    t2.loadFromFile("steve top down.png");
    t3.loadFromFile("slime.png");
    t4.loadFromFile("goblin.png");
    t5.loadFromFile("wolf.png");
    t6.loadFromFile("golem.png");
    t7.loadFromFile("dire.png");
    t8.loadFromFile("hob.png");
    t9.loadFromFile("zombie.png");
    t10.loadFromFile("w102.png");
    t1.setSmooth(true);
    t2.setSmooth(true);
    t3.setSmooth(true);
    t4.setSmooth(true);
    t5.setSmooth(true);
    t6.setSmooth(true);
    t7.setSmooth(true);
    t8.setSmooth(true);
    t9.setSmooth(true);
    t10.setSmooth(true);
    Sprite sBackground(t1), player(t2), slime(t3), goblin(t4), wolf(t5), golem(t6), dire(t7), hob(t8), zombie(t9), open(t10);

    sBackground.scale(3,3);
    player.scale(.35, .35);
    player.setPosition(100, 240);
    player.setOrigin(22, 22);
    slime.scale(1.8,1.5);
    goblin.scale(1.8,1.5);
    wolf.scale(1.8,1.5);
    golem.scale(1.8,1.5);
    dire.scale(1.8,1.5);
    hob.scale(1.8,1.5);
    zombie.scale(1.8,1.5);
    open.scale(1.1,1.6);



    float R=22;

    const int N=1;
    Human Human[N];
    for(int i=0;i<N;i++)
    {
      Human[i].x=300+i*50;
      Human[i].y=500+i*80;
      Human[i].speed=7+i;
    }

   float speed=0,angle=0;
   float maxSpeed=2.0;
   float acc=0.3, dec=0.3;
   float turnSpeed=0.05;

   int offsetX=0,offsetY=0;
    app.draw(open);
    app.display();
    cout << "***********************************************************************\n"
        <<endl;
     cout<< "Welcome to the wizarding world of Wizard 102,(Dragons sold separately)TM\n"
     <<endl;
    cout<< "*************************************************************************\n";
    cout << "Enter thy name young adventurer:\n";
    getline(cin, name);

    cout << "Choose your class, if you dare:\n";
    cout << "******************************************\n"
    << "Enter 1 for Warrior\n" << "Enter 2 for Wizard\n" <<
    "Enter 3 for Ranger\n" << "Enter 4 for Thief\n" << endl;
    cin >> clas;

    Player p1(name, clas);
    p1.displayPlayer();
    cout<<endl;
    cout<<endl;
    cout<<"Enter capital P to search for people while in the village."<<endl;
    cout<<"Enter capital F to detect any monster nearby"<<endl;
    cout<<"Enter capital S to show your Stats"<<endl;
    cout<<"Enter capital I to show your Equipment"<<endl;
    cout<<endl;
    cout<<endl;
    srand(time(NULL));
    int Found;


    while (app.isOpen())
    {
        Event e;
        while (app.pollEvent(e))
        {

            switch(e.type)
            {
            case Event::TextEntered:

            Found=rand()%2+1;
            if(e.text.unicode==80)
            {

                if(Found==2)
                {
                     cout<<"After searching for a bit, You found an injured person.\n"
                     <<"You help them recover from their wound, they have a potion to spare and give it to you\n"
                     <<"Gain +1 potion"<<endl;
                     p1.IncresePotion(potion);
                     p1.displayEquipment();
                }
                else{cout<<"there is no one here\n"
                <<"Continue on your journey, young adventurer"<<endl;}
                cout<<endl;
            }
            if(e.text.unicode==73)
            {
                p1.displayEquipment();
                cout<<endl;
                cout<<endl;

            }
            if(e.text.unicode==83)
            {
                p1.displayStats();
                cout<<endl;
                cout<<endl;
            }
            if(e.text.unicode==70)
            {
                if (Found==2)
            {
            int i=rand()%7+1;
                Monster n(i); //Monster creation
                n.DisplayMonster();//Displays what monster you are fighting
                bool NoRan=true;
            cout<<"You found a monster get ready to fight"<<endl;


        while(p1.getHP()>0 && n.getHp()> 0)
        {
          if(i==1)
                    {
                        app.draw(slime);

                    }

                    if(i==2)
                    {
                        app.draw(goblin);
                    }

                    if(i==3)
                    {
                        app.draw(wolf);
                    }

                    if(i==4)
                    {
                        app.draw(golem);
                    }

                    if(i==5)
                    {
                        app.draw(dire);
                    }

                    if(i==6)
                    {
                        app.draw(hob);
                    }

                    if(i==7)
                    {
                        app.draw(zombie);
                    }
                    app.display();
            cout << "\nWhat do you choose to do?\n"
            << "1 - Attack\n" << "2 - Heal (Heals 50 HP)\n" <<"3 - Run way"<<endl;
            cin >> choice;

            switch(choice)
            {
            case 1:
                {
                    bool success = D.DiceRoll();
                    if(success)
                    {// when player is successful and hits monster
                        cout << "\nYou attacked the monster! Monster takes damage." << endl;
                        n.TakeDamage(p1.getATK());
                        cout << "Remaining Player hp: " << p1.getHP() << endl;
                    }
                    else
                    { //When player misses and takes damage
                        cout << "\nYou missed your attack! You took damage." << endl;
                        cout << "Remaining Monster hp: " << n.getHp() << endl;
                        p1.takeDMG(n.getAttack());
                    }
                }
                break;
            case 2:
                { // Heals the player, (monster still attacks you)
                    p1.heal();
                    cout << "\nPlayer has " << p1.getHP() << " hp remaining." << endl;

                    bool monsterSuccess = D.DiceRoll(); //Monster has a chance to attack you when you heal
                    if(monsterSuccess)
                    {
                        cout << "\nMonster took advantage and attacks you!\n";
                        p1.takeDMG(n.getAttack());
                    }
                    else
                    {
                        cout << "\nMonster tried taking advantage to attack you, but missed!\n";
                    }
                }break;
            case 3:
                    {
                        int run=rand()%2+1;
                    if(run==1)
                    {
                        cout<<"Monster attacks you while you flee\n";
                        p1.takeDMG(n.getAttack()*3);
                        NoRan=false;
                        n.playerRun();
                    }
                    else{
                        cout<<"You ran like a coward, but you are at least alive.\n";
                        NoRan=false;
                        n.playerRun();
                    }
                    }


                break;
            }
        if(p1.getHP()<=0)
        { Clock c;

            Time elapsed1= c.getElapsedTime();
            float Tim=elapsed1.asSeconds();
            while(Tim<4)
            {
            app.close();
            }

        }

        }

        if(NoRan)
            p1.givenEXP(); //Every time you kill a monster, you get exp to level up (Player must have hp)

            }
            else
            {
                cout<<"You could not find anything nearby continue on your journey"<<endl;
            }
            }
            break;
            }
            if (e.type == Event::Closed)
                app.close();
        }

    bool Up=0,Right=0,Down=0,Left=0;

    if (Keyboard::isKeyPressed(Keyboard::Up)) Up=.1;
    if (Keyboard::isKeyPressed(Keyboard::Right)) Right=.1;
    if (Keyboard::isKeyPressed(Keyboard::Down)) Down=.1;
    if (Keyboard::isKeyPressed(Keyboard::Left)) Left=.1;

    if (Up && speed<maxSpeed)
        if (speed < 0)  speed += dec;
        else  speed += acc;

    if (Down && speed>-maxSpeed)
        if (speed > 0) speed -= dec;
        else  speed -= acc;


    if (!Up && !Down)
        if (speed - dec > 0) speed -= dec;
        else if (speed + dec < 0) speed += dec;
        else speed = 0;

    if (Right && speed!=0)  angle +=turnSpeed * speed/maxSpeed;
    if (Left && speed!=0)   angle -=turnSpeed * speed/maxSpeed;

    Human[0].speed = speed;
    Human[0].angle = angle;

	for(int i=0;i<N;i++) Human[i].move();
	for(int i=1;i<N;i++) Human[i].findTarget();




    app.clear(Color::White);

    if (Human[0].x>520) offsetX = Human[0].x-520;
    if (Human[0].y>240) offsetY = Human[0].y-240;

   sBackground.setPosition(-offsetX,-offsetY);
    app.draw(sBackground);



   for(int i=0;i<N;i++)
    {
      player.setPosition(Human[i].x-offsetX, Human[i].y-offsetY);
      player.setRotation(Human[i].angle*180/3.141593);
      player.setColor(Color::White);
      app.draw(player);
    }


    app.display();
    }

    return 0;
}

