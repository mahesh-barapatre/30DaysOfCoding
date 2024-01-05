class Solution {
public:
    int n, m;
    vector<int> a{0, 1, 0, -1};
    vector<int> b{1, 0, -1, 0};

    bool possible(int r, int c){
        if(r < 0 || r >= n || c < 0 || c >= m) return false;
        return true;
    }

    void solve(queue<pair<int, int>> &q, vector<vector<int>>& mat){
        while(!q.empty()){
            auto top = q.front(); q.pop();
            int r = top.first, c = top.second;

            for(int i=0; i<4; i++){
                int nrow = r + a[i];
                int ncol = c + b[i];

                if(possible(nrow, ncol) && mat[nrow][ncol] > mat[r][c] + 1){
                    mat[nrow][ncol] = mat[r][c] + 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        n = mat.size(), m = mat[0].size();
        queue<pair<int, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0) q.push({i, j});
                else mat[i][j] = INT_MAX;
            }
        }

        solve(q, mat);
        return mat;
    }
};