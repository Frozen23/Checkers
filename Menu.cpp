//
// Created by kubam on 09.06.2023.
//

#include "Menu.h"
#include "SFML/Graphics.hpp"
#include "Gamecontroller.h"
void Menu::ShowMenu() {
    sf::RenderWindow menuWindow(sf::VideoMode(800, 800), "Checkers Main Menu");
    menuWindow.setFramerateLimit(120);
    sf::Font font;
    font.loadFromFile("Font2.ttf");
    sf::Text title("Checkers",font,100);
    title.setPosition(65,30);
    title.setFillColor(sf::Color::Black);
    sf::Text playOption("Play 1 vs 1", font, 70);
    playOption.setPosition(130,180);
    playOption.setFillColor(sf::Color::Black);
    sf::Text bestScores("Play bot1", font, 70);
    bestScores.setPosition(150, 380);
    bestScores.setFillColor(sf::Color::Black);
    sf::Text quitOption("Play bot2", font, 70);
    quitOption.setPosition(150, 580);
    quitOption.setFillColor(sf::Color::Black);


    menuWindow.clear();
    for (int col = 0; col < 8; col++) {
        for (int row = 0; row < 8; row++) {
            sf::RectangleShape square(sf::Vector2f(100, 100));
            square.setPosition(col * 100, row * 100);

            if ((col + row) % 2 == 0)
                square.setFillColor(sf::Color(200, 200, 200));
            else
                square.setFillColor(sf::Color(100, 100, 100));
            menuWindow.draw(square);

        }
    }
    menuWindow.draw(title);
    menuWindow.draw(playOption);
    menuWindow.draw(bestScores);
    menuWindow.draw(quitOption);
    menuWindow.display();

    bool isMenuOpen = true;
    while (isMenuOpen) {
        sf::Event event;
        while (menuWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                menuWindow.close();
                isMenuOpen = false;
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (playOption.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    Gamecontroller game;
                    game.play(menuWindow);
                    isMenuOpen= false;
                }
                if (bestScores.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {

                    Gamecontroller game;
                    game.playBot(menuWindow);
                    isMenuOpen=false;
                }
                if (quitOption.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    Gamecontroller game;
                    game.playBot2(menuWindow);
                    isMenuOpen = false;
                }

            }
        }
    }
}