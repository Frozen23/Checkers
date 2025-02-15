//
// Created by kubam on 03.06.2023.
//

#ifndef CHECKERS_CHECKERBOARD_H
#define CHECKERS_CHECKERBOARD_H


class Checkerboard {
public:
    Checkerboard();
    enum Piece {
        Empty = 0,
        White = 1,
        Black = 2,
        WhiteQueen = 3,
        BlackQueen = 4,
        PossibleMove = 5
    };
    void SetPieces();
    int board[8][8]{};
    void DrawBoard();
    bool movePiece(int currentRow, int currentCol, int newRow, int newCol);
    bool IsOccupied(int row, int col);
    void CalculatePossibleMoves(int row,int col);//ToMakeSFML
    int GetGameState();
    bool IfCanMoveThere(int currentRow, int currentCol, int newRow, int newCol);
    bool CanTake(int row,int col);
    void Promotion();
    bool IfCanBeBeaten(int row,int col);
private:

};


#endif //CHECKERS_CHECKERBOARD_H
