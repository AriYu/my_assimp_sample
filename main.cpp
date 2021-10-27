//
// mac : brew install assimp
// ref: https://assimp-docs.readthedocs.io/en/latest/usage/use_the_lib.html
//

#include <assimp/Importer.hpp>      // C++ importer interface
#include <assimp/scene.h>           // Output data structure
#include <assimp/postprocess.h>     // Post processing flags

#include <iostream>

bool DoTheImportThing( const std::string& pFile)
{
  Assimp::Importer importer;

  const aiScene* scene = importer.ReadFile( pFile, 
        aiProcess_CalcTangentSpace       | 
        aiProcess_Triangulate            |
        aiProcess_JoinIdenticalVertices  |
        aiProcess_SortByPType);
  
  if( !scene)
  {
    return false;
  }

  for (int i = 0; i < scene->mNumMeshes; i++)
  {
      for (int j = 0; j < scene->mMeshes[i]->mNumVertices; j++)
      {
        std::cout << "x : " << scene->mMeshes[i]->mVertices[j].x << std::endl;
        std::cout << "y : " << scene->mMeshes[i]->mVertices[j].x << std::endl;
        std::cout << "z : " << scene->mMeshes[i]->mVertices[j].x << std::endl;
      }
      for (int j = 0; j < scene->mMeshes[i]->mNumFaces; j++)
      {
          for (int k = 0; k < scene->mMeshes[i]->mFaces[j].mNumIndices; k++)
          {
              std::cout << scene->mMeshes[i]->mFaces[j].mIndices[k] << ", " << std::flush;
          }
          std::cout << std::endl;
      }
  }

  return true;
}

int main(void)
{
    if (!DoTheImportThing("./Cube_3d_printing_sample.stl"))
    {
        std::cout << "failed to read file" << std::endl;
        return -1;
    }
    std::cout << "OK" << std::endl;
    return 0;
}