#include <stdio.h>
#include <stdlib.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = nums1Size - 1;
    n--;
    m--;
    while (n > -1 || m > -1) {
        if ((n < 0) || (m > -1 && nums1[m] > nums2[n])) {
            nums1[i] = nums1[m];
            m--;
        }
        else {
            nums1[i] = nums2[n];
            n--;
        }
        i--;
    }
}

int main() {
    int m = 0;
    int n = 1;
    int size = m + n;
    int* num1 = (int *)malloc(sizeof(int) * (size));
    int* num2 = (int *)malloc(sizeof(int) * (n));
     num1[0] = 0;
    // num1[1] = 2;
    // num1[2] = 3;
    // num1[3] = 0;
    // num1[4] = 0;
    // num1[5] = 0;
    
     num2[0] = 1;
    // num2[1] = 5;
    // num2[2] = 6;

    merge(num1, size, m, num2, n, n);
    for (int i = 0; i < size; i++) {
        printf("%i\n", num1[i]);
    }
    return 0;

}
