#include<iostream>
using namespace std;
int main(){
    int num ,total;
    cout<<"Enter num:";
    cin>>num;
    for (int i=1;i<=num;i++){
        total=0;
        for (int j=1;j<=i;j++){   
            total=total+j ;
            cout<<j;
            if (j < i){
                cout << " + ";
            }
        }
        cout<<" = ";
        cout<<total<<" "<<endl;
    }
}
