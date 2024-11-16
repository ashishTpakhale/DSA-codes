#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    int priority;
    struct node*next;
};

struct queue{
    struct node* front;
    struct node* rear;
};

struct node* createnode(int d,int p){
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->priority=p;
    newnode->next=NULL;
    return newnode;
}
struct node* enqueue(struct queue* q,int d,int p){
    struct node* newnode= createnode(d,p);
    if(q->front==NULL || p>q->front->priority){
        newnode->next=q->front;
        return newnode;
    }
    struct node*temp=q->front;
    while(p>temp->priority){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=temp->next;
    return newnode;
}
struct node* dequeue(struct node * head)
// isfull
// isempty
// createnode
// display
