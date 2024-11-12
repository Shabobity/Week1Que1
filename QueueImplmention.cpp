#include "Queue.h"
#include <iostream>

void initQueue(Queue* q, unsigned int size) 
{
    q->_maxSize = size;
    q->_values = new int[size];
    q->_index = 0;
}

void cleanQueue(Queue* q) 
{
    delete[] q->_values;
}


void enqueue(Queue* q, unsigned int newValue) 
{
    if (q->_index < q->_maxSize) 
    {
        q->_values[q->_index++] = newValue;
    }
}

int dequeue(Queue* q) 
{
    int value = q->_values[0];
    int i = 1;
    if (isEmpty(q)) 
    {
        return -1;
    }
    for (i = 1; i < q->_index; ++i) 
    {
        q->_values[i - 1] = q->_values[i];
    }
    q->_index--;
    return value;
}

bool isEmpty(Queue* q) 
{
    if (q->_index == 0) 
    {
        return true;
    }
    return false;
}

bool isFull(Queue* q) 
{
    if (q->_index == q->_maxSize) 
    {
        return true;
    }
    return false;
}


