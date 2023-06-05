class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int pts=coordinates.size();
        int x_dif=(coordinates[1][0]-coordinates[0][0]);
        int y_dif=(coordinates[1][1]-coordinates[0][1]);
        int curr_x, curr_y;
        for(int i=2;i<pts;i++)
        {
            curr_x=(coordinates[i][0]-coordinates[i-1][0]);
            curr_y=(coordinates[i][1]-coordinates[i-1][1]);
            if(y_dif*curr_x != x_dif*curr_y) return false;
        }
        return true;
    }
};