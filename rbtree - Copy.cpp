#include <stdio.h>
#include <stdlib.h>

typedef enum { RED, BLACK } Color;

typedef struct Node {
    int data;
    Color color;
    struct Node *left, *right, *parent;
} Node;

typedef struct RBTree {
    Node *root;
    Node *nullNode;
} RBTree;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->parent = NULL;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->color = RED;
    return newNode;
}

RBTree* createRBTree() {
    RBTree* tree = (RBTree*)malloc(sizeof(RBTree));
    tree->nullNode = createNode(0);
    tree->nullNode->color = BLACK;
    tree->root = tree->nullNode;
    return tree;
}

void fixInsert(RBTree *tree, Node *newNode) {
    Node *uncle;
    while (newNode->parent->color == RED) {
        if (newNode->parent == newNode->parent->parent->left) {
            uncle = newNode->parent->parent->right;
            if (uncle->color == RED) {
                newNode->parent->color = BLACK;
                uncle->color = BLACK;
                newNode->parent->parent->color = RED;
                newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->right) {
                    newNode = newNode->parent;
                    Node *temp = newNode->left;
                    newNode->left = temp->right;
                    if (temp->right != tree->nullNode) temp->right->parent = newNode;
                    temp->parent = newNode->parent;
                    if (newNode->parent == NULL) {
                        tree->root = temp;
                    } else if (newNode == newNode->parent->left) {
                        newNode->parent->left = temp;
                    } else {
                        newNode->parent->right = temp;
                    }
                    temp->right = newNode;
                    newNode->parent = temp;
                }
                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                Node *temp = newNode->parent->parent;
                Node *temp2 = newNode->parent;
                temp2->parent = temp;
                temp->left = temp2->right;
                if (temp->left != tree->nullNode) temp->left->parent = temp;
                temp->right = temp2;
                temp2->parent = temp;
            }
        } else {
            uncle = newNode->parent->parent->left;
            if (uncle->color == RED) {
                newNode->parent->color = BLACK;
                uncle->color = BLACK;
                newNode->parent->parent->color = RED;
                newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->left) {
                    newNode = newNode->parent;
                    Node *temp = newNode->right;
                    newNode->right = temp->left;
                    if (temp->left != tree->nullNode) temp->left->parent = newNode;
                    temp->parent = newNode->parent;
                    if (newNode->parent == NULL) {
                        tree->root = temp;
                    } else if (newNode == newNode->parent->left) {
                        newNode->parent->left = temp;
                    } else {
                        newNode->parent->right = temp;
                    }
                    temp->left = newNode;
                    newNode->parent = temp;
                }
                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                Node *temp = newNode->parent->parent;
                Node *temp2 = newNode->parent;
                temp2->parent = temp;
                temp->right = temp2->left;
                if (temp->right != tree->nullNode) temp->right->parent = temp;
                temp->left = temp2;
                temp2->parent = temp;
            }
        }
        if (newNode == tree->root) break;
    }
    tree->root->color = BLACK;
}

void rbInsert(RBTree *tree, int data) {
    Node *newNode = createNode(data);
    newNode->parent = NULL;
    newNode->left = tree->nullNode;
    newNode->right = tree->nullNode;

    Node *y = NULL;
    Node *x = tree->root;

    while (x != tree->nullNode) {
        y = x;
        if (newNode->data < x->data) {
            x = x->left;
        } else {
            x = x->right;
        }
    }

    newNode->parent = y;
    if (y == NULL) {
        tree->root = newNode;
    } else if (newNode->data < y->data) {
        y->left = newNode;
    } else {
        y->right = newNode;
    }

    if (newNode->parent == NULL) {
        newNode->color = BLACK;
        return;
    }

    if (newNode->parent->parent == NULL) {
        return;
    }

    fixInsert(tree, newNode);
}

void inorderTraversal(Node *current) {
    if (current != NULL) {
        inorderTraversal(current->left);
        printf("%d ", current->data);
        inorderTraversal(current->right);
    }
}

void inorder(RBTree *tree) {
    inorderTraversal(tree->root);
}

int main() {
    RBTree *tree = createRBTree();
    int data[] = {40, 20, 50, 10, 30, 60, 25, 35};

    for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
        rbInsert(tree, data[i]);
    }

    printf("Inorder Traversal of the constructed Red-Black Tree: ");
    inorder(tree);
    printf("\n");

    return 0;
}