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
        Element(Node topLeft, Mesh homeMesh);

        // Non-Modifying Member Functions
        Matrix formElementMatrix() const {}
        int    getElementNumber()  const {return ElementNumber;}
        void   printElement()      const;
        Node   getNode(int index)  const {return ElementNodes[index];}



    private:
        std::vector<Node>   ElementNodes;
        double              ElementArea;
        int                 ElementNumber;



};


// Helper Functions
