#include <stdio.h>

int main()
{
    int seats[5][6];
    int row = 0, col;
    int i, j;
    int count, booked, bestRow, bestCount;

    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 6; j++)
        {
            seats[i][j] = 0;
        }
    }

    while (row != -1)
    {
        printf("Enter row (1-5, -1 to stop): ");
        scanf("%d", &row);

        if (row != -1)
        {
            printf("Enter column (1-6): ");
            scanf("%d", &col);

            if (row < 1 || row > 5 || col < 1 || col > 6)
            {
                printf("Error: Invalid row or column!\n");
            }
            else if (seats[row - 1][col - 1] == 1)
            {
                printf("Error: Seat already booked!\n");
            }
            else
            {
                seats[row - 1][col - 1] = 1;
                printf("Seat booked successfully.\n");
            }
        }
    }

    printf("\nSeating Chart:\n");
    printf("      1 2 3 4 5 6\n");

    booked = 0;
    bestRow = 1;
    bestCount = 0;

    for (i = 0; i < 5; i++)
    {
        count = 0;
        printf("Row %d ", i + 1);

        for (j = 0; j < 6; j++)
        {
            if (seats[i][j] == 1)
            {
                printf("X ");
                count++;
            }
            else
            {
                printf("O ");
            }
        }
        printf("\n");

        booked = booked + count;

        if (count > bestCount)
        {
            bestCount = count;
            bestRow = i + 1;
        }
    }

    printf("\nTotal booked seats: %d\n", booked);
    printf("Total empty seats: %d\n", 30 - booked);
    printf("Row with most bookings: Row %d\n", bestRow);

    return 0;
}