#include "Mesh.hpp"


// Constructors
Mesh::Mesh(double lx, double ly, int Nx, int Ny) : LengthX{lx}, LengthY{ly}, DivsX{Nx}, DivsY{Ny}
{
    for (int i=0; i<=Nx*Ny-1; i++)
        GridData.push_back(0.0);
    
    for (int i=0; i<=4; i++)
        BoundaryTypes.push_back(0);

    
    SpaceX = LengthX / (DivsX - 1.0);
    SpaceY = LengthY / (DivsY - 1.0);
}


// Non-Modifying Member Function Definitions
void    Mesh::displayMesh()   const
{
    
}



// Helper Functions
StencilIndicies getIndiciesFromIndex(int myIndex, Mesh& thisMesh)
{
    StencilIndicies myIndicies;
    int myI;
    int myJ;

    int Nx = thisMesh.getDivisionsX();

    myI = myIndex / Nx;
    myJ = myIndex % Nx;

    myIndicies.i = myI;
    myIndicies.j = myJ;

    return myIndicies;

}