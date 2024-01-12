#include<stdio.h>

int main() {
    int k[5] = {15, 8, 22, 9, 30};
    int t[5];

    for (int i = 0; i < 5; i++) {
        int r = k[i] % 5;
        t[r] = k[i];
    }

    printf("Transformed Array: ");
    for (int j = 0; j < 5; j++) {
        printf("%d ", t[j]);
    }

    return 0;
}
