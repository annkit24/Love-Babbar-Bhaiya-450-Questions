#include <iostream>
using namespace std;
int partition(int *a,int s,int e){
    
    int pivot=a[e];
    int j=s-1;
    int i=s;
    for(;i<e;i++){
        if(a[i]<=pivot){
            j++;
            swap(a[j],a[i]);
        }
    }
    swap(a[j+1],a[e]);
    return j+1;
    
}

void quickSort(int *a,int s,int e){
    
    if(s>=e){
        return;
    }
    
    int p=partition(a,s,e);
    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
    
}
 
int main() {
	int a[]={4,2,6,1,3};
	int n=sizeof(a)/sizeof(int);
	quickSort(a,0,n-1);
	for(int i=0;i<n;i++){
	    cout<<a[i]<<" ";
	}
	return 0;
}
