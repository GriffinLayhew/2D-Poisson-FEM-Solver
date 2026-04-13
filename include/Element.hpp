#pragma once

#include "Matrix.hpp"
#include "Mesh.hpp"

typedef struct 
{
    double x;
    double y;

    StencilIndicies Indicies;

} GlobalPosition;

typedef struct
{
    GlobalPosition myPos;
    double         value;

} Node;

class Element
{
    public:
        // Constructors


        // Non-Modifying Member Functions



    private:
        std::vector<Node>   ElementNodes;
        double              ElementArea;
        int                 ElementNumber;
         


};


// Helper Functions
