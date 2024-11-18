#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node*right;
    struct node*left;
    int data;
    int bfactor;
};

void createnode(int d){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=d;
    newnode->bfactor=0;
}