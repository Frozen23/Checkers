//
// Created by kubam on 09.06.2023.
//

#ifndef CHECKERS_GAMECONTROLLER_H
#define CHECKERS_GAMECONTROLLER_H
#include <SFML/Graphics.hpp>

class Gamecontroller {

public:
    void play(sf::RenderWindow &window);
    static void playBot(sf::RenderWindow &window);
    static void playBot2(sf::RenderWindow &window);
};


#endif //CHECKERS_GAMECONTROLLER_H
