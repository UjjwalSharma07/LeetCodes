class Solution {
public:
    int getIndex(string &stamp, string &currStr){
        
    for(int i=0;i<=currStr.size()-stamp.size();i++){
            int j=0;
            int index=i;
            bool allMark=true;
        while(j<stamp.size() && index<currStr.size() && (currStr[index]==stamp[j] || currStr[index]=='?')){

                if(currStr[index]!='?'){
                    allMark=false;
                }
                index++;
                j++;
            }
            if(j==stamp.size() && allMark==false){
                return i;
            }
        }
        return -1;
    }
    
    void update(string &stamp, string &curr, int index){
        for(int i=0;i<stamp.size();i++){
            curr[i+index]='?';
        }
    }
    
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        int n=target.size();
        string curr=target;
        string T(n,'?');
        while(curr!=T){
            int StampIndex=getIndex(stamp,curr);
            if(StampIndex==-1){  //NOT FOUND
                return {};
            }
            update(stamp,curr,StampIndex);
            res.push_back(StampIndex);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};