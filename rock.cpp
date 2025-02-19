#include "rock.h"

namespace figure {
    Rook::Rook(Color color) : Figure(color) {}

    bool Rook::isValidMove(int x1, int y1, int x2, int y2, const std::vector<std::vector<Figure*>>& board) const {
        if (x1 != x2 && y1 != y2) return false; // Ладья ходит только по прямой
        return true; // Упрощенная проверка (без учета препятствий)
    }

    char Rook::getSymbol() const {
        return (color == Color::WHITE) ? 'R' : 'r';
    }
}