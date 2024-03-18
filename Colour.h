//
// Created by Jai Joshi on 2024-03-14.
//
#include <iostream>
#include <vector>

#ifndef RUBIKS_CUBE_COLOUR_H
#define RUBIKS_CUBE_COLOUR_H


class Colour {
public:
    std::string colourName;
    std::vector <int> colourRepresentation;
    float r, g, b;

    Colour(std::string colourName, std::vector<int> colourRepresentation);

    Colour() = default;
};


#endif //RUBIKS_CUBE_COLOUR_H
