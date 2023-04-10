#include<stdio.h>
#include<conio.h>
#include<string.h>
void main()
{
    char data[100][100],search[50];
    int i,n,c=0;
    //clrscr();
    printf("/How many names you want\nto Add in 2-D Array/\n\nEnter limit:");
    scanf("%d",&n);
    printf("-----------------\n");
    for(i=0;i<n;i++)
    {
	printf("Enter name:%d=",i+1);
	scanf("%s",data[i]);
    }
    printf("\nElement present in 2-D Array are:\n");
    printf("------------------\n");
    for(i=0;i<n;i++)
    {
      printf("\t%s\n",data[i]);
    }
    printf("\nEnter the student name to be Searched:");
    scanf("%s",search);
    for(i=0;i<n;i++)
    {
      if(strcmp(data[i],search)==0)
      {
	 c=1;
	 break;
      }
    }
    if(c==1)
     printf("\n%sStudent name found at position '%d'",data[i],i+1);
    else
      printf("\n%s Student name is not present in the Above Array",data[i]);
      getch();
}
