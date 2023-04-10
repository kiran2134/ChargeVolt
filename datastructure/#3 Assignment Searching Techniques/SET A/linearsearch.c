#include<stdio.h>
#include<conio.h>
void main()
{
   int a[5],i=0,j,item;
   //clrscr();
   printf("Enter Array elements:");
   for(j=0;j<5;j++)
   {
      scanf("%d",&a[j]);
   }
   printf("Input searching item...");
   scanf("%d",&item);
   while(i<5)
   {
       if(a[i]==item)
       {
	 printf("Item found at location=%d",i);
	 break;
       }
     i++;
   }
   if(i>=5)
   printf("Item not found");
   getch();
}