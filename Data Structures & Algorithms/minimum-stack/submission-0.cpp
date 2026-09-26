class MinStack {
public:
 stack<pair<int,int>> st;
    MinStack() {
       
    }
    
    void push(int val) {

        if(st.size() == 0){
            st.push({val,val});
        }

        else{
        if(val<st.top().second){
            st.push({val,val});
        }
        else{st.push({val,st.top().second});}}

    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
        }
        
    }
    
    int top() {
        if(!st.empty()){
        return st.top().first;
        }
        return 0;
    }
    
    int getMin() {
        if(!st.empty()){
        return st.top().second;
        }

        return 0;
    }
};
