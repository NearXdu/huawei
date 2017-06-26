#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;
struct record{
    string num;
    string file;
    mutable int count;
    record(string n,string f):num(n),file(f),count(1){}
};
bool operator==(const struct  record & X,const struct record & Y)
{
    //return hash<string>()(X.num+X.file)==hash<string>()(Y.num+Y.file);
    return (Y.num==X.num)&&(Y.file==X.file);
}


struct record_hash{
    size_t operator()(const struct record& _r) const {
	string tmp=_r.file+_r.num;
	return std::hash<string>()(tmp);
    }
};
string getFileName(const string &input)
{
    std::size_t found = input.find_last_of("/\\");
    string file = input.substr(found+1);
    if(file.size()>16)
    {
	file = file.substr(file.size() - 16);
    }
    return file;

}
int main(int argc,char **argv)
{
    string input1;
    string input2;
    unordered_set<record,record_hash> records;
    records.insert(record("zhang","xiao"));
    record r("zhang","xiao");
    auto it = records.find(r);
    cout<<it->num<<" "<<it->file<<endl;
    ++it->count;

#if 0 
    while(cin>>input1>>input2)
    {
	string file=getFileName(input1);
	struct record r(input2,getFileName(input1));
	unordered_set<record,record_hash>::iterator it = records.find(r);
	if(it!=records.end())
	{
	    it->count++;
	}
	else
	{
	    records.insert(r);
	}
    }
    int count=0;
    for(auto it = records.begin();it!=records.end();++it)
    {
	
	if(count+8>=records.size())
	{
	    cout<<it->file<<" "<<it->num<<" "<<it->count<<endl;
	}
	++count;
    }
#endif
    return 0;
}
