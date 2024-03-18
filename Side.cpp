
#include "Side.h"

bool Side::allSameColours() {
    for (auto edgePiece: edgePieces) {
        if (edgePiece.colour.colourName != centrePiece.colour.colourName) {
            return false;
        }
    }
    for (auto cornerPiece: cornerPieces) {
        if (cornerPiece.colour.colourName != centrePiece.colour.colourName) {
            return false;
        }
    }
    return true;
}
