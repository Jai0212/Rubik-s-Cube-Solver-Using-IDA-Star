
#ifndef RUBIKS_CUBE_EDGEPIECE_H
#define RUBIKS_CUBE_EDGEPIECE_H

#include "iostream"
#include "Pieces.h"

class EdgePiece : public Pieces {
public:
    Colour colour;
    Colour otherColour;

    std::vector <Colour> colours;

    EdgePiece() = default;

    EdgePiece(Colour colourFront, Colour colourSide);

    EdgePiece flip();
};


#endif //RUBIKS_CUBE_EDGEPIECE_H
