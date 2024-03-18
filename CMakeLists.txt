cmake_minimum_required(VERSION 3.21)
project(Rubiks_Cube)

set(CMAKE_CXX_STANDARD 17)

find_package(glfw3 REQUIRED)

# NEW
find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR}/include)

# NEW
link_directories(${PROJECT_SOURCE_DIR}/lib)

add_executable(Rubiks_Cube main.cpp
        Colour.cpp
        Colour.h
        Pieces.h
        EdgePiece.cpp
        EdgePiece.h
        CornerPiece.cpp
        CornerPiece.h
        CentrePiece.cpp
        CentrePiece.h
        Side.cpp
        Side.h
        Cube.cpp
        Cube.h)

# NEW
target_link_libraries(Rubiks_Cube GLEW)

target_link_libraries(Rubiks_Cube glfw ${COCOA_LIBRARY} ${OPENGL_LIBRARIES} ${IOKIT_LIBRARY} "-framework OpenGL")
target_link_libraries(Rubiks_Cube glfw ${GLEW_LIBRARY} ${COCOA_LIBRARY} ${OPENGL_LIBRARIES} ${IOKIT_LIBRARY} "-framework GLUT")
# above is new old was -framework OpenGL

