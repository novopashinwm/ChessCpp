#include "Pawn.h"
namespace figure {
    Pawn::Pawn(Color color) : Figure(color) {}

    bool Pawn::isValidMove(int x1, int y1, int x2, int y2, const std::vector<std::vector<Figure*>>& board) const {
        int direction = (color == Color::WHITE) ? 1 : -1;
        if (x2 == x1 + direction && (y2 == y1 && !board[x2][y2])) {
            if (isFirstMove)
                isFirstMove = false;
            return true; // Ход на одну клетку вперед
        }
        if (isFirstMove && x2 == x1 + direction * 2 && y2 == y1 && !board[x2][y2]) {
            isFirstMove = false;
            return true; // Ход на две клетки вперед
        }
        return false;
    }

    char Pawn::getSymbol() const {
        return (color == Color::WHITE) ? 'P' : 'p';
    }
}