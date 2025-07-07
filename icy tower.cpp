#include <iostream>
#include<SFML/Graphics.hpp>
#include<time.h>
#include "Menu.h"
#include "Pause.h"
#include"game_over.h"
#include<fstream>
using namespace sf;
using namespace std;

Vector2f velocity(0, 0); // Velocity 
void collision(Sprite& iceman, Sprite& wall);
int GAMEOVER(RenderWindow& window_gameover);
int PAUSE(RenderWindow& window_pausemenu);
int loadHighScore();
struct Player {
    Texture icemanTexture;
    Sprite iceman;
    float speed = 50.0f;     // Horizontal speed
    float gravity = 3599.0f; // Gravity 
    float jumpStrength = -1550.0f; // Upward jump
    float friction = 10.0f; // Friction
    bool grounded = 0, jump = 0;
}player;

// Function to save the high score to a file
void saveHighScore(int score)
{
    std::ofstream file("highscore.txt");
    if (file.is_open())
    {
        file << score;
        file.close();
    }
}
int score = 0;
//save progress
int highScore = loadHighScore();
int currentScore = 0;
Text highScoreText;
int main()
{   //score

    Font font;
    font.loadFromFile("./CrotahFreeVersionItalic-z8Ev3.ttf");//\\Users\\pc\\Desktop\\roqia r mohammady\\font.ttf
    Text text1;
    text1.setFont(font);
    text1.setFillColor(Color::White);
    text1.setCharacterSize(30);
    text1.setPosition(50, 50);
    Texture amaz, good, hurry;
    amaz.loadFromFile("./amazing.png");
    good.loadFromFile("./good.png");
    hurry.loadFromFile("./hurry up.png");
    Sprite amaz_s(amaz), good_s(good), hurry_s(hurry);
    amaz_s.setPosition(100, 0);
    good_s.setPosition(80, 0);
    good_s.scale(3, 3);
    //===============================================================================================================================
    RenderWindow main_menu(VideoMode(800, 800), "Main menu", Style::Close | Style::Default);
    //calling the class
    Menu menu(800, 800);
    // big view
    Texture b_view;
    b_view.loadFromFile("./main menu/pngtree-background-red-brick-with-simple-texture-image_900845.jpg");


    Sprite b_view_s;
    b_view_s.setTexture(b_view);
    b_view_s.scale(1.8, 1.8);
    //view
    Texture view;
    view.loadFromFile("./main menu/icy tower.png");
    Sprite view_s;
    view_s.setTexture(view);


    //icy tower
    Texture icy_tower;
    icy_tower.loadFromFile("./main menu/giugkjk.png");
    Sprite icy_tower_s;
    icy_tower_s.setTexture(icy_tower);
    icy_tower_s.setPosition(550, 50);
    //paper
    Texture paper;
    paper.loadFromFile("./main menu/pngtree-white-a4-printing-paper-png-image_2962596.jpg");
    Sprite paper_s;
    paper_s.setTexture(paper);
    paper_s.setPosition(500, 400);
    paper_s.scale(1.5, 1.5);
    while (main_menu.isOpen()) {
        Event event;

        while (main_menu.pollEvent(event)) {
            switch (event.type) {
            case Event::Closed:
                main_menu.close();
                break;
            }
            if (event.type == Event::KeyReleased) {
                if (event.key.code == Keyboard::Up)
                {
                    menu.Moveup();
                    break;
                }
                if (event.key.code == Keyboard::Down)
                {
                    menu.Movedown();
                    break;
                }
                //select pages
                if (event.key.code == Keyboard::Return)//Enter
                {
                    Vector2i screenD(1270, 830);
                    RenderWindow window(VideoMode(screenD.x, screenD.y), "Play");
                    RenderWindow options(VideoMode(800, 800), "option");
                    /* RenderWindow window_pausemenu(VideoMode(400, 300), "pause menu");
                     RenderWindow window_gameover(VideoMode(800, 800), "Game Over", Style::Close | Style::Default);*/
                    int x = menu.pressed();

                    if (x == 0) {//play

                        Texture tex;
                        tex.loadFromFile("./tank.png");

                        Sprite Tank;
                        Tank.setTexture(tex);
                        Tank.setPosition(5, 110);
                        Tank.setScale(0.4, 0.4);
                        Texture texture;
                        texture.loadFromFile("./Red.jpeg");
                        Sprite color;
                        color.setTexture(texture);
                        color.setPosition(40, 140);
                        color.setScale(1, 1.02);

                        int const size = 12;
                        int timer1 = 0;

                        Texture tex1;
                        tex1.loadFromFile("./12.png");
                        Texture tex2;
                        tex2.loadFromFile("./1.png");
                        Texture tex3;
                        tex3.loadFromFile("./2.png");
                        Texture tex4;
                        tex4.loadFromFile("./3.png");
                        Texture tex5;
                        tex5.loadFromFile("./4.png");
                        Texture tex6;
                        tex6.loadFromFile("./5.png");
                        Texture tex7;
                        tex7.loadFromFile("./6.png");
                        Texture tex8;
                        tex8.loadFromFile("./7.png");
                        Texture tex9;
                        tex9.loadFromFile("./8.png");
                        Texture tex10;
                        tex10.loadFromFile("./9.png");
                        Texture tex11;
                        tex11.loadFromFile("./10.png");
                        Texture tex12;
                        tex12.loadFromFile("./11.png");

                        Texture arr[size] = { tex1,tex2,tex3,tex4,tex5,tex6,tex7,tex8,tex9,tex10,tex11,tex12 };

                        Sprite cl;
                        Clock timerc;

                        srand(static_cast<unsigned>(time(NULL)));

                        Vector2i screenD(1270, 830);
                        Vector2f position(5, 0);
                        // Create a window
                        RenderWindow window(VideoMode(screenD.x, screenD.y), "SFML Example");
                        window.setFramerateLimit(60);

                       
                       player.icemanTexture.loadFromFile("./icy tower/man.png");
                   
                       player.iceman.setTexture(player.icemanTexture);
                       player.iceman.setScale(1.6, 1.6);
                        int numrows = 6;
                        int numcolumns = 4;
                        int frameWidth = player.icemanTexture.getSize().x / numcolumns;
                        int frameHeight = player.icemanTexture.getSize().y / numrows;
                        float timer = 0.0f;
                        float delay = -0.1f;

                       player. iceman.setOrigin(25, 25); // Set the origin to the center of the sprite
                        player.iceman.setPosition(375, 600); // Start at the bottom of the screen

                        Clock clock;             // delta time**
                        float gravity2 = 99.9f;

                        // background, rightwall and leftwall
                        Texture WallTexture;
                        WallTexture.loadFromFile("./icy tower/BackWall.jpg");
                        Texture RightWallTexture;
                        RightWallTexture.loadFromFile("./icy tower/right wall.jpg");
                        Texture LeftWallTexture;
                        LeftWallTexture.loadFromFile("./icy tower/left wall.jpg");

                        Sprite background[2];
                        Sprite RightWall[2];
                        Sprite LeftWall[2];

                        for (int i = 0; i < 2; i++)
                        {
                            background[i].setTexture(WallTexture);
                            RightWall[i].setTexture(RightWallTexture);
                            LeftWall[i].setTexture(LeftWallTexture);

                            background[i].setPosition(Vector2f(110, i * 830));
                            background[i].setScale(1.3, 1.4);

                            RightWall[i].setPosition(1150, i * 830);
                            RightWall[i].setScale(1.4, 1.4);

                            LeftWall[i].setPosition(0, i * 830);
                            LeftWall[i].setScale(1.4, 1.39);
                        }

                        /////////////////////////////////// NS STAIRS  ////////////////////////////////////
                                    //NS
                        Texture StartStairTexture;
                        StartStairTexture.loadFromFile("./icy tower/NS.jpg");
                        Sprite StartStair;
                        StartStair.setTexture(StartStairTexture);
                        StartStair.setScale(3.99, 1.5);
                        StartStair.setPosition(125, 700);

                        //NS1
                        Texture Stair1Texture;
                        Stair1Texture.loadFromFile("./icy tower/NS1.jpg");
                        Sprite Stair1;
                        Stair1.setTexture(Stair1Texture);

                        //NS2
                        Texture Stair2Texture;
                        Stair2Texture.loadFromFile("./icy tower/NS2.jpg");
                        Sprite Stair2;
                        Stair2.setTexture(Stair2Texture);

                        /////////////////////////////////// FS STAIRS  /////////////////////////////////////
                       //FS
                        Texture SnowStairsTexture;
                        SnowStairsTexture.loadFromFile("./icy tower/FS.png");
                        Sprite SnowStairs;
                        SnowStairs.setScale(3.53, 1.5);
                        SnowStairs.setPosition(0, -2000);

                        //FS1
                        Texture SnowStair1Texture;
                        SnowStair1Texture.loadFromFile("./icy tower/FS1.png");
                        Sprite SnowStair1;
                        SnowStair1.setTexture(SnowStair1Texture);

                        //FS2
                        Texture SnowStair2Texture;
                        SnowStair2Texture.loadFromFile("./icy tower/FS2.png");
                        Sprite SnowStair2;
                        SnowStair2.setTexture(SnowStair2Texture);

                        /////////////////////////////////// PS STAIRS  /////////////////////////////////////
                        //PS
                        Texture PurpleStartStairTexture;
                        PurpleStartStairTexture.loadFromFile("./icy tower/PS1.png");
                        Sprite PurpleStartStair;
                        PurpleStartStair.setScale(3.53, 1.5);
                        PurpleStartStair.setPosition(125, 1130);

                        //PS1
                        Texture PurpleStair1Texture;
                        PurpleStair1Texture.loadFromFile("./icy tower/PS1.png");
                        Sprite PurpleStair1;
                        PurpleStair1.setTexture(PurpleStair1Texture);

                        //PS2
                        Texture PurpleStair2Texture;
                        PurpleStair2Texture.loadFromFile("./icy tower/PS2.png");
                        Sprite PurpleStair2;
                        PurpleStair2.setTexture(PurpleStair2Texture);

                        /////////////////////////////////// WS STAIRS  /////////////////////////////////////
                        //WS
                        Texture WoodenStartStairTexture;
                        WoodenStartStairTexture.loadFromFile("./icy tower/WS1.png");
                        Sprite WoodenStartStair;
                        WoodenStartStair.setScale(3.53, 1.5);
                        WoodenStartStair.setPosition(125, 1130);

                        //WS1
                        Texture WoodenStair1Texture;
                        WoodenStair1Texture.loadFromFile("./icy tower/WS1.png");
                        Sprite WoodenStair1;
                        WoodenStair1.setTexture(WoodenStair1Texture);

                        //WS2
                        Texture WoodenStair2Texture;
                        WoodenStair2Texture.loadFromFile("./icy tower/WS2.png");
                        Sprite WoodenStair2;
                        WoodenStair2.setTexture(WoodenStair2Texture);
                        /////////////////////////////////// STAIRS ARRAYS  /////////////////////////////////////
                        Sprite plates1[400];
                        Sprite plates2[400];
                        Sprite Step1;
                        Sprite SnowStep1;
                        Sprite PurpleStep1;
                        Sprite WoodenStep1;


                        int y = 850;
                        for (int i = 0; i < 400; i++)
                        {
                            if (i < 100)
                            {
                                Step1.setTexture(StartStairTexture);
                                Step1.setScale(3.99, 1.5);
                                plates1[i].setTexture(Stair1Texture);
                                plates1[i].setScale(1.6, 1.5);
                                plates2[i].setTexture(Stair2Texture);
                                plates2[i].setScale(1.5, 1.4);
                            }
                            if (i >= 100 && i < 200)
                            {
                                SnowStep1.setTexture(SnowStairsTexture);
                                SnowStep1.setScale(3.0, 1.5);
                                plates1[i].setTexture(SnowStair1Texture);
                                plates1[i].setScale(1.2, 1.2);
                                plates2[i].setTexture(SnowStair2Texture);
                                plates2[i].setScale(1.0, 1.3);

                            }
                            if (i >= 200 && i < 300)
                            {
                                PurpleStep1.setTexture(PurpleStartStairTexture);
                                PurpleStep1.setScale(4.8, 1.5);
                                plates1[i].setTexture(PurpleStair1Texture);
                                plates1[i].setScale(2.0, 1.4);
                                plates2[i].setTexture(PurpleStair2Texture);
                                plates2[i].setScale(1.4, 1.5);

                            }
                            if (i >= 300 && i < 400)
                            {
                                WoodenStep1.setTexture(WoodenStartStairTexture);
                                WoodenStep1.setScale(4.8, 1.5);
                                plates1[i].setTexture(WoodenStair1Texture);
                                plates1[i].setScale(1.7, 1.5);
                                plates2[i].setTexture(WoodenStair2Texture);
                                plates2[i].setScale(1.1, 1.4);

                            }

                        }

                        for (int i = 0; i < 400; i++)
                        {
                            if (i < 100)
                            {
                                int x = 130 + rand() % (700 - 130 + 1);
                                if (i == 50)
                                    Step1.setPosition(125, y -= 10);
                                else if (i % 2 == 0)
                                    plates1[i].setPosition(x, y -= 200);
                                else
                                    plates2[i].setPosition(x, y -= 150);
                            }
                            else if (i >= 100 && i < 200)
                            {
                                int x = 130 + rand() % (700 - 130 + 1);
                                if (i == 150 || i == 100)
                                    SnowStep1.setPosition(-30, y -= 70);
                                else if (i % 2 == 0)
                                    plates1[i].setPosition(x, y -= 200);
                                else
                                    plates2[i].setPosition(x, y -= 150);

                            }
                            else if (i >= 200 && i < 300)
                            {
                                int x = 130 + rand() % (700 - 130 + 1);
                                if (i == 250 || i == 200)
                                    PurpleStep1.setPosition(5, y -= 70);
                                else if (i % 2 == 0)
                                    plates1[i].setPosition(x, y -= 200);
                                else
                                    plates2[i].setPosition(x, y -= 150);

                            }
                            else if (i >= 300 && i < 400)
                            {
                                int x = 130 + rand() % (700 - 130 + 1);
                                if (i == 350 || i == 300)
                                    WoodenStep1.setPosition(5, y -= 70);
                                else if (i % 2 == 0)
                                    plates1[i].setPosition(x, y -= 200);
                                else
                                    plates2[i].setPosition(x, y -= 150);

                            }

                        }
                        //Animation sprite columns
                        int currentcolumn = 0, currentRow = 0;

                        //Open loop
                        while (window.isOpen())
                        {
                            Event event;
                            while (window.pollEvent(event))
                            {
                                if (event.type == Event::Closed)
                                    window.close();

                            } //clock and tank
                            cl.setTexture(arr[0]);
                            Tank.setTexture(tex);

                            if (timerc.getElapsedTime().asSeconds() >= 1) {
                                timer1++;

                                timerc.restart();
                            }
                            //movement
                            if (Keyboard::isKeyPressed(Keyboard::Left))
                            {
                                velocity.x -= player.speed;

                                //animation part
                                player.iceman.setScale(-1.6, 1.6);
                                currentcolumn++;
                                currentcolumn = currentcolumn % numcolumns;
                                currentRow = 1;
                            }

                            // Right movement
                            if (Keyboard::isKeyPressed(Keyboard::Right)) {
                                velocity.x += player.speed;

                                //animation part
                                player.iceman.setScale(1.6, 1.6);
                                currentcolumn++;
                                currentcolumn = currentcolumn % numcolumns;
                                currentRow = 1;
                            }

                            // Stop horizontal movement when keys are released
                            // stop walk right or left without pressing on the keys
                            if (event.type == Event::KeyReleased &&
                                (event.key.code == Keyboard::Right || event.key.code == Keyboard::Left)) {
                                velocity.x = 0;
                                currentcolumn = 0;
                                currentRow = 0;
                            }
                            //delta time
                            float deltaTime = clock.restart().asSeconds();
                            //pausemenu
                            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                                RenderWindow window_pausemenu(VideoMode(400, 300), "pause menu");
                                int xx = PAUSE(window_pausemenu);
                                if (xx == 0) {
                                    window_pausemenu.close();
                                    //  break;
                                }
                                if (xx == 1) {
                                    window_pausemenu.close();
                                    window.close();
                                    break;
                                }
                            }
                            // when collision with stairs  
                            // Jumping
                            if (Keyboard::isKeyPressed(Keyboard::Space)) {
                                
                                if (player.grounded == 1 && player.jump == 0) { // If on the ground
                                    velocity.y = player.jumpStrength;
                                   player.jump = 1;
                               

                                    if (timer1 >= 1) {
                                        cl.setTexture(arr[0]);
                                        Tank.setTexture(tex);
                                    }
                                    if (timer1 >= 2) {

                                        cl.setTexture(arr[1]);
                                    }
                                    if (timer1 >= 3) {

                                        cl.setTexture(arr[2]);
                                    }
                                    if (timer1 >= 4) {

                                        cl.setTexture(arr[3]);
                                    }
                                    if (timer1 >= 5) {

                                        cl.setTexture(arr[4]);
                                    }
                                    if (timer1 >= 6) {

                                        cl.setTexture(arr[5]);
                                    }
                                    if (timer1 >= 7) {

                                        cl.setTexture(arr[6]);
                                    }
                                    if (timer1 >= 8) {

                                        cl.setTexture(arr[7]);
                                    }
                                    if (timer1 >= 9) {

                                        cl.setTexture(arr[8]);
                                    }
                                    if (timer1 >= 10) {

                                        cl.setTexture(arr[9]);

                                    }if (timer1 >= 11) {

                                        cl.setTexture(arr[10]);
                                    }
                                    if (timer1 >= 12) {

                                        cl.setTexture(arr[11]);
                                        timer1 = 0;
                                    }
                                }
                            }

                            // Apply gravity and get it back on the ground
                            velocity.y += (player.gravity * deltaTime);

                            // Update the sprite's position
                            player.iceman.move(velocity * deltaTime);

                        
                            // Update texture rect
                            player.iceman.setTextureRect(IntRect(currentcolumn * frameWidth, currentRow * frameHeight, frameWidth, frameHeight));


                            // game over
                            // roqia can add the game over with this condition

                            if (player.iceman.getPosition().y >= screenD.y)
                            {
                                RenderWindow window_gameover(VideoMode(800, 800), "Game Over", Style::Close | Style::Default);
                                int xx = GAMEOVER(window_gameover);
                                if (xx == 0) {//yes

                                    window_gameover.close();


                                }
                                if (xx == 1) {//no
                                    window_gameover.close();
                                    window.close();
                                    break;
                                }
                            }

                            //screen auto move
                            for (int i = 0; i < 2; i++)
                            {
                                background[i].move(Vector2f(0, 0.8));
                                RightWall[i].move(Vector2f(0, 0.8));
                                LeftWall[i].move(Vector2f(0, 0.8));

                                for (int j = 0; j < 400; j++)
                                {
                                    plates1[j].move(Vector2f(0, 0.8));
                                    plates2[j].move(Vector2f(0, 0.8));
                                }
                                if (background[i].getPosition().y > screenD.y)
                                {
                                    background[i].setPosition(Vector2f(110, -830 + 5));
                                    RightWall[i].setPosition(Vector2f(1150, -830 + 5));
                                    LeftWall[i].setPosition(Vector2f(0, -830 + 5));
                                }
                                StartStair.move(Vector2f(0, 0.8));
                            }
                            //add the animation here too
                            if (velocity.y > 0) {
                                for (int i = 0; i < 400; i++)
                                {
                                    collision(player.iceman, plates1[i]);
                                    collision(player.iceman, plates2[i]);
                                }
                            }
                            for (int i = 0; i < 2; i++)
                            {
                                collision(player.iceman, RightWall[i]);
                                collision(player.iceman, LeftWall[i]);
                            }
                            collision(player.iceman, StartStair);
                            window.clear();

                            for (int i = 0; i < 2; i++)
                            {
                                window.draw(background[i]);
                                window.draw(RightWall[i]);
                                window.draw(LeftWall[i]);
                            }

                            //// step at 0
                            window.draw(StartStair);
                            //// step at 100
                            //window.draw(SnowStairs);
                            //window.draw(PurpleStartStair);
                            //window.draw(WoodenStartStair);

                            for (int i = 0; i < 400; i++)
                            {
                                if (i < 100)
                                {
                                    // 0,50
                                    if (i == 50 || i == 0)
                                        window.draw(Step1);
                                    else if (i % 2 == 0)
                                        window.draw(plates1[i]);
                                    else
                                        window.draw(plates2[i]);
                                }
                                else if (i >= 100 && i < 200)
                                {
                                    //100,150
                                    if (i == 150 || i == 100)
                                        window.draw(SnowStep1);
                                    else if (i % 2 == 0)
                                        window.draw(plates1[i]);
                                    else
                                        window.draw(plates2[i]);
                                }
                                else if (i >= 200 && i < 300)
                                {
                                    //200,250
                                    if (i == 250 || i == 200)
                                        window.draw(PurpleStep1);
                                    else if (i % 2 == 0)
                                        window.draw(plates1[i]);
                                    else
                                        window.draw(plates2[i]);
                                }
                                else if (i >= 300 && i < 400)
                                {
                                    //300,350
                                    if (i == 350 || i == 300)
                                        window.draw(WoodenStep1);
                                    else if (i % 2 == 0)
                                        window.draw(plates1[i]);
                                    else
                                        window.draw(plates2[i]);
                                }

                            }

                            window.draw(player.iceman);
                            //amazing
                            if (score >= 100 && score <= 200) {
                                amaz_s.move(0, gravity2 * deltaTime);
                                window.draw(amaz_s);
                            }
                            //good
                            if (score >= 10 && score <= 100) {
                                good_s.move(0, gravity2 * deltaTime);
                                window.draw(good_s);
                            }
                            //hurry   
                           /* if () {
                                hurry_s.move(0, gravity2 * deltaTime);
                                window.draw(hurry_s);
                            }*/
                            options.close();
                            text1.setString(to_string(score));
                            window.draw(text1);
                            window.draw(cl);
                            window.draw(Tank);
                            window.draw(color);
                            window.display();

                        }


                    }
                    if (x == 1)
                    {//option

                        while (options.isOpen()) {

                            Event options_event;
                            while (options.pollEvent(options_event)) {
                                if (options_event.type == Event::Closed) {
                                    options.close();
                                }
                                if (options_event.type == Event::KeyPressed) {
                                    if (options_event.key.code == Keyboard::Escape) {
                                        options.close();
                                    }

                                }


                            }

                            window.close();
                            options.clear();
                            /* window_pausemenu.close();
                             window_gameover.close();*/
                            options.display();


                        }


                    }
                    if (x == 2) {   //exist

                        main_menu.close();
                        break;
                    }
                }

            }

        }

        main_menu.clear(Color::Black);
        main_menu.draw(b_view_s);
        main_menu.draw(view_s);
        main_menu.draw(icy_tower_s);
        main_menu.draw(paper_s);
        menu.draw(main_menu);
        main_menu.display();

    }





    return 0;
}
void collision(Sprite& iceman, Sprite& wall) {

    // Check for collision
    FloatRect rectangleBounds1 = iceman.getGlobalBounds();
    FloatRect rectangleBounds = wall.getGlobalBounds();

    if (rectangleBounds1.intersects(rectangleBounds)) {
        sf::Vector2f overlap;

        //overlap calculation
        overlap.x = min(rectangleBounds1.left + rectangleBounds1.width, rectangleBounds.left + rectangleBounds.width) -
            max(rectangleBounds1.left, rectangleBounds.left);
        overlap.y = min(rectangleBounds1.top + rectangleBounds1.height, rectangleBounds.top + rectangleBounds.height) -
            max(rectangleBounds1.top, rectangleBounds.top);

        // Adjust position
        if (overlap.x < overlap.y) {
            // left or right?
            if (rectangleBounds1.left < rectangleBounds.left)
                iceman.setPosition(iceman.getPosition().x - overlap.x, iceman.getPosition().y);
            else
                iceman.setPosition(iceman.getPosition().x + overlap.x, iceman.getPosition().y);
            score++;
        }
        else {
            //top or bottom?
            if (rectangleBounds1.top < rectangleBounds.top) {
               player. grounded = 1; player.jump = 0;
                velocity.y = 0;
                iceman.setPosition(iceman.getPosition().x, iceman.getPosition().y - overlap.y);
            }
            else
                iceman.setPosition(iceman.getPosition().x, iceman.getPosition().y + overlap.y);
        }
    }

}
int GAMEOVER(RenderWindow& window_gameover) {
    int x;
    // RenderWindow window_gameover(VideoMode(800, 800), "Game Over", Style::Close | Style::Default);
    game_over Gameover(600, 600);
    //back groung
    Texture game_over;
    game_over.loadFromFile("./Pause menu/Game_Over_logo.png");
    Sprite game_over_s;
    game_over_s.setTexture(game_over);
    game_over_s.scale(0.8, 0.5);
    game_over_s.setPosition(30, -20);
    //view
    Texture view;
    view.loadFromFile("./Pause menu/background_gameover.png");
    Sprite view_s;
    view_s.setTexture(view);
    // view_s.setPosition(50, 300);
    view_s.scale(1.5, 1.5);
    //ground
    Texture t;
    t.loadFromFile("./icy tower/BackWall.jpg");
    Sprite s(t);
    s.scale(1.5, 1.5);

    //font
    Font font;
    font.loadFromFile("./CrotahFreeVersionItalic-z8Ev3.ttf");
    Text text1;
    text1.setFont(font);
    text1.setFillColor(Color::White);
    text1.setCharacterSize(30);
    text1.setString("SCORe : " + to_string(score));
    text1.setPosition(50, 200);
    Text text2;
    text2.setFont(font);
    text2.setFillColor(Color::White);
    text2.setCharacterSize(30);
    text2.setString("BeSt COMBO : " + to_string(score));
    text2.setPosition(50, 300);
    Text text3;
    text3.setFont(font);
    text3.setFillColor(Color::White);
    text3.setCharacterSize(100);
    text3.setString("PLAY AGAIN?");
    text3.setPosition(90, 400);
    while (window_gameover.isOpen()) {
        Event event_gameover;
        while (window_gameover.pollEvent(event_gameover)) {
            switch (event_gameover.type) {
            case Event::Closed:
                window_gameover.close();
                break;
            }

            if (event_gameover.type == Event::KeyReleased) {
                if (event_gameover.key.code == Keyboard::Right)
                {
                    Gameover.Moveright_gameover();
                    break;
                }
                if (event_gameover.key.code == Keyboard::Left)
                {
                    Gameover.Moveleft_gameover();
                    break;
                }
                if (event_gameover.key.code == Keyboard::Return)
                {
                    x = Gameover.pressed_gameover();
                    if (x == 0) {
                        return 0;

                    }
                    if (x == 1) {
                        return 1;
                    }
                }
            }

        }
        //font.setString("SCORE: " + to_string(score));
        window_gameover.clear(Color::Black);
        //window_gameover.draw(s);
        window_gameover.draw(view_s);
        window_gameover.draw(game_over_s);
        window_gameover.draw(text1);
        window_gameover.draw(text2);
        window_gameover.draw(text3);
        Gameover.draw_gameover(window_gameover);
        window_gameover.display();

    }

}
int PAUSE(RenderWindow& window_pausemenu) {
    // RenderWindow window_pausemenu(VideoMode(400, 300), "pause menu");
    Texture view;
    view.loadFromFile("./Pause menu/continue.png");
    Sprite view_s;
    view_s.setTexture(view);
    view_s.scale(.5, .5);
    view_s.setPosition(20, 20);
    Pause pause(400, 400);
    while (window_pausemenu.isOpen()) {
        Event event_pause;
        while (window_pausemenu.pollEvent(event_pause)) {
            switch (event_pause.type) {
            case Event::Closed:
                window_pausemenu.close();
                break;
            }
            if (event_pause.type == Event::KeyReleased) {
                if (event_pause.key.code == Keyboard::Right)
                {
                    pause.Moveright_Pause();
                    break;
                }
                if (event_pause.key.code == Keyboard::Left)
                {
                    pause.Moveleft_Pause();
                    break;
                }

                if (event_pause.key.code == Keyboard::Return)//Enter
                {
                    int page_number_pausemenu = pause.pressed_Pause();
                    if (page_number_pausemenu == 0) {//continue
                        return 0;
                        /*  window_pausemenu.close();
                          break;*/
                    }
                    if (page_number_pausemenu == 1) {//main menu
                        return 1;
                        /* window_pausemenu.close();
                         window.close();
                         break;*/
                    }
                }
            }
            break;

        }
        //play.close();
        window_pausemenu.clear(Color::Black);
        window_pausemenu.draw(view_s);
        pause.draw_Pause(window_pausemenu);
        window_pausemenu.display();
    }

}
int loadHighScore()
{
    ifstream file("highscore.txt");
    int highScore = 0;
    if (file.is_open())
    {
        file >> highScore;
        file.close();
    }
    return highScore;
}