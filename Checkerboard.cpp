//
// Created by kubam on 03.06.2023.
//

#include <random>
#include "Checkerboard.h"
#include "iostream"
//boardsize 8 squaresize 100
Checkerboard::Checkerboard(){
    SetPieces();
}

void::Checkerboard::SetPieces(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            board[i][j]=0;
        }
    }
    for (int row = 5; row < 8; row++) {
        for (int col = 0; col < 8; col += 1) {
            if ((col + row) % 2 == 1) {
                board[row][col]=1;
            }
        }
    }
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 8; col += 1) {
            if ((col + row) % 2 == 1) {
                board[row][col]=2;
            }
        }
    }
}

void Checkerboard::DrawBoard() {
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            std::cout<<board[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

bool Checkerboard::IsOccupied(int row, int col){
    if(board[row][col]!=0&&board[row][col]!=5) return true;
    return false;
}

bool Checkerboard::movePiece(int currentRow, int currentCol, int newRow, int newCol) {
    if (newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8 ||board[newRow][newCol]!=5){
        return false ;
    }
        // Update the board state
        board[newRow][newCol] = board[currentRow][currentCol];
        board[currentRow][currentCol] = 0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]==5)board[i][j]=0;}}
        return true;
    }

void Checkerboard::CalculatePossibleMoves(int row,int col) {
    // Check for valid diagonal moves
    if (board[row][col] == 1 ) {
        if (row - 1 >= 0) {
            if (col - 1 >= 0) {
                // Check if the top-left position is empty(white)
                    if (!IsOccupied(row - 1, col - 1)) {
                        board[row - 1][col - 1] = 5;
                    }
                //ruch z biciem(dokonczyc dla czarnych i bialcyh
                if (IsOccupied(row - 1, col - 1)) {
                    if (!IsOccupied(row - 2, col - 2) && (board[row - 1][col - 1] == 2||board[row-1][col-1]==4)
                        && (col - 2) >= 0 &&
                        (row - 2) >= 0) {
                        board[row - 2][col - 2] = 5;

                    }
                }
            }
            if (col + 1 < 8) {
                // Check if the top-right position is empty(white)

                    if (!IsOccupied(row - 1, col + 1)) {
                        board[row - 1][col + 1] = 5;

                    }

                if (IsOccupied(row - 1, col + 1)) {//biciebialego
                    if (!IsOccupied(row - 2, col + 2) && (board[row - 1][col + 1] == 2||board[row-1][col+1]==4)
                        && (row - 2) >= 0 &&
                        (col + 2) <= 8) {
                        board[row - 2][col + 2] = 5;
                    }
                }
            }
        }
    }//blacks
    if (board[row][col] == 2   ) {
        if (row + 1 <= 8) {
            if (col - 1 >= 0) {
                // Check if the top-left position is empty(black)

                    if (!IsOccupied(row + 1, col - 1)) {
                        board[row + 1][col - 1] = 5;
                    }

                if (IsOccupied(row + 1, col - 1)) {
                    if (!IsOccupied(row + 2, col - 2) && (board[row + 1][col - 1] == 1||board[row + 1][col - 1] == 3)
                        && (row + 2) < 8  &&(col - 2) >= 0) {
                       board[row + 2][col - 2] = 5;

                    }
                }
            }

            if ((col + 1 < 8) && (row + 1 < 8)) {
                // Check if the top-right position is empty(black)

                    if (!IsOccupied(row + 1, col + 1)) {
                       board[row + 1][col + 1] = 5;
                    }

                if (IsOccupied(row + 1, col + 1)) {
                    if (!IsOccupied(row + 2, col + 2) && (board[row + 1][col + 1] == 1 ||board[row+1][col+1]==3)
                        && (row + 2) < 8 &&(col + 2) <= 8) {
                        board[row + 2][col + 2] = 5;
                    }

                }
            }
        }
    }
    if (board[row][col] == 3   ) {//biala dama
        if (row - 1 >= 0) {
            if (col - 1 >= 0) {
                // Check if the top-left position is empty(white)

                    if (!IsOccupied(row - 1, col - 1)) {
                       board[row - 1][col - 1] = 5;
                    }

                if (IsOccupied(row - 1, col - 1)) {//lewe bicie bialej damy
                    if (!IsOccupied(row - 2, col - 2) && (board[row - 1][col - 1] == 2||board[row - 1][col - 1] == 4) && (col - 2) >= 0 &&
                        (row - 2) >= 0) {
                        board[row - 2][col - 2] = 5;

                    }
                }
            }
            if (col + 1 < 8) {
                // Check if the top-right position is empty(white)

                    if (!IsOccupied(row - 1, col + 1)) {
                       board[row - 1][col + 1] = 5;
                    }

                if (IsOccupied(row - 1, col + 1)) {//biciebialego prawe
                    if (!IsOccupied(row - 2, col + 2) && (board[row - 1][col + 1] == 2||board[row - 1][col + 1] == 4) && (row - 2) >= 0 &&
                        (col + 2) < 8) {
                        board[row - 2][col + 2] = 5;
                    }
                }
            }
        }
        if (row + 1 < 8) {
            if (col - 1 >= 0) {
                // Check if the down-left bialej damy

                    if (!IsOccupied(row + 1, col - 1)) {
                        board[row + 1][col - 1] = 5;
                    }

                if (IsOccupied(row + 1, col - 1)) {//down left bicie bialej damy
                    if (!IsOccupied(row + 2, col - 2) && (board[row + 1][col - 1] == 2||board[row + 1][col - 1] == 4)&& (row + 2) < 8 &&
                        (col - 2) >= 0) {
                        board[row + 2][col - 2] = 5;
                    }
                }
            }

            if ((col + 1 < 8) && (row + 1 < 8)) {
                // Check if the down-right position is empty(black)

                    if (!IsOccupied(row + 1, col + 1)) {
                        board[row + 1][col + 1] = 5;
                    }

                if (IsOccupied(row + 1, col + 1)) {//bicie down right
                    if (!IsOccupied(row + 2, col + 2) && (board[row + 1][col + 1] == 2||board[row + 1][col + 1] == 4) && (row + 2) < 8 &&
                        (col + 2) < 8) {
                        board[row + 2][col + 2] = 5;
                    }

                }
            }
        }
    }
    if (board[row][col] == 4   ) {//black queen
        if (row - 1 >= 0) {
            if (col - 1 >= 0) {
                // Check if the down-left position dama czarna

                    if (!IsOccupied(row - 1, col - 1)) {
                        board[row - 1][col - 1] = 5;
                    }

                if (IsOccupied(row - 1, col - 1)) {//bicie down left
                    if (!IsOccupied(row - 2, col - 2) && (board[row - 1][col - 1] == 1 || board[row - 1][col - 1] == 3)  && (col - 2) >= 0 &&
                        (row - 2) >= 0) {
                        board[row - 2][col - 2] = 5;
                    }
                }
            }
            if (col + 1 < 8) {//biala dama
                // Check if the down-right damablack

                    if (!IsOccupied(row - 1, col + 1)) {
                        board[row - 1][col + 1] = 5;
                    }

                if (IsOccupied(row - 1, col + 1)) {//bicie down right
                    if (!IsOccupied(row - 2, col + 2) && (board[row - 1][col + 1] == 1 || board[row - 1][col + 1] == 3) && (row - 2) >= 0 &&
                        (col + 2) < 8) {
                        board[row - 2][col + 2] = 5;
                    }
                }
            }
        }
        if (row + 1 < 8) {
            if (col - 1 >= 0) {
                // Check if the top-left position is empty(black queen
                    if (!IsOccupied(row + 1, col - 1)) {
                        board[row + 1][col - 1] = 5;
                    }

                if (IsOccupied(row + 1, col - 1)) {//top left bicie
                    if (!IsOccupied(row + 2, col - 2) && (board[row + 1][col - 1] == 1 || board[row + 1][col - 1] == 3) && (row + 2) < 8 &&
                        (col - 2) >= 0) {
                        board[row + 2][col - 2] = 5;
                    }
                }
            }
            if ((col + 1 < 8) && (row + 1 < 8)) {
                // Check if the top-right position is empty(black)
                    if (!IsOccupied(row + 1, col + 1)) {
                        board[row + 1][col + 1] = 5;
                    }

                if (IsOccupied(row + 1, col + 1)) {
                    if (!IsOccupied(row + 2, col + 2) && (board[row + 1][col + 1] == 1 || board[row + 1][col + 1] == 3) && (row + 2) < 8 &&
                        (col + 2) < 8) {
                        board[row + 2][col + 2] = 5;
                    }
                }
            }
        }
    }
}//TODO

int Checkerboard::GetGameState() {
    int counter=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]==1 ||board[i][j]==3)counter++;}}
    if(counter==0)return 2;
    counter=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[i][j]==2||board[i][j]==4)counter++;}}
    if(counter==0)return 1;
    else return 0;

}

bool Checkerboard::IfCanMoveThere(int currentRow, int currentCol, int newRow, int newCol) {
    // Implement your own logic here based on the game rules

    if (newRow < 0 || newRow >= 8 || newCol < 0 || newCol >= 8) {
        return false ;
    }

    // Example: Check if the destination is a valid empty square
    if ( board[newRow][newCol] != 5) {
        return false;
    }
    else {
        return true;
    }
    // Handle special cases if needed

}

bool Checkerboard::CanTake(int row,int col) {//potrzebne do wyswietlania
    CalculatePossibleMoves(row,col);
    if ((board[row - 1][col - 1] == 2 || board[row - 1][col + 1] == 2|| board[row - 1][col - 1] == 4 || board[row - 1][col + 1] == 4)&&board[row][col]==1) {//lewa prawa strona biale
        if (IfCanMoveThere(row, col, row - 2, col - 2)) {
            return true;
        }
        if (IfCanMoveThere(row, col, row - 2, col + 2)) {
            return true;
        }
    }
    CalculatePossibleMoves(row,col);
    if ((board[row + 1][col - 1] == 1 || board[row + 1][col + 1] == 1 ||board[row + 1][col - 1] == 3 || board[row + 1][col + 1] == 3)&&board[row][col]==2) {//lewaprawaczarne
        if (IfCanMoveThere(row, col, row + 2, col - 2)) {
            return true;
        }
        if (IfCanMoveThere(row, col, row + 2, col + 2)) {
            return true;
        }
    }
    if((board[row - 1][col - 1] == 2 || board[row - 1][col + 1] == 2|| board[row - 1][col - 1] == 4 || board[row - 1][col + 1] == 4
    ||board[row + 1][col - 1] == 2 || board[row + 1][col + 1] == 2 ||board[row + 1][col - 1] == 4 || board[row + 1][col + 1] == 4)&&board[row][col]==3)  {
        if (IfCanMoveThere(row, col, row - 2, col - 2)) {
            return true;
        }
        if (IfCanMoveThere(row, col, row - 2, col + 2)) {
            return true;
        }
        if (IfCanMoveThere(row, col, row + 2, col - 2)) {
            return true;
        }
        if (IfCanMoveThere(row, col, row + 2, col + 2)) {
            return true;
        }
    }
    if((board[row - 1][col - 1] == 1 || board[row - 1][col + 1] == 1|| board[row - 1][col - 1] == 3 || board[row - 1][col + 1] == 3
        ||board[row + 1][col - 1] == 1 || board[row + 1][col + 1] == 1 ||board[row + 1][col - 1] == 3 || board[row + 1][col + 1] == 3)&&board[row][col]==4)  {
        if (IfCanMoveThere(row, col, row - 2, col - 2)) {
            return true;
        }
        if (IfCanMoveThere(row, col, row - 2, col + 2)) {
            return true;
        }
        if (IfCanMoveThere(row, col, row + 2, col - 2)) {
            return true;
        }
        if (IfCanMoveThere(row, col, row + 2, col + 2)) {
            return true;
        }
    }else return false;

}//TODO

void Checkerboard::Promotion() {
    for(int col=0;col<8;col++){
        if(board[0][col]==1)board[0][col]=3;
    }
    for(int col=0;col<8;col++){
        if(board[7][col]==2)board[7][col]=4;
    }
}

//bots

bool Checkerboard::IfCanBeBeaten(int row, int col) {
    if (col - 1 >= 0 && row - 1 >= 0 && col + 1 < 8) {
        if ((board[col - 1][row + 1] == 1 ||board[col - 1][row - 1] == 3) && board[row - 1][col + 1] == 0) {//lewy dolny spr czy bialy
            return true;
        }

    }
    if (col - 1 >= 0 && row + 1 <8  && col + 1 < 8 && row-1>=0)  {
        if ((board[col + 1][row + 1] == 1||board[col + 1][row + 1] == 3) && board[row - 1][col - 1] == 0) {
            return true;
        }

    }else return false;
}
