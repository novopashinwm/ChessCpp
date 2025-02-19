#include "figure.h"

namespace figure {
    Figure::Figure(Color color) : color(color) {}
    Figure::~Figure() {}

    figure::Color figure::Figure::getColor() const {
        return color;
    }
}