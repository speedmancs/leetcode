#include "..\..\stdafx.h"
using namespace std;
NS(709)
class Solution {
public:
    string toLowerCase(string str) {
        for (char& c : str) c = ::tolower(c);
        return str;
    }
};
END_NS