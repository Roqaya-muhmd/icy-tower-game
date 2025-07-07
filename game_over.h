#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
using namespace std;
const int number_selected_gameover = 2;
class game_over
{
public:

    game_over(float width, float hight);//function  calling to class in main file
    void draw_gameover(RenderWindow& Window);
    void Moveright_gameover();
    void Moveleft_gameover();
    void setselected_gameover(int s);
    int pressed_gameover() {
        return selected_gameover;
    }
    ~game_over();
private:
    int selected_gameover;
    Font font;
    Text GameOver[number_selected_gameover];

};