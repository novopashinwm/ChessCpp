#include "knight.h"

namespace figure {
    Knight::Knight(Color color) : Figure(color) {}

    bool Knight::isValidMove(int x1, int y1, int x2, int y2, const std::vector<std::vector<Figure*>>& board) const {
        return false; // TODO - реализовать проверку для коня
    }

    char Knight::getSymbol() const {
        return (color == Color::WHITE) ? 'N' : 'n';
    }
}