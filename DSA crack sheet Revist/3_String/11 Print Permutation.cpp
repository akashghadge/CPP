/*

*/
#include <bits/stdc++.h>
using namespace std;
		set<string> ans;
	    void help(int id,int n,string str)
	    {
	        if(id==n)
	        {
	            ans.insert(str);
	            return;
	        }
	        for(int i=id;i<n;i++)
	        {
	            swap(str[id],str[i]);
	            help(id+1,n,str);
	        }
	    }
		vector<string>find_permutation(string str)
		{
		    // Code here there
		    sort(str.begin(),str.end());
		    help(0,str.size(),str);
		    vector<string> res(ans.begin(),ans.end());
		    return res;
		}
int main()
{
}