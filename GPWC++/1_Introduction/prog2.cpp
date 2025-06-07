#include <iostream>
#include <iomanip> //for setprecision

using namespace std;

int main()
{
	float f;
	cout<<"Enter degree in Farhenheit: ";
	cin>>f;
	
	cout<<setprecision(2)<<"Temperature in Celcius is: "<<((f-32)*5/9)<<" degree celcius. "<<endl;
	// setprecision works as .2
	
	cout<<fixed<<setprecision(2)<<"Temperature in Celcius is: "<<((f-32)*5/9)<<" degree celcius. "<<endl;
	// w/o fixed it will give 2 digits no matter what with ceiling function. 150 becomes 1.5e+02, 26.66 becomes 27.
	//fixed behaves same as .2f of printf.
		
	return 0;
}
