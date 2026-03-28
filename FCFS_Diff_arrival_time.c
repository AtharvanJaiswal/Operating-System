//Different arrival time
#include<stdio.h>
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], wt[n], tat[n];

    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter arrival time of P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Enter burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    int time = 0;

    for (int i = 0; i < n; i++) {
        if (time < at[i]) {
            time = at[i];  
        }
        wt[i] = time - at[i];
        time += bt[i];
        tat[i] = wt[i] + bt[i];
    }

   
    printf("\nPID\tAT\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], wt[i], tat[i]);
    }

    
    float avg_wt = 0, avg_tat = 0;
    for (int i = 0; i < n; i++) {
        avg_wt += wt[i];
        avg_tat += tat[i];
    }
    avg_wt /= n;
    avg_tat /= n;

    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    printf("\nGantt Chart:\n ");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bt[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n|");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bt[i] - 1; j++) printf(" ");
        printf("P%d", pid[i]);
        for (int j = 0; j < bt[i] - 1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < bt[i]; j++) printf("--");
        printf(" ");
    }
    printf("\n");

    time = 0;
    if (time < at[0]) time = at[0];
    printf("%d", time);

    for (int i = 0; i < n; i++) {
        time += bt[i];
        printf("%*d", bt[i] * 2 + 1, time);
    }
    printf("\n");

    return 0;
}