# Rubik's Cube Solver Using IDA* and DFS

A fully implemented Rubik's Cube that allows you to make all possible moves with the functionality of 
solving the Rubik's Cube using the IDA* (Iterative Deepening A Star) algorithm and DFS (Depth First Search).

Cube solver created using the IDA* (Iterative Deepening A Star) algorithm 
involving DFS (Depth First Search), heuristic value calculation (using the Manhattan Distance) and optimized 
using pruning techniques such as preventing the algorithm from iterating over the same cube state again.

Graphics implemented using OpenGL.

<img width="400" alt="Screenshot 2024-03-17 at 5 37 20 PM" src="https://github.com/Jai0212/Rubiks-Cube-Solver-Using-IDA-Star/assets/86296165/80c9c474-bff0-4d90-a1ec-457727b8f134">

## Features
- Solves the Rubik's Cube extremely fast using the IDA* algorithm coupled with DFS and displays all the moves
required to reach the solution 
- Heuristic value generated using the Manhattan Distance for accurate results and preventing overestimation
- Optimized by adding functionality such as preventing iteration over the same cube state again
- Ability to make custom moves on the Rubik's Cube
- Visually appealing Rubik's Cube graphics implemented using OpenGL
- Fully implemented Rubik's Cube with instant change in cube graphics when making a move


## Technical Aspects
This project was created in C++ (3.17) in the CLion IDE. 

I implemented the Rubik's Cube using the standard OOP's techniques. A class 'Cube' represents the cube in which 
all the movement, solving algorithms and initialization methods are
present. The class 'Pieces' is the parent class of all the pieces in a Rubik's Cube. I stored the various Rubik's
Cube pieces as classes - CornerPiece, EdgePiece and CentrePiece. Each of these classes store the colour of each
edge and its orientation. The 'Side' class represents the side of a Rubik's Cube and has vector attributes that
stores the corner pieces, edge pieces and the center pieces. The 'Colour' class is used to store the RGB colour
data and the colour name.

The 'main' file is where the program runs and the graphics are implemented using OpenGL.

The project has been structured in the traditional C++ style with header and cpp files being separate for 
readability.

<img width="400" alt="Screenshot 2024-03-26 at 11 10 36 PM" src="https://github.com/Jai0212/Rubiks-Cube-Solver-Using-IDA-Star/assets/86296165/e32ef818-b45e-4f1c-8ca4-7d7603ecf519">


## Usage and Requirements
The program can be run on any normal laptop. To use the project, you can use any IDE that supports C++ (3.17).

To use this, you will need C++ and any IDE that runs C++. You will first need to install OpenGL using Homebrew
(use any online tutorial to learn how to install OpenGL using Homebrew). You might need to change some file locations 
depending on where your OpenGL package is saved in the CMakeLists.txt file.

To use this program, you must run the 'main' file. Once done, the OpenGL window should pop up and you should see
a solved Rubik's Cube spinning. In the console, you can type various commands to perform operations on the cube.
You can type something like 'white R' to perform the R move on the cube facing the white side. Similarly, you
can type 'orange FI' to perform the inverse of the F move on the cube facing the orange side. You will see the
cube update based on your command. You can continue typing these commands or you can type 'scramble'. This
will randomly scramble the cube. You can then type 'solve' to solve the cube.

The program can be terminated directly from the IDE.


## Acknowledgement

I worked on this project alone and will not be actively working on the project anymore 
(I will be creating other related projects). However, I would love any suggestions/feedback/collaborative requests.

## Author and Date
by Jai Joshi  
18th March, 2024
