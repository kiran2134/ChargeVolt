#include <iostream>
#include<string.h>
using namespace std;
class String{
private:
    char string1[100] = "Hello ";
    char string2[100] = "Hel ";
public:
    char str_length(char string[]){

        int i = 0;
        do{
            i++;
        }while(string[i] != '\0');

        cout << i;
    }
    void str_Concat(){
        char newString[100];
        int i;

        for ( i = 0; string1[i] != '\0'; i++)
            cout<<i;
        for (int j = 0; string2[j] != '\0'; i++ ,j++){
            string1[i]=string2[j];
        }
        
        cout<< endl << string1;
    }   
    void str_reverse(){
         strrev(string1);
         cout<<string1;
    }
    void str_compare(){
        int a = strcmp(string1, string2);
        cout<<a;

    }
};
int main(){
    // char string1[] = {"Hello fellsa kay mag"};
    String s1;
    // s1.str_length(string1);
    // s1.str_Concat();
    // s1.str_reverse();
    s1.str_compare();

    return 0 ;
}