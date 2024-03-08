#include <stdio.h>

int swap(int arr[], int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bubbleSort(int arr[], int n, int swapCount[]){
int i, j, totalSwaps = 0;

for(i = 0; i < n; i++){
    for(j = 0; j < n - i - 1; j++) {
        if(arr[j] > arr[j + 1]) {
            swap(arr, &arr[j], &arr[j + 1]);
            swapCount[arr[j + 1]]++;
            swapCount[arr[j]]++;
            totalSwaps++;
            }
        }
    }
    return totalSwaps;
}

int selectionSort(int arr[], int n, int swapCount[]) {
    int i, j, minIndex, totalSwaps = 0;

    for(i = 0; i < n; i++){
        minIndex = i;
        for(j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
            if(minIndex != i){
                swap(arr, &arr[minIndex], &arr[i]);
                swapCount[arr[minIndex]]++;
                swapCount[arr[i]]++;
                totalSwaps++;
            }
        }
    return totalSwaps;
    
}

int resetArray(int arr[], int original[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = original[i];
    }
}

int main(){
int arr1[9] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
int arr2[9] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
int n1 = sizeof(arr1) / sizeof(arr1[0]);
int n2 = sizeof(arr2) / sizeof(arr2[0]);
int swapCount1[100] = {0};
int swapCount2[100] = {0};
int original_arr1[9];
int original_arr2[9];

 for (int i = 0; i < n1; i++) {
        original_arr1[i] = arr1[i];
    }
for (int i = 0; i < n2; i++) {
        original_arr2[i] = arr2[i];
    }

printf("Array 1:\n");
int totalSwaps1_bubble = bubbleSort(arr1, n1, swapCount1);
printf("Total number of swaps: %d\n", totalSwaps1_bubble);
    for (int i = 0; i < n1; i++) {
        printf("%d: %d\n", arr1[i], swapCount1[arr1[i]]);
        swapCount1[arr1[i]]=0;
    }
    
printf("\nArray 2:\n");
int totalSwaps2_bubble = bubbleSort(arr2, n2, swapCount2);
printf("Total number of swaps: %d\n", totalSwaps2_bubble);
    for (int i = 0; i < n2; i++) {
        printf("%d: %d\n", arr2[i], swapCount2[arr2[i]]);
        swapCount2[arr2[i]]=0;

    }

resetArray(arr1, original_arr1, n1);
resetArray(arr2, original_arr2, n2);

printf("Array 1:\n");
int totalSwaps1_selection = selectionSort(arr1, n1, swapCount1);
printf("Total number of swaps: %d\n", totalSwaps1_selection);
    for (int i = 0; i < n1; i++) {
        printf("%d: %d\n", arr1[i], swapCount1[arr1[i]]);
    }



printf("\nArray 2:\n");
int totalSwaps2_selection = selectionSort(arr2, n2, swapCount2);
printf("Total number of swaps: %d\n", totalSwaps2_selection);
    for (int i = 0; i < n2; i++) {
        printf("%d: %d\n", arr2[i], swapCount2[arr2[i]]);
    }

    return 0;
}
//Ezekiel Echenique Lab 7
