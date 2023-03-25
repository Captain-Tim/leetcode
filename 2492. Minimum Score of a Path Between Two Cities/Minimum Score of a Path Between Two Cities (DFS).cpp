class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        ++n;
        using pii = pair<int, int>;
        vector<vector<pii>> adj(n);
        for (const vector<int>& road : roads)
        {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        vector<bool> visited(n, false);
        int res = INT_MAX;
        helper(adj, visited, 1, res);
        return res;
    }
    void helper(vector<vector<pair<int, int>>>& adj, vector<bool>& visited, int cur_city, int& res)
    {
        visited[cur_city] = true;
        for (const auto& p : adj[cur_city])
        {
            res = min(res, p.second);
            if (visited[p.first] == false)
                helper(adj, visited, p.first, res);
        }
        return;
    }
};
