#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class String{
	char *name;
	int len;
	
	public:
	String(){
		len = 0;
		name = new char[len+1];
		name[0] = '\0';
	}

	String(const char *s){           //parameterized constructor
		len = strlen(s);
		name = new char[len+1];
		strcpy(name, s);
	}
	
	String(const String &s){        //copy by reference
		len = s.len;
		name = new char[len+1];
		strcpy(name, s.name);
	}
	
	void destroy(){
		delete[] name;
	}
	
	void join(const String &s1, const String &s2){
		delete[] name;
		len = s1.len + s2.len;
		name = new char[len+1];
		strcpy(name, s1.name);
		strcat(name, s2.name);
	}
	
	void display(){
		cout << "\"" << name << "\"" << endl;
	}
};

int main(){
	String fname = "Jagadeeswar ", lname = "Patro", full;
	
	full.join(fname, lname);
	
	cout << "First Name: ";
	fname.display();
	cout << "Last Name: ";
	lname.display();
	cout << "Full Name: ";
	full.display();
	
	fname.destroy();
	lname.destroy();
	full.destroy();
	
	return 0;
}

