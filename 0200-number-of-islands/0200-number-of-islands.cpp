class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&& !vis[i][j]){
                    count = count+1;
                    q.push({i,j});
                    vis[i][j]=true;
                    while(q.size()>0){
                        int i = q.front().first;
                        int j = q.front().second;
                        q.pop();
                        if(i-1>=0&&grid[i-1][j]=='1'&&!vis[i-1][j]){
                            q.push({i-1,j});
                            vis[i-1][j]=true;
                        }
                        if(j+1<m&&grid[i][j+1]=='1'&&!vis[i][j+1]){
                            q.push({i,j+1});
                            vis[i][j+1]=true;
                        }
                        if(i+1<n&&grid[i+1][j]=='1'&&!vis[i+1][j]){
                            q.push({i+1,j});
                            vis[i+1][j]=true;
                        }
                        if(j-1>=0&&grid[i][j-1]=='1'&&!vis[i][j-1]){
                            q.push({i,j-1});
                            vis[i][j-1]=true;
                        }
                    }
                }
            }
        }
        return count;
    }
};