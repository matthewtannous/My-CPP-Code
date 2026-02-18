#include <iostream>
#include "Queue.h"

void reverseQueue(Queue &queue);

using namespace std;

int main()
{
    Queue q;

    q.enqueue(3);
    q.enqueue(1);
    q.enqueue(5);
    q.enqueue(12);
    q.enqueue(4);
    q.enqueue(8);

    cout << q;
    reverseQueue(q);
    cout << q;
}

void reverseQueue(Queue &queue)
{
    // keep dequeuing until empty, then enqueue last removed element and continue
    if (!queue.isEmpty())
    {
        // get element at front and dequeue it
        ElementType front = queue.getFront();
        queue.dequeue();
        reverseQueue(queue);

        queue.enqueue(front);
    }
}
