//1D array filled with random elements of size 10, print, shift right by 2, fill 1st 2 elements by random (20 to 30). display both.

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	int arr1[10];
	int arr2[10];
	
	cout << "Original Array: ";
	for(int i = 0; i < 10; ++i){
		arr1[i] = rand() % 100;
		cout << arr1[i] << " ";
	}
	cout << endl;
	
	arr2[0] = 20 + rand() % 11;
	arr2[1] = 20 + rand() % 11;
	
	for(int i = 2; i < 10; ++i){
		arr2[i] = arr1[i-2];
	}
	
	cout << "New Array: ";
	for(int i = 0; i < 10; ++i){
		cout << arr2[i] << " ";
	}
	cout << endl;
	
	return 0;
}

