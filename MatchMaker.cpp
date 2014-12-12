#include "MatchMaker.h"
#include <unistd.h>
using namespace std;
MatchMaker& MatchMaker::get(char &ch)
{
	if(new_count>0)
	{
		ch = newone[newone.size() - new_count--];
		readfromold = true;
	}
	else if(old_count>0)
	{
		ch = old[ oldStringLength  - old_count--];
		readfromnew = true;
	}
	else
	{
		myFile.get(ch);
		readfromnew =readfromold= false;
		
	}
	return *this;
}


void MatchMaker::replace()
{
	new_count = newone.size();
}

void MatchMaker::rewind(int matches,char ch)
{
	myFile.do_over(ch);
	myFile.put(old[0]);

	old_count = matches - 1;
	oldStringLength = matches;
}

bool MatchMaker::eof()
{
	if(readfromnew || readfromold)
		return false;
	else
		return myFile.endoffile();
}
void MatchMaker::replaceString()
{
	int searchStringLen=old.length();
	int newoneLen=newone.length();
	int match =0;
	while(!get(ch).eof())
	{
		if(ch==old[match])
		{
			match++;
			if(match < searchStringLen)
				continue;
		} 
		if(match == searchStringLen ) //It's a match!
		{
			replace();
		}
		else if( match > 0) 	
		{
			rewind(match,ch);
		}

		else myFile.put(ch); //Just a character, matching  process was never started
		/* POSSIBLE SOLUTION: just put out the new string */
		match=0;
	}

	if(newoneLen<searchStringLen)
	{
		truncate(filename, myFile.getputter());
	}
}
