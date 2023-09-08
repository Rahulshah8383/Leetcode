class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp(1, 1);
        ans.push_back(temp);

        if(numRows == 1){
            return ans;
        }

        for(int i=2;i<=numRows;i++){
            temp.push_back(0);
            vector<int> sub;
            while(!temp.empty()){
                int sum = temp.back();
                temp.pop_back();
                if(!temp.empty()) 
                    sum = sum + temp.back();
                sub.push_back(sum);
            }
            ans.push_back(sub);
            temp = sub;
        }
        
        return ans
    }
};
