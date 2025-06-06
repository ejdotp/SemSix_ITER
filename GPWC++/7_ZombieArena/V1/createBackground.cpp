#include <SFML/Graphics.hpp>
#include "createBackground.h"
int createBackground(VertexArray& rVA, IntRect arena)
{
		const int TILE_SIZE = 50;
		const int TILE_TYPES = 3;
		const int VERTS_IN_QUAD = 4;

		int worldWidth = arena.width / TILE_SIZE;
		int worldHeight = arena.height / TILE_SIZE;

		rVA.setPrimitiveType(Quads);

		rVA.resize(worldWidth * worldHeight * VERTS_IN_QUAD);

		int currentVertex = 0;

		for (int w = 0; w < worldWidth; w++)
		{
				for (int h = 0; h < worldHeight; h++)
				{

						rVA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);
						rVA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);
						rVA[currentVertex + 2].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);
						rVA[currentVertex + 3].position = Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);


						if (h == 0 || h == worldHeight - 1 || w == 0 || w == worldWidth - 1) //FOR WALL
						{
								rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);
								rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + TILE_TYPES * TILE_SIZE);
								rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES * TILE_SIZE);
								rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + TILE_TYPES * TILE_SIZE);
						}
						// else if(h == worldHeight / 2 || w == worldWidth/2){ //for vertical horizontal question only
						// 	int mOrG = 1;
						// 	int verticalOffset = mOrG * TILE_SIZE;
						// 	rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
						// 	rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
						// 	rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
						// 	rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);
						// }
						else
						{
								srand((int)time(0) + h * w - h);
								int mOrG = (rand() % TILE_TYPES);
								// if(mOrG % 2 == 0) for vertical horizontal question only
								// 	mOrG = 0;
								// else
								// 	mOrG = 2;
								int verticalOffset = mOrG * TILE_SIZE;

								rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
								rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
								rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
								rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);
						}

						currentVertex = currentVertex + VERTS_IN_QUAD;
				}
		}

		return TILE_SIZE;
}
