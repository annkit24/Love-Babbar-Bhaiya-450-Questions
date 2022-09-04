public class NQueens {

    public static void nQueens(char arr[][],int i) {
        
        if(i==arr.length){
            printBiard(arr);
            return;
        }

        for (int j = 0; j < arr.length; j++) {
            
            if(isSafe(arr,i,j)){

                arr[i][j]='Q';
                nQueens(arr, i+1);
                arr[i][j]='x';
            }
        }
    }

    private static boolean isSafe(char[][] arr, int row, int col) {
        
        //for left diagonal
        for(int i=row-1,j=col-1;i>=0&&j>=0;i--,j--){
            if(arr[i][j]=='Q'){
                return false;
            }

        }

        //for colum

        for (int i =row-1; i >=0; i--) {
         
            if(arr[i][col]=='Q'){
                return false;
            }
        }


        //for right diagonal
        for(int i=row-1,j=col+1;i>=0&&j<arr.length;i--,j++){
            if(arr[i][j]=='Q'){
                return false;
            }

        }

        
        
        return true;
    }

    public static void printBiard(char board[][]) {
        
        System.out.println("------Board-------");
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j <board.length; j++) {
                System.out.print(board[i][j]+" ");
            }
            System.out.println();
        }
    }
    public static void main(String args[]) {
        
        int n=4;
        char array[][]=new char[n][n];

        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array.length; j++) {
                array[i][j]='x';
            }
        }

        nQueens(array,0);
        

       
      

    }
}
