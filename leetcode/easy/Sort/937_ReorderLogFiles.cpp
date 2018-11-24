#include "..\..\stdafx.h"
using namespace std;
NS(937)
class Log
{
public:
    Log(int _index, string& _identifier, string& _str) : 
        index(_index), identifier(&_identifier), str(&_str)
    {
        isLetterLog = true;
        if (isdigit(_str[index])) isLetterLog = false;
    }

    bool IsLetterLog() const { return isLetterLog; }
    string& Str() const { return *str; }
    int Index() const { return index; }
    string& Identifier() const { return *identifier; }

private:
    string* str;
    int index;
    bool isLetterLog;
    string* identifier;
};
class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> identifiers;
        vector<int> indexes;
        vector<string> results;
        vector<Log> logItems;
        for (auto& log : logs)
        {
            int index = log.find(" ");
            string identifier = log.substr(0, index);
            index++;
            indexes.push_back(index);
            identifiers.push_back(identifier);
            logItems.push_back(Log(index, identifier, log));
        }

        std::stable_sort(logItems.begin(), logItems.end(), [](const Log& a, const Log& b)
        {
            if (a.IsLetterLog() && !b.IsLetterLog()) return true;
            if (!a.IsLetterLog() && b.IsLetterLog()) return false;
            if (a.IsLetterLog() && b.IsLetterLog())
            {
                int result = strcmp(a.Str().c_str() + a.Index(), b.Str().c_str() + b.Index());
                if (result < 0) return true;
                if (result > 0) return false;
                return a.Identifier() < b.Identifier();
            }

            return false;
        });

        for (auto& log : logItems)
        {
            results.push_back(log.Str());
        }

        return results;
    }
};

void Test()
{
    vector<string> input = { "a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo" };
    auto results = Solution().reorderLogFiles(input);
}
END_NS
