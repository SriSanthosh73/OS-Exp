#include <stdio.h>

int main()
{
    int n, i;
    int bt[20], wt[20], tat[20];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    // Enter burst time
    for (i = 0; i < n; i++)
    {
        printf("Enter Burst Time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    // Waiting time
    wt[0] = 0;

    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    // Turnaround time and averages
    for (i = 0; i < n; i++)
    {
        tat[i] = wt[i] + bt[i];

        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    // Display results
    printf("\nProcess\tBT\tWT\tTAT\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\n",
               i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", avg_wt / n);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat / n);

    return 0;
}