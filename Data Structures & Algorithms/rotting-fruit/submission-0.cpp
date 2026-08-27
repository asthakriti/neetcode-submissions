class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        int fresh = 0;

        // 1. Put all rotten oranges into queue
        //    and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j});
                }

                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        int minutes = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // 2. Multi-source BFS
        while (!q.empty() && fresh > 0) {

            int size = q.size();

            // Process oranges that were rotten
            // at the START of this minute
            for (int i = 0; i < size; i++) {

                auto [row, col] = q.front();
                q.pop();

                for (int j = 0; j < 4; j++) {

                    int nr = row + dr[j];
                    int nc = col + dc[j];

                    if (nr >= 0 && nr < n &&
                        nc >= 0 && nc < m &&
                        grid[nr][nc] == 1) {

                        // Fresh orange becomes rotten
                        grid[nr][nc] = 2;

                        fresh--;

                        q.push({nr, nc});
                    }
                }
            }

            // One BFS level = one minute
            minutes++;
        }

        // 3. If fresh oranges are still left,
        //    they can never become rotten
        if (fresh > 0) {
            return -1;
        }

        return minutes; 
    }
};
