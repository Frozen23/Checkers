//
// Created by kubam on 06.06.2023.
//

#include <random>
#include <iostream>
#include "CheckerboardSFML.h"
#include <SFML/Graphics.hpp>
using namespace std;
CheckerboardSFML::CheckerboardSFML(Checkerboard &checkerboard1):checkerboard(checkerboard1){

}
void CheckerboardSFML::draw(sf::RenderWindow &window) {//Rysowanie planszy
    for (int col = 0; col < 8; col++) {
        for (int row = 0; row < 8; row++) {
            sf::RectangleShape square(sf::Vector2f(100, 100));
            square.setPosition(col * 100, row * 100);

            if ((col + row) % 2 == 0)
                square.setFillColor(sf::Color(200, 200, 200));
            else
                square.setFillColor(sf::Color(100, 100, 100));
            window.draw(square);

        }
    }
}

void CheckerboardSFML::DrawPieces(sf::RenderWindow &window) {
    Whites.clear();
    Blacks.clear();
    Reds.clear();
    Blues.clear();
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col ++) {
            if (checkerboard.board[row][col]== 1) {
                White.setRadius(100 / 2 - 5);
                White.setPosition(col * 100 + 5, row * 100 + 5);
                Whites.push_back(White);
            }
        }
    }
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col ++) {
            if (checkerboard.board[row][col]== 3) {
                Red.setRadius(100 / 2 - 5);
                Red.setPosition(col * 100 + 5, row * 100 + 5);
                Red.setFillColor(sf::Color::Red);
                Reds.push_back(Red);
            }
        }
    }
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col ++) {
            if (checkerboard.board[row][col]== 2) {
                Black.setRadius(100 / 2 - 5);
                Black.setPosition(col * 100 + 5, row * 100 + 5);
                Black.setFillColor(sf::Color::Black);
                Blacks.push_back(Black);
            }
        }
    }
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col ++) {
            if (checkerboard.board[row][col]== 4) {
                Blue.setRadius(100 / 2 - 5);
                Blue.setPosition(col * 100 + 5, row * 100 + 5);
                Blue.setFillColor(sf::Color::Blue);
                Blues.push_back(Blue);
            }
        }
    }
    for (const auto& White : Whites) {
        window.draw(White);
    }
    for (const auto& Black : Blacks) {
        window.draw(Black);
    }
    for (const auto& Red : Reds) {
        window.draw(Red);
    }
    for (const auto& Blue : Blues) {
        window.draw(Blue);
    }
}

bool CheckerboardSFML::IsMouseOverPiece(const sf::Vector2f& mousePosition, const sf::CircleShape& piece) {
    // Check if the mouse position is within the bounds of the piece
    sf::FloatRect bounds = piece.getGlobalBounds();
    return bounds.contains(mousePosition);
}

bool CheckerboardSFML::SelectPiece(const sf::Vector2f& mousePosition) {
    // Check if any white piece was clicked
    for (const auto& white : Whites) {
        if (IsMouseOverPiece(mousePosition, white)) {
            // White piece selected
            // Perform desired action or return true to indicate selection
            return true;
        }
    }
    // Check if any black piece was clicked
    for (const auto& black : Blacks) {
        if (IsMouseOverPiece(mousePosition, black)) {
            return true;
        }
    }
    for (const auto& red : Reds) {
        if (IsMouseOverPiece(mousePosition, red)) {
            return true;
        }
    }
    for (const auto& blue : Blues) {
        if (IsMouseOverPiece(mousePosition, blue)) {
            return true;
        }
    }
    // No piece was selected
    return false;
}

// void CheckerboardSFML::CalculatePossibleMovesSFML( sf::Vector2f& currentPosition,sf::RenderWindow &window) {
//     possibleMoves.clear();
//     int row = static_cast<int>(currentPosition.y / 100);
//     int col = static_cast<int>(currentPosition.x / 100);
//     selectedPiecePosition.x = (col);
//     selectedPiecePosition.y = (row);
//     sf::CircleShape move(15);
//     if (checkerboard.board[row][col] == 1 && turn==1) {
//         if (row - 1 >= 0) {
//             if (col - 1 >= 0) {
//                 // Check if the top-left position is empty(white)
//                 if(checkerboard.CanTake(row,col)==false) {
//                     if (!checkerboard.IsOccupied(row - 1, col - 1)) {
//                         checkerboard.board[row - 1][col - 1] = 5;
//                         move.setPosition((col - 1) * 100 + 37, (row - 1) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//                 if (checkerboard.IsOccupied(row - 1, col - 1)) {
//                     if (!checkerboard.IsOccupied(row - 2, col - 2) && (checkerboard.board[row - 1][col - 1] == 2||checkerboard.board[row-1][col-1]==4)
//                     && (col - 2) >= 0 &&
//                         (row - 2) >= 0) {
//                         checkerboard.board[row - 2][col - 2] = 5;
//                         move.setPosition((col - 2) * 100 + 37, (row - 2) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//
//                     }
//                 }
//             }
//             if (col + 1 < 8) {
//                     // Check if the top-right position is empty(white)
//                     if(checkerboard.CanTake(row,col)==false) {
//                         if (!checkerboard.IsOccupied(row - 1, col + 1)) {
//                             checkerboard.board[row - 1][col + 1] = 5;
//                             move.setPosition((col + 1) * 100 + 37, (row - 1) * 100 + 37);
//                             move.setFillColor(sf::Color::Green);
//                             possibleMoves.push_back(move);
//                         }
//                     }
//                 if (checkerboard.IsOccupied(row - 1, col + 1)) {//biciebialego
//                     if (!checkerboard.IsOccupied(row - 2, col + 2) && (checkerboard.board[row - 1][col + 1] == 2||checkerboard.board[row-1][col+1]==4)
//                     && (row - 2) >= 0 &&
//                         (col + 2) <= 8) {
//                         checkerboard.board[row - 2][col + 2] = 5;
//                         move.setPosition((col + 2) * 100 + 37, (row - 2) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//             }
//         }
//     }//blacks
//     if (checkerboard.board[row][col] == 2 && turn==2  ) {
//         if (row + 1 <= 8) {
//             if (col - 1 >= 0) {
//                 // Check if the top-left position is empty(black)
//                 if(checkerboard.CanTake(row,col)==false) {
//                     if (!checkerboard.IsOccupied(row + 1, col - 1)) {
//                         checkerboard.board[row + 1][col - 1] = 5;
//                         move.setPosition((col - 1) * 100 + 37, (row + 1) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//                 if (checkerboard.IsOccupied(row + 1, col - 1)) {
//                     if (!checkerboard.IsOccupied(row + 2, col - 2) && (checkerboard.board[row + 1][col - 1] == 1||checkerboard.board[row + 1][col - 1] == 3)
//                     && (row + 2) < 8  &&(col - 2) >= 0) {
//                         checkerboard.board[row + 2][col - 2] = 5;
//                         move.setPosition((col - 2) * 100 + 37, (row + 2) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//             }
//
//             if ((col + 1 < 8) && (row + 1 < 8)) {
//                 // Check if the top-right position is empty(black)
//                 if(checkerboard.CanTake(row,col)==false) {
//                     if (!checkerboard.IsOccupied(row + 1, col + 1)) {
//                         checkerboard.board[row + 1][col + 1] = 5;
//                         move.setPosition((col + 1) * 100 + 37, (row + 1) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//                 if (checkerboard.IsOccupied(row + 1, col + 1)) {
//                     if (!checkerboard.IsOccupied(row + 2, col + 2) && (checkerboard.board[row + 1][col + 1] == 1 ||checkerboard.board[row+1][col+1]==3)
//                     && (row + 2) < 8 &&(col + 2) <= 8) {
//                         checkerboard.board[row + 2][col + 2] = 5;
//                         move.setPosition((col + 2) * 100 + 37, (row + 2) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//
//                 }
//             }
//         }
//     }
//     if (checkerboard.board[row][col] == 3 && turn==1  ) {//biala dama
//         if (row - 1 >= 0) {
//             if (col - 1 >= 0) {
//                 // Check if the top-left position is empty(white)
//                 if(checkerboard.CanTake(row,col)==false) {
//                     if (!checkerboard.IsOccupied(row - 1, col - 1)) {
//                         checkerboard.board[row - 1][col - 1] = 5;
//                         move.setPosition((col - 1) * 100 + 37, (row - 1) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//                 if (checkerboard.IsOccupied(row - 1, col - 1)) {//lewe bicie bialej damy
//                     if (!checkerboard.IsOccupied(row - 2, col - 2) && (checkerboard.board[row - 1][col - 1] == 2||checkerboard.board[row - 1][col - 1] == 4) && (col - 2) >= 0 &&
//                         (row - 2) >= 0) {
//                         checkerboard.board[row - 2][col - 2] = 5;
//                         move.setPosition((col - 2) * 100 + 37, (row - 2) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//
//                     }
//                 }
//             }
//             if (col + 1 < 8) {
//                 // Check if the top-right position is empty(white)
//                 if(checkerboard.CanTake(row,col)==false) {
//                     if (!checkerboard.IsOccupied(row - 1, col + 1)) {
//                         checkerboard.board[row - 1][col + 1] = 5;
//                         move.setPosition((col + 1) * 100 + 37, (row - 1) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//                 if (checkerboard.IsOccupied(row - 1, col + 1)) {//biciebialego prawe
//                     if (!checkerboard.IsOccupied(row - 2, col + 2) && (checkerboard.board[row - 1][col + 1] == 2||checkerboard.board[row - 1][col + 1] == 4) && (row - 2) >= 0 &&
//                         (col + 2) < 8) {
//                         checkerboard.board[row - 2][col + 2] = 5;
//                         move.setPosition((col + 2) * 100 + 37, (row - 2) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//             }
//         }
//         if (row + 1 < 8) {
//             if (col - 1 >= 0) {
//                 // Check if the down-left bialej damy
//                 if(checkerboard.CanTake(row,col)==false) {
//                     if (!checkerboard.IsOccupied(row + 1, col - 1)) {
//                         checkerboard.board[row + 1][col - 1] = 5;
//                         move.setPosition((col - 1) * 100 + 37, (row + 1) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//                 if (checkerboard.IsOccupied(row + 1, col - 1)) {//down left bicie bialej damy
//                     if (!checkerboard.IsOccupied(row + 2, col - 2) && (checkerboard.board[row + 1][col - 1] == 2||checkerboard.board[row + 1][col - 1] == 4)&& (row + 2) < 8 &&
//                         (col - 2) >= 0) {
//                         checkerboard.board[row + 2][col - 2] = 5;
//                         move.setPosition((col - 2) * 100 + 37, (row + 2) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//             }
//
//             if ((col + 1 < 8) && (row + 1 < 8)) {
//                 // Check if the down-right position is empty(black)
//                 if(checkerboard.CanTake(row,col)==false) {
//                     if (!checkerboard.IsOccupied(row + 1, col + 1)) {
//                         checkerboard.board[row + 1][col + 1] = 5;
//                         move.setPosition((col + 1) * 100 + 37, (row + 1) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//                 if (checkerboard.IsOccupied(row + 1, col + 1)) {//bicie down right
//                     if (!checkerboard.IsOccupied(row + 2, col + 2) && (checkerboard.board[row + 1][col + 1] == 2||checkerboard.board[row + 1][col + 1] == 4) && (row + 2) < 8 &&
//                         (col + 2) < 8) {
//                         checkerboard.board[row + 2][col + 2] = 5;
//                         move.setPosition((col + 2) * 100 + 37, (row + 2) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//
//                 }
//             }
//         }
//     }
//     if (checkerboard.board[row][col] == 4 && turn==2  ) {//black queen
//         if (row - 1 >= 0) {
//             if (col - 1 >= 0) {
//                 // Check if the down-left position dama czarna
//                 if(checkerboard.CanTake(row,col)==false) {
//                     if (!checkerboard.IsOccupied(row - 1, col - 1)) {
//                         checkerboard.board[row - 1][col - 1] = 5;
//                         move.setPosition((col - 1) * 100 + 37, (row - 1) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//                 if (checkerboard.IsOccupied(row - 1, col - 1)) {//bicie down left
//                     if (!checkerboard.IsOccupied(row - 2, col - 2) && (checkerboard.board[row - 1][col - 1] == 1 || checkerboard.board[row - 1][col - 1] == 3)  && (col - 2) >= 0 &&
//                         (row - 2) >= 0) {
//                         checkerboard.board[row - 2][col - 2] = 5;
//                         move.setPosition((col - 2) * 100 + 37, (row - 2) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//
//                     }
//                 }
//             }
//             if (col + 1 < 8) {//biala dama
//                 // Check if the down-right damablack
//                 if(checkerboard.CanTake(row,col)==false) {
//                     if (!checkerboard.IsOccupied(row - 1, col + 1)) {
//                         checkerboard.board[row - 1][col + 1] = 5;
//                         move.setPosition((col + 1) * 100 + 37, (row - 1) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//                 if (checkerboard.IsOccupied(row - 1, col + 1)) {//bicie down right
//                     if (!checkerboard.IsOccupied(row - 2, col + 2) && (checkerboard.board[row - 1][col + 1] == 1 || checkerboard.board[row - 1][col + 1] == 3) && (row - 2) >= 0 &&
//                         (col + 2) < 8) {
//                         checkerboard.board[row - 2][col + 2] = 5;
//                         move.setPosition((col + 2) * 100 + 37, (row - 2) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//             }
//         }
//         if (row + 1 < 8) {
//             if (col - 1 >= 0) {
//                 // Check if the top-left position is empty(black queen
//                 if(checkerboard.CanTake(row,col)==false) {
//                     if (!checkerboard.IsOccupied(row + 1, col - 1)) {
//                         checkerboard.board[row + 1][col - 1] = 5;
//                         move.setPosition((col - 1) * 100 + 37, (row + 1) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//                 if (checkerboard.IsOccupied(row + 1, col - 1)) {//top left bicie
//                     if (!checkerboard.IsOccupied(row + 2, col - 2) && (checkerboard.board[row + 1][col - 1] == 1 || checkerboard.board[row + 1][col - 1] == 3) && (row + 2) < 8 &&
//                         (col - 2) >= 0) {
//                         checkerboard.board[row + 2][col - 2] = 5;
//                         move.setPosition((col - 2) * 100 + 37, (row + 2) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//             }
//
//             if ((col + 1 < 8) && (row + 1 < 8)) {
//                 // Check if the top-right position is empty(black)
//                 if(checkerboard.CanTake(row,col)==false) {
//                     if (!checkerboard.IsOccupied(row + 1, col + 1)) {
//                         checkerboard.board[row + 1][col + 1] = 5;
//                         move.setPosition((col + 1) * 100 + 37, (row + 1) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//                 if (checkerboard.IsOccupied(row + 1, col + 1)) {
//                     if (!checkerboard.IsOccupied(row + 2, col + 2) && (checkerboard.board[row + 1][col + 1] == 1 || checkerboard.board[row + 1][col + 1] == 3) && (row + 2) < 8 &&
//                         (col + 2) < 8) {
//                         checkerboard.board[row + 2][col + 2] = 5;
//                         move.setPosition((col + 2) * 100 + 37, (row + 2) * 100 + 37);
//                         move.setFillColor(sf::Color::Green);
//                         possibleMoves.push_back(move);
//                     }
//                 }
//             }
//         }
//     }
// }
void CheckerboardSFML::CalculatePossibleMovesSFML(sf::Vector2f& currentPosition, sf::RenderWindow& window) {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (checkerboard.board[row][col] == 5) {
                checkerboard.board[row][col] = 0;
            }
        }
    }
    using Piece = Checkerboard::Piece;
    possibleMoves.clear();
    const int row = static_cast<int>(currentPosition.y / 100);
    const int col = static_cast<int>(currentPosition.x / 100);
    selectedPiecePosition = {col, row};

    const auto piece = static_cast<Piece>(checkerboard.board[row][col]);
    const bool validTurn = (piece == Piece::White && turn == 1) ||
                         (piece == Piece::Black && turn == 2) ||
                         (piece == Piece::WhiteQueen && turn == 1) ||
                         (piece == Piece::BlackQueen && turn == 2);
    if (!validTurn) return;

    //  kierunki i przeciwnicy
    const std::vector<std::pair<int, int>> directions = [&]() {
        if (piece == Piece::White) {
            return std::vector<std::pair<int, int>>{{-1, -1}, {-1, 1}};
        }
        if (piece == Piece::Black) {
            return std::vector<std::pair<int, int>>{{1, -1}, {1, 1}};
        }
        return std::vector<std::pair<int, int>>{{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    }();

    const std::vector<Piece> enemies = (piece == Piece::White || piece == Piece::WhiteQueen)
        ? std::vector<Piece>{Piece::Black, Piece::BlackQueen}
    : std::vector<Piece>{Piece::White, Piece::WhiteQueen};

    //  dodawanie ruchów
    auto addMove = [&](int r, int c) {
        checkerboard.board[r][c] = Piece::PossibleMove;
        sf::CircleShape move(15);
        move.setPosition(c * 100 + 37, r * 100 + 37);
        move.setFillColor(sf::Color::Green);
        possibleMoves.push_back(move);
    };

    const bool canTake = checkerboard.CanTake(row, col);

    for (const auto& [dr, dc] : directions) {
        const int newRow = row + dr;
        const int newCol = col + dc;

        // Sprawdź podstawowy ruch
        if (newRow >= 0 && newRow < 8 && newCol >= 0 && newCol < 8) {
            if ( !canTake && checkerboard.board[newRow][newCol] == 5) {
                addMove(newRow, newCol);
            }

            // Sprawdź bicie
            if (std::find(enemies.begin(), enemies.end(), checkerboard.board[newRow][newCol]) != enemies.end()) {
                const int jumpRow = row + 2*dr;
                const int jumpCol = col + 2*dc;
                if (jumpRow >= 0 && jumpRow < 8 && jumpCol >= 0 && jumpCol < 8 &&
                    checkerboard.board[jumpRow][jumpCol] == 5) {
                    addMove(jumpRow, jumpCol);
                }
            }
        }
    }
    std::cout << "Liczba możliwych ruchów: " << possibleMoves.size() << std::endl;
}

void CheckerboardSFML::MoveSFML(sf::RenderWindow &window) {
    int currentRow = selectedPiecePosition.y;
    int currentCol =selectedPiecePosition.x ;
    int newRow=PieceDestinationPosition.y;
    int newCol=PieceDestinationPosition.x;
    sf::Vector2f position(currentRow,currentCol);
    // Check if the move is valid and update the board state
    take(currentRow, currentCol, window);
    possibleMoves.clear();
    if (checkerboard.board[currentRow][currentCol]==1)turn=2;
    if (checkerboard.board[currentRow][currentCol]==2)turn=1;
    if (checkerboard.board[currentRow][currentCol]==3)turn=2;
    if (checkerboard.board[currentRow][currentCol]==4)turn=1;
    if (checkerboard.movePiece(currentRow, currentCol, newRow, newCol)) {
        possibleMoves.clear();
        DrawPieces(window);
    }else return;
}

sf::Vector2f CheckerboardSFML::Getdestination(const sf::Vector2f& destinationPosition){
    int row=static_cast<int>(destinationPosition.y/100);
    int col=static_cast<int>(destinationPosition.x/100);
    PieceDestinationPosition.x=col;
    PieceDestinationPosition.y=row;
    return PieceDestinationPosition;
}

bool CheckerboardSFML::take(int row, int col, sf::RenderWindow &window) {
    if (checkerboard.board[row - 1][col - 1] == 2 || checkerboard.board[row - 1][col + 1] == 2 || checkerboard.board[row - 1][col + 1] == 4 || checkerboard.board[row - 1][col - 1] == 4) {//lewa prawa strona biale
        if (checkerboard.movePiece(row, col, row - 2, col - 2)) {
            checkerboard.board[row - 1][col - 1] = 0;
            possibleMoves.clear();
            DrawPieces(window);
            return true;
        }
        if (checkerboard.movePiece(row, col, row - 2, col + 2)) {
            checkerboard.board[row - 1][col + 1] = 0;
            possibleMoves.clear();
            DrawPieces(window);
            return true;
        }
    }
    if (checkerboard.board[row + 1][col - 1] == 1 || checkerboard.board[row + 1][col + 1] == 1 || checkerboard.board[row + 1][col + 1] == 3 || checkerboard.board[row + 1][col - 1] == 3) {//lewaprawaczarne
        if (checkerboard.movePiece(row, col, row + 2, col - 2)) {
            checkerboard.board[row + 1][col - 1] = 0;
            possibleMoves.clear();
            DrawPieces(window);
            return true;
        }
        if (checkerboard.movePiece(row, col, row + 2, col + 2)) {
            checkerboard.board[row + 1][col + 1] = 0;
            possibleMoves.clear();
            DrawPieces(window);
            return true;
        }

    }
    if ((checkerboard.board[row + 1][col - 1] == 2 || checkerboard.board[row + 1][col + 1] == 2 || checkerboard.board[row + 1][col - 1] == 4 || checkerboard.board[row + 1][col + 1] == 4) &&checkerboard.board[row][col]==3) {//Damabiala
        if (checkerboard.movePiece(row, col, row + 2, col - 2)) {
            checkerboard.board[row + 1][col - 1] = 0;
            possibleMoves.clear();
            DrawPieces(window);
            return true;
        }
        if (checkerboard.movePiece(row, col, row + 2, col + 2)) {
            checkerboard.board[row + 1][col + 1] = 0;
            possibleMoves.clear();
            DrawPieces(window);
            return true;
        }
        if (checkerboard.movePiece(row, col, row - 2, col - 2)) {
            checkerboard.board[row - 1][col - 1] = 0;
            possibleMoves.clear();
            DrawPieces(window);
            return true;
        }
        if (checkerboard.movePiece(row, col, row - 2, col + 2)) {
            checkerboard.board[row - 1][col + 1] = 0;
            possibleMoves.clear();
            DrawPieces(window);
            return true;

        }

    }
    if ((checkerboard.board[row - 1][col - 1] == 1 || checkerboard.board[row - 1][col + 1] == 1 ||checkerboard.board[row - 1][col - 1] == 3 || checkerboard.board[row - 1][col + 1] == 3) && checkerboard.board[row][col]==4) {//DAma czarna
        if (checkerboard.movePiece(row, col, row - 2, col - 2)) {
            checkerboard.board[row - 1][col - 1] = 0;
            possibleMoves.clear();
            DrawPieces(window);
            return true;
        }
        if (checkerboard.movePiece(row, col, row - 2, col + 2)) {
            checkerboard.board[row - 1][col + 1] = 0;
            possibleMoves.clear();
            DrawPieces(window);
            return true;

        }
        if (checkerboard.movePiece(row, col, row + 2, col - 2)) {
            checkerboard.board[row + 1][col - 1] = 0;
            possibleMoves.clear();
            DrawPieces(window);
            return true;
        }
        if (checkerboard.movePiece(row, col, row + 2, col + 2)) {
            checkerboard.board[row + 1][col + 1] = 0;
            possibleMoves.clear();
            DrawPieces(window);
            return true;
        }
    }
    else return false;
}//TODO
//bots

void CheckerboardSFML::botMove(sf::RenderWindow &window) {
   //Determine the available black pieces on the checkerboard
    std::vector<sf::CircleShape *> blackPieces;
    for (auto &black: Blacks) {
        blackPieces.push_back(&black);
    }
    std::vector<sf::CircleShape *> blackQueens;
    for (auto &blue: Blues) {
        blackQueens.push_back(&blue);
    }

    // Randomly select one of the black pieces
    srand(static_cast<unsigned>(time(nullptr)));
    int randomNumber = rand() % 2;
    sf::CircleShape *selectedPiece = nullptr;
    sf::Vector2f currentPosition;
    bool hasValidMove = false;
    while (!hasValidMove && possibleMoves.empty()) {
        if (!blackQueens.empty()) {//jak queen albo pion nie ma ruchow a zostal wylosowany to wywala program
            if (!blackPieces.empty() &&randomNumber == 1) {//bialy pionek i nie mial ruchow
                int selectedPieceIndex = rand() % blackPieces.size();//if black pieces empty i to samo z queens trzeba juz tutaj zamiast na doleelse if bo wywala
                selectedPiece = blackPieces[selectedPieceIndex];
                currentPosition = selectedPiece->getPosition();
            }
            if (!blackQueens.empty() && randomNumber == 0) {
                int selectedPieceIndex = rand() % blackQueens.size();
                selectedPiece = blackQueens[selectedPieceIndex];
                currentPosition = selectedPiece->getPosition();
            }
        } if (blackPieces.empty()) {
            int selectedPieceIndex = rand() % blackQueens.size();
            selectedPiece = blackQueens[selectedPieceIndex];
            currentPosition = selectedPiece->getPosition();
        } else {
            int selectedPieceIndex = rand() % blackPieces.size();
            selectedPiece = blackPieces[selectedPieceIndex];
            currentPosition = selectedPiece->getPosition();
        }
        //Calculate the possible moves for the selected black piece
        CalculatePossibleMovesSFML(currentPosition, window);


        //Check if the selected piece has any move
        if (!possibleMoves.empty()) {
            hasValidMove = true;
        }
    }
    //Randomly select one of the possible moves
    int selectedMoveIndex = rand() % possibleMoves.size();
    sf::CircleShape selectedMove = possibleMoves[selectedMoveIndex];


    //Make the selected move on the checkerboard
    int moveRow = static_cast<int>(selectedMove.getPosition().y / 100);
    int moveCol = static_cast<int>(selectedMove.getPosition().x / 100);
    int pieceRow = static_cast<int>(currentPosition.y / 100);
    int pieceCol = static_cast<int>(currentPosition.x / 100);
    take(pieceRow, pieceCol, window);
    checkerboard.movePiece(pieceRow, pieceCol, moveRow, moveCol);

    //Update the graphical
    DrawPieces(window);

    //Switch  turn
    turn = 1;

}

void CheckerboardSFML::botMove2(sf::RenderWindow &window) {
    std::vector<sf::CircleShape *> blackPieces;
    for (auto &black: Blacks) {
        blackPieces.push_back(&black);
    }
    std::vector<sf::CircleShape *> blackQueens;
    for (auto &blue: Blues) {
        blackQueens.push_back(&blue);
    }

    srand(static_cast<unsigned>(time(nullptr)));
    int randomNumber = rand() % 2;
    sf::CircleShape *selectedPiece = nullptr;
    sf::Vector2f currentPosition;
    bool hasValidMove = false;
    while (!hasValidMove) {
        if (!blackQueens.empty()) {
            if ((!blackPieces.empty()&&randomNumber == 1) ) {
                int selectedPieceIndex = rand() % blackPieces.size();
                selectedPiece = blackPieces[selectedPieceIndex];
                currentPosition = selectedPiece->getPosition();
            }
            if (!blackQueens.empty()&&randomNumber == 0) {
                int selectedPieceIndex = rand() % blackQueens.size();
                selectedPiece = blackQueens[selectedPieceIndex];
                currentPosition = selectedPiece->getPosition();
            }
        }  if (blackPieces.empty()) {
            int selectedPieceIndex = rand() % blackQueens.size();
            selectedPiece = blackQueens[selectedPieceIndex];
            currentPosition = selectedPiece->getPosition();
        } else {
            int selectedPieceIndex = rand() % blackPieces.size();
            selectedPiece = blackPieces[selectedPieceIndex];
            currentPosition = selectedPiece->getPosition();
        }
        CalculatePossibleMovesSFML(currentPosition, window);
        if(possibleMoves.empty()){
            botMove(window);
            return;
        }
        std::vector<sf::CircleShape> safeMoves;
        for (const auto& move : possibleMoves) {
            int moveRow = static_cast<int>(move.getPosition().y / 100);
            int moveCol = static_cast<int>(move.getPosition().x / 100);
            int pieceRow = static_cast<int>(currentPosition.y / 100);
            int pieceCol = static_cast<int>(currentPosition.x / 100);

            Checkerboard tempBoard = checkerboard;
            tempBoard.movePiece(pieceRow, pieceCol, moveRow, moveCol);

            bool isSafeMove = true;
            for (auto &white : Whites) {
                int opponentRow = static_cast<int>(white.getPosition().y / 100);
                int opponentCol = static_cast<int>(white.getPosition().x / 100);
                if (tempBoard.CanTake(opponentRow, opponentCol)) {
                    isSafeMove = false;
                    break;
                }
            }
            if (isSafeMove) {
                safeMoves.push_back(move);
            }
        }

        if (!safeMoves.empty()) {
            int selectedMoveIndex = rand() % safeMoves.size();
            sf::CircleShape selectedMove = safeMoves[selectedMoveIndex];


            int moveRow = static_cast<int>(selectedMove.getPosition().y / 100);
            int moveCol = static_cast<int>(selectedMove.getPosition().x / 100);
            int pieceRow = static_cast<int>(currentPosition.y / 100);
            int pieceCol = static_cast<int>(currentPosition.x / 100);
            take(pieceRow, pieceCol, window);
            checkerboard.movePiece(pieceRow, pieceCol, moveRow, moveCol);

            DrawPieces(window);

            turn = 1;

            return;
        }
    }
}




