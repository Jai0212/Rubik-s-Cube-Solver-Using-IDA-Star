
#ifndef RUBIKS_CUBE_SIDE_H
#define RUBIKS_CUBE_SIDE_H

#include "iostream"
#include "EdgePiece.h"
#include "Colour.h"
#include "CornerPiece.h"
#include "CentrePiece.h"

class Side {
public:
    Side() = default;
    std::vector <EdgePiece> edgePieces;
    std::vector <CornerPiece> cornerPieces;
    CentrePiece centrePiece;

    bool allSameColours();
};


#endif //RUBIKS_CUBE_SIDE_H
