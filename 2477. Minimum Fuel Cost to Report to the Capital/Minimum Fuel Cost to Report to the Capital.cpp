class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int, vector<int>> adj_list;
        for (auto& vec : roads)
        {
            adj_list[vec[1]].push_back(vec[0]);
            adj_list[vec[0]].push_back(vec[1]);
        }
        long long fuel = 0;
        dfs(adj_list, seats, 0, -1, fuel);
        return fuel;
    }
    int dfs(unordered_map<int, vector<int>>& adj_list, int seats, int cur_node, int parent_node, long long& fuel)
    {
        int passenger = 0;
        for (const int& i : adj_list[cur_node])
        {
            if (i != parent_node)
            {
                int p = dfs(adj_list, seats, i, cur_node, fuel);
                passenger += p;
                fuel += ceil((double) p / seats);
            }
        }
        return 1 + passenger;
    }
};