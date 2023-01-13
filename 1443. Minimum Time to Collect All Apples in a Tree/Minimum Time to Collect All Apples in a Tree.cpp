class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (const vector<int>& vec : edges)
        {
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }
        return dfs(adj, hasApple, -1, 0);
    }
    int dfs(vector<vector<int>>& adj, vector<bool>& hasApple, int parent_idx, int cur_idx)
    {
        int total_time = 0;
        for (const int& i : adj[cur_idx])
        {
            if (i == parent_idx)
                continue;
            int child_time = dfs(adj, hasApple, cur_idx, i);
            if (child_time > 0 || hasApple[i])
                total_time += child_time + 2;
        }
        return total_time;
    }
};