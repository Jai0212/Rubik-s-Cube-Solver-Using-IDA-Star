
#include "EdgePiece.h"
#include "iostream"

EdgePiece::EdgePiece(Colour colourFront, Colour colourSide) {
    colour = colourFront;
    otherColour = colourSide;
    colours = {colour, otherColour};
}

EdgePiece EdgePiece::flip() {
    EdgePiece flipEdgePiece(this->otherColour, this->colour);
    return flipEdgePiece;
}
