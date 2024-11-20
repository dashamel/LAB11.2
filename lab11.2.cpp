#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool hasWordStartingWithA(const string& fname) 
{
    ifstream file(fname);
    if (!file.is_open()) {
        cout << "Cannot open file.\n";
        return false;
    }

    string line;

    while (getline(file, line)) 
    {
        size_t pos = 0;
        while ((pos = line.find(' ', pos)) != string::npos)
        {
            pos++;
            if ((line[pos] == 'a' && (pos == 0 || line[pos - 1] == ' ')) || (line[0] == 'a' && pos == 0)) 
            {
                file.close();
                return true;
            }
        }
    }

    file.close();
    return false;
}

int main() 
{
    string fname;
    cout << "Type filename: ";
    cin >> fname;

    if (hasWordStartingWithA(fname))
    {
        cout << "File contains words starting with 'a'.\n";
    }
    else 
    {
        cout << "File does not contain words starting with 'a'.\n";
    }

    return 0;
}

