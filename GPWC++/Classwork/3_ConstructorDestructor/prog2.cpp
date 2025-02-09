//demonstrate default copy and parameterised constructor in 1 program

#include <iostream>

using namespace std;

class test{
	int score;
	
	public:
	test(){}
	test(int a){ score = a; }
	test(test &t){ score = t.score; }
	
	void getScore(){
		cout << "Enter marks: ";
		cin >> score;
	}
	
	void display(){
		cout << "Marks = " << score << endl;
	}
};

int main(){
	test t1;
	t1.getScore();
	t1.display();
	
	test t2(97);
	t2.display();
	
	test t3(t2);
	t3.display();	
	
	return 0;
}

