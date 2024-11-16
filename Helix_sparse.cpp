#include<stdio.h>
#include<stdlib.h>

struct node {
    int row;
    int col;
    int val;
    struct node* next;
};

void traverseSparseMatrix(int P, int Q, int N, struct node *matrix[], int I, int J) {
   
    int visited[P][Q];
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < Q; j++) {
            visited[i][j] = 0;
        }
    }

    int dir = 0; 
    int row = I;
    int col = J;
    while (true) {
       
        visited[row][col] = 1;

        struct node *currentNode = matrix[row];
        while (currentNode != NULL && currentNode->col != col) {
            currentNode = currentNode->next;
        }
        if (currentNode != NULL) {
            printf("%d %d %d %d\n", row, col, currentNode->val, dir + 1);
        } else {
            printf("%d %d 0 %d\n", row, col, dir + 1);
        }
        int nextRow = row;
        int nextCol = col;
        switch (dir) {
            case 0: // Down
                nextRow = row + 1;
                break;
            case 1: // Right
                nextCol = col + 1;
                break;
            case 2: // Up
                nextRow = row - 1;
                break;
            case 3: // Left
                nextCol = col - 1;
                break;
        }

        if (nextRow >= 0 && nextRow < P && nextCol >= 0 && nextCol < Q && !visited[nextRow][nextCol]) {
            row = nextRow;
            col = nextCol;
        } else {
      
            dir = (dir + 1) % 4;
            switch (dir) {
                case 0: // Down
                    nextRow = row + 1;
                    break;
                case 1: // Right
                    nextCol = col + 1;
                    break;
                case 2: // Up
                    nextRow = row - 1;
                    break;
                case 3: // Left
                    nextCol = col - 1;
                    break;
            }
            row = nextRow;
            col = nextCol;
        }

        if (visited[row][col]) {
            break;
        }
    }
}

int main() {
    int P, Q, N;
    scanf("%d %d %d", &P, &Q, &N);

    struct node* matrix[P];
    for (int i = 0; i < P; i++) {
        matrix[i] = NULL;
    }
    for (int i = 0; i < N; i++) {
        int row, col, val;
        scanf("%d %d %d", &row, &col, &val);
        struct node* newNode = ( struct node*)malloc(sizeof(struct node));
        newNode->row = row;
        newNode->col = col;
        newNode->val = val;
        newNode->next = matrix[row];
        matrix[row] = newNode;
    }

    int I, J;
    scanf("%d %d", &I, &J);

    traverseSparseMatrix(P, Q, N, matrix, I, J);

    return 0;
}