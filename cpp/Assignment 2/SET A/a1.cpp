#include<iostream>
using namespace std;
class Cylinder{
    private:
        int radius, height;
        float area1;
    public:
        void aradius(){
            cout<< endl <<"Enter Radius";
            cin>>radius;
        }
        void aheight(){
            cout<< endl <<"Enter Height" << endl;
            cin>>height;
        }
        void volume(){
            float pi = 3.14;
            int r = radius , h = height;
            float volume = pi * (r * r) * h;  
            cout<< endl <<volume << endl ;
        }
        void area(){
            float pi = 3.14;
            int r = radius , h = height;
            area1 = 2 * pi * r * h + 2 * pi * r * r;
            cout<< endl <<area1;    
        }
};
int main(){
    Cylinder Obj1, Obj2;
    Obj1.aradius();
    Obj1.aheight();
    Obj1.volume();
    Obj1.area();    
    Obj2.aradius();
    Obj2.aheight();
    Obj2.volume();
    Obj2.area();    
    return 0;
}