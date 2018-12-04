#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isTriangleWord(string word);
bool isTriangleNumber(int num);


int main()
{
    ifstream textFile("words.txt");
    string word;
    vector<string> words;

    int newWordsFound = 2;
    int answer = 0;

    while (newWordsFound != 0)
    {
        getline(textFile, word, '"');
        if (word.length() > 0 && word != ",")
        {
            words.push_back(word);
            newWordsFound += 2;
        }
        newWordsFound--;
    }
    textFile.close();

    for (vector<string>::iterator it = words.begin(); it < words.end(); it++)
    {
        if (isTriangleWord(*it))
        {
            answer++;
        }
    }

    cout << answer << endl;

    return 0;
}

bool isTriangleWord(string word)
{
    int sum = 0;

    for (int i = 0; i < static_cast<int>(word.length()); i++)
    {
        sum += word.at(i) - 64;
    }
    return isTriangleNumber(sum);
}

bool isTriangleNumber(int num)
{
    for (int n = 1; (n * (n + 1)) / 2 <= num; n++)
    {
        if (num == ((n * (n + 1)) / 2))
        {
            return true;
        }
    }
    return false;
}
