#include<stdio.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;

int mutex = 1;
int full = 0;
int empty = SIZE;

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

void producer()
{
    int item;

    if((mutex == 1) && (empty != 0))
    {
        mutex = wait(mutex);
        empty = wait(empty);

        printf("Enter item to produce: ");
        scanf("%d", &item);

        buffer[in] = item;
        in = (in + 1) % SIZE;

        printf("Produced: %d\n", item);

        mutex = signal(mutex);
        full = signal(full);
    }
    else
    {
        printf("Buffer is Full!\n");
    }
}

void consumer()
{
    int item;

    if((mutex == 1) && (full != 0))
    {
        mutex = wait(mutex);
        full = wait(full);

        item = buffer[out];
        out = (out + 1) % SIZE;

        printf("Consumed: %d\n", item);

        mutex = signal(mutex);
        empty = signal(empty);
    }
    else
    {
        printf("Buffer is Empty!\n");
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n1. Produce\n2. Consume\n3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: producer(); break;
            case 2: consumer(); break;
            case 3: return 0;
            default: printf("Invalid choice\n");
        }
    }
}