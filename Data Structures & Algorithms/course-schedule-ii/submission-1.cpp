class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        vector<int> ans;

        for(auto it : prerequisites){
            //it = {u, v}
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> indegree(numCourses, 0);
        //Find indegree
        for(auto it : adj){
            //it = {list of array}
            for(auto node : it){
                indegree[node]++;
            }
        }

        //push indegree = 0 in queue

        queue<int> q;
          for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){

            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto it : adj[node]){
                indegree[it]--;

                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(ans.size() == numCourses){
            return ans;
        }

        else{
            return {};
        }

    }
};
