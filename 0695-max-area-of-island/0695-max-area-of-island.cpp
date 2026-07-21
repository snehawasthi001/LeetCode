class Solution {
public:
int n , m;
int count =0;
void dfs(int i,int j,vector<vector<int>> &grid,vector<vector<bool>>&vis){
    if(i<0||i>=n || j<0 || j>=m || grid[i][j]==0 || vis[i][j]){
        return;
    }
    vis[i][j] = true;
    count++;
    dfs(i-1,j,grid,vis);
    dfs(i,j+1,grid,vis);
    dfs(i+1,j,grid,vis);
    dfs(i,j-1,grid,vis);

}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int maxArea = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    count = 0;
                    dfs(i,j,grid,vis);
                    maxArea = max(maxArea,count);
                }

            }
        }
        return maxArea;
        
    }
};