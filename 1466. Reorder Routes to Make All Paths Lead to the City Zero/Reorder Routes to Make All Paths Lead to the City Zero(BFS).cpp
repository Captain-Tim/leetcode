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
        vector<bool> visited(n, false);
        queue<int> qu;
        qu.push(0);
        visited[0] = true;
        int res = 0;
        while (!qu.empty())
        {
            int cur_node = qu.front();
            qu.pop();
            for (auto& [child, sign] : adj[cur_node])
            {
                if (!visited[child])
                {
                    qu.push(child);
                    res += sign;
                    visited[child] = true;
                }
            }
        }
        return res;
    }
};