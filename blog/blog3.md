# 牛客华为刷题记录

所有代码都在[github](https://github.com/NearXdu/huawei)


## 21.简单密码
大写字母转成小写+1，即A变成b
小写字母按九宫格排列转成数字，这里我比较暴力，直接map一下
数字不变
```cpp
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map< char,char> m;
    m['a']='2';  
    m['b']='2';  
    m['c']='2';  
    m['d']='3';  
    m['e']='3';  
    m['f']='3';  
    m['g']='4';  
    m['h']='4';  
    m['i']='4';  
    m['j']='5';  
    m['k']='5';  
    m['l']='5';  
    m['m']='6';  
    m['n']='6';  
    m['o']='6';  
    m['p']='7';  
    m['q']='7';  
    m['r']='7';  
    m['s']='7';  
    m['t']='8';  
    m['u']='8';  
    m['v']='8';  
    m['w']='9';  
    m['x']='9';  
    m['y']='9';  
    m['z']='9';  
    string str;
    while(cin >> str)
    {
	for(int i=0;i<str.size();++i)
	{
	    if(str[i]<='z'&&str[i]>='a')
	    {
		str[i]=m[str[i]];
	    }
	    else if(str[i]<='Z'&&str[i]>='A')
	    {
		str[i]=std::tolower(str[i]);
		if(str[i]=='z')
		    str[i]='a';
		else
		    str[i]+=1;
	    }
	}
	cout<<str<<endl;

    }
    return 0;
}
```


---


## 22.汽水瓶
智力题，三个空瓶子可以换一个瓶，并且当最后剩下两个空瓶子的时候，还可以借一瓶。

假设刚开始有n个瓶子，那么这一次可以喝n/3瓶汽水，这n/3瓶汽水多出来的空瓶子和n/3没除尽的空瓶子将进入下一次结算。

因此每次迭代  n=n/3+n%3

```cpp
#include <iostream>
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
	if(n==0)
	    break;
	int count=0;
	while(n/3)
	{
	    count+=n/3;
	    n=n/3+n%3;
	}
	cout<<count+n-1<<endl;

    }
    return 0;

}
```

---

## 23.删除字符串中出现次数最少的字符
我的做法比较暴力，字符串中每个字符都hash一下统计出现次数，
接着把最小值找到，最后遍历原串，把不等于最小值的输出即可。
```cpp
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    int minVal=21;
    string str;
    while(cin >> str)
    {
	unordered_map<char,int>m;
	for(int i=0;i<str.size();++i)
	{
	    m[str[i]]++;
	}//init

	for(auto it = m.begin();it!=m.end();++it)
	{
	    if(it->second<minVal)
		minVal=it->second;
	}
	string res;
	for(int i=0;i<str.size();++i)
	{
	    if(m[str[i]]!=minVal)
		res+=str[i];
	}
	cout<<res<<endl;

    }
    return 0;
}
```

---


## 24.合唱队
这题有点意思，看了大神题解才做出来。传送门：[](https://www.nowcoder.com/questionTerminal/6d9d69e3898f45169a441632b325c7b4)

要求两次LIS，最长递增子序列还是可以做的。

LIS的一般解法方程：
$dp(i)=dp(j)_{max}+1  ,  0\leq j < i,a_j < a_i$

这里dp(i)表示以a[i]为结尾的最长递增子序列的长度

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <limits>

using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {

    	vector<int>a(n);
	vector<int>dp1(n+1,1);//
	vector<int>dp2(n+1,1);//
	for(int i=0;i<n;++i)
	{
	    cin>>a[i];
	}
	vector<int>ra(a.rbegin(),a.rend());
	for(int i=1;i<a.size();++i)
	{
	    for(int j=0;j<i;++j)
	    {
		if(a[i]>a[j])
		{
		    dp1[i]=max(dp1[i],dp1[j]+1);
		}
	    }
	}
	for(int i=1;i<ra.size();++i)
	{
	    for(int j=0;j<i;++j)
	    {
		if(ra[i]>ra[j])
		{
		    dp2[i]=max(dp2[i],dp2[j]+1);
		}
	    }
	}

	int mm=std::numeric_limits<int>::min();
	for(int i=0;i<a.size();++i)
	{
	    int j=a.size()-i-1;
	    if(dp1[i]+dp2[j]>mm)
	    {
		mm=dp1[i]+dp2[j];
	    }
	}
	cout<<a.size()-mm+1<<endl;
    }

    return 0;
}

```

---

## 25.数据分类处理
复杂的地方在于输出。
过程很简单：
1.对R排序去重
2.判断I中每个数字是否包含R
3.统计I中包含R的索引和数字
4.最后统计要输出的个数
```cpp

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool contain(int n,int i)
{
    string x1=to_string(n);
    string x2=to_string(i);

    return (x1.find(x2)==string::npos)?false:true;


}
int main(int argc,char **argv)
{
#if 1

    int In;
    int Rn;

    while(cin>>In)
    {
	int tmp;
	vector<int>I;
	vector<int>R;
	I.reserve(1024);
	R.reserve(1024);
	for(int i=0;i<In;++i)
	{
	    cin>>tmp;
	    I.push_back(tmp);
	}
	cin>>Rn;
	for(int i=0;i<Rn;++i)
	{
	    cin>>tmp;
	    R.push_back(tmp);
	}
	sort(R.begin(),R.end());
	R.erase(unique(R.begin(),R.end()),R.end());
	bool flag;

	vector<int> fin;
	for(int i=0;i<R.size();++i)
	{
	    vector<int>result;
	    flag=false;
	    int count=0;
	    for(int j=0;j<In;++j)
	    {
		if(contain(I[j],R[i]))
		{
		    flag=true;
		    ++count;
		    result.push_back(j);
		    result.push_back(I[j]);
		}

	    }
	    if(flag)
	    {
		fin.reserve(1024);
		fin.push_back(R[i]);
		fin.push_back(result.size()/2);
		for(int i=0;i<result.size();++i)
		{
		    fin.push_back(result[i]);
		}
	    }

	}
	cout<<fin.size()<<" ";
	for(int i=0;i<fin.size()-1;++i)
	{
	    cout<<fin[i]<<" ";
	}
	cout<<fin[fin.size()-1]<<endl;
    }


#endif

}

```

---

## 26.字符串排序
三个约束：
1.字母排序
2.大小写同时出现按照输入顺序，例如BxbaA -> aABbx
3.其他字符不变

我的做法比较简单粗暴，定义一个大小为26的string数组，遍历一遍原字符串，将字符塞到对应的位置。

输出的时候再遍历一次，如果是字母，就输出处理过的字符，非字母就直接输出。

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(int argc,char **argv)
{
    string raw;
    while(getline(cin,raw))
    {
	vector<string>sorted(26);
	for(int i=0;i<raw.size();++i)
	{
	    if(std::isalpha(raw[i]))
	    {
		if(raw[i]>='a'&&raw[i]<='z')
		{
		    sorted[raw[i]-'a']+=raw[i];
		}
		else
		{
		    sorted[raw[i]-'A']+=raw[i];
		}
	    }
	}
	string tmp;
	for(int i=0;i<sorted.size();++i)
	{
	    tmp+=sorted[i];
	}
	int count=0;
	for(int i=0;i<raw.size();++i)
	{
	    if(std::isalpha(raw[i]))
	    {
		cout<<tmp[count++];
	    }
	    else
	    {
		cout<<raw[i];
	    }
	}
	cout<<endl;
    }
   
    return 0;
}

```


---

## 27.查找兄弟单词
1.兄弟单词输入要先排序，这是一个坑，因为题目说了字典序
2.判断两个单词是否是兄弟单词，倒是很简单。
3.输出是个坑，比如如果要输出第2个兄弟单词，但实际上字典中只有1个符合要求
这个时候只输出2,

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool judgeBrother(const string &a,const string &b)
{
    if(a==b)//same string
	return false;
    if(a.size()!=b.size())
	return false;
    string ta(a.begin(),a.end());
    sort(ta.begin(),ta.end());
    string tb(b.begin(),b.end());
    sort(tb.begin(),tb.end());
    return ta==tb;
}
int main()
{
    int n;

    while(cin>>n)
    {
	vector<string>input(n);
	for(int i=0;i<n;++i)
	{
	    cin>>input[i];
	}
	sort(input.begin(),input.end());
	string target;
	cin>>target;
	int k;
	cin>>k;

	vector<string>res;
	res.reserve(1024);
	int count=0;
	for(int i=0;i<input.size();++i)
	{
	    if(judgeBrother(input[i],target))
	    {
		++count;
		res.push_back(input[i]);
	    }
	}
	cout<<count<<endl;
	if(k<=count)
	    cout<<res[k-1]<<endl;

    }
    return 0;

}
```


---

## 28.素数伴侣
这题属于放弃题，先说下我的思路（超时）

题目保证了输入数列的长度为偶数，如果输入是1 2 3 4
那么，我求出这个序列的全排列（stl有next_permutation）
```
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3 
1 4 3 2
//...
//...
```
然后相邻两个相加最后算出最大的素数伴侣对。

我们知道全排列的复杂度是$O(n!)$，最后超时。


网上大神的解法：[讨论区](https://www.nowcoder.com/questionTerminal/b9eae162e02f4f928eac37d7699b352e)

这里我就不贴代码了。


---

## 29.字符串加解密
比较简单了，按照规则来就可以：
```cpp
#include <iostream>
#include <string>
using namespace std;
string & code(string &s)
{
    for(int i=0;i<s.size();++i)
    {
	if(std::isalpha(s[i]))
	{
	    if(s[i]<='z'&&s[i]>='a')
	    {
		if(s[i]=='z')
		{
		    s[i]='A';
		}
		else
		{
		    s[i]=std::toupper(s[i])+1;
		}
	    }
	    else
	    {

		if(s[i]=='Z')
		{
		    s[i]='a';
		}
		else
		{
		    s[i]=std::tolower(s[i])+1;
		}
	    }
	}//end if
	else if(std::isalnum(s[i]))
	{
	    if(s[i]=='9')
		s[i]='0';
	    else
		s[i]=s[i]+1;
	}
    }
    return s;
}

string & decode(string &s)
{
    for(int i=0;i<s.size();++i)
    {
	if(std::isalpha(s[i]))
	{
	    if(s[i]<='z'&&s[i]>='a')
	    {
		if(s[i]=='a')
		{
		    s[i]='Z';
		}
		else
		{
		    s[i]=std::toupper(s[i])-1;
		}
	    }
	    else
	    {

		if(s[i]=='A')
		{
		    s[i]='z';
		}
		else
		{
		    s[i]=std::tolower(s[i])-1;
		}
	    }
	}//end if
	else if(std::isalnum(s[i]))
	{
	    if(s[i]=='0')
		s[i]='9';
	    else
		s[i]=s[i]-1;
	}
    }
    return s;

}
int main()
{
    string s1;
    string s2;
    while(cin>>s1>>s2)
    {
	s1=code(s1);
	s2=decode(s2);
	cout<<s1<<endl;
	cout<<s2<<endl;
    }
    return 0;

}
```

---

## 30.字符串合并处理
也是按要求即可。
1.先把输入合并
2.提取出奇数和偶数的子串
3.分别排序
4.组合
5.按要求转化

>note：题目的要求是二进制翻转，我懒得想算法了，直接map一下

```cpp
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
unordered_map<char ,char>idx;
string & change(string &tmp)
{
    for(int i=0;i<tmp.size();++i)
    {
	if(std::isdigit(tmp[i]))
	{
	    tmp[i]=idx[tmp[i]];
	    if(std::isalpha(tmp[i]))
		tmp[i]=toupper(tmp[i]);
	}
	else if((tolower(tmp[i])<='f'&&tolower(tmp[i])>='a'))
	{
	    tmp[i]=idx[tolower(tmp[i])];
	    if(std::isalpha(tmp[i]))
		tmp[i]=std::toupper(tmp[i]);
	}

    }
    return tmp;
}
int main()
{
    idx['0']='0';
    idx['1']='8';
    idx['2']='4';
    idx['3']='C';
    idx['4']='2';
    idx['5']='a';
    idx['6']='6';
    idx['7']='e';
    idx['8']='1';
    idx['9']='9';
    idx['a']='5';
    idx['b']='d';
    idx['c']='3';
    idx['d']='b';
    idx['e']='7';
    idx['f']='f';
    string str1;
    string str2;
    while(cin>>str1>>str2)
    {
	string tmp = str1+str2;
	string s1;//odd
	string s2;//even
	for(int i=0;i<tmp.size();++i)
	{
	    if((i&1)==0)//even
	    {
		s2+=tmp[i];
	    }
	    else//odd
	    {
		s1+=tmp[i];
	    }
	}
	sort(s1.begin(),s1.end());//odd
	sort(s2.begin(),s2.end());//even
	int ii=0;//even
	int jj=0;//odd
	string tmp2;
	for(int i=0;i<tmp.size();++i)
	{
	    if((i&1)==0)//even
	    {
		tmp2+=s2[ii++];
	    }
	    else//odd
	    {
		tmp2+=s1[jj++];
	    }
	}
	tmp2=change(tmp2);
	cout<<tmp2<<endl;
    }
    return 0;
}
```


---

