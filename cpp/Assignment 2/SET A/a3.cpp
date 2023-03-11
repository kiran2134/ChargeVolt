#include <iostream>
using namespace std;
class District{
    private:
        int district_code, population, literacy_rate;
        float area_sqft;
        char district_name[10];

    public:
        void accept();
        void display();
        void highest_literacy(District Obj[], int n);
        void least_population(District Obj[], int n);
};
void District :: accept(){
    cout<< endl <<"Enter Details"<< endl;
    cout<< endl <<"District_code | District_name | Population | Literacy_rate | Area_Sqft"<< endl ;
    cin>> district_code >> district_name >> population >> literacy_rate >> area_sqft;
}
void District :: display(){
    cout<< endl << district_code << district_name << population << literacy_rate << area_sqft << endl ;
}
void District :: highest_literacy(District Obj[], int n ){
    int max = Obj[0].literacy_rate;
    int pos = 1;
    for (int i = 0; i < n; i++){
        if (Obj[i].literacy_rate > max){
            max = Obj[i].literacy_rate; 
            pos = i;
        }
    }

    cout<< endl << Obj[pos].district_code << " " << Obj[pos].district_name << " " << Obj[pos].population << " " << Obj[pos].literacy_rate << " " << Obj[pos].area_sqft;
}

void District :: least_population(District Obj[] ,int n){
    int min = Obj[0].population;
    int pos = 1;
    for (int i = 0; i < n; i++){
        if (Obj[i].population < min){
            min = Obj[i].population; 
            pos = i;
        }
    }
    cout<< endl << Obj[pos].district_code << " " << Obj[pos].district_name << " " << Obj[pos].population << " " << Obj[pos].literacy_rate << " " << Obj[pos].area_sqft;
}

int main(){
    District Obj[10],Obj1;
    Obj[0].accept();
    Obj[1].accept();
    Obj[2].accept();
    int n = 3;
    Obj1.highest_literacy(Obj,3);
    Obj1.least_population(Obj,3);
    return 0;
}