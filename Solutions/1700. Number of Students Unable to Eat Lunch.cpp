class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();

        int count[2] = {0};
        // count[0] = number of student liking 0 sandwich
        // count[1] = number of student liking 1 sandwich

        for(int &stu : students){
            count[stu]++;
        }

        for(int i=0;i<n;i++){
            int sand = sandwiches[i];

            if(count[sand] == 0)
                return n-i;

            count[sand]--;
        }

        return 0;
    }
};
