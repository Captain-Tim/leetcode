class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        ++n;
        vector<vector<pair<int, int>>> adj(n);
        for (const vector<int>& road : roads)
        {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        vector<bool> visited(n, false);
        queue<int> qu;
        qu.push(1);
        int res = INT_MAX;
        while (!qu.empty())
        {
            int cur_city = qu.front();
            qu.pop();
            if (!visited[cur_city])
            {
                visited[cur_city] = true;
                for (pair<int, int>& p : adj[cur_city])
                {
                    res = min(res, p.second);
                    if (!visited[p.first])
                        qu.push(p.first);
                }
            }
        }
        return res;
    }
};