
#ifndef TRACKINGQUEUE_H
#define TRACKINGQUEUE_H

#include <iostream>
#include<queue>
using namespace std;

template<class T>
class TrackingQueue : public queue <T>
{
  int counter;
  int maxSize;

  public:

  TrackingQueue()
  {
    counter=0;
    maxSize=0;
  }
  
  ~TrackingQueue()
  {
    cout<<"-->"<<maxSize<<"<--";
  }
  void push(T x);
  void pop();
  T front();

};

#endif
