#ifndef __MOVECHESS_H__
#define __MOVECHESS_H__
#include "../inc/file.h"
struct node{
    int chesstype[2];//被吃掉的旗子
    int start[2];//刪除項的x,y座標
    int end[2];//剩下的x,y座標
    struct node*next,*prev;
}; 
typedef struct node NODE;

extern int ax,ay,by;
extern char bx;
extern int i;

#define max 10
    enum elementType {Bking, Bcar, Bgold,Bhorse,Bsilver,Bcorner,Bfly,Bstep,blank,Rking, Rcar, Rgold,Rhorse,Rsilver,Rcorner,Rfly,Rstep};
    static const char *chess[]={"\033[34m王\033[m","\033[34m香\033[m","\033[34m金\033[m","\033[34m桂\033[m","\033[34m銀\033[m","\033[34m角\033[m","\033[34m飛\033[m","\033[34m步\033[m","  ","\033[31m王\033[m","\033[31m香\033[m","\033[31m金\033[m","\033[31m桂\033[m","\033[31m銀\033[m","\033[31m角\033[m","\033[31m飛\033[m","\033[31m步\033[m"};
    extern int chessBoard[max][max]; //存enum數字

void open_file();

void opponent_move_chess();
void me_move_chess();
void me_regret();//悔棋未定義
void opponent_regret();
void print_chessBoard();//x,y座標都是先輸入y再輸入x move to file.h 12/14

void Rstepfunc(int w,int x,int y,int z);
void Rcarfunc(int w,int x,int y,int z);
void Rhorsefunc(int w,int x,int y,int z);
void Rsilverfunc(int w,int x,int y,int z);
void Rgoldfunc(int w,int x,int y,int z);
void Rcornerfunc(int w,int x,int y,int z);
void Rflyfunc(int w,int x,int y,int z);
void Rkingfunc(int w,int x,int y,int z);

void Bstepfunc(int w,int x,int y,int z);
void Bcarfunc(int w,int x,int y,int z);
void Bhorsefunc(int w,int x,int y,int z);
void Bsilverfunc(int w,int x,int y,int z);
void Bgoldfunc(int w,int x,int y,int z);
void Bcornerfunc(int w,int x,int y,int z);
void Bflyfunc(int w,int x,int y,int z);
void Bkingfunc(int w,int x,int y,int z);

#endif
