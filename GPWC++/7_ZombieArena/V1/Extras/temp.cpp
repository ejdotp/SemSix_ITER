#include<SFML/Graphics.hpp>
using namespace sf;
int main(){
    VideoMode vm(1280, 720);
    RenderWindow window(vm,"Background");

    Texture texture;
    texture.loadFromFile("graphics/background_sheet.png");

    const int ts=50;//TILE_SIZE
    const int tt=3;//TILE_TYPES
    const int gw=1250/50;//GRID_WIDTH
    const int gh=700/50;//GRID_HEIGHT

    VertexArray background(Quads,gw*gh*4);

    int currentVertex=0;
    for(int w=0;w<gw;w++){
        for(int h=0;h<gh;h++){
            background[currentVertex+0].position=Vector2f(w*ts,h*ts);//upper left
            background[currentVertex+1].position=Vector2f((w+1)*ts,h*ts);//upper right
            background[currentVertex+2].position=Vector2f((w+1)*ts,(h+1)*ts);//lower right
            background[currentVertex+3].position=Vector2f((w)*ts,(h+1)*ts);//lower left

            if (h == 0 || h == gh - 1 || w == 0 || w == gw - 1)
            {
                background[currentVertex + 0].texCoords = Vector2f(0, 0 + tt * ts);
                background[currentVertex + 1].texCoords = Vector2f(ts, 0 + tt * ts);
                background[currentVertex + 2].texCoords = Vector2f(ts, ts + tt * ts);
                background[currentVertex + 3].texCoords = Vector2f(0, ts + tt * ts);
            }else{
                int ti=(w+h)%tt;//tileIndex
                //int vo=ti*ts;vericalOffset

                srand((int)time(0) + h * w - h);
                int mOrG = (rand() % tt);
                int vo = mOrG * ts;

                background[currentVertex+0].texCoords=Vector2f(0,vo);
                background[currentVertex+1].texCoords=Vector2f(ts,vo);
                background[currentVertex+2].texCoords=Vector2f(ts,ts+vo);
                background[currentVertex+3].texCoords=Vector2f(0,ts+vo);

            }
            currentVertex += 4;
        }
    }
    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)){
            if(event.type==Event::Closed)
            window.close();
        }
        window.clear();
        RenderStates states;
        states.texture=&texture;
        window.draw(background,states);
        window.display();
    }
    return 0;
}