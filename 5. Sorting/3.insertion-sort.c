#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void display_arr (int*, int);
void insertion_sort (int*, int);

int main(int argc, char* argv[])
{
    int num[MAX] = {10,3,67,88,32,25,12,82,61,38,55,58,100};
    int size = 13;
    printf("Before sorting:\n");
    display_arr(num,size);
    insertion_sort(num,size);
    printf("After sorting:\n");
    display_arr(num,size);
    return 0;
}

void display_arr (int num[], int size)
{   
    for (int i = 0; i < size; i++){
        printf("%d ",num[i]);
    }
    printf("\n");
}

void insertion_sort (int num[], int size)
{   
    int i, j, curr;
    for (i = 1; i < size; i++){
        curr = num[i];
        j = i - 1;
        while (j >= 0 && num[j] > curr){
            num[j+1] = num[j];
            j--;
        }
        num[j+1] = curr;
    }
}