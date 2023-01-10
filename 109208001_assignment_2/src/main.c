#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include "../inc/movechess.h"
#include "../inc/file.h"
void initialize_chessBoard();
int i;
int chessBoard[10][10];
int main(){
    open_file();
    initialize_chessBoard();//初使化棋譜
    print_chessBoard();
  do{
    me_move_chess();
    if(i==-1)
        break;
    print_chessBoard();
    opponent_move_chess();
    if(i==-1)
        break;
    print_chessBoard();
  }while(1);
  return 0;
}
void initialize_chessBoard(){
   int i,j;
   for(i=1;i<10;i++){
       for(j=1;j<10;j++){
           chessBoard[i][j]=blank;
       }
   }
   chessBoard[1][9]=chessBoard[1][1]=Rcar;
   chessBoard[1][8]=chessBoard[1][2]=Rhorse;
   chessBoard[1][7]=chessBoard[1][3]=Rsilver;
   chessBoard[1][6]=chessBoard[1][4]=Rgold;
   chessBoard[1][5]=Rking;
   chessBoard[2][8]=Rfly;
   chessBoard[2][2]=Rcorner;
   for(i=9;i>0;i--){
       chessBoard[3][i]=Rstep;
   }
   chessBoard[9][1]=chessBoard[9][9]=Bcar;
   chessBoard[9][2]=chessBoard[9][8]=Bhorse;
   chessBoard[9][3]=chessBoard[9][7]=Bsilver;
   chessBoard[9][4]=chessBoard[9][6]=Bgold;
   chessBoard[9][5]=Bking;
   chessBoard[8][2]=Bfly;
   chessBoard[8][8]=Bcorner;
   for(i=9;i>0;i--){
       chessBoard[7][i]=Bstep;
   }
}