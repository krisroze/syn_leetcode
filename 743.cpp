// https://leetcode.com/problems/network-delay-time/
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);

        for (const auto& time : times) adj[time[0]].push_back({time[1], time[2]});

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        vector<int> network(n+1, INT_MAX);
        network[k] = 0;

        while (!pq.empty()) {
            auto [currentTime, currentNode] = pq.top();
            pq.pop();

            for (const auto& [nextNode, weight] : adj[currentNode]) {
                int newTime = currentTime + weight;

                if (newTime < network[nextNode]) {
                    network[nextNode] = newTime;
                    pq.push({newTime, nextNode});
                }
            }
        }

        int minTime = 0;
        for (int i = 1; i <= n; i++) {
            if (network[i] == INT_MAX) return -1;
            minTime = max(minTime, network[i]);
        }

        return minTime;
    }
};