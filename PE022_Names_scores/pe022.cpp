#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream textfile("names.txt");
    string name;
    vector<string> namelist;

    int newNamesFound = 2;
    int totalScore = 0;
    int sumOfLetters = 0;
    int index = 1;

    while(newNamesFound != 0)
    {
        getline(textfile, name, '"');
        if (name.length() > 1)
        {
            namelist.push_back(name);
            newNamesFound += 2;
        }
        newNamesFound--;
    }
    textfile.close();

    sort(namelist.begin(), namelist.end());

    for (string name : namelist)
    {
        sumOfLetters = 0;
        for (int letterPosition = 0; letterPosition < name.length(); letterPosition++)
        {
            sumOfLetters += name.at(letterPosition) - 64;
        }
        totalScore += sumOfLetters * index;
        index++;
    }

    cout << totalScore << endl;

    return 0;
}
