class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        const int can_pass = 1;
        const int cannot_pass = 0;
        vector<vector<pair<int, int>>> adj(n);
        for (vector<int>& conn : connections)
        {
            adj[conn[0]].push_back({conn[1], can_pass});
            adj[conn[1]].push_back({conn[0], cannot_pass});
        }
        int res = 0;
        dfs(adj, -1, 0, res);
        return res;
    }
    void dfs(vector<vector<pair<int, int>>>& adj, int parent, int cur, int& res)
    {
        for (auto& [child, sign] : adj[cur])
        {
            if (child != parent)
            {
                res += sign;
                dfs(adj, cur, child, res);
            }
        }
    }
};