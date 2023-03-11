#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
class Number{
    int num;
    public:
        inline void sqroot(int num){
            cout<< setprecision(3) << sqrt(num) << endl;
        }
        inline void cube_root(int num){
            cout<< setprecision(3) << cbrt(num) << endl;
        }
};
int main(){
    Number N1;
    N1.sqroot(5);
    N1.cube_root(5);
    return 0;
}