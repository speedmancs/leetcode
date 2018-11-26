#include "..\..\stdafx.h"
using namespace std;
NS(743)
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<vector<pair<int, int>>> edges(N);
        for (auto& v : times)
        {
            edges[v[0] - 1].push_back(make_pair(v[1] - 1, v[2]));
        }
        K--;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(N, INT_MAX);
        dist[K] = 0;
        pq.push(make_pair(0, K));
        unordered_set<int> S;
        while (!pq.empty())
        {
            int u = pq.top().second;
            int minDis = pq.top().first;
            pq.pop();

            if (S.find(u) != S.end()) continue;
            S.insert(u);

            for (auto& p : edges[u])
            {
                int v = p.first;
                if (minDis + p.second < dist[v])
                {
                    dist[v] = minDis + p.second;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        if (S.size() != N) return -1;
        return *max_element(dist.begin(), dist.end());
    }
};

//class Solution {
//public:
//    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
//        vector<vector<pair<int, int>>> g(N, vector<pair<int, int>>());
//        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
//        for (auto &v : times) {
//            g[v[0] - 1].push_back(make_pair(v[1] - 1, v[2]));
//        }
//        K--;
//        pq.push(make_pair(0, K));
//        vector<int> weights(N, INT_MAX);
//        weights[K] = 0;
//        while (!pq.empty()) {
//            auto t = pq.top();
//            pq.pop();
//            for (auto &p : g[t.second]) {
//                int new_weight = t.first + p.second;
//                if (weights[p.first] > new_weight) {
//                    weights[p.first] = new_weight;
//                    pq.push(make_pair(new_weight, p.first));
//                }
//            }
//        }
//        int val = *max_element(weights.begin(), weights.end());
//        if (val == INT_MAX) return -1;
//        return val;
//    }
//};
END_NS