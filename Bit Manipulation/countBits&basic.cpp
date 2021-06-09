#include <iostream>
using namespace std;
int unique(int *a,int n){
    int res=0;
    for(int i=0;i<n;i++){
        res=res^a[i];
    }
    return res;
}
void oddEven(int n){
    if(n&1){
        cout<<"Odd";
    }
    else{
        cout<<"Even";
    }
    cout<<endl;
}
int countBits(int n){
    int cnt=0;
    while(n>0){
        cnt+=(n&1);
        n=n>>1;
    }
    return cnt;
}
int countBitseff(int n){
    
    int cnt=0;
    while(n>0){
        cnt++;
        n=n &  (n-1);
    }
    return cnt;
}
int main() {
	int a[]={1,2,3,2,1};
	int n=sizeof(a)/sizeof(int);
//	cout<<unique(a,n)<<endl;
 //   oddEven(10);
 //Min. no. of bits that i need to convert a into b (XOR)
 //and calculate no. of set bits
    cout<<countBitseff(14); 
	return 0;
}
