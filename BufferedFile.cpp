#include "BufferedFile.h"

void BufferedFile::do_over(char ch)
{
	Q.push(ch);
}

char BufferedFile::get(char &ch)
{	
	if(!Q.empty())
	{
		ch=Q.front();
		Q.pop();
		return ch;
	}
	
	fstream::seekg(getter);
	ch=fstream::get();		
	
	if(fstream::eof())
	{
		fstream::clear();
		atTheEnd = true;
	}	
	
	getter++;
	return ch; 
}


void BufferedFile::put(char ch)
{
	
		if(putter == getter && !atTheEnd)
		{
			fstream::seekg(getter);		
			Q.push(fstream::get());		
		
			if(fstream::eof())
			{
				fstream::clear();
				atTheEnd = true;
			}		
			getter++;
		}
		fstream::seekp(putter);
		fstream::put(ch);
		putter++;
	
}


int BufferedFile::getputter()
{
    return putter;
}

bool BufferedFile::endoffile()
{
	if(!Q.empty())
		return false;
	return atTheEnd;

}
