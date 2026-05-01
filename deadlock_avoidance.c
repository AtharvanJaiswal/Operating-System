#include<stdio.h>

int main()
{
    int alloc[10][10], max[10][10];
    int avail[10], work[10], total[10];
    int need[10][10];
    int i, j, k, n, m;
    int count = 0, c = 0;
    char finish[10];

    printf("Enter number of processes and resources: ");
    scanf("%d%d", &n, &m);

    for(i = 0; i < n; i++)
        finish[i] = 'n';

    printf("Enter the claim matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &max[i][j]);

    printf("Enter the allocation matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter the resource vector:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &total[i]);

    for(i = 0; i < m; i++)
        avail[i] = 0;

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            avail[j] += alloc[i][j];

    for(j = 0; j < m; j++)
        work[j] = total[j] - avail[j];

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    while(count < n)
    {
        for(i = 0; i < n; i++)
        {
            c = 0;
            for(j = 0; j < m; j++)
                if(need[i][j] <= work[j] && finish[i] == 'n')
                    c++;

            if(c == m)
            {
                printf("Process %d can be executed\n", i + 1);
                for(k = 0; k < m; k++)
                    work[k] += alloc[i][k];

                finish[i] = 'y';
                count++;
            }
        }
    }

    printf("\nSystem is in safe state\n");

    return 0;
}