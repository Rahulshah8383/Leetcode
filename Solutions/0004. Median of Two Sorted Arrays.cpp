class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        int size1 = nums1.size();
        int size2 = nums2.size();
        int size = size1+size2;
        int mid = size/2;
        int ans[size];
        int i=0, j=0, k=0;

        while(i<size1 && j<size2){
            if(nums1[i] < nums2[j]){
                ans[k] = nums1[i];
                k++; i++;
            }
            else{
                ans[k]=nums2[j];
                k++; j++;
            }
        }

        while(i<size1){
            ans[k]=nums1[i];
            k++; i++;
        }

        while(j<size2){
            ans[k]=nums2[j];
            k++; j++;
        }

        double median;
        if(size%2==0){
            median = ans[mid] + ans[mid-1];
            median /= 2;
        }
        else{
            median = ans[mid];
        }

        return median;
        */

        vector<double> v;
        
        for(int i=0;i<nums1.size();i++){
            v.push_back(nums1[i]);
        }
        
        for(int i=0;i<nums2.size();i++){
            v.push_back(nums2[i]);
        }
        
        sort(v.begin(), v.end());
		int n = v.size();
		    
		if(n%2){
            double ans = v[n/2];
            return ans;
		}
	    double ans = (v[n/2] + v[(n/2)-1])/2;
        return ans;
    }
};
