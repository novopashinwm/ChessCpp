#include "queen.h"
namespace figure {
    Queen::Queen(Color color) : Figure(color) {}

    bool Queen::isValidMove(int x1, int y1, int x2, int y2, const std::vector<std::vector<Figure*>>& board) const {
        return x2*y1 == x1*y2 || (x1 == x2 || y1 == y2); //TODO королева должна объединять и ладью и слона
    }

    char Queen::getSymbol() const {
        return (color == Color::WHITE) ? 'Q' : 'q';
    }
}