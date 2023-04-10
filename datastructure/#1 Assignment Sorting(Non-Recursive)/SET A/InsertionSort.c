#include<stdio.h>
void accept(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("Enter Element %d:",i);
        scanf("%d",&arr[i]);
    }
}
void insertionsort(int arr[],int n){
    int i,j,key;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void display(int arr[],int n){
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
}
int main(){
    int n;
    printf("Enter the number of elements you wanna enter:");
    scanf("%d",&n);
    int arr[n];
    accept(arr,n);
    insertionsort(arr,n);
    display(arr,n);
    return 0;
}