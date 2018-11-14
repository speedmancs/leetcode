#include "..\..\stdafx.h"
using namespace std;
NS(800)
class Solution {
public:
    int convert(char a)
    {
        return isdigit(a) ? a - '0' : a - 'a' + 10;
    }

    char convert(int v)
    {
        if (v < 10) return '0' + v;
        return 'a' + v - 10;
    }
    int parse(char a, char b)
    {
        return convert(a) * 16 + convert(b);
    }

    string findMin(char a, char b)
    {
        int min_v = INT_MAX;
        int value = parse(a, b);
        int index = 0;
        for (int i = 0; i < 16; i++)
        {
            int value2 = i * 16 + i;
            int dis = abs(value - value2);
            if (dis < min_v)
            {
                min_v = dis;
                index = i;

            }
        }
        
        string res;
        res += convert(index);
        res += convert(index);
        return res;
    }
    string similarRGB(string color) {
        string result = "#";
        for (int i = 0; i < 3; i++)
        {
            result += findMin(color[2 * i + 1], color[2 * i + 2]);
        }
        return result;
    }
};

// Math O(1)
class Solution2 {
public:
    int convert(char a)
    {
        return isdigit(a) ? a - '0' : a - 'a' + 10;
    }

    char convert(int v)
    {
        if (v < 10) return '0' + v;
        return 'a' + v - 10;
    }
    int parse(char a, char b)
    {
        return convert(a) * 16 + convert(b);
    }

    string findMin(char a, char b)
    {
        int min_v = INT_MAX;
        int value = parse(a, b);
        
        int index = value / 17;
        if (index < 15 && (17 * (index + 1) - value) < (value - 17 * index))
        {
            index++;
        }

        string res;
        res += convert(index);
        res += convert(index);
        return res;
    }
    string similarRGB(string color) {
        string result = "#";
        for (int i = 0; i < 3; i++)
        {
            result += findMin(color[2 * i + 1], color[2 * i + 2]);
        }
        return result;
    }
};

void Test()
{
    cout << Solution2().similarRGB(string("#09f166")) << endl;
}
END_NS