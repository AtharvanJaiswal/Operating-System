#include<stdio.h>

int main()
{
    char job[10][10];
    int time[10], avail, temp[10], index[10];
    int safe[10];
    int i, j, n, t, ind = 0;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter job name and time: ");
        scanf("%s%d", job[i], &time[i]);
        temp[i] = time[i];
        index[i] = i;
    }

    printf("Enter available resources: ");
    scanf("%d", &avail);

    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(temp[i] > temp[j])
            {
                t = temp[i]; temp[i] = temp[j]; temp[j] = t;
                t = index[i]; index[i] = index[j]; index[j] = t;
            }
        }
    }

    for(i = 0; i < n; i++)
    {
        int k = index[i];
        if(time[k] <= avail)
        {
            safe[ind++] = k;
            avail -= time[k];
        }
        else
        {
            printf("No safe sequence\n");
            return 0;
        }
    }

    printf("Safe sequence is:\n");
    for(i = 0; i < ind; i++)
        printf("%s %d\n", job[safe[i]], time[safe[i]]);

    return 0;
}