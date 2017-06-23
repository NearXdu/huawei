#include <iostream>
using namespace std;
int main()
{
    double f;
    while(cin>>f)
    {
	string str(std::to_string(f));
	int pos=str.find('.');
	int v1=std::stoi(str.substr(0,pos));
	int v2=str[pos+1]-'0';
	cout<< (v2>4?(v1+1):v1)<<endl;
    }
    return 0;
}
