class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int m=0;
        //m is the maximum element in an array piles
        for(int i=0;i<piles.size();i++){
            if(m<piles[i]){
                m=piles[i];
            }
        }
        long long s=1;
        long long e=m;
        long long ans;
        while(s<=e){
            long long mid=(s+e)/2;
            long long totalH=count(piles,mid);
            if(totalH <= h){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
        
    }
    //this function find the total number of hours 
    long long count(vector<int>& v,int hourly){
        long long hour=0;
        for(int i=0;i<v.size();i++){
            hour=hour+ceil((double) v[i]/ (double)hourly);
        }
        return hour;
    }
    
};
