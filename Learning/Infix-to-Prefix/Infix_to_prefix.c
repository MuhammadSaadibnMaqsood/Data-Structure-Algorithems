#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct data
{
    int minus;
    int plus;
    int divide;
    int mul;
};
struct Stack
{
    int top;
    int size;
    char arr;
};

char covertInfixToPrefix(char exp, struct data *data)
{
    int sizeOfExp = strlen(exp);
    struct Stack *stack = (char *)malloc(sizeOfExp * (sizeof(char)));
}

int main(int argc, char const *argv[])
{
    struct data *data = (int *)malloc(sizeof(int));
    data->plus = 1;
    data->minus = 1;
    data->divide = 2;
    data->mul = 2;
    char exp = "x+y/z-k*d";

    char convertedExp = covertInfixToPrefix(exp, data);

    printf(convertedExp);

    return 0;
}
