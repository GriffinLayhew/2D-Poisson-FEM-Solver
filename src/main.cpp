/*
    AUTHOR:                     Griffin Layhew

    DATE:                       04/02/26
    PROGRAM TITLE:              2D Poisson Solver using the Finite Element Methods
    PROGRAM DESCRIPTION:
            " This program solves 2D Poisson Equation in Serial.
              Different elements can be chose, and the system of 
              linear equations can be solved with 4 different iterative
              solvers. The mesh is assuned to be made of othogonal rectangles."


*/

#include "Utilities.hpp"
#include "Mesh.hpp"

// Standard Function to Calculate Amount of Memory Being Used
long GetProgramMemoryUsage() 
{
    struct rusage usage;
    int ret = getrusage(RUSAGE_SELF, &usage);
    if (ret == -1) {
        perror("getrusage error");
        return -1;
    }
    return usage.ru_maxrss; 
}

            //===============================//
            //      MAIN STARTS HERE //
            //===============================//
int main(int argc, char* argv[])
{
    /*
    =============================================
                Input Space for Constants
    =============================================
    */

    /*
    =============================================
                Intiialize Mesh and Solver
    =============================================
    */


    /*
    =============================================
                Solve the System
    =============================================
    */
 
 
    /*
    =============================================
                Output the Results
    =============================================
    */

    /*
    =============================================
                     Tests
    =============================================
    */
    Mesh myMesh(1.0, 1.0, 10, 10);
    myMesh.displayMesh();
   return 0;
}