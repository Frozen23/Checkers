//
// Created by kubam on 06.06.2023.
//

#ifndef CHECKERS_CHECKERBOARDSFML_H
#define CHECKERS_CHECKERBOARDSFML_H
#include "Checkerboard.h"
#include "SFML/Graphics.hpp"

class CheckerboardSFML {
Checkerboard &checkerboard;
    //SFML
sf::CircleShape White;
std::vector<sf::CircleShape> Whites;
sf::CircleShape Black;
std::vector<sf::CircleShape> Blacks;
sf::CircleShape Red;
std::vector<sf::CircleShape> Reds;
sf::CircleShape Blue;
std::vector<sf::CircleShape> Blues;
sf::Vector2i selectedPiecePosition;
sf::Vector2f PieceDestinationPosition;


    bool IsMouseOverPiece(const sf::Vector2f& mousePosition, const sf::CircleShape& piece);

    bool take(int row, int col, sf::RenderWindow &window);

public:
    explicit CheckerboardSFML(Checkerboard& checkerboard1);

    void draw(sf::RenderWindow &window);

    std::vector<sf::CircleShape>possibleMoves;

    bool SelectPiece(const sf::Vector2f& mousePosition);

    void CalculatePossibleMovesSFML( sf::Vector2f& currentPosition,sf::RenderWindow &window);

    sf::Vector2f Getdestination(const sf::Vector2f& destinationPosition);

    void MoveSFML(sf::RenderWindow &window);

    void DrawPieces(sf::RenderWindow &window);

    int turn=1;

    void botMove(sf::RenderWindow &window);

    void botMove2(sf::RenderWindow &window);
};


#endif //CHECKERS_CHECKERBOARDSFML_H
