#pragma once

#include <iostream>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Voxel.h"

class Chunk{
public:

    //Constructors And Functions
    Chunk();
    void generateChunk();
    void Update();
    void RenderChunk();
    ~Chunk();

private:
    //Variables
    std::vector<Voxel> Voxels;
    int height, width, depth;
    std::vector<Vertex> vertices;
    std::vector<uint32_t> indices;

    bool isVoxelVisible(int x, int y, int z, int axis);
    void createOrMergeQuad(int x, int y, int z, int axis, std::vector<bool>& mask);
    Voxel& getVoxel(int X, int y, int z);
    void addQuad(int x, int y, int z, int w, int h, int axis);
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