#include <stdio.h>

int main()
{
    int stock[3][4];
    int i, j, sum, empty, grand, bestAisle, bestTotal;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("Units at Aisle %d, Position %d: ", i + 1, j + 1);
            scanf("%d", &stock[i][j]);
        }
    }

    printf("\nOriginal stock:\n");
    for (i = 0; i < 3; i++)
    {
        printf("Aisle %d: ", i + 1);
        for (j = 0; j < 4; j++)
        {
            printf("%4d", stock[i][j]);
        }
        printf("\n");
    }

    bestAisle = 1;
    bestTotal = 0;
    for (i = 0; i < 3; i++)
    {
        sum = 0;
        for (j = 0; j < 4; j++)
        {
            sum = sum + stock[i][j];
        }
        if (sum > bestTotal)
        {
            bestTotal = sum;
            bestAisle = i + 1;
        }
    }
    printf("\nAisle with most stock: Aisle %d (%d units)\n", bestAisle, bestTotal);

    empty = 0;
    printf("\nLow stock alerts:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (stock[i][j] < 5)
            {
                printf("Aisle %d, Position %d -> %d units\n", i + 1, j + 1, stock[i][j]);
            }
            if (stock[i][j] == 0)
            {
                empty++;
            }
        }
    }
    printf("\nEmpty shelves: %d\n", empty);

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (stock[i][j] < 5)
            {
                stock[i][j] = stock[i][j] + 10;
            }
        }
    }

    grand = 0;
    printf("\nStock after restocking:\n");
    for (i = 0; i < 3; i++)
    {
        printf("Aisle %d: ", i + 1);
        for (j = 0; j < 4; j++)
        {
            printf("%4d", stock[i][j]);
            grand = grand + stock[i][j];
        }
        printf("\n");
    }
    printf("\nNew grand total: %d units\n", grand);

    return 0;
}