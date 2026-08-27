class Solution {
public:

    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid){
       
       queue<pair<int,int>> q;

       q.push({row, col});
       vis[row][col] = 1;

       int n = grid.size();
       int m = grid[0].size();

       while(!q.empty()){

        int row = q.front().first;
        int col = q.front().second;

        q.pop();

        int nrow[] = {-1, 1, 0, 0};
        int ncol[] = {0, 0, -1, 1};

        for(int i = 0; i < 4; i++){
            
            int delrow = row + nrow[i];
            int delcol = col + ncol[i];

            if(delrow >= 0 && delcol >=0 && delrow < n && delcol < m
                && vis[delrow][delcol] == 0 && grid[delrow][delcol] == '1'){
                    vis[delrow][delcol] = 1;
                    q.push({delrow, delcol});
                }
        }

       }

            //traverse all its(8-side) neighbor
            // for(int delrow=-1;delrow<=1;delrow++){
            //     for(int delcol=-1;delcol<=1;delcol++){
            //         int nrow=row+delrow;
            //         int ncol=col+delcol;
            
            //     if(nrow>=0 && ncol>=0 && 
            //        nrow<n && ncol<m &&
            //        grid[nrow][ncol]=='1' &&
            //        !vis[nrow][ncol]){

            //         vis[nrow][ncol]=1;
            //         q.push({nrow,ncol});
            //         }
            //     }
            // }

            //traverse all 4 side
            //left,right,up,down
           
    }

    void dfs(int row, int col, vector<vector<int>>& vis,
            vector<vector<char>>& grid){

                int n = grid.size();
                int m = grid[0].size();

                vis[row][col] = 1;

                int dr[] = {-1, 1, 0, 0};
                int dc[] = {0, 0, -1, 1};

                for(int i = 0; i < 4; i++){
                    int nr = row + dr[i];
                    int nc = col + dc[i];

                    if(nr < n && nc < m && nr >= 0 && nc >= 0
                        && !vis[nr][nc] && grid[nr][nc] == '1'){
                            dfs(nr, nc, vis, grid);
                        }
                }
            }
        
    

    int numIslands(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int cnt = 0;

        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(grid[row][col] == '1' && !vis[row][col]){
                    cnt++;
                    dfs(row, col, vis, grid);
                }
            }
        }
        
        return cnt;
    }
}; 