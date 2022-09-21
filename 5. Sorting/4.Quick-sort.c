#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void display_arr (int*, int);
void quick_sort (int*, int, int);
void pwrtition (int*, int, int);
void swap (int*, int*);

int main(int argc, char* argv[])
{
    int num[MAX] = {10,3,67,88,32,25,12,82,61,38,55,58,100};
    int size = 13;
    printf("Before sorting:\n");
    display_arr(num,size);
    quick_sort (num,0,12);
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


int partition (int num[], int start, int end)
{   
    int pivot = end;
    int i = start-1, j;

    for (j = start; j <= end; j++){
        if (num[j] < num[pivot]){
            i++;
            swap(&num[i], &num[j]);
        }
    }
    swap(&num[pivot],&num[i+1]);
    return i+1;
}

void quick_sort (int num[], int start, int end)
{
    
    if (start < end){
        int pos = partition(num,start,end);
        quick_sort(num,start,pos-1);
        quick_sort(num,pos+1,end);
    }
}

void swap (int* ptr1, int* ptr2)
{
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}