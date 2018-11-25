#include "..\..\stdafx.h"
using namespace std;
NS(929)
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> set;
        for (auto& email: emails)
            set.insert(transform(email));
        return set.size();
    }

    string transform(const string& email)
    {
        int index = email.find('@');
        string domain = email.substr(index);
        string name = email.substr(0, index);
        int index2 = name.find('+');
        if (index2 != string::npos)
        {
            name = name.substr(0, index2);
        }

        //name.erase(remove(name.begin(), name.end(), '.'), name.end());
        string result;
        for (char c : name)
        {
            if (c != '.') result += c;
        }
        result += domain;
        return result;
    }
};
END_NS