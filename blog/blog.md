# 牛客华为刷题记录

马上华为提前批开始了，吓得我赶紧上牛客网刷题，记录如下：
所有代码都在[github](https://github.com/NearXdu/huawei)

## 1.字符串最后一个单词的长度
一段英文字符串中最后一个单词的长度。
题目比较简单，做法有很多：
比如，
可以放到stringstream里面split，拿到最后一个单词
也可以从后往前数到第一个空格为止。

让我觉得麻烦是第一次做这种要自己写输入的题，
C++用cin是遇到空格停止的，因此要用`getline`读入一行

```cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin,str);
    int i=str.size()-1;
    int count=0;
    while(str[i]!=' '&&i>=0)
    {
	++count;
	--i;
    }
    cout<<count<<endl;
    return 0;
}
```

---


## 2.计算字符个数
输入一个字符串和一个字符，统计该字符在该字符串中出现的次数。
for循环比较即可，没什么好说的
```cpp
#include <iostream>
#include <string>
using namespace std;
int main(int argc,char **argv)
{
    string str;
    char c;

    getline(cin,str);
    cin>>c;

    int count=0;
    for(int i=0;i<str.size();++i)
    {
	if(tolower(str[i])==tolower(c))
	    ++count;
    }
    cout << count<<endl;


    return 0;
}
```

---

## 3.明明的随机数
说是随机数，其实跟随机数没有半毛钱关系，
就是输入一串整数，整数去重，输出排好序的结果，
C++使用`std::sort`、`std::unique`、`vector::erase`可以轻易做到

```cpp
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;


int main()
{
    // input 
    int n;
    while(cin>>n)
    {
	vector<int>v;
	v.reserve(1024);
	int j;
	for(int i=0;i<n;++i)
	{
	    cin >> j;
	    v.push_back(j);
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	if(v.capacity()<1024)
	    vector<int>(v).swap(v);

	//copy(v.begin(),v.end(),ostream_iterator<int>(cout,"\n"));
	for(int i=0;i<v.size();++i)
	    cout<<v[i]<<endl;
    }
    return 0;
}
```


---


## 4.字符串分隔
给定一个字符串，对其等距（长度8）分隔，最后不足的补0
例如，`123456789`将分割成:`12345678`和`90000000`

方法也很多，比如可以用`string::substr`，考虑到最后如果不足8个字符，需要补0，
这里我先创建一个`00000000`然后用`std::copy`来做

```cpp
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

```

---

## 5.进制转换
16进制转成10进制，基础题没啥好说的，
做一个map把0~F映射进去，比较方便，或者写个if-else判断当前字符是数字还是字母
```cpp
#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
using namespace std;
int main()
{
    unordered_map<char,int>mmap;
    mmap['0']=0;
    mmap['1']=1;
    mmap['2']=2;
    mmap['3']=3;
    mmap['4']=4;
    mmap['5']=5;
    mmap['6']=6;
    mmap['7']=7;
    mmap['8']=8;
    mmap['9']=9;
    mmap['a']=10;
    mmap['A']=10;
    mmap['b']=11;
    mmap['B']=11;
    mmap['c']=12;
    mmap['C']=12;
    mmap['d']=13;
    mmap['D']=13;
    mmap['e']=14;
    mmap['E']=14;
    mmap['F']=15;
    mmap['f']=15;
    string str;
    while(cin >> str)
    {
	str=str.substr(2);
	long sum=0;
	for(int i=0;i<str.size();++i)
	{
	    sum*=16;
	    sum+=mmap[str[i]];
	}
	cout<<sum<<endl;

    }

    return 0;
}
```

---

## 6.质数因子
不知道有没有更高端的方法，我的理解就是，对于一个数来说，比如180
从2开始遍历，如果能被2整除，那么180/=2，并且输出2，之后再拿90重复上述操作
直到变成1为止
```cpp
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long input;
    while(cin>>input)
    {
	while(input>static_cast<int>(1))
	{
	    for(int i=2;i<=input;++i)
	    {
		if(input%i==0)
		{
		    input/=i;
		    cout<<i<<" ";
		    break;
		}

	    }
	}
	cout<<endl;
    }
    return 0;
}
```

---

## 7.取近似值
输出一个浮点数四舍五入的值，C++标准库也有`round``floor``ceil`这样的函数，
我的办法比较土，转成string以后提出小数点第一位然后再判断：
```cpp
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
```

---

## 8.合并表记录
这题不复杂，就是麻烦，大概意思就是输入(key-value)对，
key相同的要合并，合并就是将value加起来，最后将这些(key-value)对升序排行
我的做法定义一个结构体，然后重写`operator==`和`std::sort`的比较函数，实际上定义一个`unordered_map<int,int>`会更简单吧。
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct pair_
{
    int key;
    int value;

    bool operator==(const struct pair_ &x)
    {
	return x.key==this->key;
    }
};
typedef vector<pair_> Pairs;
class comp{
    public:
	bool operator()(const pair_&a,const pair_&b)
	{
	    return a.key<b.key;
	}
};
int main(int argc,char **argv)
{
    int N;
    Pairs pairs;
    pairs.reserve(1024);
    while(cin>>N)
    {
	Pairs::iterator it;
	for(int i=0;i<N;++i)
	{
	    pair_ tmp;
	    cin>>tmp.key>>tmp.value;
#if 1
	    if((it =find(pairs.begin(),pairs.end(),tmp))!=pairs.end())
		it->value+=tmp.value;
	    else
		pairs.push_back(tmp);
#endif
	}
	sort(pairs.begin(),pairs.end(),comp());
	for(int i=0;i<pairs.size();++i)
	{
	    cout<<pairs[i].key<<" "<<pairs[i].value<<endl;

	}


    }
    return 0;
}
```
---

## 9.提取不重复整数
简单粗暴的做法，定义一个`unordered_set`把出现过的放进去
从后往前迭代一次就可以了。
```cpp
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
	string str=to_string(n);
	unordered_set<char>s;
	int sum=0;
	for(int i=str.size()-1;i>=0;--i)
	{
	    if(s.find(str[i])==s.end())
	    {
		sum*=10;
		sum+=(str[i]-'0');
		s.insert(str[i]);
	    }
	}
	cout<<sum<<endl;;
    }
    return 0;
}
```

## 10.字符个数统计
统计ACSII码范围（0-127）的字符，重复的字符只统计一次
比如`aaa`只统计为1

我的做法依然简单粗暴，用一个`unordered_set`

其实只需要一个127大小的char数组，出现就赋值1，最后统计即可

```cpp
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
int main()
{
    string str;
    unordered_set<char>s;
    std::getline(cin,str);

    int count=0;
    for(int i=0;i<str.size();++i)
    {
	if(str[i]<128&&str[i]>=0)
	{
	    if(s.find(str[i])==s.end())
	    {
		++count;
		s.insert(str[i]);
	    }
	}
    }
    cout<<count<<endl;

    return 0;
}
```
