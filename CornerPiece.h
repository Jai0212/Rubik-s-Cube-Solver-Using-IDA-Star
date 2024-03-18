
#ifndef RUBIKS_CUBE_CORNERPIECE_H
#define RUBIKS_CUBE_CORNERPIECE_H

#include "iostream"
#include "Colour.h"
#include "Pieces.h"

class CornerPiece : public Pieces {
public:
    Colour colour;
    Colour topColour;
    Colour sideColour;

    std::vector<Colour> colours;

    CornerPiece() = default;

    CornerPiece(Colour colourFront, Colour colourTop, Colour colourSide);

    CornerPiece top();

    CornerPiece side();
};


#endif //RUBIKS_CUBE_CORNERPIECE_H
