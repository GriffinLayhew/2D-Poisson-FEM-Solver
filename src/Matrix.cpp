#include "Matrix.hpp"


// Constructors
Matrix::Matrix(int Dim) : MatrixDim(Dim) 
{
    for (int i=0; i< Dim * Dim -1; i++)
        MatrixEntries.push_back(0.0);       // Matrix Constructed with 0 Entries
}

Matrix::Matrix(const Mesh& derivedMesh)
{
    MatrixDim = derivedMesh.getDivisionsX() * derivedMesh.getDivisionsY();

    for (int i=0; i< MatrixDim * MatrixDim -1; i++)
        MatrixEntries.push_back(0.0);       // Matrix Constructed with 0 Entries
}

// Non-Modifying Member Function Definitions




// Helper Functions
