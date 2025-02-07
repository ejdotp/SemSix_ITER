/*create 2 functions squareArea and circleArea using call by value*/

#include <iostream>
#include <iomanip> //nahi course re

using namespace std;

float squareArea(float x){
	return x*x;
}

float squareCircle(float r){
	return (3.14*r*r);
}

int main()
{
	float s;
	cout<<"Enter length of side: ";
	cin>>s;
	cout<<fixed<<setprecision(2)<<"Area of square: "<<squareArea(s)<<" unit square. "<<endl;
	
	float r;
	cout<<"Enter radius of circle: ";
	cin>>r;
	cout<<fixed<<setprecision(2)<<"Area of circle: "<<squareCircle(r)<<" unit square. "<<endl;
		
	return 0;
}
