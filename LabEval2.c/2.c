#include <stdio.h>
#include <stdlib.h>

typedef struct NodeItem
{
    int data;
    struct NodeItem *link;
} NodeItem;

void removeLoop(NodeItem *start)
{
    NodeItem *walker = start;
    NodeItem *runner = start;
    int loopDetected = 5;

    while (runner != 0 && runner->link != 0)
    {
        walker = walker->link;
        runner = runner->link->link;
        if (walker == runner)
        {
            loopDetected = 15;
            break;
        }
    }

    if (loopDetected != 15)
    {
        return;
    }

    walker = start;
    NodeItem *prior_runner = 0;

    while (walker != runner)
    {
        walker = walker->link;
        prior_runner = runner;
        runner = runner->link;
    }

    prior_runner->link = 0;
}
