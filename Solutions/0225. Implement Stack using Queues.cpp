/* 1. making push and top function costly 
class MyStack {
public:
    queue<int> q1;
    queue<int> q2; 

    MyStack() {  
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
       int n = q1.size();
       while(n>1){
           q2.push(q1.front());
           q1.pop();
           n--;
       } 
       int x = q1.front();
       q1.pop();

       while(!q2.empty()){
           q1.push(q2.front());
           q2.pop();
       }
       return x;
    }
    
    int top() {
        int n = q1.size();
       while(n>1){
           q2.push(q1.front());
           q1.pop();
           n--;
       } 
       int x = q1.front();
       q1.pop();

       while(!q2.empty()){
           q1.push(q2.front());
           q2.pop();
       }
       q1.push(x);
       return x;
    }
    
    bool empty() {
        return q1.size()==0;
    }
};
*/

/* 2, making push function costly
class MyStack {
public:
    queue<int> q1;
    queue<int> q2; 

    MyStack() {  
    }
    
    void push(int x) {
        q2.push(x);

        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }
    
    int pop() {
        if(q1.empty()){
            return 0;
        }
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    int top() {
        if(q1.empty()){
            return 0;
        }
        return q1.front();
    }
    
    bool empty() {
        return q1.size()==0;
    }
};
*/

class MyStack {
public:
    queue<int> q;

    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);

        int n = q.size();

        while(n>1){
            int e = q.front();
            q.pop();
            q.push(e);
            n--;
        }

    }
    
    int pop() {
        if(q.empty()){
            return 0;
        }
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        if(q.empty()){
            return 0;
        }
        return q.front();
    }
    
    bool empty() {
        return q.size()==0;
    }
};




/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
