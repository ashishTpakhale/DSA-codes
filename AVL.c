#include<stdio.h>
#include<stdlib.h>
int max(int a,int b){
    return (a>b)?a:b;
}
struct node{
    int data;
    struct node*right;
    struct node*left;
    int h;
};
int height(struct node*head){
    if(head==NULL)
    return -1;
    return head->h;
}
struct node*R(struct node*head){
    struct node*temp=head->right;
    head->right=temp->left;
    temp->left=head;
    head->h=max(height(head->right),height(head->left))+1;
    temp->h=max(height(temp->right),head->h);
    return temp;
}

struct node*L(struct node*head){
    struct node*temp=head->left;
    head->left=temp->right;
    temp->right=head;
    head->h=max(height(head->left),height(head->right))+1;
    temp->h=max(height(temp->left),head->h);
    return temp;
}

struct node*LL(struct node*head){
    head->left=R(head->left);
    return R(head);
}

struct node*RR(struct node*head){
    head->right=L(head->right);
    return L(head);
}

struct node*insert(struct node*root,int val){
    if(root==NULL){
        root=(struct node*)malloc(sizeof(struct node));
        root->data=val;
        root->h=0;
        root->left=root->right=NULL;
    }
    else if(val >root->data){
        root->right=insert(root->right,val);
        if((height(root->right)-height(root->left))==2)
        {
            if(val<root->right->data){
                root=R(root);
            }
            else{
                root=RR(root);
            }
        }
    }
    else if(val<root->data){
        root->left=insert(root->left,val);
        if((height(root->left)-height(root->right))==2){
            if(val<root->left->data){
                root=L(root);
            }
            else{
                root=LL(root);
            }
        }
    }
    root->h=max(height(root->left),height(root->right))+1;
    return root;
}

void inorder(struct node*root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main()
{
    int x;
    scanf("%d",&x);
    struct node*head=NULL;
    for(int i=0;i<x;i++)
    {
        int k;
        scanf("%d",&k);
        head=insert(head,k);
    }
    inorder(head);
}