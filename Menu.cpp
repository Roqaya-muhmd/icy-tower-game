#include "Menu.h"
#include "Pause.h"
#include"game_over.h"
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;
//main menu
Menu::Menu(float width, float hight) {
	font.loadFromFile("./CrotahFreeVersionItalic-z8Ev3.ttf");//;//C:\\Users\\pc\\Desktop\\roqia r mohammady\\font.ttf
	main_menu[0].setFont(font);
	main_menu[0].setFillColor(Color::Blue);
	main_menu[0].setString("Play");
	main_menu[0].setCharacterSize(70);
	main_menu[0].setPosition(530, 430);

	main_menu[1].setFont(font);
	main_menu[1].setFillColor(Color::Black);
	main_menu[1].setString("Options");
	main_menu[1].setCharacterSize(70);
	main_menu[1].setPosition(530, 530);

	main_menu[2].setFont(font);
	main_menu[2].setFillColor(Color::Black);
	main_menu[2].setString("Exit");
	main_menu[2].setCharacterSize(70);
	main_menu[2].setPosition(530, 630);

	selected = 0;
}
Menu:: ~Menu() {}

void Menu::draw(RenderWindow& mainmenu) {//by reference couse it needs the last behavier ???? ? ???? ????????
	for (int i = 0; i < number_selected; i++) {
		mainmenu.draw(main_menu[i]);
	}
}
void Menu::Movedown() {
	if (selected + 1 <= number_selected) {
		main_menu[selected].setFillColor(Color::Black);
		selected++;
		if (selected == number_selected) {
			selected = 0;
		}
		main_menu[selected].setFillColor(Color::Blue);
	}

}
void Menu::Moveup() {
	if (selected - 1 >= -1) {
		main_menu[selected].setFillColor(Color::Black);
		selected--;
		if (selected == -1) {
			selected = 2;
		}
		main_menu[selected].setFillColor(Color::Blue);
	}

}
//pause menu
Pause::Pause(float width, float hight) {
	font.loadFromFile("./CrotahFreeVersionItalic-z8Ev3.ttf");
	pause_menu[0].setFont(font);
	pause_menu[0].setFillColor(Color::Blue);
	pause_menu[0].setString("YES");
	pause_menu[0].setCharacterSize(70);
	pause_menu[0].setPosition(50, 200);




	pause_menu[1].setFont(font);
	pause_menu[1].setFillColor(Color::White);
	pause_menu[1].setString("NO");
	pause_menu[1].setCharacterSize(70);
	pause_menu[1].setPosition(250, 200);

	selected_Pause = 0;
}
Pause:: ~Pause() {}

void Pause::draw_Pause(RenderWindow& Window) {//by reference couse it needs the last behavier ???? ? ???? ????????
	for (int i = 0; i < number_selected_pause; i++) {
		Window.draw(pause_menu[i]);
	}
}
void Pause::Moveleft_Pause() {
	if (selected_Pause + 1 <= number_selected_pause) {
		pause_menu[selected_Pause].setFillColor(Color::White);
		selected_Pause++;
		if (selected_Pause == number_selected_pause) {
			selected_Pause = 0;
		}
		pause_menu[selected_Pause].setFillColor(Color::Blue);
	}

}
void Pause::Moveright_Pause() {
	if (selected_Pause - 1 >= -1) {
		pause_menu[selected_Pause].setFillColor(Color::White);
		selected_Pause--;
		if (selected_Pause == -1) {
			selected_Pause = 1;
		}
		pause_menu[selected_Pause].setFillColor(Color::Blue);
	}

}
//gameover menu
game_over::game_over(float width, float hight) {
	font.loadFromFile("./CrotahFreeVersionItalic-z8Ev3.ttf");
	GameOver[0].setFont(font);
	GameOver[0].setFillColor(Color::Blue);
	GameOver[0].setString("YES");
	GameOver[0].setCharacterSize(40);
	GameOver[0].setPosition(200, 600);




	GameOver[1].setFont(font);
	GameOver[1].setFillColor(Color::White);
	GameOver[1].setString("NO");
	GameOver[1].setCharacterSize(40);
	GameOver[1].setPosition(500, 600);

	selected_gameover = 0;
}
game_over:: ~game_over() {}

void game_over::draw_gameover(RenderWindow& Window) {//by reference couse it needs the last behavier ???? ? ???? ????????
	for (int i = 0; i < number_selected_gameover; i++) {
		Window.draw(GameOver[i]);
	}
}
void game_over::Moveleft_gameover() {
	if (selected_gameover + 1 <= number_selected_gameover) {
		GameOver[selected_gameover].setFillColor(Color::White);
		selected_gameover++;
		if (selected_gameover == number_selected_gameover) {
			selected_gameover = 0;
		}
		GameOver[selected_gameover].setFillColor(Color::Blue);
	}

}
void game_over::Moveright_gameover() {
	if (selected_gameover - 1 >= -1) {
		GameOver[selected_gameover].setFillColor(Color::White);
		selected_gameover--;
		if (selected_gameover == -1) {
			selected_gameover = 1;
		}
		GameOver[selected_gameover].setFillColor(Color::Blue);
	}

}