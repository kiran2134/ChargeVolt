#include<stdio.h>
#include<conio.h>
void main()
{
   int a[5]={10,20,30,40,50},lr=0,up=4,f=0,mid,item;
   //clrscr();
   printf("Enter searching item:");
   scanf("%d",&item);
   while(lr<=up)
   {
      mid=(lr+up)/2;
      if(a[mid]==item)
      {
	f=1;
	break;
      }
      if(a[mid]<item)
      lr=mid+1;
      else
      up=mid-1;
   }
   if(f==1)
   printf("Item found with location:%d",mid);
   else
   printf("Not found");
   getch();
}