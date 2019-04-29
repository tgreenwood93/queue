#include <iostream> // std::cin, std::cout
#include <queue>    // std::queue
#include <string>

//#include <bits/stdc++.h>
#define queue_min (0)
#define endl "\n"
using namespace std;

// A structure to represent a queue
class Queue
{
  public:
    uint16_t front;
    uint16_t rear;
    uint16_t size;
    uint8_t capacity;
    uint16_t *array;
};

// function to create a queue of given capacity.
// It initializes size of queue as 0
Queue *createQueue(uint16_t capacity)
{
    Queue *queue = new Queue();
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1; // This is important, see the enqueue
    queue->array = new uint16_t[(queue->capacity * sizeof(int))];
    return queue;
}

// Queue is full when size
// becomes equal to the capacity
uint8_t isFull(Queue *queue)
{
    return (queue->size == queue->capacity);
}

// Queue is empty when size is 0
uint8_t isEmpty(Queue *queue)
{
    return (queue->size == 0);
}

// Function to add an item to the queue.
// It changes rear and size
void enqueue(Queue *queue, uint16_t item)
{
    if (true == isFull(queue))
    {
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    cout << item << " enqueued to queue\n";
}

// Function to remove an item from queue.
// It changes front and size
uint16_t dequeue(Queue *queue)
{
    if (true == isEmpty(queue))
    {
        return queue_min;
    }
    uint16_t item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function to get front of queue
uint16_t front(Queue *queue)
{
    if (true == isEmpty(queue))
        {
            return queue_min;
        }    
    return queue->array[queue->front];
}

// Function to get rear of queue
uint16_t rear(Queue *queue)
{
    if (true == isEmpty(queue))
        {
            return queue_min;
        }    
    return queue->array[queue->rear];
}

int main()
{
    /*Queue *queue = createQueue(10);

    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);

    cout << dequeue(queue) << " dequeued from queue\n";

    cout << "Front item is " << front(queue) << endl;
    cout << "Rear item is " << rear(queue) << endl;
*/
    cout << "hello world" << flush;
        return 0;
}
