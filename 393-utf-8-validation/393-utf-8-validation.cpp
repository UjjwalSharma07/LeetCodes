class Solution {
public:
    bool validUtf8(vector<int>& data) {
      
    int rbytes = 0;       
    for (auto ele : data){    
     
      if (rbytes==0){ 
	  
        if ((ele >> 5) == 0b110) 
          rbytes = 1; 
		
        else if ((ele >> 4) == 0b1110)
          rbytes = 2; 
		
        else if ((ele >> 3) == 0b11110)
          rbytes = 3; 
	
        else if ((ele >> 7))
          return false; 
      }
      else{
	
        if ((ele >> 6) != 0b10)
          return false; 
        rbytes--;        
      }
    }
    return (rbytes == 0); 
  
    }
};