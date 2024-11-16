#include <stdio.h> 
#include <stdlib.h>

struct node { 
    int coeff; 
    int expo; 
    struct node* next; 
}; 

struct node *createnode(int c, int e) {
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->coeff = c;
    newnode->expo = e;
    newnode->next = NULL;
    return newnode;
}

void append(int c, int e, struct node** head) {
    struct node *newnode = createnode(c, e);
    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void polyadd(struct node* head1, struct node* head2, struct node* poly) { 
    while (head1 != NULL && head2 != NULL) { 
        if (head1->expo > head2->expo) { 
            poly->expo = head1->expo; 
            poly->coeff = head1->coeff; 
            head1 = head1->next; 
        } 
        else if (head1->expo < head2->expo) { 
            poly->expo = head2->expo; 
            poly->coeff = head2->coeff; 
            head2 = head2->next; 
        } 
        else { 
            poly->expo = head1->expo; 
            poly->coeff = head1->coeff + head2->coeff; 
            head1 = head1->next; 
            head2 = head2->next; 
        } 
        if (head1 != NULL || head2 != NULL) {
            poly->next = (struct node*)malloc(sizeof(struct node)); 
            poly = poly->next; 
            poly->next = NULL; 
        }
    } 

    while (head1 != NULL) { 
        poly->expo = head1->expo; 
        poly->coeff = head1->coeff; 
        head1 = head1->next; 
        if (head1 != NULL) {
            poly->next = (struct node*)malloc(sizeof(struct node)); 
            poly = poly->next; 
            poly->next = NULL; 
        }
    } 

    while (head2 != NULL) { 
        poly->expo = head2->expo; 
        poly->coeff = head2->coeff; 
        head2 = head2->next; 
        if (head2 != NULL) {
            poly->next = (struct node*)malloc(sizeof(struct node)); 
            poly = poly->next; 
            poly->next = NULL; 
        }
    } 
}

void print_poly(struct node* poly) {
    while (poly != NULL) {
        if(poly->expo==0)
        printf("%d", poly->coeff);
        else
        printf("%dx^%d", poly->coeff, poly->expo);
        poly = poly->next;
        if (poly != NULL){
            printf(" + ");
        }
    }
    printf("\n");
}

int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    struct node* poly = (struct node*)malloc(sizeof(struct node));  
    poly->next = NULL;

    int n1,n2;
    printf("Enter Size of poly1 : ");
    scanf("%d",&n1);
    printf("Enter Size of poly2 : ");
    scanf("%d",&n2);
    for(int i=0;i<n1;i++){
        int c,e;
        printf("Enter Coefficient and Exponent: ");
        scanf("%d %d",&c,&e);
        append(c,e,&poly1);
    } 

    for(int i=0;i<n2;i++){
        int c,e;
        printf("Enter Coefficient and Exponent: ");
        scanf("%d %d",&c,&e);
        append(c,e,&poly2);
    }
    // append(9, 2, &poly1);
    // append(8, 1, &poly1);4
    // append(7, 0, &poly1);

    // append(1, 3, &poly2);
    // append(2, 2, &poly2);
    // append(3, 1, &poly2);
    // append(4, 0, &poly2);

    polyadd(poly1, poly2, poly);

    printf("Polynomial 1: ");
    print_poly(poly1);

    printf("Polynomial 2: ");
    print_poly(poly2);

    printf("Sum of Polynomials: ");
    print_poly(poly);

    return 0;
}
