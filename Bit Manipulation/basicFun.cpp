//extract ith Bit
#include <iostream>
using namespace std;
//xor swapping a=a^b
//b=a^b
//a=a^b


int countBitseff(int n,int i){
    
    int cnt=0;
    while(n>0){
        cnt++;
        n=n &  (n-1);
    }
    return cnt;
}
int getIthBit(int n,int i){
    return (n & (1<<i))!=0?1:0;
}
//change ith bit to 1
void setBit(int &n,int i){
    
    int mask=(1<<i);
    n=n|mask;
    cout<<n<<endl;
    
}
//clear ith bit mask and not
void clearBit(int &n,int i){
    int mask=~(1<<i);
    n=n&mask;
    cout<<n<<endl;
}
int main() {
	
    int n,i;
    cin>>n>>i;
    //cout<<getIthBit(n,i)<<endl;
     clearBit(n,i);
	return 0;
}
