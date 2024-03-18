#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <map>

#include <cstdio>
#define GL_SILENCE_DEPRECATION
#include "include/glew.h"

#include <OpenGL/gl.h>
#include "include/glfw3.h"
#include "GLUT/glut.h"
#include "OpenGL/glu.h"

#include <cstdlib>
#include "Cube.h"
#include <thread>
#include <atomic>
#include <chrono>

#include <random>
#include <ctime>

std::atomic<bool> running(true);

GLfloat T = 0;
Cube cube;
Cube displayCube;

void userInputThread() {
    while (running) {
        std::string userInput;
        std::getline(std::cin, userInput);

        int index = -1;

        if (userInput == "solve") {
            cube.IDAStar(cube.findHeuristicValue() + 1);

            std::cout << "Solution: ";

            for (auto sol: cube.solution) {
                std::cout << sol << " ";
            }
        }
        else if(userInput == "scramble") {
            cube.scramble(5);
        }
        else if(userInput == "solved") {
            std::cout << cube.solved() << "\n";
        }
        // Do something with the input
        if (userInput.substr(0, 1) == "w") {
            index = 0;
        }
        else if (userInput.substr(0, 1) == "o") {
            index = 1;
        }
        else if (userInput.substr(0, 1) == "y") {
            index = 2;
        }
        else if (userInput.substr(0, 1) == "r") {
            index = 3;
        }
        else if (userInput.substr(0, 1) == "b") {
            index = 4;
        }
        else if (userInput.substr(0, 1) == "g") {
            index = 5;
        }
        else {
        }

        if (userInput.substr(userInput.length() - 1, userInput.length()) == "I") {

            if (userInput.substr(userInput.length() - 2, userInput.length() - 1) == "UI") {
                cube.UI(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 2, userInput.length() - 1) == "DI") {
                cube.DI(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 2, userInput.length() - 1) == "RI") {
                cube.RI(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 2, userInput.length() - 1) == "LI") {
                cube.LI(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 2, userInput.length() - 1) == "FI") {
                cube.FI(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 2, userInput.length() - 1) == "BI") {
                cube.BI(cube.sides[index]);
            }
            else {
            }
        }

        else {
            if (userInput.substr(userInput.length() - 1, userInput.length()) == "U") {
                cube.U(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 1, userInput.length()) == "D") {
                cube.D(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 1, userInput.length()) == "R") {
                cube.R(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 1, userInput.length()) == "L") {
                cube.L(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 1, userInput.length()) == "F") {
                cube.F(cube.sides[index]);
            }
            else if (userInput.substr(userInput.length() - 1, userInput.length()) == "B") {
                cube.B(cube.sides[index]);
            }
            else {
            }
        }
    }
}


void spin() {

    T += 0.5;

    if (T > 360) {
        T = 0;
    }

    glutPostRedisplay();
}

void initializeWindow() {
    glClearColor(0, 0, 0, 1);
    glColor3f(1, 0, 0);

    glEnable(GL_DEPTH_TEST);
}

void line(GLfloat A[], GLfloat B[]) {

//    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3);

    glBegin(GL_LINES);
    glVertex3fv(A);
    glVertex3fv(B);
    glEnd();

//    glFlush();
}

void face(GLfloat A[], GLfloat B[], GLfloat C[], GLfloat D[]) {

    glBegin(GL_POLYGON);
    glVertex3fv(A);
    glVertex3fv(B);
    glVertex3fv(C);
    glVertex3fv(D);
    glEnd();

}

void drawSide(GLfloat vertices[][3], int index) {

    glColor3f(cube.sides[index].cornerPieces[0].colour.r, cube.sides[index].cornerPieces[0].colour.g, cube.sides[index].cornerPieces[0].colour.b);
    face(vertices[0], vertices[1], vertices[5], vertices[4]);

    glColor3f(cube.sides[index].edgePieces[0].colour.r, cube.sides[index].edgePieces[0].colour.g, cube.sides[index].edgePieces[0].colour.b);
    face(vertices[1], vertices[2], vertices[6], vertices[5]);

    glColor3f(cube.sides[index].cornerPieces[1].colour.r, cube.sides[index].cornerPieces[1].colour.g, cube.sides[index].cornerPieces[1].colour.b);
    face(vertices[2], vertices[3], vertices[7], vertices[6]);

    glColor3f(cube.sides[index].edgePieces[3].colour.r, cube.sides[index].edgePieces[3].colour.g, cube.sides[index].edgePieces[3].colour.b);
    face(vertices[4], vertices[5], vertices[9], vertices[8]);

    glColor3f(cube.sides[index].centrePiece.colour.r, cube.sides[index].centrePiece.colour.g, cube.sides[index].centrePiece.colour.b);
    face(vertices[5], vertices[6], vertices[10], vertices[9]); // CENTRE

    glColor3f(cube.sides[index].edgePieces[1].colour.r, cube.sides[index].edgePieces[1].colour.g, cube.sides[index].edgePieces[1].colour.b);
    face(vertices[6], vertices[7], vertices[11], vertices[10]);

    glColor3f(cube.sides[index].cornerPieces[3].colour.r, cube.sides[index].cornerPieces[3].colour.g, cube.sides[index].cornerPieces[3].colour.b);
    face(vertices[8], vertices[9], vertices[13], vertices[12]);

    glColor3f(cube.sides[index].edgePieces[2].colour.r, cube.sides[index].edgePieces[2].colour.g, cube.sides[index].edgePieces[2].colour.b);
    face(vertices[9], vertices[10], vertices[14], vertices[13]);

    glColor3f(cube.sides[index].cornerPieces[2].colour.r, cube.sides[index].cornerPieces[2].colour.g, cube.sides[index].cornerPieces[2].colour.b);
    face(vertices[10], vertices[11], vertices[15], vertices[14]);

    //Vertical
    glColor3f(0, 0, 0);
    line(vertices[1], vertices[13]);
    glColor3f(0, 0, 0);
    line(vertices[2], vertices[14]);
    glColor3f(0, 0, 0);
    line(vertices[0], vertices[12]);
    glColor3f(0, 0, 0);
    line(vertices[3], vertices[15]);

    //Horizontal
    glColor3f(0, 0, 0);
    line(vertices[4], vertices[7]);
    glColor3f(0, 0, 0);
    line(vertices[8], vertices[11]);
    glColor3f(0, 0, 0);
    line(vertices[0], vertices[3]);
    glColor3f(0, 0, 0);
    line(vertices[12], vertices[15]);

}

void draw() {

//    cube.U(cube.sides[0]);

//    std::cout << cube.sides[0].edgePieces[1].colours[0].colourName << "\n";
//    std::cout << cube.solved()<< "\n";

    // Z is reversed

    GLfloat sideOneVertices[16][3] = {
            {-0.45, 0.45, 0.45},
            {-0.15, 0.45, 0.45},
            {0.15, 0.45, 0.45},
            {0.45, 0.45, 0.45},

            {-0.45, 0.15, 0.45},
            {-0.15, 0.15, 0.45},
            {0.15, 0.15, 0.45},
            {0.45, 0.15, 0.45},

            {-0.45, -0.15, 0.45},
            {-0.15, -0.15, 0.45},
            {0.15, -0.15, 0.45},
            {0.45, -0.15, 0.45},

            {-0.45, -0.45, 0.45},
            {-0.15, -0.45, 0.45},
            {0.15, -0.45, 0.45},
            {0.45, -0.45, 0.45}
    };

    GLfloat sideTwoVertices[16][3] = {
            {-0.45, 0.45, -0.45},
            {-0.15, 0.45, -0.45},
            {0.15, 0.45, -0.45},
            {0.45, 0.45, -0.45},

            {-0.45, 0.45, -0.15},
            {-0.15, 0.45, -0.15},
            {0.15, 0.45, -0.15},
            {0.45, 0.45, -0.15},

            {-0.45, 0.45, 0.15},
            {-0.15, 0.45, 0.15},
            {0.15, 0.45, 0.15},
            {0.45, 0.45, 0.15},

            {-0.45, 0.45, 0.45},
            {-0.15, 0.45, 0.45},
            {0.15, 0.45, 0.45},
            {0.45, 0.45, 0.45}
    };

    GLfloat sideThreeVertices[16][3] = {
            {0.45, 0.45, -0.45},
            {0.15, 0.45, -0.45},
            {-0.15, 0.45, -0.45},
            {-0.45, 0.45, -0.45},

            {0.45, 0.15, -0.45},
            {0.15, 0.15, -0.45},
            {-0.15, 0.15, -0.45},
            {-0.45, 0.15, -0.45},

            {0.45, -0.15, -0.45},
            {0.15, -0.15, -0.45},
            {-0.15, -0.15, -0.45},
            {-0.45, -0.15, -0.45},

            {0.45, -0.45, -0.45},
            {0.15, -0.45, -0.45},
            {-0.15, -0.45, -0.45},
            {-0.45, -0.45, -0.45}
    };

    GLfloat sideFourVertices[16][3] = {
            {-0.45, -0.45, 0.45},
            {-0.15, -0.45, 0.45},
            {0.15, -0.45, 0.45},
            {0.45, -0.45, 0.45},

            {-0.45, -0.45, 0.15},
            {-0.15, -0.45, 0.15},
            {0.15, -0.45, 0.15},
            {0.45, -0.45, 0.15},

            {-0.45, -0.45, -0.15},
            {-0.15, -0.45, -0.15},
            {0.15, -0.45, -0.15},
            {0.45, -0.45, -0.15},

            {-0.45, -0.45, -0.45},
            {-0.15, -0.45, -0.45},
            {0.15, -0.45, -0.45},
            {0.45, -0.45, -0.45}
    };

//    GLfloat sideFiveVertices[16][3] = {
//            {0.45, 0.45, 0.45},
//            {0.45, 0.45, 0.15},
//            {0.45, 0.45, -0.15},
//            {0.45, 0.45, -0.45},
//
//            {0.45, 0.15, 0.45},
//            {0.45, 0.15, 0.15},
//            {0.45, 0.15, -0.15},
//            {0.45, 0.15, -0.45},
//
//            {0.45, -0.15, 0.45},
//            {0.45, -0.15, 0.15},
//            {0.45, -0.15, -0.15},
//            {0.45, -0.15, -0.45},
//
//            {0.45, -0.45, 0.45},
//            {0.45, -0.45, 0.15},
//            {0.45, -0.45, -0.15},
//            {0.45, -0.45, -0.45}
//    };
//
//    GLfloat sideSixVertices[16][3] = {
//            {-0.45, 0.45, -0.45},
//            {-0.45, 0.45, -0.15},
//            {-0.45, 0.45, 0.15},
//            {-0.45, 0.45, 0.45},
//
//            {-0.45, 0.15, -0.45},
//            {-0.45, 0.15, -0.15},
//            {-0.45, 0.15, 0.15},
//            {-0.45, 0.15, 0.45},
//
//            {-0.45, -0.15, -0.45},
//            {-0.45, -0.15, -0.15},
//            {-0.45, -0.15, 0.15},
//            {-0.45, -0.15, 0.45},
//
//            {-0.45, -0.45, -0.45},
//            {-0.45, -0.45, -0.15},
//            {-0.45, -0.45, 0.15},
//            {-0.45, -0.45, 0.45}
//    };

    GLfloat sideFiveVertices[16][3] = {
            {-0.45, 0.45, 0.45},
            {-0.45, 0.45, 0.15},
            {-0.45, 0.45, -0.15},
            {-0.45, 0.45, -0.45},

            {-0.45, 0.15, 0.45},
            {-0.45, 0.15, 0.15},
            {-0.45, 0.15, -0.15},
            {-0.45, 0.15, -0.45},

            {-0.45, -0.15, 0.45},
            {-0.45, -0.15, 0.15},
            {-0.45, -0.15, -0.15},
            {-0.45, -0.15, -0.45},

            {-0.45, -0.45, 0.45},
            {-0.45, -0.45, 0.15},
            {-0.45, -0.45, -0.15},
            {-0.45, -0.45, -0.45}
    };

    GLfloat sideSixVertices[16][3] = {
            {0.45, 0.45, -0.45},
            {0.45, 0.45, -0.15},
            {0.45, 0.45, 0.15},
            {0.45, 0.45, 0.45},

            {0.45, 0.15, -0.45},
            {0.45, 0.15, -0.15},
            {0.45, 0.15, 0.15},
            {0.45, 0.15, 0.45},

            {0.45, -0.15, -0.45},
            {0.45, -0.15, -0.15},
            {0.45, -0.15, 0.15},
            {0.45, -0.15, 0.45},

            {0.45, -0.45, -0.45},
            {0.45, -0.45, -0.15},
            {0.45, -0.45, 0.15},
            {0.45, -0.45, 0.45}
    };

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glRotatef(T, 0.2, 1, 0);

    drawSide(sideOneVertices, 0);
    drawSide(sideTwoVertices, 1);
    drawSide(sideThreeVertices, 2);
    drawSide(sideFourVertices, 3);
    drawSide(sideFiveVertices, 4); //doubt
    drawSide(sideSixVertices, 5); //doubt

    glutSwapBuffers();
}


int main(int argC, char*argV[])
{
    cube.generateNewSolvedCube();
    displayCube.generateNewSolvedCube();

    std::cout << "Welcome!\n";
    std::cout << "Type 'scramble' to scramble the cube\n";
    std::cout << "Type 'solve' to solve the cube\n";
    std::cout << "Enter commands to move the cube in the format 'white R'\n";

    fflush(stdin);

    std::thread inputThread(userInputThread);

    glutInit(&argC, argV);

    glutInitWindowPosition(250, 50);
    glutInitWindowSize(600, 600);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Rubik's Cube");

    initializeWindow();
    glutDisplayFunc(draw);

    glutIdleFunc(spin);

    glutMainLoop();

    running = false;
    inputThread.join();

    return 0;
}