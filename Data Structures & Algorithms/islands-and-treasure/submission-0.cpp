class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int MAX = numeric_limits<int>::max();
        queue<pair<int, int>> q;
        int r = grid.size();
        int c = grid[0].size();
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        int dist = 0;
        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};
        while (!q.empty()) {
            dist++;
            int level_size = q.size();
            for (int i = 0; i < level_size; ++i) {
                pair<int, int> curr = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int x1 = curr.first + x[i];
                    int y1 = curr.second + y[i];
                    if (x1 >= 0 && x1 < grid.size() 
                        && y1 >= 0 && y1 < grid[0].size()
                        && grid[x1][y1] == MAX) {
                            grid[x1][y1] = dist;
                            q.push({x1, y1});
                    }
                }
            }
        }
    }
};
