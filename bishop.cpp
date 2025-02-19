#include "bishop.h"

namespace figure {
    Bishop::Bishop(Color color) : Figure(color) {}

    bool Bishop::isValidMove(int x1, int y1, int x2, int y2, const std::vector<std::vector<Figure*>>& board) const {
       return x2*y1 == x1*y2;
    }

    char Bishop::getSymbol() const {
        return (color == Color::WHITE) ? 'B' : 'b';
    }
}