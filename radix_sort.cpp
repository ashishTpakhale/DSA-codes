#include <stdio.h>
#include <stdlib.h>

void countsort(int a[], int n, int d) {
    int otp[n];
    int count[10]={0};

    for (int i = 0; i < n; i++) {
        count[ (a[i]/d)%10 ]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i-1];
    }
    for (int i = n - 1; i >= 0; i--) {
        otp[ --(count[(a[i]/d ) % 10] ) ] = a[i];
        //count[(a[i]/d) % 10]--;
    }
    for (int i = 0; i < n; i++) {
        a[i] = otp[i];
    }
}

void radix_sort(int a[], int n) {
    int m = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i]  q]]==y> m) {
            m = a[i];
        }
    }

    for (int d = 1; m > 0; d *= 10) {
        countsort(a, n, d);
        m /= 10;
    }
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the elements of array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    radix_sort(a, n);

    printf("\nThe Sorted array is : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    free(a);
    return 0;
}