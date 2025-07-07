#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
using namespace std;
const int number_selected_pause = 2;
class Pause
{
public:

    Pause(float width, float hight);//function  calling to class in main file
    void draw_Pause(RenderWindow& Window);
    void Moveright_Pause();
    void Moveleft_Pause();
    void setselected_Pause(int s);
    int pressed_Pause() {
        return selected_Pause;
    }
    ~Pause();
private:
    int selected_Pause;;
    Font font;
    Text pause_menu[number_selected_pause];

};