#include <stdio.h>
#include <string.h>

void reverseStr(char* str) {
    int n = strlen(str);
    for (int i=0;i<n/2;i++) {
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}

int main() {
    printf("------Multi-Precision Addition------\n");

    char n1[1000], n2[1000], ans[1001];
    int len1,len2,carry=0,i=0;

    printf("Enter First Number:\n");
    scanf("%s",n1);
    printf("Enter Second Number:\n");
    scanf("%s",n2);

    reverseStr(n1);
    reverseStr(n2);

    len1 = strlen(n1);
    len2 = strlen(n2);

    while (i < len1 || i < len2 || carry) {
        int digit1 = (i < len1) ? n1[i] - '0' : 0;
        int digit2 = (i < len2) ? n2[i] - '0' : 0;
        int sum = digit1 + digit2 + carry;

        carry = sum / 10;
        ans[i] = (sum % 10) + '0';
        i++;
    }
    ans[i] = '\0';
    reverseStr(ans);
    printf("Addition : %s\n", ans);
    return 0;
}
