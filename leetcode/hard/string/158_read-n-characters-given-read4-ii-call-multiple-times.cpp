#include "..\..\stdafx.h"
using namespace std;
NS(158)
// Forward declaration of the read4 API.
int location = 0;
char data[] = "ab";
int dataLen = 2;
int read4(char *buf)
{
    int nLen = min(4, dataLen - location);
    for (int i = 0; i < nLen; i ++)
        buf[i] = 0;
    location += nLen;
    return nLen;
}

class Solution {
private:
    queue<char> cache;
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int remaining = n;
        while (remaining > 0)
        {
            int cachedLen = cache.size();
            if (cachedLen >= remaining)
            {
                while (remaining--)
                {
                    *buf = cache.front();
                    cache.pop();
                    buf++;
                }
                remaining = 0;
                break;
            }

            // cacheLen < remaining
            while (cachedLen--)
            {
                *buf = cache.front();
                cache.pop();
                buf++;
                remaining--;
            }
                
            int len = read4(buf);
            if (len <= remaining)
            {
                buf += len;
                remaining -= len;
                if (len < 4) break;
            }
            // len > remaining
            else
            {
                buf += remaining;
                int gap = len - remaining;
                int i = 0;
                while (gap--)
                {
                    cache.push(buf[i ++]);
                }
                remaining = 0;
                break;
            }
        }
        return n - remaining;
    }
};
void Test()
{
    char buf[5];
    auto sol = Solution();
    sol.read(buf, 1);
    sol.read(buf, 1);
    sol.read(buf, 1);
}
END_NS
