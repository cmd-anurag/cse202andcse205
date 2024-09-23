#include<iostream>
using namespace std;

enum PIECE {
    PAWN = 1,
    BISHOP = 3,
    KNIGHT = 3,
    ROOK = 5,
    QUEEN = 9
};

enum class PieceValue {
    PAWN = 1,
    BISHOP = 3,
    KNIGHT = 3,
    ROOK = 5,
    QUEEN = 9
};


int main()
{
    // PIECE currentPiece = PAWN;
    // cout << "The current piece's value is " << currentPiece;

    PieceValue value = PieceValue::QUEEN;
    cout << "The value of queen is " << static_cast<int>(value);

    return 0;
}