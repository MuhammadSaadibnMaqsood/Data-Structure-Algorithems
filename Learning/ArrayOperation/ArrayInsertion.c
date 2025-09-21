#include <stdio.h>

void show(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int insertElement(int arr[], int index, int capacity, int element, int size)
{
    if (size >= capacity)
    {
        printf("Cannot insert, because capacity is full");
        return -1;
    }

    for (int i = size; i > index; i--)
    {
        arr[i + 1] = arr[i];
    }

    arr[index] = element;

    return 1;
}

int deleteElement(int arr[], int size, int index, int capacity)
{

    if (index > size)
    {
        printf("Index is not available");
        return -1;
    }

    for (int i = index; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    /* code */

    int arr[100] = {2, 3, 4, 5, 6, 7};
    int size = 6;
    int capacity = 100;
    int element = 16;
    int index = 3;
    printf("Array before insertion\n");
    show(arr, size);
    printf("\nArray after insertion\n");

    insertElement(arr, index, capacity, element, size);
    size++;
    show(arr, size);
    printf("\nArray after insertion\n");
    int element2 = 16;
    int indexnew = 7;

    insertElement(arr, indexnew, capacity, element2, size);
    size++;
    show(arr, size);

    printf("\n Array after deletion\n");
    deleteElement(arr, size, index, capacity);
    size--;
    show(arr, size);
    return 0;
}
