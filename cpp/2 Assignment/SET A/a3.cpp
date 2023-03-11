#include<iostream>
using namespace std;
class District
{
     int district_code,area_sqft,pop,lr;
    char name[20];
public:
    void accept()
    {
        cout<<"\n\nEnter The Details:";
        cout<<"\nDistrict Code:";
        cin>>district_code;
        cout<<"District Name:";
        cin>>name;
        cout<<"Area In Sqft:";
        cin>>area_sqft;
        cout<<"District Population:";
        cin>>pop;
        cout<<"District Literacy Rate:";
        cin>>lr;
        cout<<"\nDetails Have Been Entered!!";
    }
    void display()
    {
        cout<<"\nEntered Details Are:";
        cout<<"\nDistrict Code:"<<district_code;
        cout<<"\nDistrict Name:"<<name;
        cout<<"\nArea In Sqft:"<<area_sqft<<" Sqft";
        cout<<"\nDistrict Population:"<<pop;
        cout<<"\nDistrict Literacy Rate:"<<lr<<"\n\n";
    }
    void hlrate(District D[],int n,int i)
    {
        int max,pos;
        max=D[1].lr;
        for(i=1;i<n;i++)
        {
            if(D[i].lr>max)
            {
                max=D[i].lr;
                pos=i;
                cout<<"Details Of District Having Highest Literacy Rate Is:"<<endl;
                D[pos].display();
            }
        }
    }
    void lpop(District D[20],int n,int i)
    {
        int min,pos1;
        min=D[1].pop;
        cout<<"Details Of District Having Least Population Is:"<<endl;
        for(i=1;i<n;i++)
        {
            if(D[i].pop<min)
            {
                min=D[i].pop;
                pos1=i;
                D[pos1].display();
            }
        }
    }
};
int main()
{
    int i,n,ch;
    District D[20];
    cout<<"How Many Details You Want To Enter:";
    cin>>n;
    while(1)
    {
        cout<<"\n\n---MENU---\n 1.Accept \n 2.Display \n 3.Display details of district having highest literacy rate. \n 4.Display details of district having least population. \n 5.Exit\n";
        cout<<" \n Enter Your Choice :";
        cin>>ch;
        switch(ch){
            case 1:
                    for(i=0;i<n;i++){
                        D[i].accept();
                    }
                    break;
            case 2:
                    for(i=0;i<n;i++){
                        D[i].display();
                    }
                    break;
            case 3:
                    D[i].hlrate(D,n,i);
                    break;
            case 4:
                    {
                        D[i].lpop(D,n,i);
                    }
                    break;
            case 5:
                    {
                        exit(1);
                    }
        }
    }
   return 0;
}