#pragma GCC optimize("O3, unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
static const bool __io_boost = [](){
    cin.tie(nullptr); cout.tie(nullptr);
    return ios_base::sync_with_stdio(false);      
}();

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int cnt = 0;
        priority_queue<int> pq;
        for(int i = 0; i < heights.size()-1; i++){
            if(heights[i+1] > heights[i]){
                bricks -= heights[i+1]-heights[i];
                pq.push(heights[i+1]-heights[i]);
            }
            if(bricks < 0 && ladders){
                ladders--;
                if(!pq.empty()){
                    bricks += pq.top();
                    pq.pop();
                }
                else
                    return i; 
            }
            if(bricks < 0){
                return i;
            }
        }
        return heights.size()-1;
    }
};