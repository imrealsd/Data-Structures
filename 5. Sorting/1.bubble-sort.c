#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void display_arr (int*, int);
void bubble_sort (int*, int);

int main(int argc, char* argv[])
{
    int num[MAX] = {10,3,67,88,32,25,12,82,61,38,55,58,100};
    int size = 13;
    printf("Before sorting:\n");
    display_arr(num,size);
    bubble_sort(num,size);
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

void bubble_sort (int num[], int size)
{   
    int total_turn = size - 1;

    while (total_turn--){
        for (int i = 0; i < size-1; i++){
            if (num[i] > num[i+1]){
                int temp = num[i];
                num[i] = num[i+1];
                num[i+1] = temp;
            }
        }
    }
}