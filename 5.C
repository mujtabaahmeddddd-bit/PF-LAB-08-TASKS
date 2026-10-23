#include <stdio.h>

int main()
{
    int image[4][4];
    int temp[4][4];
    int result[4][4];
    int amount, threshold;
    int i, j, x, y, sum;

    printf("Enter 16 pixel values (row by row): ");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%d", &image[i][j]);
        }
    }
    printf("Enter brightness amount: ");
    scanf("%d", &amount);
    printf("Enter threshold: ");
    scanf("%d", &threshold);

    printf("\nOriginal image:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", image[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            temp[i][j] = image[i][j] + amount;
            if (temp[i][j] > 255)
                temp[i][j] = 255;
            if (temp[i][j] < 0)
                temp[i][j] = 0;
        }
    }
    if (amount >= 0)
        printf("\nBrightness (+%d):\n", amount);
    else
        printf("\nBrightness (%d):\n", amount);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", temp[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (image[i][j] >= threshold)
                temp[i][j] = 255;
            else
                temp[i][j] = 0;
        }
    }
    printf("\nBlack and white (threshold %d):\n", threshold);
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", temp[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            temp[i][j] = image[i][3 - j];
        }
    }
    printf("\nFlipped horizontally:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", temp[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            if (i == 0 || i == 3 || j == 0 || j == 3)
            {
                result[i][j] = image[i][j];
            }
            else
            {
                sum = 0;
                for (x = i - 1; x <= i + 1; x++)
                {
                    for (y = j - 1; y <= j + 1; y++)
                    {
                        sum = sum + image[x][y];
                    }
                }
                result[i][j] = sum / 9;
            }
        }
    }
    printf("\nSmoothed image:\n");
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            printf("%5d", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}