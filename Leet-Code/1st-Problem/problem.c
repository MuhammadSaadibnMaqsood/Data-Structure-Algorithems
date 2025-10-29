#include <stdio.h>


int findLaser(int matrix[4][6])
{
    int prevDevices = 0;
    int totalLasers = 0;

    for (int i = 0; i < 4; i++)
    {
        int currentDevices = 0;

        for (int j = 0; j < 6; j++)
        {
            if (matrix[i][j] == 1)
                currentDevices++;
        }
        if (currentDevices > 0)
        {
            totalLasers += prevDevices * currentDevices;
            prevDevices = currentDevices; 
        }
    }

    return totalLasers;
}
int main(int argc, char const *argv[])
{

    // Anti-theft security devices are activated inside a bank. You are given a 0-indexed
    // binary string array bank representing the floor plan of the bank, which is an m x n 2D matrix.
    // bank[i] represents the ith row, consisting of '0's and '1's. '0' means the cell is empty,
    // while'1' means the cell has a security device.

    // There is one laser beam between any two security devices if both conditions are met:

    // The two devices are located on two different rows: r1 and r2, where r1 < r2.
    // For each row i where r1 < i < r2, there are no security devices in the ith row.
    // Laser beams are independent, i.e., one beam does not interfere nor join with another.

    // Return the total number of laser beams in the bank.

   int matrix[4][6] = {
        {0, 1, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0},
        {0, 0, 1, 0, 0, 0}};

    int lasers = findLaser(matrix);
    printf("\nTotal lazer:  %d", lasers);
    return 0;
}
