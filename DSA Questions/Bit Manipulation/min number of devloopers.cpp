#include <iostream>
using namespace std;
#include "unordered_map"
#include "vector"
int solution(int dev[], int currentDevNumber, int currerntDevCount, int nSkills, int nDev, int *minNumber, vector<vector<int>> &res)
{
}

/*
	public static void solution(int[] people, int nskills, int cp, ArrayList<Integer> onesol, int skills) {
		// write your code here
		if(cp==people.length){
		    if(skills==(1<<nskills)-1){
    		    if(sol.size()==0 || onesol.size() < sol.size()){
    		        sol=new ArrayList<>(onesol);
    		    }
		    }
		    return;
		}
		solution(people,nskills,cp+1,onesol,skills);
		onesol.add(cp);
		solution(people,nskills,cp+1,onesol,(people[cp]|skills));
		onesol.remove(onesol.size()-1);
	}
*/
int main()
{
    int numberOfSkills;
    cin >> numberOfSkills;
    unordered_map<string, int> skills;
    for (int i = 0; i < numberOfSkills; i++)
    {
        string temp;
        cin >> temp;
        pair<string, int> p = make_pair(temp, i);
        skills.insert(p);
    }
    int nDev;
    cin >> nDev;
    int devlopers[nDev];
    for (int i = 0; i < nDev; i++)
    {
        int nDevSkills;
        cin >> nDevSkills;

        for (int j = 0; j < nDevSkills; j++)
        {
            string temp;
            cin >> temp;
            int val = skills[temp];
            devlopers[i] |= 1 << val;
        }
    }
    vector<vector<int>> res;
    int minNumber = nDev;
    solution(devlopers, 0, 0, numberOfSkills, nDev, &minNumber, res);
}