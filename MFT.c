#include <stdio.h>

int main()
{
    int ms, bs, nob, ef, n;
    int mp[10], tif = 0;
    int i, p = 0;

    printf("Enter total memory (Bytes): ");
    scanf("%d", &ms);

    printf("Enter block size (Bytes): ");
    scanf("%d", &bs);

    nob = ms / bs;
    ef = ms - nob * bs;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter memory for process %d: ", i + 1);
        scanf("%d", &mp[i]);
    }

    printf("\nBlocks available: %d\n", nob);
    printf("\nPROCESS\tMEMORY\tALLOCATED\tFRAGMENTATION\n");

    for(i = 0; i < n && p < nob; i++)
    {
        printf("%d\t%d\t", i + 1, mp[i]);

        if(mp[i] > bs)
        {
            printf("NO\t\t---\n");
        }
        else
        {
            printf("YES\t\t%d\n", bs - mp[i]);
            tif += (bs - mp[i]);
            p++;
        }
    }

    if(i < n)
        printf("\nMemory Full! Remaining processes not allocated.\n");

    printf("\nTotal Internal Fragmentation: %d", tif);
    printf("\nTotal External Fragmentation: %d\n", ef);

    return 0;
}