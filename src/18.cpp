#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
using namespace std;

bool judgemask(string mask,vector<int>&result)
{

    struct sockaddr_in ss;
    int ret = inet_pton(AF_INET,mask.c_str(),&ss.sin_addr);
    if(ret!=1)
    {
	++result[5];
	return false;
    }
    unsigned int num=ss.sin_addr.s_addr;
    num=ntohl(num);//
    if(num==0||~num==0)
    {
	++result[5];
	return false;
    }
    unsigned int y=~num;
    unsigned int z=(y+1);
    if((y&z)==0)
    {
	return true;
    }
    else
    {
	++result[5];
	return false;
    }

}
void judgeip(string ip,bool mask,vector<int>&result)
{
    if(mask==false)
    {
	return ;
    }
    struct sockaddr_in ss;
    int ret = inet_pton(AF_INET,ip.c_str(),&ss.sin_addr);
    if(ret!=1)
    {
	++result[5];
    }
    else
    {
#if 1
	stringstream ss(ip);
	string a1;
	string a2;
	getline(ss,a1,'.');
	getline(ss,a2,'.');
	int num=std::stoi(a1);
	int num2=std::stoi(a2);
	if(num>=1&&num<=126)
	{
	    ++result[0];
	    if(num==10)
		++result[6];
	}
	else if(num>=128&&num<=191)
	{
	    ++result[1];
	    if((num==172)&& (num2>=16&&num2<=31))
		++result[6];
	}
	else if(num>=192&&num<=223)
	{
	    ++result[2];
	    if((num==192)&&(num2==168))
		++result[6];
	}
	else if(num>=224&&num<=239)
	    ++result[3];
	else if(num>=240&&num<=255)
	    ++result[4];

#endif
    }

}
int main()
{

    string str;
    //0    1    2    3    4       5             6
    //A    B    C    D    E     wrongIP/mask  private 
    vector<int>result(7);
    while(cin>>str)
    {
	int pos=str.find('~');
	string ip=str.substr(0,pos);
	string mask=str.substr(pos+1);
	bool ret = judgemask(mask,result);
	judgeip(ip,ret,result);
    }
    adjacent_difference(result.begin(),result.end(),ostream_iterator<int>(cout),
	    [](int x,int y){cout<<" ";return x;} );
    cout<<endl;
    return 0;

}
