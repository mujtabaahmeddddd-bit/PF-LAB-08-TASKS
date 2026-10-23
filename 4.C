#include <stdio.h>

int main()
{
    int beds[2][3][2];
    int choice = 0;
    int f, w, b;
    int floor, id, placed, found;
    int floorOcc, occ;
    int bestFloor, bestWard, bestOcc;
    float percent[2];

    for (f = 0; f < 2; f++)
    {
        for (w = 0; w < 3; w++)
        {
            for (b = 0; b < 2; b++)
            {
                beds[f][w][b] = 0;
            }
        }
    }

    while (choice != 4)
    {
        printf("\n1. Admit\n2. Discharge\n3. Report\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            placed = 0;

            printf("Floor (1-2): ");
            scanf("%d", &floor);
            printf("Patient ID: ");
            scanf("%d", &id);

            if (floor < 1 || floor > 2 || id <= 0)
            {
                printf("Invalid floor or patient ID.\n");
            }
            else
            {
                for (w = 0; w < 3; w++)
                {
                    for (b = 0; b < 2; b++)
                    {
                        if (placed == 0 && beds[floor - 1][w][b] == 0)
                        {
                            beds[floor - 1][w][b] = id;
                            placed = 1;
                            printf("Patient %d admitted: Floor %d, Ward %d, Bed %d.\n",
                                   id, floor, w + 1, b + 1);
                        }
                    }
                }
                if (placed == 0)
                {
                    printf("Floor %d is full.\n", floor);
                }
            }
        }

        else if (choice == 2)
        {
            found = 0;

            printf("Patient ID: ");
            scanf("%d", &id);

            for (f = 0; f < 2; f++)
            {
                for (w = 0; w < 3; w++)
                {
                    for (b = 0; b < 2; b++)
                    {
                        if (found == 0 && id > 0 && beds[f][w][b] == id)
                        {
                            beds[f][w][b] = 0;
                            found = 1;
                            printf("Patient %d discharged from Floor %d, Ward %d, Bed %d.\n",
                                   id, f + 1, w + 1, b + 1);
                        }
                    }
                }
            }
            if (found == 0)
            {
                printf("Patient ID %d not found.\n", id);
            }
        }

        else if (choice == 3)
        {
            bestFloor = 1;
            bestWard = 1;
            bestOcc = -1;

            printf("\n--- Occupancy Report ---\n");

            for (f = 0; f < 2; f++)
            {
                floorOcc = 0;
                printf("Floor %d\n", f + 1);

                for (w = 0; w < 3; w++)
                {
                    occ = 0;
                    for (b = 0; b < 2; b++)
                    {
                        if (beds[f][w][b] != 0)
                        {
                            occ++;
                        }
                    }
                    printf("  Ward %d: Occupied %d, Vacant %d\n", w + 1, occ, 2 - occ);
                    floorOcc = floorOcc + occ;

                    if (occ > bestOcc)
                    {
                        bestOcc = occ;
                        bestFloor = f + 1;
                        bestWard = w + 1;
                    }
                }

                percent[f] = floorOcc * 100.0 / 6;
                printf("Floor occupancy: %.1f%%\n", percent[f]);
            }

            printf("Highest occupancy: Floor %d, Ward %d (%d occupied)\n",
                   bestFloor, bestWard, bestOcc);

            for (f = 0; f < 2; f++)
            {
                if (percent[f] > 80)
                {
                    printf("WARNING: Floor %d is more than 80%% full.\n", f + 1);
                }
            }
        }
    }

    return 0;
}