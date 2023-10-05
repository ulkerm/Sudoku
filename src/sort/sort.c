#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void merge(int a[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1; 
    int k = 0;
    int temp_arr[MAX];
  
    while (i <= mid && j <= right) {
      if (a[i] <= a[j])
          temp_arr[k++] = a[i++]; /* store left  */
      else
          temp_arr[k++] = a[j++]; /* store right */
    }
    //iterate through rest of the left 
    while (i <= mid) 
        temp_arr[k++] = a[i++];
    // iterate through rest of the right 
    while (j <= right) 
        temp_arr[k++] = a[j++];
    k--; /* go to last element */
    // copy temporary array to a 
    while (k >= 0) {
        a[left + k] = temp_arr[k]; 
        k--;
    }
}

void merge_sort_recursive(int a[], int left, int right) {
    int mid;
    if(left < right) {
        mid = left + (right - left) / 2;
        merge_sort_recursive(a, left, mid);
        merge_sort_recursive(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}

void MergeSort(int a[], int n) {
    merge_sort_recursive(a, 0, n - 1);
}

void print_Array(int a[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main(int argc, char *argv[]) {
    int n, a[MAX];
    n = argc - 1;
    for (int i = 1; i < argc; i++) {
        a[i - 1] = atoi(argv[i]);
    }
        
  /* code to read a maximum of MAX values from argv to a and
     to set n to the actual number of values in a */
  // code to display unsorted array a 
    printf("Unsorted array:\n");
    print_Array(a, n);
    MergeSort(a, n);
  // code to display sorted array a 
    printf("Sorted array:\n");
    print_Array(a, n);
  return 0;
}

