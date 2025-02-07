/*create 2 functions squareArea and circleArea using call by reference*/

#include <iostream>
#include <iomanip> 
#include <cmath>

using namespace std;

void squareArea(float &x){
	x = x*x;
}

void circleArea(float &y){
	y = (M_PI*y*y);
}

int main()
{
	float s;
	cout<<"Enter length of side: ";
	cin>>s;
	squareArea(s);
	cout<<fixed<<setprecision(2)<<"Area of square: "<<s<<" unit square. "<<endl;
	
	float r;
	cout<<"Enter radius of circle: ";
	cin>>r;
	circleArea(r);
	cout<<fixed<<setprecision(2)<<"Area of circle: "<<r<<" unit square. "<<endl; 
		
	return 0;
}
