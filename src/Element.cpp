#include "Element.hpp"


// Constructors
Element::Element(Node topLeft, Mesh homeMesh) 
{
    for (int i=0; i<4; i++)
        ElementNodes.push_back(topLeft);     // Allocates 4 Nodes for the Quad Element

    Node topRight;
    Node bottomRight;
    Node bottomLeft;

    double dx = homeMesh.getSpacingX();
    double dy = homeMesh.getSpacingY();

    // Generate the other Nodes consistent with the Mesh and the Top Left Node
        // TOP RIGHT ELEMENT
    topRight.myPos.x = topLeft.myPos.x + dx;
    topRight.myPos.y = topLeft.myPos.y;

    topRight.value = 0.0;

    topRight.myPos.Indicies.i = topLeft.myPos.Indicies.i + 1;
    topRight.myPos.Indicies.j = topLeft.myPos.Indicies.j;

        // BOTTOM RIGHT ELEMENT
    bottomRight.myPos.x = topLeft.myPos.x + dx;
    bottomRight.myPos.y = topLeft.myPos.y + dy;

    bottomRight.value = 0.0;

    bottomRight.myPos.Indicies.i = topLeft.myPos.Indicies.i + 1;
    bottomRight.myPos.Indicies.j = topLeft.myPos.Indicies.j + 1;

            // BOTTOM LEFT ELEMENT
    bottomLeft.myPos.x = topLeft.myPos.x;
    bottomLeft.myPos.y = topLeft.myPos.y + dy;

    bottomLeft.value = 0.0;

    bottomLeft.myPos.Indicies.i = topLeft.myPos.Indicies.i;
    bottomLeft.myPos.Indicies.j = topLeft.myPos.Indicies.j + 1;

    // Fill the Vector of Nodes
    ElementNodes[0] = topLeft;    ElementNodes[1] = topRight; 
    ElementNodes[3] = bottomLeft; ElementNodes[2] = bottomRight;

    // Calculate the Node's Area
    ElementArea = dx * dy;

    // Get this Element's Unique ID
    ElementNumber = getIndexFromIndicies(topLeft.myPos.Indicies,homeMesh);

}


// Non-Modifying Member Function Definitions
void Element::printElement() const 
{
    std::cout << "======================= Element " << ElementNumber << " ===================" << std::endl;
    std::cout << "                  (" << this->getNode(0).myPos.Indicies.i << ", " << this->getNode(0).myPos.Indicies.j << ")        " << "(" << this->getNode(1).myPos.Indicies.i << ", " << this->getNode(1).myPos.Indicies.j << ")" << std::endl;
    std::cout << "                  (" << this->getNode(3).myPos.Indicies.i << ", " << this->getNode(3).myPos.Indicies.j << ")        " << "(" << this->getNode(2).myPos.Indicies.i << ", " << this->getNode(2).myPos.Indicies.j << ")" << std::endl;
    std::cout << "======================================================" << std::endl;
}




// Helper Functions
