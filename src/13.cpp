#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int main()
{
    string line;
    while(getline(cin,line))
    {
	string tmp(line.rbegin(),line.rend());
	stringstream ss(tmp);
	string word;
	vector<string>words;
	while(ss>>word)
	{
	    words.push_back(string(word.rbegin(),word.rend()));
	    words.push_back(" ");
	}
	for(int i=0;i<words.size();++i)
	{
	    if(i==words.size()-1)
		words[i].pop_back();    
	    cout<<words[i];

	}
	cout<<endl;
    }
    return 0;


}
