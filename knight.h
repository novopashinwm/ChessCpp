#include "figure.h"

namespace figure{
    class Knight : public Figure {
    public:
        Knight(Color color);
        bool isValidMove(int x1, int y1, int x2, int y2, const std::vector<std::vector<Figure*>>& board) const override;
        char getSymbol() const override;
    };
}