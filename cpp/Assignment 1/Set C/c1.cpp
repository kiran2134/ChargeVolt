#include<iostream>
using namespace std;
int main(){
    int nor,i,j,s,k=1;       //s=space
    cout<<"Enter no. of Rows:";
    cin>>nor;
    for(i=1;i<=nor;i++){
        for(s=i;s<nor;s++){
            cout<<"\t";
        }
        for(j=1;j<=i;j++){
            cout<<k<<"\t";
            k++;
        }
        cout<<"\n";
    }
    return 0;
}