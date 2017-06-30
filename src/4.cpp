#include <iostream>
#include <string>
using namespace std;

int main(int argc, char ** argv)
{
    string str1;
    string str2;
    cin>>str1>>str2;

    
    for(int i=0;i<str1.size();i+=8)
    {
	string output("00000000");
	int l=(i+8)<str1.size()?8:(str1.size()-i);
	std::copy(str1.begin()+i,str1.begin()+i+l,output.begin());
	cout<<output<<endl;
    }
    for(int i=0;i<str2.size();i+=8)
    {
	string output("00000000");
	int l=(i+8)<str2.size()?8:(str2.size()-i);
	std::copy(str2.begin()+i,str2.begin()+i+l,output.begin());
	cout<<output<<endl;
    }

    return 0;
}

