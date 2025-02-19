#pragma once
#include <vector>

namespace figure {
    const int BOARD_SIZE = 8;

    enum class Color {
        WHITE,
        BLACK,
        NONE
    };

    class Figure {
    protected:
        Color color;

    public:
        Figure(Color color);
        virtual ~Figure();

        Color getColor() const;
        virtual bool isValidMove(int x1, int y1, int x2, int y2, const std::vector<std::vector<Figure*>>& board) const = 0;
        virtual char getSymbol() const = 0;
    };
}