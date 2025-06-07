//1's compliment but using int

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class Compliment
{
    int bin;
    int length;
    
    public:
    void chk_bin(void){
        int temp = bin;
        while (temp > 0){
            if (temp % 10 != 0 && temp % 10 != 1){
                cout << "Incorrect Binary Number!\nQuitting..." << endl;
                exit(0);
            }
            temp /= 10;
        }
    }
    
    void ones(void){
        chk_bin();
        int temp = bin;
        int result = 0;
        int place = 1;

        while (temp > 0){
            if (temp % 10 == 0){
                result += 1 * place;
            }
            place *= 10;
            temp /= 10;
        }
        bin = result;
    }
    
    void displayones(void){
        ones();
        cout << "1's compliment is " << bin << endl;
    }
    void read(void){
        cout << "Enter a binary number: ";
        cin >> bin;

        length = floor(log10(bin) + 1);
    }
};

int main()
{ 
    Compliment b;
    b.read();
    b.displayones();
        
    return 0;
}

