#include<iostream>
#include<string.h>
using namespace std;
class Metro{
    private:
        int metro_no, no_of_seats;
        char metro_name[100];
        char starting_point[100], destination[100];
    public:
        void accept(){

            cout << "Enter Details "<< endl;
            cout << "Metro NO | Metro Name | No of Seats | Starting Point | Ending Point"<< endl;

            cin >> metro_no >> metro_name >> no_of_seats >> starting_point >> destination;
            // cin>>starting_point>>destination;

        }
        void display(){
            cout << metro_no << " " << metro_name << " " << no_of_seats << " " << starting_point << " " << destination << endl;
        }
        void search(char source[], char desti[], Metro M1[],int n){
            for (int i = 0; i < n; i++)
            {
                if (strcmp(M1[i].starting_point,source) == 0 && strcmp(M1[i].destination,desti) == 0)
                {
                    cout << M1[i].metro_no << " " << M1[i].metro_name << " " << M1[i].no_of_seats << " " << M1[i].starting_point << M1[i].destination << endl;
                }   
            }
        }
};
int main(){
    char source[100], desti[100];
    int n=3;
    Metro M1[n],M2;
    M1[0].accept();
    M1[1].accept();
    M1[2].accept();
    for (int i = 0; i < n; i++){
        M1[i].display();
    }
    cout<<"Enter Source | Destination ";
    cin>>source>>desti;
    M2.search(source,desti,M1,n);
}