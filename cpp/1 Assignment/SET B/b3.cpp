#include <iostream>
using namespace std;
void decToHexa(int n){
    cout<<hex<<n<<endl;
}
int main(){
	int n;
    cout<<"Enter N:";
    cin>>n;
	decToHexa(n);
	return 0;
}
