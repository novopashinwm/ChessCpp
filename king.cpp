//
// Created by novop on 19.02.2025.
//

#include "king.h"
#include <algorithm>
namespace figure {
    King::King(Color color) : Figure(color) {}

    bool King::isValidMove(int x1, int y1, int x2, int y2, const std::vector<std::vector<Figure*>>& board) const {
        return std::abs(x2-x1)<=1 && std::abs(y2-y1) <=1 ; //TODO король дальше 1 клетки не ходит
    }

    char King::getSymbol() const {
        return (color == Color::WHITE) ? 'K' : 'k';
    }
}