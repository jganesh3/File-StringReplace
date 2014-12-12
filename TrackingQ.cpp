#include "TrackingQ.h"

template <class T>
T TrackingQueue<T>::front()
{
  return queue<T>::front();
}


template <class T>
void TrackingQueue<T>::push(T x)
{
  queue<T>::push(x);
  counter++;
  if(maxSize < counter)
    maxSize++;
}


template <class T>
void TrackingQueue<T>::pop()
{
  queue<T>::pop();
  counter--;
}
