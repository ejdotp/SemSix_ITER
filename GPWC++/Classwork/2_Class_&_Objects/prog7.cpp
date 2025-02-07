/*area of rect & square using class concepts*/

#include <iostream>

using namespace std;

class builderbhaina
{
	int area;
	string obj;
	
	int read(void){
		return area;
	}
	
	public:
	void areain(int x, int y);
	void areain(int x);
	void areaout(void);
};

void builderbhaina :: areain(int x, int y){
	area = x*y;
	obj = "Rectangle";
}

void builderbhaina :: areain(int x){
	area = x*x;
	obj = "Square";
}

void builderbhaina :: areaout(void){
	int x = read();                              //only way of accessing a private function
	cout<<"Area of "<<obj<<" = "<<x<<endl;
}
//626 pp haba instead of 350 pp
int main()
{
	builderbhaina rect, sqr;
	rect.areain(7, 8);
	rect.areaout();
	sqr.areain(5);
	sqr.areaout();
	cout<<(3758/6)<<"Per person haba instead of "<<(2775/6)<<" per person."<<endl;
		
	return 0;
}
