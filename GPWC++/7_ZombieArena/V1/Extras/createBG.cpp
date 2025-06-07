#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime> // For srand() and time()
using namespace sf;

int TILE_SIZE = 50;
int VERTS_IN_QUAD = 4;
int TILE_TYPES = 3;  // Adding the TILE_TYPES variable as in your friend's code

VertexArray createBG(IntRect arena)
{
    VertexArray bg;
    bg.setPrimitiveType(Quads);

    // Grid Size: Number of tiles horizontally and vertically
    int w = arena.width / TILE_SIZE; // width
    int h = arena.height / TILE_SIZE; // height

    bg.resize(w * h * VERTS_IN_QUAD); // Resize the VertexArray based on the grid size

    int currentVertex = 0;

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            // Position each vertex of the quad
            bg[currentVertex + 0].position = Vector2f(x * TILE_SIZE, y * TILE_SIZE);
            bg[currentVertex + 1].position = Vector2f((x + 1) * TILE_SIZE, y * TILE_SIZE);
            bg[currentVertex + 2].position = Vector2f((x + 1) * TILE_SIZE, (y + 1) * TILE_SIZE);
            bg[currentVertex + 3].position = Vector2f(x * TILE_SIZE, (y + 1) * TILE_SIZE);

            // Randomly select the texture for the tiles
            if (y == 0 || y == h - 1 || x == 0 || x == w - 1) {
                // Set texture coordinates for the boundary (edge) tiles
                bg[currentVertex + 0].texCoords = Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);
                bg[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + TILE_TYPES * TILE_SIZE);
                bg[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES * TILE_SIZE);
                bg[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + TILE_TYPES * TILE_SIZE);
            } else {
                // Randomly select a tile type for the non-boundary tiles
                srand((int)time(0) + y * x - y);
                int tileType = rand() % TILE_TYPES;
                int verticalOffset = tileType * TILE_SIZE;

                bg[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
                bg[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
                bg[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
                bg[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);
            }

            currentVertex += VERTS_IN_QUAD;
        }
    }

    return bg;
}
