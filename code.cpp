class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size() , n = maze[0].size();
        vector<vector<int>> test(m,vector<int>(n,0));
        queue<array<int,3>> q;
        int sr = entrance[0] , sc = entrance[1];
        q.push({sr,sc,0});
        test[sr][sc] = 1;
        int dr[4] = {1,-1,0,0};
        int dc[4] = {0,0,1,-1};
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int r = curr[0] , c = curr[1] , d = curr[2];
            if((r==0 || r==m-1 || c==0 || c==n-1)&&!(r==sr && c==sc)){
                return d;
            }
            for(int k=0;k<4;++k){
                int nr = r + dr[k];
                int nc = c + dc[k];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !test[nr][nc] && maze[nr][nc]=='.'){
                    test[nr][nc] = 1;
                    q.push({nr,nc,d+1});
                }
            }
        }
        return -1;
    }
};
