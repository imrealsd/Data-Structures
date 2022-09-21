#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void display_arr (int*, int);
void selection_sort (int*, int);
void swap (int*, int*);

int main(int argc, char* argv[])
{
    int num[MAX] = {10,3,67,88,32,25,12,82,61,38,55,58,100};
    int size = 13;
    printf("Before sorting:\n");
    display_arr(num,size);
    selection_sort (num,size);
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

/* one swap per interation */
void selection_sort (int num[], int size)
{   
    int min, index = 0,i , j;

    for (i = 0; i < size-1; i++){
        min = num[i];
        index = i;

        for (j = i+1; j < size; j++){
            if (num[j] < min){
                min = num[j];
                index = j;
            }
        }
        swap(&num[i], &num[index]);
    }
}

void swap (int* ptr1, int* ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}