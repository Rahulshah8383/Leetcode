class Solution {
public:
    /*
    // Time Limit Exceeded : low = 15753396, high = 106864044
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        for(int i=low;i<=high;i++){
            int digit = i%10;
            int temp = i/10;
            bool flag = true;

            while(temp){
                if((temp%10)+1 == digit){
                    digit = temp%10;
                    temp = temp/10;
                } 
                else{
                    flag = false;
                    break;
                }
            }

            if(flag){
                ans.push_back(i);
            }
        }

        return ans;
    }
    */

    // vector<int> Sequence{12, 23, 34, 45, 56, 67, 78, 89, 123, 234, 345, 456, 567, 678, 789, 1234, 2345, 3456, 4567, 5678, 6789, 12345, 23456, 34567, 45678, 56789, 123456, 234567, 345678, 456789, 1234567, 2345678, 3456789, 12345678, 23456789, 123456789};

    // vector<int> sequentialDigits(int low, int high){
    //     vector<int> ans;

    //     for(int i=0;i<Sequence.size();i++){
    //         if(Sequence[i] >= low && Sequence[i] <= high){
    //             ans.push_back(Sequence[i]);
    //         }
    //     }

    //     return ans;
    // }

    vector<int> ans;

    void Helper(int low, int high, int i, int num){
        if(num >= low && num <= high){
            ans.push_back(num);
        }

        if(num > high || i > 9){
            return;
        }

        Helper(low, high, i+1, num*10+i);
    }

    vector<int> sequentialDigits(int low, int high){
        for(int i=1;i<=9;i++){
            Helper(low, high, i, 0);
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};
