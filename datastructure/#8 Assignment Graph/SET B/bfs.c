#include<stdio.h>
#include<conio.h>
#define max 10
struct node{
    int data[max];
    int front,rear;
};
void add(struct node *p,int n){
    p->rear++;
    p->data[p->rear]=n;
}
int remove1(struct node *q){
    int a=-1;
    q->front++;
    a=q->data[q->front];
}
void intit(struct node *p){
    p->front=p->rear=-1;
}
void isempty(struct node *q){
    if(q->rear==q->front)
        return 1;
    return 0;
}
void main(){
    int a[10][10],n,i,j;
    void bfs(int a[10][10],int n);
    printf("Enter how many vertices:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Is there an edge between V%d and V%d (1/0):",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
    bfs(a,n);
}
void bfs(int a[10][10],int n){
    int i,j,w,v;
    int r[20];
    struct node *p;
    intit(p);
    printf("The breadth of first transversal:");
    r[v]=1;
    add(p,v);
    while(!isempty(p)){
        v=remove(p);
        printf("V%d",v+1);
        for(w=0;w<n;w++){
            if(a[v][w]==1&&r[w]==0){
                printf("%d",j);
                r[w]=1;
                add(p,w);
            }
        }
    }
}