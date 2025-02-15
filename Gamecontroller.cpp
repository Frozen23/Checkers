//
// Created by kubam on 09.06.2023.
//

#include "Gamecontroller.h"
#include "SFML/Graphics.hpp"
#include "CheckerboardSFML.h"
#include "iostream"
void Gamecontroller::play(sf::RenderWindow &window) {
    Checkerboard checkerboard;
    CheckerboardSFML checkerboardSfml(checkerboard);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (checkerboardSfml.SelectPiece(mousePosition)) {
                        checkerboardSfml.CalculatePossibleMovesSFML(mousePosition,window);
                        checkerboard.DrawBoard();
                    }
                }
                if (event.mouseButton.button == sf::Mouse::Right) {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    checkerboardSfml.Getdestination(mousePosition);
                    checkerboardSfml.MoveSFML(window);
                    checkerboard.GetGameState();
                    //klasa do ekranu koncowego
                    checkerboard.Promotion();
                    checkerboard.DrawBoard();
                }

            }
        }
        window.clear();
        checkerboardSfml.draw(window);
        checkerboardSfml.DrawPieces(window);
        if(!checkerboardSfml.possibleMoves.empty()) {
            for (const auto &move: checkerboardSfml.possibleMoves)
                window.draw(move);
        }
        window.display();
    }

    return ;
}
void Gamecontroller::playBot(sf::RenderWindow &window){
    srand(static_cast<unsigned int>(time(0)));
    Checkerboard checkerboard;
    CheckerboardSFML checkerboardSfml(checkerboard);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (checkerboardSfml.SelectPiece(mousePosition)) {
                        checkerboardSfml.CalculatePossibleMovesSFML(mousePosition,window);
//                        checkerboard.DrawBoard();

                    }
                }
                if (event.mouseButton.button == sf::Mouse::Right) {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    checkerboardSfml.Getdestination(mousePosition);
                    checkerboardSfml.MoveSFML(window);
                    checkerboard.GetGameState();
                    checkerboard.Promotion();

                }
                std::cout<<std::endl;
            }
            if(checkerboardSfml.turn==2){
                checkerboardSfml.botMove(window);
                checkerboard.GetGameState();
                checkerboardSfml.possibleMoves.clear();
                checkerboard.Promotion();
            }

        }
        window.clear();
        checkerboardSfml.draw(window);
        checkerboardSfml.DrawPieces(window);

        if (!checkerboardSfml.possibleMoves.empty()) {
            for (const auto& move : checkerboardSfml.possibleMoves) {
                window.draw(move);
            }
        }window.display();
    }

    return ;

}
void Gamecontroller::playBot2(sf::RenderWindow &window){
    srand(static_cast<unsigned int>(time(0)));
    Checkerboard checkerboard;
    CheckerboardSFML checkerboardSfml(checkerboard);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed) {
                checkerboard.GetGameState();
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    if (checkerboardSfml.SelectPiece(mousePosition)) {
                        checkerboardSfml.CalculatePossibleMovesSFML(mousePosition,window);
                        checkerboard.DrawBoard();
                    }
                }
                if (event.mouseButton.button == sf::Mouse::Right) {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                    checkerboardSfml.Getdestination(mousePosition);
                    checkerboardSfml.MoveSFML(window);
                    checkerboard.GetGameState();
                    checkerboard.Promotion();

                }
                std::cout<<std::endl;
            }
            if(checkerboardSfml.turn==2){
                checkerboardSfml.botMove2(window);
                checkerboard.GetGameState();
//                checkerboardSfml.possibleMoves.clear();
                checkerboard.Promotion();
            }

        }
        window.clear();
        checkerboardSfml.draw(window);
        checkerboardSfml.DrawPieces(window);

        for (const auto& move : checkerboardSfml.possibleMoves) {
            window.draw(move);
        }
        window.display();
    }

    return ;

}