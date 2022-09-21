#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int _binary_search_ (int, int, int, int);
int arr[MAX] = {1,21,22,34,49,55,59,61,64,67,78,80,92,103,340,560,780};

int main()
{
    int size = 16, val = 0;
    int start = 0, end = (size -1), mid = 0;
    printf("Enter value to serach:");
    scanf("%d", &val);
    printf("index of %d is: %d\n", val, _binary_search_(val, start, mid, end));
    return 0;
}

int _binary_search_ (int val, int start, int mid, int end)
{
    mid = (start + end)/2;
    if (start <= end){
        if (arr[mid] == val){
            return mid;

        } else if (val < arr[mid] ){ 
            end = mid-1; _binary_search_(val, start, mid,end);

        } else if (val > arr[mid]) { 
            start = mid+1; _binary_search_(val,start,mid,end);
        }
    }
}
