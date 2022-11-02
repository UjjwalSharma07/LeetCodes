class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>seen;
        queue<string>q;
        
        q.push(start);
        seen.insert(start);
        
        int steps=0;
        
        while(!q.empty()){
            int size = q.size();
            
            for(int i=0; i<size; i++){
                auto topnode = q.front();
                q.pop();
                
                if(topnode == end)
                    return steps;
                
                for(auto j:"ACGT"){
                    for(int k=0; k<topnode.size(); k++){
                        string temp = topnode;
                        temp[k] = j;
                        
                        if( !seen.count(temp) && find(bank.begin(),bank.end(),temp) != bank.end() ){
                            q.push(temp);
                            seen.insert(temp);
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};