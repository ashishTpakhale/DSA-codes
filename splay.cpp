#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a Node structure for the Splay Tree
typedef struct Node {
    int key;
    int value;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
} Node;

// Define a structure for the SplayTreeCache
typedef struct {
    Node* root;
    int size;
    int capacity;
} SplayTreeCache;

// Helper function to create a new node
Node* create_node(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

// Right rotation
void right_rotate(SplayTreeCache* cache, Node* x) {
    Node* y = x->left;
    x->left = y->right;
    if (y->right) y->right->parent = x;
    y->parent = x->parent;
    if (!x->parent) {
        cache->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->right = x;
    x->parent = y;
}

// Left rotation
void left_rotate(SplayTreeCache* cache, Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left) y->left->parent = x;
    y->parent = x->parent;
    if (!x->parent) {
        cache->root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

// Splay operation
void splay(SplayTreeCache* cache, Node* n) {
    while (n->parent) {
        Node* p = n->parent;
        Node* g = p->parent;
        if (!g) { // Zig case
            if (n == p->left) {
                right_rotate(cache, p);
            } else { //zag case
                left_rotate(cache, p);
            }
        } else if (n == p->left && p == g->left) { // Zig-Zig case
            right_rotate(cache, g);
            right_rotate(cache, p);
        } else if (n == p->right && p == g->right) { // Zag-Zag case
            left_rotate(cache, g);
            left_rotate(cache, p);
        } else if (n == p->right && p == g->left) { // Zag-Zig case
            left_rotate(cache, p);
            right_rotate(cache, g);
        } else { // Zig-Zag case
            right_rotate(cache, p);
            left_rotate(cache, g);
        }
    }
}

// Find a node and splay it to the root
Node* find(SplayTreeCache* cache, int key) {
    Node* n = cache->root;
    while (n) {
        if (key == n->key) {
            splay(cache, n);
            return n;
        } else if (key < n->key) {
            n = n->left;
        } else {
            n = n->right;
        }
    }
    return NULL;
}

// Insert a new key-value pair into the Splay Tree
void insert(SplayTreeCache* cache, int key, int value) {
    Node* n = cache->root;
    Node* parent = NULL;
    while (n) {
        parent = n;
        if (key < n->key) {
            n = n->left;
        } else if (key > n->key) {
            n = n->right;
        } else {
            n->value = value; // Update value if key already exists
            splay(cache, n);
            return;
        }
    }
    Node* new_node = create_node(key, value);
    new_node->parent = parent;
    if (!parent) {
        cache->root = new_node;
    } else if (key < parent->key) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }
    splay(cache, new_node);
    cache->size++;
}

// Print preorder traversal of the tree
void print_preorder(Node* n) {
    if (!n) return;
    printf("%d(%d) ", n->key, n->value);
    print_preorder(n->left);
    print_preorder(n->right);
}

void print_cache(SplayTreeCache* cache) {
    print_preorder(cache->root);
    printf("\n");
}

// Initialize a Splay Tree Cache
SplayTreeCache* create_cache(int capacity) {
    SplayTreeCache* cache = (SplayTreeCache*)malloc(sizeof(SplayTreeCache));
    cache->root = NULL;
    cache->size = 0;
    cache->capacity = capacity;
    return cache;
}

// Evict the least recently used node
void evict(SplayTreeCache* cache) {
    Node* n = cache->root;
    while (n->left) {
        n = n->left;
    }
    splay(cache, n);
    if (n->right) {
        n->right->parent = NULL;
    }
    cache->root = n->right;
    free(n);
    cache->size--;
}

// Add a key-value pair with eviction policy
void put(SplayTreeCache* cache, int key, int value) {
    if (cache->size == cache->capacity) {
        evict(cache);
    }
    insert(cache, key, value);
}

// Retrieve a value by key
int get(SplayTreeCache* cache, int key) {
    Node* n = find(cache, key);
    return n ? n->value : -1;
}

// Main function to demonstrate usage
int main() {
    SplayTreeCache* cache = create_cache(10);

    // Insert key-value pairs
    put(cache, 10, 640);
    put(cache, 5, 100);
    put(cache, 3, 150);
    put(cache, 4, 125);
    put(cache, 7, 700);
    put(cache, 11, 500);
    put(cache, 9, 230);
    put(cache, 2, 560);
    put(cache, 6, 580);
    put(cache, 8, 780);

    // Print cache
    print_cache(cache);

    return 0;
}