#include <iostream>

using namespace std;

class DB; //forward delcaration

class DM{
	float m, cm;
	
	public:
	void getDist()
	{
		cout<< "Enter distance in meters and centimeters: ";
		cin >> m >> cm;
	}
	
	void showDist(){
		cout << "DM: " << m << " meters " << cm << " cm" << endl;
	}
	
	friend DM addem(DM, DB);
	
};

class DB{
	float f, in;
	
	public:
	void getDist()
	{
		cout<< "Enter distance in feet and inches: ";
		cin >> f >> in;
	}
	
	void showDist(){
		cout << "DM: " << f << " feet " << in << " inches" << endl;
	}
	
	friend DM addem(DM, DB);
	
};

DM addem(DM d1, DB d2){
	DM res;
	
	float M = d1.m + ( d2.f * 0.3048 );
	float CM = d1.cm + (d2.in * 2.54 );
	
	if(CM >= 100){
		M += CM / 100;
		CM = (int)CM % 100;	
	}
	
	res.m = M;
	res.cm = CM;
	
	return res;
}

int main(){
	DM o1;
	DB o2;
	
	o1.getDist();
	o2.getDist();
	
	o1.showDist();
	o2.showDist();
	
	DM result = addem(o1, o2);
	
	cout << "Total Distance = ";
	result.showDist();

	return 0;
}








