#include <iostream>
using namespace std;
#include "vector"
#include "bitset"
#include "unordered_map"

unordered_map<char, int> getLetterMap()
{
    unordered_map<char, int> letters;
    int j = 0;
    for (char i = 'a'; i <= 'z'; i++)
    {
        letters[i] = j;
        j++;
    }
    return letters;
}
int numberOfValidWords(vector<string> puzzels, vector<string> words)
{
    unordered_map<char, int> letters = getLetterMap();
    for (auto puzzel : puzzels)
    {
        int finalCount = 0;
        bitset<32> bitPuzzel;
        for (int i = 0; i < puzzel.size(); i++)
        {
            bitPuzzel.set(letters[puzzel[i]], 1);
        }

        for (auto word : words)
        {
            if (puzzel[0] == word[0])
            {
                bitset<32> bitWord;
                for (int i = 0; i < word.size(); i++)
                {
                    bitWord.set(letters[word[i]], 1);
                }
                bitset<32> result;
                result = bitWord & bitPuzzel;
                if (result.count() == bitPuzzel.count())
                {
                    finalCount++;
                }
            } 
        }
        cout << puzzel << " -> " << finalCount << endl;
    }
    return 0;
}

int main()
{
    // main
    int nPuzzel;
    cin >> nPuzzel;
    vector<string> puzzels;
    for (int i = 0; i < nPuzzel; i++)
    {
        string temp;
        cin >> temp;
        puzzels.push_back(temp);
    }
    int nWord;
    cin >> nWord;
    vector<string> words;
    for (int i = 0; i < nWord; i++)
    {
        string temp;
        cin >> temp;
        words.push_back(temp);
    }

    // unordered_map<char, int> letters = getLetterMap();
    // cout << letters['b'] << endl;

    numberOfValidWords(puzzels, words);
}

// 7
// aaaa asas able ability actt actor access
// 6
// aboveyz abrodyz abslute absoryz actresz gaswxyz