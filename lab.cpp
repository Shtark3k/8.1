#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string ExtractPrefix(const string& s)
{
    size_t pos = s.find(' ');
    if (pos == string::npos)
        return s;       
    return s.substr(0, pos);
}


string Normalize(const string& segment)
{
    string result;
    result.reserve(segment.size());

    for (char ch : segment)
    {
        if (isalnum(static_cast<unsigned char>(ch)))
        {
            if (isupper(static_cast<unsigned char>(ch)))
                result.push_back(static_cast<char>(tolower(static_cast<unsigned char>(ch))));
            else
                result.push_back(ch);
        }
    }
    return result;
}

int main()
{
    cout << "Enter string:\n";
    string input;
    getline(cin, input);

    string prefix = ExtractPrefix(input);

    string output = Normalize(prefix);

    cout << "Transformed segment: " << output << endl;
    return 0;
}
