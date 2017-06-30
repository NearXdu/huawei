# 牛客华为刷题记录（二）

所有代码都在[github](https://github.com/NearXdu/huawei)


## 11.数字颠倒
颠倒就是逆序，可以把数字`to_string`一下然后再`reserve`
我的做法是按数字的方式处理，模10除10
```cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
	string str;
	while(n)
	{
	    str+=to_string(n%10);
	    n/=10;
	}
	cout<<str<<endl;
    }
    return 0;

}
```

---

## 12.字符串翻转
利用STL逆向迭代器和构造函数搞定

```cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string n;
    while(getline(cin,n))
    {
	string str(n.rbegin(),n.rend());
	cout<<str<<endl;
    }
    return 0;

}
```

---

## 13.句子逆序
`"hello world"`变成`"world hello"`
这个要逆转两次，先对整个句子进行逆序
`"dlrow olleh"`
再逐个单词逆序
`"world hello"`
```cpp
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
```

---

## 14.字串的连接最长路径查找
看完题目才知道是字符串字典序排序，直接上`std::sort`也行
不过我用了优先级队列，这样的话复杂度应该低一些。
`std::priority_queue`需要注意的是模板参数
```cpp
#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
int main()
{
    int n;
    priority_queue<string,vector<string>,greater<string> >q;
    
    string str;
    while(cin>>n)
    {
	for(int i=0;i<n;++i)
	{
	    cin>>str;
	    q.push(str);
	}
	while(!q.empty())
	{
	    cout<<q.top()<<endl;
	    q.pop();
	}
    }
    return 0;
}
```

---

## 15.求int型正整数在内存中存储时1的个数
剑指offer上的题，有一个小小的trick吧，当然直接按位比较也行的
```cpp
#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
	int count=0;
	while(n)
	{
	    n&=(n-1);
	    ++count;
	}
	cout<<count<<endl;
    }
}
```

---

## 16.购物单
这应该是前20题里面最耗费我时间的一题了。
改进的0-1背包，先回顾一下0-1背包：
最朴素的0-1背包问题里面，只有拿和不拿两个选项
因此动规方程可以如下写：
$dp(i,j) = max(dp(i-1,j), dp(i-1,j-w(i))+v(i))$

其中$dp(i,j)$表示在前i件物品，在j容量的前提下可以获得的最大价值
$w(i)$表示第i件物品的容量
$v(i)$表示第i件物品的价值

这题复杂在于要分情况讨论（主组件还是次要组件）,然后套一下0-1背包即可
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
	vector<int>v(m+1);//value
	vector<int>p(m+1);//importance
	vector<int>q(m+1);//major or minor
	vector< vector<int>  >dp(m+1,vector<int>(n+1));//dp
	//input
	for(int i=1;i<=m;++i)
	{
	    cin>>v[i]>>p[i]>>q[i];
	}
	for(int i=1;i<=m;++i)
	{
	    for(int j=1;j<=n;++j)
	    {
		if(!q[i])//major
		{
		    if(v[i]<=j)
		    {
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+v[i]*p[i]);
		    }
		}
		else// minor
		{
		    if(v[i]+v[q[i]]<=j)
		    {
			dp[i][j]=max(dp[i-1][j],dp[i-1][j-v[i]]+v[i]*p[i]);
		    }

		}

	    }
	}//end for
	cout<<dp[m][n]<<endl;
    }
}
```


---

## 17.坐标移动
坐标移动有几个要素：
1.将输入的数据分割成一个个的命令，可以用stringstream
2.判断每个命令是否合法
3.对命令进行编码（方向和移动的数值）

本题的坑在于不要盲目使用`std::stoi`，比如说遇到`A10A`这样的非法输入，
`std::stoi`会尽可能的转换，也就是说`stoi("10A")`将得到10，因此，

使用时需要判断，`stoi`是否全部转换：
```cpp
  	size_t index=0;
    auto res=std::stoi(response,&index);
    if(index==response.size())//完全转化
    {
	op=res;
    }
    else//
    {
	return false;
    }

```

```cpp
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
    //
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

```

---

## 18.识别有效的IP地址和掩码并进行分类统计
这题可以说是相当麻烦了，以至于我拿出了我压箱底的网络编程的技能。

每组数据表示一个IP和mask，比如`192.168.1.1~255.255.255.0`

题目要求堆这一组数据进行分类：
A、B、C、D、E、不合法的IP或者mask、私有IP

几个要考虑的地方：
1.判断IP和mask是否合法直接交给`inet_pton`了，这里只是从物理角度判断是否合法。排除类似192.1..1或者255...这种情况

2.判断mask是否合法，mask有个特点就是高地址全为1，低地址都是0，例如11111111000000000000000000000000
网上有人通过计算出二进制形式再去判断是挺麻烦的，我有更好的办法：
对于一个mask来说，判断是否为合法的mask，可以这样做：
a) 取反 `tmp=~mask`
b) 取反+1 `tmp2=tmp+1`
c) 相与，如果为0，则说明mask合法
这个算法很容易验证。

3.在使用socket函数注意大小端存储问题

4.只有mask和ip都合法之后，才能统计ip的类型，这是个体力活，一堆if-else

5.一个IP既可以是A类也可以是private

```cpp
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
```

---

## 19.简单错误记录

题目的几个描述：
1.记录最多8条记录，意思就是，如果有很多错误记录，只打印最后8条

2.输出的时候如果文件名超过16个字符则只要16个字符

3.输入的文件名有路径，输出不带路径

另外只比较文件名，不考虑路径，也就是/tmp/zx.c和/opt/zx.c认为是同一个文件

```cpp
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
```

---

## 20.密码验证合格程序
三个条件，前两个简单，第三个的意思就是
如果字符串中有重复子串，那么他们重复的数目不能超过2
也就是说`"abcxxxabc"`这样的字符是不合法的

第三个条件我的做法比较蠢，从0开始每次挑长度为3的子串，然后在剩下的部分查找子串，复杂度比较高，网上看到有正则表达式的解法，不是很熟。

```cpp
#include <iostream>
#include <string>
using namespace std;
bool condition1(const string& s)
{
    if(s.size()>8)
	return true;
    else
	return false;

}

bool condition2(const string& s)
{
    int upper=0;
    int lower=0;
    int digit=0;
    int symbol=0;
    int cnt=0;
    for(int i=0;i<s.size();++i)
    {
	if(s[i]>='0'&&s[i]<='9')
	{
	    digit=1;
	}
	else if(s[i]>='a'&&s[i]<='z')
	{
	    lower=1;
	}
	else if(s[i]>='A'&&s[i]<='Z')
	{
	    upper=1;
	}
	else
	{
	    symbol=1;
	}

    }
    cnt=upper+lower+digit+symbol;
    return cnt>2?true:false;
}

bool condition3(const string& s)
{
    for(int i=0;i<s.size()-2;++i)
    {
	string tmp=s.substr(i,3);
	string ss=s.substr(i+1);
	if(ss.find(tmp)!=string::npos)
	{
	    return false;
	}
    }
    return true;

}
int main()
{
    string s;
    while(cin>>s)
    {
	if(condition1(s)&&condition2(s)&&condition3(s))
	{
	    cout<<"OK"<<endl;
	}
	else
	{
	    cout<<"NG"<<endl;
	}
    }
    return 0;
}
```


