/*1's compliment of binary number using nested member functions*/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Compliment
{
	string bin;
	
	public:
	void chk_bin(void){
		
		for(int i = 0; i<bin.length(); i++){
			if(bin.at(i) != '0' && bin.at(i) != '1'){
				cout << "Incorrect Binary Number!\nQuitting..." << endl;
				exit(0);
			}
		}
	}
	
	void ones(void){
		chk_bin();
		for(int i = 0; i<bin.length(); i++){
			if(bin.at(i) == '0'){
				bin.at(i) = '1';
			}else{
				bin.at(i) = '0';
			}
		}
	}
	
	void displayones(void){
		ones();
		cout<<"1's compliment is "<<bin<<endl;
	}
	void read(void){
		cout<<"Enter a binary number: ";
		cin>>bin;
	}
};

int main()
{ 
	Compliment b;
	b.read();
	b.displayones();
		
	return 0;
}
