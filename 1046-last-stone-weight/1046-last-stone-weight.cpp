class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1){
            sort(stones.begin(),stones.end());
            for(int i=stones.size()-1;i>0;i-=2){
                if(stones[i]==stones[i-1]){
                    stones[i]=-1;
                    stones[i-1]=-1;
                }else if(stones[i]>stones[i-1]){
                    stones[i]=stones[i]-stones[i-1];
                    stones[i-1]=-1;
                }else{
                    stones[i-1]=stones[i-1]-stones[i];
                    stones[i]=-1;
                }
                break;
            }
            sort(stones.begin(),stones.end());
            while(!stones.empty() && stones[0]==-1){
                stones.erase(stones.begin());
            }
        }
        return stones.empty() ? 0 : stones[0];
    }
};