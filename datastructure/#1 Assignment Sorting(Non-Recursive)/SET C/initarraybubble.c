#include<stdio.h>
#include<conio.h>
void main(){
    int array[5]={10,20,35,23,12};
    int length=5,n,i,j,temp;
    clrscr();
    for(i=0;i<length;i++){
        for(j=0;j<(length-1);j++){
            if(array[j]>array[j+1]){
                temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    for(i=0;i<length;i++){
        printf("array[%d]=%d\n",i,array[i]);
    }
    printf("\n Elements are sorted in ascending order by using bubble sort");
    getch();
}