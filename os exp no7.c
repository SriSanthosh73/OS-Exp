#include <stdio.h>

int main()
{
    int n, m;
    int i, j, k;

    int allocation[10][10];
    int max[10][10];
    int need[10][10];

    int available[10];
    int finish[10] = {0};
    int safeSeq[10];

    int count = 0;

    // Input number of processes
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    // Input number of resources
    printf("Enter Number of Resources: ");
    scanf("%d", &m);

    // Input Allocation Matrix
    printf("\nEnter Allocation Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Input Maximum Matrix
    printf("\nEnter Maximum Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources:\n");

    for (i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }

    // Calculate Need Matrix
    // Need = Max - Allocation
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Banker's Algorithm
    while (count < n)
    {
        int found = 0;

        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                // Check if Need <= Available
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > available[j])
                    {
                        break;
                    }
                }

                // If all required resources are available
                if (j == m)
                {
                    // Release allocated resources
                    for (k = 0; k < m; k++)
                    {
                        available[k] += allocation[i][k];
                    }

                    // Add process to safe sequence
                    safeSeq[count] = i;
                    count++;

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // No process can proceed
        if (found == 0)
        {
            printf("\nSystem is NOT in Safe State\n");
            return 0;
        }
    }

    // System is safe
    printf("\nSystem is in Safe State\n");

    printf("Safe Sequence: ");

    for (i = 0; i < n; i++)
    {
        printf("P%d ", safeSeq[i]);
    }

    printf("\n");

    return 0;
}