#include <iostream>
using namespace std;
#include "string"
#include "map"
int main()
{
    map<string, int> cricketScore;

    cricketScore["akash"] = 100;
    cricketScore["ash"] = 264;
    cricketScore["tech"] = 9;

    cout << cricketScore["akash"] << endl;

    map<string, int>::iterator itr;

    itr = cricketScore.begin();
    while (itr != cricketScore.end())
    {
        cout << "Name : " << (*itr).first << " Runs Score : " << (*itr).second << endl;
        itr++;
    }

    // finding value using key
    cout << cricketScore.at("akash") << endl;

    // insert key value pair or use pair data structure
    cricketScore.insert({"ghadge", 50});

    cout << "size of map : " << cricketScore.size() << endl;

    itr = cricketScore.begin();
    while (itr != cricketScore.end())
    {
        cout << "Name : " << (*itr).first << " Runs Score : " << (*itr).second << endl;
        itr++;
    }
}