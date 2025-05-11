#include <SFML/Graphics.hpp>
#include <cstdlib>
using namespace sf;

int TILE_SIZE = 50;
int VERTS_IN_QUAD = 4;

VertexArray createBG(IntRect arena)
{
    VertexArray bg;
    bg.setPrimitiveType(Quads);

    //Grid Size: Number of tile shorizontally and vertically
    int w = arena.width / TILE_SIZE; //width
    int h = arena.height / TILE_SIZE; //height

    int currentVertex = 0; //tentative
    for(int y = 0; y < h; y++){
        for(int x = 0; x < h; x++){
            //position each vertex of the quad:
            bg[currentVertex + 0].position = Vector2f(x * TILE_SIZE, y * TILE_SIZE);
            bg[currentVertex + 1].position = Vector2f((x+1) * TILE_SIZE, y * TILE_SIZE);
            bg[currentVertex + 2].position = Vector2f((x+1) * TILE_SIZE, (y+1) * TILE_SIZE);
            bg[currentVertex + 3].position = Vector2f(x * TILE_SIZE, (y+1) * TILE_SIZE);
        }
    }
}