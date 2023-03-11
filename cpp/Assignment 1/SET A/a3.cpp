#include <iostream>
using namespace std;
int main(){
    int a, i;
    cout << "Enter the number: ";
    cin >> a;
    for (i=1;i<=10;i++){
        int table = a * i;
        cout<<"\n"<<a<<"x"<<i<<"="<<table;
    }
}
