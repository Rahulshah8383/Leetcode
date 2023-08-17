class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        if(arr.size()<3) 
            return false;
        
        else{
            int sum=0;
            for(int i=0; i<arr.size(); i++){
                sum+=arr[i];
            }
            if(sum%3==0){
                int cnt=0, sum1=0;
                for(int i=0; i<arr.size(); i++)
                {
                    sum1+=arr[i];
                    if(sum1==sum/3){
                        cnt++;
                        sum1=0;
                    }
                }
                if(cnt>=3) 
                    return true;
                else 
                    return false;
            }
            else 
                return false;
        }
    }
};
