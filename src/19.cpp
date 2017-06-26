#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
struct record{
    string num;
    string file;
    mutable int count;
    record(string n,string f):num(n),file(f),count(1){}
};
bool operator==(const struct  record & X,const struct record & Y)
{
    return (Y.num==X.num)&&(Y.file==X.file);
}
bool operator!=(const struct  record & X,const struct record & Y)
{
    return  !(X==Y);
}

string getFileName(const string &input)
{
    std::size_t found = input.find_last_of("/\\");
    string file = input.substr(found+1);
#if 0
    if(file.size()>16)
    {
	file = file.substr(file.size() - 16);
    }
#endif
    return file;
}
void outFile(string &file)
{
    if(file.size()>16)
    {
	file = file.substr(file.size() - 16);
    }

}
int main(int argc,char **argv)
{
    string input1;
    string input2;
    vector<record> records;

#if  1
    while(cin>>input1>>input2)
    {
	string file=getFileName(input1);
	struct record r(input2,getFileName(input1));
	auto it = find(records.begin(),records.end(),r);
	if(it!=records.end())
	{
	    it->count++;
	}
	else
	{
	    records.push_back(r);
	}
    }
    int idx=(records.size()>8)?(records.size()-8):0;

    for(int i = idx;i<records.size();++i)
    {
	outFile(records[i].file);
	cout<<records[i].file<<" "<<records[i].num<<" "<<records[i].count<<endl;
    }
#endif
    return 0;
}
