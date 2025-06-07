#include<SFML/Graphics.hpp>
using namespace sf;


int main(){
VideoMode vm(400,400);
RenderWindow window(vm,"Tile Background");

Texture tex;
tex.loadFromFile("graphics/background_sheet.png");

const int TILE_SIZE=50;
const int TILE_TYPE=3;
const int GRID_WIDTH=4;
const int GRID_HEIGHT=4;

	//TOTAL TILES=16
	//EACH TILE HAVE 4 VERTICES=16*4=64
	//SO WE HAVE TO DRAW 16 TILES USING 64 VERTICES

	VertexArray bg(Quads,GRID_WIDTH*GRID_HEIGHT*4);
	
	int currentVertex=0;
	
	for(int w=0;w<GRID_WIDTH;++w){
		for(int h=0;h<GRID_WIDTH;++h){
			bg[currentVertex+0].position=Vector2f(w*TILE_SIZE,h*TILE_SIZE);
			bg[currentVertex+1].position=Vector2f((w+1)*TILE_SIZE,h*TILE_SIZE);
			bg[currentVertex+2].position=Vector2f((w+1)*TILE_SIZE,(h+1)*TILE_SIZE);
			bg[currentVertex+3].position=Vector2f(w*TILE_SIZE,(h+1)*TILE_SIZE);

			int tileIndex=(w+h)%TILE_TYPE;
			int verticalOffset=tileIndex*TILE_SIZE;  //y cordinate

			if(h==0||h==GRID_HEIGHT-1||w==0||w==GRID_WIDTH-1){
				bg[currentVertex+0].texCoords=Vector2f(0,verticalOffset);
				bg[currentVertex+1].texCoords=Vector2f(TILE_SIZE,verticalOffset);
				bg[currentVertex+2].texCoords=Vector2f(TILE_SIZE,verticalOffset+TILE_SIZE);
				bg[currentVertex+3].texCoords=Vector2f(0,verticalOffset+TILE_SIZE);
			}
			currentVertex+=4;

		}

	}

	while(window.isOpen()){
		Event event;
		while(window.pollEvent(event)){
			if(event.type==Event::Closed)
				window.close();
		}
		if(Keyboard::isKeyPressed(Keyboard::Escape)){
			window.close();
		}
			
	window.clear();
	
	RenderStates states;
	states.texture=&tex;
	window.draw(bg,states);
	
	window.display();
	}


}

