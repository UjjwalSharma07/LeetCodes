class MedianFinder {
private:
    priority_queue<double>maxheap;
    priority_queue<double,vector<double>,greater<double> >minheap;
    double median = 0.00;
public:
    
    int signum(int a,int b){
    if(a == b){
        return 0;
    }
    else if(a>b){
        return 1;
    }
    else{
        return -1;
    }
}
void Median(int element,priority_queue<double>&maxi,priority_queue<double,
            vector<double>,greater<double> >&mini,double& median){
    switch(signum(maxi.size(),mini.size())){
        case 0: if(element > median){
                    mini.push(element);
                    median = mini.top();
                }
                else{
                    maxi.push(element);
                    median = maxi.top();
                }
                break;
        case 1: if(element > median){
                    mini.push(element);
                    median = (mini.top()+maxi.top())/2;
                }
                else{
                    mini.push(maxi.top());
                    maxi.pop();
                    maxi.push(element);
                    median = (mini.top()+maxi.top())/2;
                }
                break;
        case -1:  if(element > median){
                    maxi.push(mini.top());
                    mini.pop();
                    mini.push(element);
                    median = (mini.top()+maxi.top())/2;
                  }
                  else{
                      maxi.push(element);
                      median = (mini.top()+maxi.top())/2;
                  }
                  break;
    }
}
    MedianFinder() {
       
    }
    
    void addNum(int num) {
        
        Median(num,maxheap,minheap,median);
        
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */