#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;
bool is_valid(string s,int& op,int &pointer)
{
    if(s.size()<2||s.size()>3)
	return false;
    char point=s[0];
    if(point!='W'&&point!='S'&&point!='A'&&point!='D')
	return false;
    else if(point=='W')
	pointer=2;
    else if(point=='A')
	pointer=0;
    else if(point=='S')
	pointer=3;
    else //D
	pointer=1;

    string response=s.substr(1);
    size_t index=0;
    auto res=std::stoi(response,&index);
    if(index==response.size())
    {
	op=res;
    }
    else
    {
	return false;
    }
    
    
    return true;
}
int main(int argc,char **argv)
{
    string input;
    while(getline(cin,input))
    {
	stringstream ss(input);
	vector<string>steps;
	int x=0;
	int y=0;
	while(ss.good())
	{
	    string step;
	    int op=-1;
	    int pointer=-1;
	    getline(ss,step,';');
	    if(is_valid(step,op,pointer))
	    {
		//op: 0 -A -x | 1 -D +x | 2 -W +y | 3 -S -y
		if(pointer==0)
		{
		    x-=op;
		}
		else if(pointer==1)
		{
		    x+=op;
		}
		else if(pointer==2)
		{
		    y+=op;
		}
		else
		{
		    y-=op;
		}
	    }//end if
	}
	cout<<x<<","<<y<<endl;

    }
    return 0;
}


