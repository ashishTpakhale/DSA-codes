#include<stdio.h>
#include<stdlib.h>

struct node{
    int rowindex;
    int columnindex;
    int data;
    struct node*next;
};
struct node*createnode(int ri, int ci, int d){
    struct node*newnode= (struct node*)malloc(sizeof(struct node));
    newnode->columnindex=ci;
    newnode->rowindex=ri;
    newnode->data=d;
    newnode->next=NULL;
}
struct node*append(struct node*head,int ri,int ci,int d){
    struct node*temp=head;
    struct node*newnode=createnode(ri,ci,d);
    if(temp==NULL){
        return newnode;
    }
    else{
        while(temp!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

