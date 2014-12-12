#ifndef BUFFEREDFILE_H
#define BUFFEREDFILE_H
#include <iostream>
#include <fstream>
#include "TrackingQ.h"
#include "TrackingQ.cpp"

class BufferedFile : public fstream 
{
  int  putter; //file pointers/offsets into files std::streampos
  int  getter; //file pointers/offsets into files std::streampos
  int  match;
  char ch;
  bool atTheEnd;
  TrackingQueue<char> Q;

  public:
  BufferedFile()
  {
    putter=0;
    getter=0;
    match=0;
	atTheEnd = false;
  }
  ~BufferedFile()
  {
    fstream::close();
  }
  char get(char& ch);
  void put(char ch);
  void do_over(char ch);
  int  getputter();
  bool endoffile();
};

#endif
