#ifndef MATCHMAKER_H
#define MATCHMAKER_H
#include <string>
#include "BufferedFile.h"
using namespace std;

class MatchMaker
{
  int  new_count; //file pointers/offsets into files std::streampos
  int  old_count; //file pointers/offsets into files std::streampos
  int  oldStringLength;
  char ch;
  string old;
  string newone;
  char* filename;
  BufferedFile myFile;
  bool readfromold;
  bool readfromnew;

public:
  MatchMaker(string oldstr, string newstr, char* fname)
  {
    new_count=0;
    old_count=0;
    oldStringLength=0;
    old = oldstr;
    newone = newstr;
    filename = fname;
  	try
	{
	myFile.open(filename,std::fstream::in | std::fstream::out);
	}catch(exception e)
	{
	}
  }
  MatchMaker& get(char& ch);
  void put(char ch);
  void replaceString();
  void rewind(int match, char ch);
  void replace();
  bool eof();
};

#endif
