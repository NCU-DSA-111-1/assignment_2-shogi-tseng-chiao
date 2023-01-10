#include <stdio.h>
#include <stdlib.h>

#include "../inc/file.h"
#include "../inc/movechess.h"
NODE *stacker=NULL;
NODE *tmper=NULL;

//startcoor為現在在的位置startsymb目的地舊的旗子，symb目的地所在地，endsymb目的地更新的旗子
void Push(int startcoor1, int startcoor2, int startsymb, int endcoor1,int endcoor2, int symb){
    tmper=(NODE*)malloc(sizeof(NODE));
    tmper->chesstype[0]=startsymb;
    tmper->chesstype[1]=symb;
    tmper->start[0]=startcoor1;
    tmper->start[1]=startcoor2;
    tmper->end[0]=endcoor1;
    tmper->end[1]=endcoor2;
    tmper->next=stacker;
    stacker=tmper;
}
int Pop(){
    if(stacker!=NULL){
        tmper=stacker;
        chessBoard[tmper->start[0]][tmper->start[1]]=tmper->chesstype[1];
        chessBoard[tmper->end[0]][tmper->end[1]]=tmper->chesstype[0];
        stacker=stacker->next;
        free(tmper);
        return 1;
    }else{
        printf("empty!\n");
        return 0;
    }
}
