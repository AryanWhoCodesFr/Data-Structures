#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1;

void addToQueue(int num)
{
    if (rear < MAX - 1)
    {
        rear++;
        queue[rear] = num;
    }
    else
    {
        printf("Queue is full\n");
    }
}

int findFirstUnique()
{
    for (int i = front; i <= rear; i++)
    {
        int frequency = 0;
        for (int j = front; j <= rear; j++)
        {
            if (queue[i] == queue[j])
                frequency++;
        }
        if (frequency == 1)
            return queue[i];
    }
    return -1;
}

int main()
{
    addToQueue(4);
    addToQueue(5);
    addToQueue(4);
    addToQueue(7);
    addToQueue(5);
    addToQueue(8);

    int result = findFirstUnique();
    if (result != -1)
        printf("The first non-repeating number in the queue is: %d\n", result);
    else
        printf("No non-repeating number found in the queue\n");

    return 0;
}
