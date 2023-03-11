#include<iostream>
using namespace std;
int main(){
    char input,alphabet=65;   //ASCII Value of A
    int i,j,nor;             //nor= Number Of Rows
    cout<<"Enter number of rows:";
    cin>>nor;

    for(i=1;i<=nor;i++){
        for(j=1;j<=i;j++){
            cout<<alphabet<<" ";
            alphabet++;
        }
        cout<<"\n";
    }
    return 0;
}