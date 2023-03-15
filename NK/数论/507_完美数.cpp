// 枚举
class Solution {
public:
    bool checkPerfectNumber(int num) {
	    if(num==1) return false;
	    int ans=1;
	    for(int i=2;i<=num/i;i++){
		if(num%i==0){
		// i 是num的因数
			ans+=i;
			if(i*i!=num) ans+=num/i;
		}
	    
	    }
	    return num==ans;

    }
};
