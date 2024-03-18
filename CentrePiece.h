
#ifndef RUBIKS_CUBE_CENTREPIECE_H
#define RUBIKS_CUBE_CENTREPIECE_H

#include "iostream"
#include "Pieces.h"

class CentrePiece : public Pieces {

public:
    Colour colour;
    std::vector <Colour> colours;

    CentrePiece() = default;

    CentrePiece(Colour colourFront);

};


#endif //RUBIKS_CUBE_CENTREPIECE_H
