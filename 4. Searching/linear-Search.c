/*Header files*/
#include <stdio.h>
#define MAX 100

/*static function prototypes*/
static int linear_search(int *arr, int element, int size);

/**
 * @brief program entry point
 * @retval int
 */
int main(int argc, char** argv)
{
    int arr[MAX] = {56,78,0,34,12,84,22,24,67,65,51,49};
    int size = 12, index, element;

    element = 34;
    index = linear_search(arr, element, size);
    printf("index of element: %d is %d\n", element, index);

    return 0;
}


/**
 * @brief  func for linear serach
 * @retval int
 */
static int linear_search(int *arr, int element, int size)
{   
    for (int i = 0; i < size; i++){
        if (arr[i] == element)
            return i;
    }
    return -1;
}