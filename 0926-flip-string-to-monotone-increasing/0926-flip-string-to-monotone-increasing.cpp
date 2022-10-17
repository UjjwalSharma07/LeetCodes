class Solution {
public:
    int countFlip(string s,int counterFlip,int countone){
        for(auto ch:s){
            if(ch == '1')
                countone++;
            else
                counterFlip++;
            counterFlip = min(counterFlip,countone);
        }
        return counterFlip;
    }
    int minFlipsMonoIncr(string s) {
        int counterFlip =0;
        int countone= 0;
        return countFlip(s,counterFlip,countone);
    }
};