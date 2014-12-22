//
//  queue.h
//  wordladder
//
//  Created by Surabhi Ravishankar  on 12/7/14.
//  Copyright (c) 2014 Surabhi Ravishankar . All rights reserved.
//
#ifndef wordladder_queue_h
#define wordladder_queue_h

#include<iostream>
#include<cstdlib>

#define def_size 1000

struct Path
{
    int row;
    int col;
};
template< class T > class Queue
{
private:
    int size;
    T *data_array;
    int front;
    int rear;
    
public:
    Queue(int = def_size);//default constructor
    ~Queue()//destructor
    {delete [] data_array;}
    void push( T );
    T pop();
    T first() const;
    T last() const;
    int queue_size();
    bool IsEmpty();
    bool IsFull();
    
};
template< class T >
Queue<T>::Queue(int x): size(x), data_array(new T[size]), front(0), rear(0)

{ /*empty*/  }
template< class T > bool Queue<T>::IsFull()
{
    if((rear + 1) %  size == front )
        return 1;
    else
        return 0;
}
template< class T > void Queue<T>::push(T x)
{
    //bool b = 0;
    if(!Queue<T>::IsFull())
    {
        data_array[rear] = x;
        rear = (rear + 1) % size;
        
    }
}

template< class T > bool Queue<T>::IsEmpty()
{
    if( rear  == front )//is empty
        return 1;
    else
        return 0; //is not empty
}

template< class T > T Queue<T>::pop()
{
    T val;
    if(!Queue<T>::IsEmpty())
    {
        val = data_array[front];
        front = ( front + 1 ) % size;
    }
    else
    {
        std::cerr << "Queue is Empty : ";
    }
    return val;
}
template<class T>
T Queue<T>::first() const
{
    return data_array[front];
    
}

template<class T>
T Queue<T>::last() const
{
    return data_array[rear];
}

template<class T>
int Queue<T>::queue_size()
{
    int size = 0;
    if(front > rear)
    {
        size = (front - rear);
    }
    else
    {
        size = front + def_size - rear;
    }
    return size;
}

#endif
