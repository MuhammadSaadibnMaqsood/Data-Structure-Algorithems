#include <stdio.h>
#include <stdlib.h>

struct array
{
    int total_size;
    int used_size;
    int *ptr;
};

void createArray(struct array *a, int total_size, int used_size)
{
    a->total_size = total_size;
    a->used_size = used_size;
    a->ptr = (int *)malloc(total_size * sizeof(int));
}

void showArray(struct array *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        printf("%d", (a->ptr)[i]);
        printf("\n");
    }
}


void setVal(struct array *a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
      printf("Enter a value for index %d: ",i);
      scanf("%d",&n);

      (a->ptr)[i] = n;
    }
    
}
int main(int argc, char const *argv[])
{
    /* code */

    struct array marks;

    createArray(&marks, 10, 2);

    printf("Set value\n");
    setVal(&marks);
    printf("Show value\n");
    showArray(&marks);

    return 0;
}
