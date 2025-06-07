#include<SFML/Graphics.hpp>
using namespace sf;
class Pickup{
	private:
			const int HEALTH_START_VALUE=50;
			const int AMMO_START_VALUE=12;
			const int START_WAIT_TIME=10;
			const int START_SECONDS_TO_LIVE=5;
			Vector2f m_Position;
			Texture m_Texture;
			Sprite m_Sprite;
			int m_Type; //1= health, 2-ammo
			int m_Value;
			IntRect m_Arena;
			bool m_Spawned;
			float m_SecondsSinceSpawn;
			float m_SecondsSinceDeSpawn;
			float m_SecondsToLive;
			float m_SecondsToWait;
public:
		Pickup(int type);
		FloatRect getPosition();
		Sprite getSprite();
		void spawn();
		bool isSpawned();
		void update(float elapsedTime);
		void setArena(IntRect arena);
		void upgrade();
		int gotIt();
};
Pickup::Pickup(int type){
	m_Type=type;
	if(m_Type==1){ // HEALTH
	  m_Texture.loadFromFile("graphics/health_pickup.png");
	  m_Sprite.setTexture(m_Texture);
	  m_Value=HEALTH_START_VALUE;
	}
	else{
		m_Texture.loadFromFile("graphics/ammo_pickup.png");
	    m_Sprite.setTexture(m_Texture);
	     m_Value=AMMO_START_VALUE;
	}
	m_Sprite.setOrigin(25,25);
	m_SecondsToLive=START_SECONDS_TO_LIVE;
	m_SecondsToWait=START_WAIT_TIME;
}
void Pickup::setArena(IntRect arena){
	m_Arena.left=arena.left+50;
	m_Arena.top=arena.top+50;
	m_Arena.width=arena.width-50;
	m_Arena.height=arena.height-50;
	spawn();
}
FloatRect Pickup::getPosition(){
	return m_Sprite.getGlobalBounds();
}
Sprite Pickup::getSprite(){
	return m_Sprite;
}
bool Pickup::isSpawned(){
		return m_Spawned;
}
void Pickup::spawn(){
		srand((int)time(0)/m_Type);
		m_Position.x=rand()%m_Arena.width; 
		srand((int)time(0)*m_Type);
		m_Position.y=rand()%m_Arena.height;
		m_Sprite.setPosition(m_Position);
		m_SecondsSinceSpawn=0;
		m_Spawned=true;
}
void Pickup::update(float elapsedTime){
	if(m_Spawned){
		m_SecondsSinceSpawn=m_SecondsSinceSpawn+ elapsedTime;
	}
	else{
		m_SecondsSinceDeSpawn=m_SecondsSinceDeSpawn+ elapsedTime;
	}
	if(m_SecondsSinceDeSpawn > m_SecondsToWait && !m_Spawned){
		spawn();
	}
	if(m_SecondsSinceSpawn>m_SecondsToLive && m_Spawned){
		m_Spawned=false;
		m_SecondsSinceDeSpawn=0;
	}
}
int Pickup::gotIt(){
	m_Spawned=false;
	m_SecondsSinceDeSpawn=0;
	return m_Value;
}
void Pickup::upgrade(){
 if(m_Type==1){
 	m_Value +=(HEALTH_START_VALUE*0.5);
 }
 else{
 	m_Value +=(AMMO_START_VALUE*0.5);
 }
 m_SecondsToLive += START_SECONDS_TO_LIVE/10;
 m_SecondsToWait -=START_WAIT_TIME/10;
 }















	
	
	
	
	
	
		
	
	
	
	
	
	
	
	
	
	
	
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
			
								
		
			
