#include "..\..\stdafx.h"
using namespace std;
NS(604)
class StringIterator {
public:
    char currentChar;
    string rawStr;
    int remainingCount;
    int position;
    StringIterator(string compressedString) {
        rawStr = compressedString;
        position = 0;
        remainingCount = 0;
    }

    void Decode()
    {
        if (position >= rawStr.size()) return;
        currentChar = rawStr[position];
        int index = position + 1;
        while (index < rawStr.size() && isdigit(rawStr[index])) index ++;
        remainingCount = stoi(rawStr.substr(position + 1, index - position - 1));
        position = index;
    }

    char next() {
        if (!hasNext()) return ' ';

        if (remainingCount == 0)
        {
            Decode();
        }
        remainingCount--;
        return currentChar;
    }

    bool hasNext() {
        if (remainingCount > 0)
        {
            return true;
        }

        if (position == rawStr.size()) return false;
        return true;
    }
};
void Test()
{
    StringIterator iter("G4X10v8G17x15A12c12d6F1A13K3z17U11Z17Z1F5J14L16o18o13M18h20n6R20Y8B5Q3f16C5y2b13W11B10A15p5O20K10v14U1e5k10e12l12E4s18p11");
    iter.next();
}
END_NS