#include <Chunk.h>

void Chunk::generateChunk(){

    //looping through the axes and merge adjacent quads
    for(int axis = 0; axis < 3; axis ++){
        int u = (axis + 1) % 3;
        int v = (axis + 2) % 3;

        std::vector<bool> mask(width * height);

        //loop through the chunk along the current axis
        for(int x = 0; x < width; x++){
            for(int y = 0; y < height; y++){
                for(int z = 0; z < depth; z++){

                    if(isVoxelVisible(x, y, z, axis)){
                        createOrMergeQuad(x, y, z, axis, mask);
                    }
                }
            }
        }
    }
}

bool Chunk::isVoxelVisible(int x, int y, int z, int axis){
    int neighbourX = x, neighbourY = y, neighbourZ = z;
    if(axis == 0){
        neighbourX += 1;
    }
    if(axis == 1){
        neighbourY += 1;
    }
    if(axis == 2){
        neighbourZ += 1;
    }

    if(neighbourX >= width || neighbourY >= height || neighbourZ >= depth){
        return true;
    }

    return getVoxel(neighbourX, neighbourY, neighbourZ).id == 0;
}

void Chunk::createOrMergeQuad(int x, int y, int z, int axis, std::vector<bool>& mask){
    int w = 0;
    int h = 0;

    while ((canExtendWidth(x, y, z, axis, w)))
    {
        w++;
    }

    while ((canExtentHeight(x, y, z, axis, w, h)))
    {
        h++;
    }


    for(int u = 0; u < w; u++){
        for(int v = 0; v < h; v++){
            mask[(x+u) + width * (y+v)] = true;
        }
    }

    addQuad(x, y, z, w, h, axis);
    
    
}

void Chunk::addQuad(int x, int y, int z, int w, int h, int axis){
    
}

Voxel& Chunk::getVoxel(int x, int y, int z){
    return Voxels[x + width * (y + height * z)];
}