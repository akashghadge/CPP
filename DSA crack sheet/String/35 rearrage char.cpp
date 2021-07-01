/*
rearrange
*/

#include <bits/stdc++.h>
#define en "\n"
#define ll long long
using namespace std;
bool isRearr(string str)
{
    unordered_map<char, int> freq;
    for (char ch : str)
    {
        freq[ch]++;
    }
    int maxFreq = 0;
    for (auto val : freq)
    {
        maxFreq = max(maxFreq, val.second);
    }
    if (maxFreq > (str.size() / 2) + 1)
    {
        return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    string str;
    while (T--)
    {
        cin >> str;
        cout << isRearr(str) << en;
    }

    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;
struct Key
{
	int freq; // store frequency of character
	char ch;
	bool operator<(const Key &k) const
	{
		return freq < k.freq;
	}
};

string rearrangeString(string str)
{
	int n = str.length();
	int count[MAX_CHAR] = {0};
	for (int i = 0 ; i < n ; i++)
		count[str[i]-'a']++;
	priority_queue< Key > pq;
	for (char c = 'a' ; c <= 'z' ; c++)
		if (count[c-'a'])
			pq.push( Key { count[c-'a'], c} );
	str = "" ;
	Key prev {-1, '#'} ;
	while (!pq.empty())
	{
		Key k = pq.top();
		pq.pop();
		str = str + k.ch;
		if (prev.freq > 0)
			pq.push(prev);
		(k.freq)--;
		prev = k;
	}
	if (n != str.length())
		return "-1";
	else
		return str;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    str=rearrangeString(str);
	int flag=1;
	if(str!="-1"){
	for(int i=0;i<str.length();i++)
	{
		if(i>0)
		if(str[i-1]==str[i])
			flag=0;
	}
	if(flag==1)
		cout<<"1\n";
	else
	cout<<"0\n";}
	else
		cout<<"0\n";
	}
return 0;
}

*/