
#include "CornerPiece.h"

#include "iostream"
#include "Colour.h"
#include "vector"
#include <utility>


CornerPiece::CornerPiece(Colour colourFront, Colour colourTop, Colour colourSide) {
    colour = colourFront;
    topColour = colourTop;
    sideColour = colourSide;
    colours = {colour, topColour, sideColour};
}

CornerPiece CornerPiece::top() {
    CornerPiece topCornerPiece(this->topColour, this->colour, this->sideColour);
    return topCornerPiece;
}

CornerPiece CornerPiece::side() {
    CornerPiece sideCornerPiece(this->sideColour, this->topColour, this->colour);
    return sideCornerPiece;
}