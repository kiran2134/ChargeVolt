#include<stdio.h>
#include<conio.h>
void bubblesort(int arr[],int n){
  int temp;
  for(int i=0;i<n;i++){
    for(int j=0;j<n-1;j++){
      if(arr[j]>arr[j+1]){
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }
}

void accept(int arr[],int n){
  for(int i=0;i<n;i++){
    printf("Enter element [%d]:",i);
    scanf("%d",&arr[i]);
  }
}

int main(){
  int array[10],i,j,n,temp;
  printf("How many elements do you want to sort?:");
  scanf("%d",&n);
  accept(array,n);
  bubblesort(array,n);
  printf("Sorted Array using Bubble Sort:\n");
  for(i=0;i<n;i++){
    printf("%d\n",array[i]);
  }
  return 0;
}