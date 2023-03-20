#include <iostream>
 using namespace std;
int main(){
    int num_complaints;
    while(cin >> num_complaints){ 
        if(num_complaints > 0)
            cout << "vai ter duas!" << endl;
        else
            cout << "vai ter copa!" << endl;
    }   
}
