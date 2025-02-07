/*area of rect & square using class concepts*/

#include <iostream>

using namespace std;

class builderbhaina{
	int area;
	string obj;
	
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
	cout<<"Area of "<<obj<<" = "<<area<<endl;
}

int main()
{
	builderbhaina rect, sqr;
	rect.areain(7, 8);
	rect.areaout();
	sqr.areain(5);
	sqr.areaout();
		
	return 0;
}
