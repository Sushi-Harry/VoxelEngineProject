#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Voxel.h"

class Chunk{

public:
    //Variables
    std::vector<Voxel> Voxels;

    //Constructors And Functions
    Chunk();

    void RenderChunk();

    ~Chunk();

private:


};


    /*
        TO DO:

        1. Create an array of Voxels
        2. Set Types 
        3. Set Positions
        4. Append Vertex Data to a VertexVector
        5. Append Colors to a ColorVector according to the Types; Eg- 0 = nothhing(don't draw); 1 = grass; 2 = dirt etc..

        6. Assign the id and positions according to a HEIGHTMAP
    */