#include "..\..\stdafx.h"
using namespace std;
NS(157)
// Forward declaration of the read4 API.
int read4(char *buf)
{
    int count = 0;
    char* p = buf;
    while (*p != '\0')
    {
        count++;
        p++;
    }
    if (count >= 4)
    {
        return 4;
    }
    else
    {
        return count;
    }
}

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int count = 0;
        int remaining = n;
        while (remaining > 0)
        {
            int len = read4(buf);
            if (len >= remaining)
            {
                count += remaining;
                remaining = 0;
            }
            // len < remaining
            else if (len == 4)
            {
                remaining -= len;
                count += len;
                buf += len;
            }
            else
            {
                count += len;
                remaining -= len;
                break;
            }
        }
        return count;
    }
};
void Test()
{
    char str[] = "abcde";
    Solution().read(str, 5);
}
END_NS
