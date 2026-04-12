#pragma once

#include "Utilities.hpp"

typedef struct 
{
    int i;
    int j;

} StencilIndicies;

class Mesh
{
    public:
        // Constructors
        Mesh(double lx, double ly, int Nx, int Ny);

        // Non-Modifying Member Functions
        int     getDivisionsX() const   {return DivsX;}
        int     getDivisionsY() const   {return DivsY;}

        void    displayMesh()   const;


    private:
        double                  LengthX;
        double                  LengthY;

        double                  SpaceX;
        double                  SpaceY;

        int                     DivsX;
        int                     DivsY;

        std::vector<double>     GridData;
        std::vector<bool>       BoundaryTypes;
        std::vector<double>     BoundaryVals;

};


// Helper Functions
int             getIndexFromIndicies(StencilIndicies myStencil, const Mesh& thisMesh);
StencilIndicies getIndiciesFromIndex(int myIndex, Mesh& thisMesh);