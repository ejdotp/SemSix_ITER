#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

class Book{
	char *author, *title, *pblshr;
	float price;
	int stock;
	
	public:
	
	void inputDetails(){
		
		string temp;
		
		cout << "Enter book title: ";
		cin >> temp;
		int len = strlen(temp);
		title = new char[len+1];
		
		cout << "Enter author name: ";
		cin >> temp;
		len = strlen(temp);
		author = new char[len+1];
		
		cout << "Enter publisher: ";
		cin >> temp;
		len = strlen(temp);
		pblshr = new char[len+1];
		
		cout << "Enter price: ";
		cin >> price;
		
		cout << "Enter stock: ";
		cin >> stock;
		
		cout << endl;
	}
	
	bool checkAvail(const char *a, const char *b){
		return (strcmp(title, a) == 0 && strcmp(author, b) == 0);
	}
	
	void updateStock(int x){
		cout << "Total cost: " << x*price;
		stock = stock - x;
	}
	
	void display(){
		cout << "Book Details:\nTitle: " << title << "\nAuthor: " << author << "\nPublisher: " << pblshr << "\nPrice: " << price << "\nStock: " << stock << " copies\n";
	}
	
	void destroy(){
		delete[] author;
		delete[] title;
		delete[] pblshr;
	}
};

int main(){
	int n, f, x; string t, a;
	
	cout << "Store Setup:\nEnter number of books: ";
	cin >> n;
	
	Book *lib = new Book[n];
	
	cout << "Enter details for " << n << " books:\n------------------------------\n";
	for (int i = 0; i < n; i++){
		lib[i].inputDetails();
	}
	
	cout << "\n------------------------------\n\nEnter the title of the book you're looking for: ";
	cin >> t;
	
	cout << "Enter the author of the book: ";
	cin >> a;
	
	cout << "\n------------------------------\n";
	for (int i = 0; i < n; i++){
		int flag = 1;
		if(checkAvail(t, a)){
			lib[i].display();
			flag = 0;
			x = i;
		}
		if(flag){
			cout << "Book not found!" << endl;
			exit(0);
		}
	}
	cout << "\n------------------------------\nEnter the number of copies required: ";
	cin >> f;
	cout << "Total cost = " << lib[x].updateStock(f) << endl;
	
	for (int i = 0; i < n; i++){
		lib[i].destroy();
	}
	
	return 0;
}

