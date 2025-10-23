#include <stdio.h>

int visited[7] = {0, 0, 0, 0, 0, 0, 0};
int adj_Matrix[7][7] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0},
};

void DFS(int i)
{
    printf("%d ", i);
    visited[i] = 1;  // ✅ mark as visited

    for (int j = 0; j < 7; j++) // ✅ increment j, not i
    {
        if (adj_Matrix[i][j] == 1 && !visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    DFS(0);
    return 0;
}
