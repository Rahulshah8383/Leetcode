/*
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size()-1;

        while(start<end){
            int mid = start + (end - start)/2;

            if(arr[mid]<arr[mid+1]){
                start = mid + 1;
            }
            else{
                end = mid;
            }
        }

        return start;
    }
};
*/

// using map --------------------------------------------------------------------------------------------------------------------------------------------------------------------------

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        map<int, int> m;

        for (int i = 0; i < arr.size(); i++) {
            m[arr[i]] = i;
        }

        // map<int, int>::iterator it = m.begin();
        // while (it != m.end()) {
        //     cout << it->first << " " << it->second <<endl;
        //     ++it;
        // }

        std::map<int, int>::reverse_iterator rit = m.rbegin();
        // if (rit != m.rend()) {
        //     cout << "Last element: " << rit->first << " " << rit->second <<endl;
        // } else {
        //     std::cout << "The map is empty." << std::endl;
        // }

        cout<<endl;
        return rit->second;
    }
};
