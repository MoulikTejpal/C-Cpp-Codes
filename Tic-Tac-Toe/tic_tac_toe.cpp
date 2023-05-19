#include <stdio.h>

void read_Board(int ttt[][3]) {
    int i,j;
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){ scanf("%d",&ttt[i][j]);}
    }
}

int count_EmptyCell(int ttt[][3]){
    int i,j,count=0;
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){
            if (ttt[i][j]== -1) {count += 1;}
        }
    }
    return count;
}

int check_Rowwise(int ttt[][3],int n){
    int i,j,sum,r=0;
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){ sum = sum + ttt[i][j];}
        if (sum==3*n) {
            printf("%d",sum);
            printf("Player%d wins",n);
            r=1;
        }
    }
    return r;
}

int check_Colwise(int ttt[][3],int n){
    int i,j,sum,r=0;
    for (i=0;i<3;i++){
        for (j=0;j<3;j++){ sum = sum + ttt[j][i];}
        if (sum==3*n) {
            printf("%d",sum);
            printf("Player%d wins",n);
            r=1;
        }
    }
    return r;
}

int check_Diagonalwise(int ttt[][3],int n){
    int i,sum1=0,sum2=0,r=0;
    for (i=0;i<3;i++){ sum1 = sum1 + ttt[i][i];
    sum2=sum2+ttt[2-i][i];
    }
        if (sum1==3*n || sum2==3*n) {
            //printf("\n%d %d",sum1,sum2);
            printf("Player%d wins",n);
            r=1;
        }
        return r;
    }

int main() {
    int board[3][3];
    
    read_Board(board);
    
    int Emptycount;
    Emptycount=count_EmptyCell(board);
    
    if (Emptycount>0) {printf("Intermediate");}
    
    else {
        int arr[5];
        arr[0]=check_Rowwise(board,1);
        arr[1]=check_Rowwise(board,2);
        arr[2]=check_Colwise(board,1);
        arr[3]=check_Colwise(board,2);
        arr[4]=check_Diagonalwise(board,1);
        arr[5]=check_Diagonalwise(board,2);
        if (arr[0]==0&&arr[1]==0&&arr[2]==0&&arr[3]==0&&arr[4]==0){printf("Draw");}
    }
}
