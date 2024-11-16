#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int expo;
    struct node*next;
};
struct node*createnode(int c,int e){
    struct node*newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff=c;
    newnode->expo=e;
    newnode->next=NULL;
    return newnode;
}
struct node*append(struct node*head,int c,int e){
        struct node* newnode = createnode(c,e);
        struct node* temp = head;
        if(head==NULL){
            return newnode;
        }else{
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
        return head;
}
void display(struct node *head3){
    while(head3!=NULL){
        if(head3->expo==0)
            printf("%d",head3->coeff);
        else
            printf("%dx^%d",head3->coeff,head3->expo);
        if(head3->next!=NULL)
            printf(" + ");
        head3=head3->next;
    }
}
struct node* poly_mul(struct node*head1,struct node*head2){
    struct node*temp1 =head1;
    struct node*temp2 =head2;
    struct node*poly=NULL;
    while(temp1!=NULL){
    int exponent=0;
    int coeffecient=0;
        while(temp2!=NULL){
            int found=0;
            struct node * temp=(struct node*)malloc(sizeof(struct node));
            exponent=temp1->expo+temp2->expo;
            coeffecient=(temp1->coeff)*(temp2->coeff);
            struct node*poly1 =poly;
            while(poly1!=NULL){
                if(poly1->expo==exponent){
                    poly1->coeff+=coeffecient;
                    found=1;
                    break;
                }
                poly1=poly1->next;
            }
            poly1=poly;
            if (!found) {
                poly = append(poly, coeffecient, exponent);
            }
            // if(poly==NULL){
            //     poly=(struct node*)malloc(sizeof(struct node));
            //     poly->expo=exponent;
            //     poly->coeff=coeffecient;
            //     poly->next==NULL;
            // }
            temp2=temp2->next;
        }
        temp1=temp1->next;
        temp2=head2;
    }
    return poly;
}

int main(){
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    // struct node* poly = (struct node*)malloc(sizeof(struct node));  
    // poly->next = NULL;

    int n1,n2;
    printf("Enter Size of poly1 : ");
    scanf("%d",&n1);
    printf("Enter Size of poly2 : ");
    scanf("%d",&n2);
    for(int i=0;i<n1;i++){
        int c,e;
        printf("Enter Coefficient and Exponent: ");
        scanf("%d %d",&c,&e);
        poly1 = append(poly1,c,e);
    } 

    for(int i=0;i<n2;i++){
        int c,e;
        printf("Enter Coefficient and Exponent: ");
        scanf("%d %d",&c,&e);
        poly2 = append(poly2,c,e);
    }
    printf("Polynomial 1: ");
    display(poly1);
    printf("\n");

    printf("Polynomial 2: ");
    display(poly2);
    printf("\n");
    struct node* poly =NULL;
    poly= poly_mul(poly1,poly2);
    printf("Multiplication of Polynomials: ");
    display(poly);

}