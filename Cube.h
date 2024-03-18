
#ifndef RUBIKS_CUBE_CUBE_H
#define RUBIKS_CUBE_CUBE_H

#include "iostream"
#include "Pieces.h"
#include "Side.h"

class Cube {
public:
    std::vector<Side> sides;
    Colour red, orange, blue, green, yellow, white;

    std::vector <std::string> solution;

    Cube() :
            red("red", {255, 0, 0, 255}),
            orange("orange", {255, 165, 0, 255}),
            blue("blue", {0, 0, 255, 255}),
            green("green", {0, 255, 0, 255}),
            yellow("yellow", {255, 255, 0, 255}),
            white("white", {255, 255, 255, 255}) {
    }

    void generateNewSolvedCube();

    bool solved();
    bool whiteLayerSolved();
    bool secondLayerSolved();
    bool isYellowCross();
    void makeYellowCross();
    void solveFinalLayer();

    void scramble(int numOfScrambleMoves = 20);

    std::string inverse(std::string move);

    void U(Side &sideFacing);
    void R(Side &sideFacing);
    void F(Side &sideFacing);
    void D(Side &sideFacing);
    void L(Side &sideFacing);
    void B(Side &sideFacing);

    void UI(Side &sideFacing);
    void RI(Side &sideFacing);
    void FI(Side &sideFacing);
    void DI(Side &sideFacing);
    void LI(Side &sideFacing);
    void BI(Side &sideFacing);

    int indexOfSide(Side &sideToBeFound);
    int indexOfRight(Side &sideToBeFound);
    int indexOfUp(Side &sideToBeFound);
    int indexOfDown(Side &sideToBeFound);
    int indexOfLeft(Side &sideToBeFound);
    int indexOfOpposite(Side &sideToBeFound);

    int findHeuristicValue();
    bool DFS(int g, int depthLimit, int& outDepth, std::vector<std::string>& solution, std::string lastMove);
    bool IDAStar(int depthLimit);

    std::pair<int, int> findFinalLocationCorner(CornerPiece &cornerPiece);
    std::pair<int, int> findFinalLocationEdge(EdgePiece &edgePiece);

    int calculateHeuristicValueOfPiece(int currSide, int currPiece, int finalSide, int finalPiece, int isCornerOrEdge);
    int* findCoordinate(int sideIndex, int pieceIndex, int isCornerEdge);

    void doMove(std::string move);
    void undoMove(std::string move);

    std::string toString(Cube cubeToBeConvertedToString);
};


#endif //RUBIKS_CUBE_CUBE_H
