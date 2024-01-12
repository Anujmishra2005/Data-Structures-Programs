#include<stdio.h>
int getMax(int nums[], int n) {
 int max = nums[0];
 int i;
 for (i = 1; i < n; i++)
 if (nums[i] > max)
 max = nums[i];
 return max;
}
void CountSort(int nums[], int n, int exp) {
 int output[n];

 int i, cnt[10] = { 0 };
 for (i = 0; i < n; i++)
 cnt[(nums[i] / exp) % 10]++;

 for (i = 1; i < 10; i++)
 cnt[i] += cnt[i - 1];
 for (i = n - 1; i >= 0; i--) {
 output[cnt[(nums[i] / exp) % 10] - 1] = nums[i];
 cnt[(nums[i] / exp) % 10]--;
 }

 for (i = 0; i < n; i++)
 nums[i] = output[i];
}
void RadixSort(int nums[], int n) {
 int m = getMax(nums, n);
 for (int exp = 1; m / exp > 0; exp *= 10)
 CountSort(nums, n, exp);
}
void print(int nums[], int n) {
 int i;
 for (i = 0; i < n; i++)
 printf("%d ", nums[i]);
}
int main() {
 printf("Enter number of elements: ");
 int N= 0;
 scanf("%d", &N);
 int nums[N];
 printf("Enter elements: ");
 for(int i=0; i<N; i++){
 scanf("%d", &nums[i]);
 }

 RadixSort(nums, N);

 printf("Sorted Array is: ");
 print(nums, N);
 return 0;
}
