#include <stdio.h>

int main()
{
    int marks[4][3];
    int total[4];
    float avg[4];
    int high[3], low[3];
    float subjAvg[3];
    int i, j, sum, top, worst;
    char grade;

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Enter mark for Student %d, Subject %d: ", i + 1, j + 1);
            scanf("%d", &marks[i][j]);

            while (marks[i][j] < 0 || marks[i][j] > 100)
            {
                printf("Invalid mark! Enter a value between 0 and 100.\n");
                printf("Enter mark for Student %d, Subject %d: ", i + 1, j + 1);
                scanf("%d", &marks[i][j]);
            }
        }
    }

    for (i = 0; i < 4; i++)
    {
        total[i] = 0;
        for (j = 0; j < 3; j++)
        {
            total[i] = total[i] + marks[i][j];
        }
        avg[i] = total[i] / 3.0;
    }

    printf("\nStudent      Prog  Calc  Phys  Total  Average  Grade\n");
    for (i = 0; i < 4; i++)
    {
        if (avg[i] >= 80)
            grade = 'A';
        else if (avg[i] >= 65)
            grade = 'B';
        else if (avg[i] >= 50)
            grade = 'C';
        else
            grade = 'F';

        printf("Student %d%8d%6d%6d%7d%9.2f%7c\n",
               i + 1, marks[i][0], marks[i][1], marks[i][2], total[i], avg[i], grade);
    }

    for (j = 0; j < 3; j++)
    {
        sum = 0;
        high[j] = marks[0][j];
        low[j] = marks[0][j];

        for (i = 0; i < 4; i++)
        {
            if (marks[i][j] > high[j])
                high[j] = marks[i][j];
            if (marks[i][j] < low[j])
                low[j] = marks[i][j];
            sum = sum + marks[i][j];
        }
        subjAvg[j] = sum / 4.0;
    }

    printf("\nSubject statistics:\n");
    printf("Subject         Highest   Lowest  Average\n");
    printf("Programming %11d%9d%9.2f\n", high[0], low[0], subjAvg[0]);
    printf("Calculus    %11d%9d%9.2f\n", high[1], low[1], subjAvg[1]);
    printf("Physics     %11d%9d%9.2f\n", high[2], low[2], subjAvg[2]);

    top = 0;
    for (i = 1; i < 4; i++)
    {
        if (avg[i] > avg[top])
            top = i;
    }

    worst = 0;
    for (j = 1; j < 3; j++)
    {
        if (subjAvg[j] < subjAvg[worst])
            worst = j;
    }

    printf("\nTop student: Student %d (Average %.2f)\n", top + 1, avg[top]);

    printf("Worst subject: ");
    if (worst == 0)
        printf("Programming");
    else if (worst == 1)
        printf("Calculus");
    else
        printf("Physics");
    printf(" (Average %.2f)\n", subjAvg[worst]);

    return 0;
}