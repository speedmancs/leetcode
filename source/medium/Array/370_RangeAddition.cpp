#include <vector>
#include <string>
#include <iostream>
using namespace std;
// class Solution {
// public:
//     vector<int> getModifiedArray(int n, vector<vector<int>>& updates) {
//         vector<int> a(n, 0);
//         // update: i, j, d => a[i:j] all add d
//         //                 => a[i:n) all add d && a[j + 1 : n) all add -d
//         // let d[j] be the amount added all to range a[j:n)

//         vector<int> d(n + 1, 0); 
//         for (auto& v: updates)
//         {
//             int i = v[0]; int j = v[1]; int amount = v[2];
//             d[i] += amount; d[j + 1] += -amount;
//         }

//         // then we have: a[0] = d[0], a[1] = d[0] + d[1],
//         //               a[i] = d[0] + ... d[i] = a[i - 1] + d[i]
//         a[0] = d[0];
//         for (int i = 1; i < n; i ++)
//         {
//             a[i] = a[i - 1] + d[i];
//         }
//         return a;
//     }
// };

// actually we can only use one array
class Solution {
public:
    vector<int> getModifiedArray(int n, vector<vector<int>>& updates) {
  
        vector<int> a(n, 0);
        // update: i, j, d => a[i:j] all add d
        //                 => a[i:n) all add d && a[j + 1 : n) all add -d
        // let d[j] be the amount added all to range a[j:n)

        for (auto& v: updates)
        {
            int i = v[0]; int j = v[1]; int amount = v[2];
            a[i] += amount; 
            if (j + 1 < n) a[j + 1] -= amount;
        }

        for (int i = 1; i < n; i ++)
        {
            a[i] = a[i - 1] + a[i];
        }
        return a;
    }
};