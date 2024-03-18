
#include "Colour.h"

Colour::Colour(std::string colourName, std::vector<int> colourRepresentation) {
    this->colourName = colourName;
    this->colourRepresentation = colourRepresentation;
    this->r = float(colourRepresentation[0]) / 255.0;
    this->g = float(colourRepresentation[1]) / 255.0;
    this->b = float(colourRepresentation[2]) / 255.0;
}

