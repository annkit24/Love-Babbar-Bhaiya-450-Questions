#include <iostream>
using namespace std;
#define n 4

void printarr(char board[n][n]){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << " " << board[i][j] << " ";
        printf("\n");
    }
    
    cout<<endl;
}

bool isSafe(char arr[n][n],int row,int col){
    
    for(int i=row-1;i>=0;i--){
        
        if(arr[i][col]=='Q'){
            return false;
        }
    }
    
     for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
        
        if(arr[i][j]=='Q'){
            return false;
        }
    }
    
    for(int i=row-1,j=col+1;i>=0&&j<n;i--,j++){
        
        if(arr[i][j]=='Q'){
            return false;
        }
    }
    
    return true;
}
void nQueen(char arr[n][n],int i){
    
    if(i==n){
        printarr(arr);
        return;
    }
    
    for (int j = 0; j <n; j++) {
      if(isSafe(arr,i,j)){    
        arr[i][j]='Q';
        nQueen(arr,i+1);
        arr[i][j]='x';
      }
    }
}

// void printarr(char board[n][n]){
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++)
//             cout << " " << board[i][j] << " ";
//         printf("\n");
//     }
// }
int main() {
	
	char arr[4][4];
	
	for(int i=0;i<n;i++){
	    for(int j=0;j<n;j++){
	        arr[i][j]='x';
	    }
	}
	
	nQueen(arr,0);
	return 0;
}
