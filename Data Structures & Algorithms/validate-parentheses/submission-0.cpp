class Solution {
public:
    bool isValid(string s) {
        int n=s.size();

        stack<char> st;

        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }

            //edge condition->()}
            //push,pop,stack empty before the completion of the string

            

            else{

                if(st.empty()){
                return false;}
            

                char top_char=st.top();

                //({}]-->
                //koi v closing char rhe ye puri condition nhi hai
                //condition ye hai ki 
                //opening and closing dono same rhe.
                //agr "(" ye hai stack me to "}","]" to ye nhi ho
                //it should be ")"

                if(s[i]==')' && top_char=='(' ||
                   s[i]=='}' && top_char=='{' ||
                   s[i]==']' && top_char=='['){st.pop();}

                else{return false;}

                
            }
        }

        //edge condition-->({[]

        // if(st.empty()){
        //     return true;
        // }
        // else{return false;}

                    //OR

                    return st.empty();
    }
};
