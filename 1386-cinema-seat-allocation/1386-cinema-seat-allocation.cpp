class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>> st;
        for(auto &x: reservedSeats){
            int row = x[0];
            int seat = x[1];
            st[row].insert(seat); //st[row].insert(seat)
        }
        int res = (n-st.size())*2;
        for(auto &[row, seats]: st){
            auto available = [&](int seat){
                return seats.find(seat)==seats.end();
            };
            bool groupA = available(2)&&available(3)&&available(4)&&available(5);
            bool groupB = available(4)&&available(5)&&available(6)&&available(7);
            bool groupC = available(6)&&available(7)&&available(8)&&available(9);
            if(groupA&&groupC){
                res+=2;
            }
            else if(groupA || groupB || groupC){
                res+=1;
            }
        }
        return res;
    }
};