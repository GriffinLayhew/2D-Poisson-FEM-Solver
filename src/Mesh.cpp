#include "Mesh.hpp"


// Constructors
Mesh::Mesh(double lx, double ly, int Nx, int Ny) : LengthX{lx}, LengthY{ly}, DivsX{Nx}, DivsY{Ny}
{
    for (int i=0; i<=Nx*Ny-1; i++)
        GridData.push_back(0.0);        // Initialize Grid with 0's
    
    for (int i=0; i<=4; i++)
        BoundaryTypes.push_back(0);     // Default is Dirichlet BC's

    for (int i=0; i<=4; i++)
        BoundaryVals.push_back(0.0);    // Default is u=0 on the boundaries

    
    SpaceX = LengthX / (DivsX - 1.0);
    SpaceY = LengthY / (DivsY - 1.0);
}


// Non-Modifying Member Function Definitions
void Mesh::displayMesh()   const
{
    for (int i=0; i<DivsX; i++)
    {
        for (int j=0; j<DivsY; j++)
        {
            StencilIndicies myStencil;
            myStencil.i = i;
            myStencil.j = j;

            int currentIndex = getIndexFromIndicies(myStencil, *this);
            std::cout << this->GridData[currentIndex] << ' ';
        }

        std::cout << std::endl;
    }
};





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

int getIndexFromIndicies(StencilIndicies myStencil, const Mesh& thisMesh)
{
    int thisIndex;
    int myI = myStencil.i;
    int myJ = myStencil.j;

    int Nx = thisMesh.getDivisionsX();
    
    thisIndex = myI*Nx + myJ;

    return thisIndex;

}