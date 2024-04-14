class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        int time = 0;
        
        /*
                    //  Approach 1: Using Queue
                    // O(n*m), O(n)
        
        queue<int> q;

        // Initialize the queue with tickets indices
        for(int i=0;i<n;i++){
            q.push(i);
        }

        // Loop until the queue is empty
        while(!q.empty()){

            // Get the front indeces from the queue
            int front_i = q.front();
            q.pop();

            // Buy a ticket for the front person
            tickets[front_i]--;

            // Increment the time counter for each iteration
            time++;

            // If person k bought all their tickest, return time
            if(front_i == k && tickets[front_i] == 0){
                return time;
            }

            // If person front_i not bought all their tickest
            if(tickets[front_i]){
                q.push(front_i);
            }
        }
        */


        /* 
                // Approach 2: Without Queue
                //  O(n*m), O(1)
        
            while(tickets[k]){
                for(int i=0;i<n;i++){
                    if(tickets[i]){
                        tickets[i]--;
                        time++;

                        if(tickets[k] == 0){
                            return time;
                        }
                    }
                }
            }
        
        */  

        // Approach 3: Using One Pass
        //                 
       

        for(int i = 0; i < n; i++){
            if(i <= k){
                time += min(tickets[k], tickets[i]);
            }
            else{
                time += min(tickets[k]-1, tickets[i]);
            }
        }

        return time;
    }
};
