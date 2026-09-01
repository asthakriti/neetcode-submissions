/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {

        if(node == nullptr){
            return nullptr;
        }

        
        queue<Node*>q;

        unordered_map<Node*,Node*> mp;
        //original_node = clone_node

        //create starting node 
        mp[node] = new Node(node->val);
        q.push(node);


        while(!q.empty()){
            //take out the node and  explore the neigh

            //step01: take out
            auto cur = q.front();
            q.pop();

            //step02 : traverse the neigh
                //if neigh not created then create and link 
                //if created then only link 
                //LINK = Original--->clone

                for(auto neigh : cur->neighbors){
                    if(mp.find(neigh) == mp.end()){
                        mp[neigh] = new Node(neigh->val);                        
                        q.push(neigh);//pushing original node so that i can traverse
                    }

                    //Link
                    mp[cur]->neighbors.push_back(mp[neigh]);
                }
        }

        return mp[node];

        
    }
};