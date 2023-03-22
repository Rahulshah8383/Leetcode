class MyCircularDeque {
public:
    stack<int> s;
    int size;

    MyCircularDeque(int k) {
        size = k;
    }
    
    bool insertFront(int value) {
        if(s.size() < size){
            s.push(value);
            return true;
        }
        else{
            return false;
        }
    }
    
    bool insertLast(int value) {
        if(s.size() < size){
            stack<int> temp;
            while(!s.empty()){
                temp.push(s.top());
                s.pop();
            }

            s.push(value);
            
            while(!temp.empty()){
                s.push(temp.top());
                temp.pop();
            }
            return true;
        }
        else{
            return false;
        }
    }
    
    bool deleteFront() {
        if(s.size()>0){
            s.pop();
            return true;
        }
        else{
            return false;
        }
    }
    
    bool deleteLast() {
        if(s.size()>0){
            stack<int> temp;
            while(!s.empty()){
                temp.push(s.top());
                s.pop();
            }

            temp.pop();
            
            while(!temp.empty()){
                s.push(temp.top());
                temp.pop();
            }
            return true;
        }
        else{
            return false;
        }
    }
    
    int getFront() {
        if(s.size()>0){
            return s.top();
        }
        else{
            return -1;
        }
    }
    
    int getRear() {
        if(s.size()>0){
            stack<int> temp;
            while(!s.empty()){
                temp.push(s.top());
                s.pop();
            }

            int lastelement = temp.top();
            
            while(!temp.empty()){
                s.push(temp.top());
                temp.pop();
            }
            
            return lastelement;
        }

        else{
            return -1;
        }
    }
    
    bool isEmpty() {
        if(s.empty()){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull() {
        if(s.size() == size){
            return true;
        }
        else{
            return false;
        }
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
