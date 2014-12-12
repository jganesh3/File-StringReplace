#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include "TrackingQ.h"
#include "MatchMaker.h"
#include "BufferedFile.h"
using namespace std;

int main(int argc, char *argv[])
{
  
	string filename=argv[3];
	char *fname=new char[filename.size()+1];
	fname[filename.size()]=0;
	memcpy(fname,filename.c_str(),filename.size());
	MatchMaker rp(argv[1], argv[2], fname);
	rp.replaceString();
	return 0;
}
	
