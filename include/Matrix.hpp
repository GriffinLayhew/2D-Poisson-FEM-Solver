#pragma once

#include "Utilities.hpp"
#include "Mesh.hpp"


class Matrix
{
    public:
        // Constructors
        Matrix(int Dim);
        Matrix(const Mesh&);


        // Non-Modifying Member Functions



    private:
        std::vector<double>     MatrixEntries;
        int                     MatrixDim;



};


// Helper Functions
