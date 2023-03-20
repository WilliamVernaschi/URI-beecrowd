#include <iostream>
 using namespace std;
 int main() {
    float n, media, qtd;
    for (int i=0; i<6; i++){
        cin >> n;    
        if(n>0){
            qtd++;
            media+=n;
        }
    }
    cout << qtd << " valores positivos\n";
    printf("%0.1f\n", (media/qtd));
         return 0;
}
