#include <stdio.h>

int main()
{
    int allocation[10][10];
    int request[10][10];
    int available[10];
    int work[10];
    int finish[10];

    int n, m;
    int i, j, k;
    int found;

    // Input number of processes
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    // Input number of resource types
    printf("Enter Number of Resource Types: ");
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

    // Input Request Matrix
    printf("\nEnter Request Matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }

    // Input Available Resources
    printf("\nEnter Available Resources:\n");

    for (i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
        work[i] = available[i];
    }

    // Initially, all processes are unfinished
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }

    // Deadlock Detection Algorithm
    do
    {
        found = 0;

        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                // Check if Request[i] <= Work
                for (j = 0; j < m; j++)
                {
                    if (request[i][j] > work[j])
                    {
                        break;
                    }
                }

                // If all resources are available
                if (j == m)
                {
                    // Work = Work + Allocation[i]
                    for (k = 0; k < m; k++)
                    {
                        work[k] += allocation[i][k];
                    }

                    finish[i] = 1;
                    found = 1;
                }
            }
        }

    } while (found);

    // Display deadlocked processes
    found = 0;

    printf("\nDeadlocked Processes:\n");

    for (i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            printf("P%d ", i);
            found = 1;
        }
    }

    // If no deadlock
    if (found == 0)
    {
        printf("No Deadlock Detected");
    }

    printf("\n");

    return 0;
}