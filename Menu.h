#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
using namespace std;
const int number_selected = 3;
class Menu
{
public:

    Menu(float width, float hight);//function  calling to class in main file
    void draw(RenderWindow& mainmenu);
    void Moveup();
    void Movedown();
    void setselected(int s);
    int pressed() {
        return selected;
    }
    ~Menu();
private:
    int selected;
    Font font;
    Text main_menu[number_selected];

};