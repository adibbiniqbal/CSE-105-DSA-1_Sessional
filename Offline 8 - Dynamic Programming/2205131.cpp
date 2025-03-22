#include <iostream>
#include <vector>
using namespace std;
bool regExpMatch(string &str, string &pattern)
{
    int lenStr = str.size();
    int lenPattern = pattern.size();
    vector<vector<bool>> dynamicRecord(lenStr + 1, vector<bool>(lenPattern + 1, false));
    dynamicRecord[0][0] = 1;
    for (int i = 1; i <= lenPattern; i++)
    {
        if (pattern[i - 1] == '*')
            dynamicRecord[0][i] = dynamicRecord[0][i - 2];
    }
    for (int i = 1; i <= lenStr; i++)
    {
        for (int j = 1; j <= lenPattern; j++)
        {
            if (pattern[j - 1] == str[i - 1] || pattern[j - 1] == '.')
            {
                dynamicRecord[i][j] = dynamicRecord[i - 1][j - 1];
            }
            else if (pattern[j - 1] == '*')
            {
                dynamicRecord[i][j] = dynamicRecord[i][j - 2] || (dynamicRecord[i - 1][j] && (pattern[j - 2] == str[i - 1] || pattern[j - 2] == '.'));
            }
            else if (pattern[j - 1] == '+')
            {
                dynamicRecord[i][j] = (dynamicRecord[i - 1][j] || dynamicRecord[i][j - 1]) && (pattern[j - 2] == str[i - 1] || pattern[j - 2] == '.');
            }
        }
    }
    return dynamicRecord[lenStr][lenPattern];
}
int main()
{
    string str, pattern;
    getline(cin,str);
    getline(cin,pattern);
    regExpMatch(str, pattern) ? cout << "True" << endl : cout << "False" << endl;
}
