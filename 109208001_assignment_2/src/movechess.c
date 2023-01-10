#include <stdio.h>
#include <stdlib.h>
#include "../inc/movechess.h"
#include "../inc/file.h"

FILE *new_game;

void open_file(){
    new_game=fopen("shogi.txt","w+");
    fprintf(new_game,"%-8s%-8s%-11s%-6s%-6s%-9s\n","start1","start2","startsymb","end1","end2","endsymb");
}
void print_chessBoard(){
   int i,j;
   for(i=9;i>0;i--){
       printf("%d ", i);
   }
   printf("\n");
   for(i=1;i<10;i++){
       for(j=9;j>=0;j--){         
           if(j!=0)
               printf("%s", chess[chessBoard[i][j]]);
           if(j==0)
               printf("%d",i);
       }
       printf("\n");
  }
}//move to file later12/14
void me_regret(){
    Pop();
    print_chessBoard();
    me_move_chess();
}
void opponent_regret(){
    Pop();
    print_chessBoard();
    opponent_move_chess();
}

void me_move_chess(){
   int a,b,w,x,y,z;
   printf("玩家X(我方)：請輸入想要移動的旗子以及目的地：(yx1,yx2)");
   scanf("%d,%d",&a,&b);
     if(a==0&&b==0){
        me_regret();
        return;
    }
    if(a==-1){
        printf("End\n");
        fclose(new_game);//open new game
        i=-1;
        return;
    }
   w=a/10;
   x=a%10;
   y=b/10;
   z=b%10;
   if(chessBoard[w][x]>=blank){ //move opponents' chess
        printf("sorry!!I can't move!!輸入錯誤！\n");
   }
    if(chessBoard[w][x]==Bstep){//己方的步
       Bstepfunc(w,x,y,z);
    }
    if(chessBoard[w][x]==Bcar){//己方的香車
        Bcarfunc(w,x,y,z);
    }
    if(chessBoard[w][x]==Bhorse){//己方的桂馬
        Bhorsefunc(w,x,y,z);
    }
    if(chessBoard[w][x]==Bsilver){//己方的銀將
        Bsilverfunc(w,x,y,z);
    }
    if(chessBoard[w][x]==Bgold){//己方的金將
        Bgoldfunc(w,x,y,z);
    }
    if(chessBoard[w][x]==Bcorner){//己方的角行
        Bcornerfunc(w,x,y,z);
    }
    if(chessBoard[w][x]==Bfly){//己方的飛車
        Bflyfunc(w,x,y,z);
        
    }
    if(chessBoard[w][x]==Bking){//己方的王將
        Bkingfunc(w,x,y,z);
    }
}
void opponent_move_chess(){
   int a,b,e,f,g,h;
   printf("玩家Y(敵方)：請輸入想要移動的旗子以及目的地：(yx1,yx2)");
   scanf("%d,%d",&a,&b);
    if(a==0&&b==0){
        opponent_regret();
        return;
    }
    if(a==-1){
        printf("End\n");
        fclose(new_game);//open new game
        i=-1;
        return;
    }
   e=a/10;
   f=a%10;
   g=b/10;
   h=b%10;
   if(((-1)<chessBoard[e][f])&(chessBoard[e][f]<Rking)){
        printf("!!sorry!!I can't move!!輸入錯誤！\n");
   }
    if(chessBoard[e][f]==Rstep){//敵方的步
       Rstepfunc(e,f,g,h);
    }
    if(chessBoard[e][f]==Rcar){//敵方的香車
        Rcarfunc(e,f,g,h);
    }
    if(chessBoard[e][f]==Rhorse){//敵方的桂馬
        Rhorsefunc(e,f,g,h);
    }
    if(chessBoard[e][f]==Rsilver){//敵方的銀將
        Rsilverfunc(e,f,g,h);
    }
    if(chessBoard[e][f]==Rgold){//敵方的金將
        Rgoldfunc(e,f,g,h);
    }
    if(chessBoard[e][f]==Rcorner){//敵方的角行
        Rcornerfunc(e,f,g,h);
    }
    if(chessBoard[e][f]==Rfly){//敵方的飛車
        Rflyfunc(e,f,g,h);
    }
    if(chessBoard[e][f]==Rking){//敵方的王將
        Rkingfunc(e,f,g,h);
    }
}
void Rstepfunc(int w,int x,int y,int z){
    if((x==z)&&((y-w)==1)&(chessBoard[y][z]<(Rstep-7))){
       Push(w,x,chessBoard[y][z],y,z,Rstep);
       fprintf(new_game,"%-8d%-8d%-11d%-6d%-6d%-9d\n",w,x,chessBoard[y][z],y,z,Rstep);
       if(chessBoard[y][z]==Bking){
            chessBoard[w][x]=blank;
            chessBoard[y][z]=Rstep;
            print_chessBoard();
            printf("Y贏了！\n");
            i=-1;
        }
       chessBoard[w][x]=blank;
       chessBoard[y][z]=Rstep;
       }
       else
           printf("輸入錯誤！\n");
}
void Bstepfunc(int w,int x,int y,int z){
    if((x==z)&&((y-w)==-1)&(chessBoard[y][z]>Bstep)){
       Push(w,x,chessBoard[y][z],y,z,Bstep);
       fprintf(new_game,"%-8d%-8d%-11d%-6d%-6d%-9d\n",w,x,chessBoard[y][z],y,z,Bstep);
       if(chessBoard[y][z]==Rking){
            chessBoard[w][x]=blank;
            chessBoard[y][z]=Bstep;
            print_chessBoard();
            printf("X贏了！椰以～～\n");
            i=-1;
        }
       chessBoard[w][x]=blank;
       chessBoard[y][z]=Bstep;
       }
       else
           printf("輸入錯誤！\n");
}

void Rcarfunc(int w,int x,int y,int z){
    if((x==z)&&(((y-w)/abs(y-w))==1)&(chessBoard[y][z]<(Rcar-1))){
       Push(w,x,chessBoard[y][z],y,z,Rcar);
       fprintf(new_game,"%-8d%-8d%-11d%-6d%-6d%-9d\n",w,x,chessBoard[y][z],y,z,Rcar);
        if(chessBoard[y][z]==Bking){
            chessBoard[w][x]=blank;
            chessBoard[y][z]=Rcar;
            print_chessBoard();
            printf("Y贏了！\n");
            i=-1;
        }
       chessBoard[w][x]=blank;
       chessBoard[y][z]=Rcar;
       }
       else
           printf("輸入錯誤！\n");
}
void Bcarfunc(int w,int x,int y,int z){
    if((x==z)&&(((y-w)/abs(y-w))==-1)&(chessBoard[y][z]>(Bcar+6))){
       Push(w,x,chessBoard[y][z],y,z,Bcar);
       fprintf(new_game,"%-8d%-8d%-11d%-6d%-6d%-9d\n",w,x,chessBoard[y][z],y,z,Bcar);
       if(chessBoard[y][z]==Rking){
            chessBoard[w][x]=blank;
            chessBoard[y][z]=Bcar;
            print_chessBoard();
            printf("X贏了！椰以～～\n");
            i=-1;
        }
       chessBoard[w][x]=blank;
       chessBoard[y][z]=Bcar;
       }
       else
           printf("輸入錯誤！\n");
}

void Rhorsefunc(int w,int x,int y,int z){
    if(((y-w)==2)&&(abs(x-z)==1)&(chessBoard[y][z]<(Rhorse-3))){
        Push(w,x,chessBoard[y][z],y,z,Rhorse);
        fprintf(new_game,"%-8d%-8d%-11d%-6d%-6d%-9d\n",w,x,chessBoard[y][z],y,z,Rhorse);
        if(chessBoard[y][z]==Bking){
            chessBoard[w][x]=blank;
            chessBoard[y][z]=Rhorse;
            print_chessBoard();
            printf("Y贏了！\n");
            i=-1;
        }       
        chessBoard[w][x]=blank;
        chessBoard[y][z]=Rhorse;
    }
    else
           printf("輸入錯誤！\n");
}
void Bhorsefunc(int w,int x,int y,int z){
    if(((y-w)==-2)&&(abs(x-z)==1)&(chessBoard[y][z]>(Bhorse+4))){
        Push(w,x,chessBoard[y][z],y,z,Bhorse);
        fprintf(new_game,"%-8d%-8d%-11d%-6d%-6d%-9d\n",w,x,chessBoard[y][z],y,z,Bhorse);
        if(chessBoard[y][z]==Rking){
            chessBoard[w][x]=blank;
            chessBoard[y][z]=Bhorse;
            print_chessBoard();
            printf("X贏了！椰以～～\n");
            i=-1;
        }
        chessBoard[w][x]=blank;
        chessBoard[y][z]=Bhorse;
    }
    else
           printf("輸入錯誤！\n");
}
void Rsilverfunc(int w,int x,int y,int z){
    if(((abs(y-w)==1)&&(abs(x-z)==1))|(((y-w)==1)&&(x==z))&(chessBoard[y][z]<(Rsilver-4))){
        Push(w,x,chessBoard[y][z],y,z,Rsilver);
        fprintf(new_game,"%-8d%-8d%-11d%-6d%-6d%-9d\n",w,x,chessBoard[y][z],y,z,Rsilver);
        if(chessBoard[y][z]==Bking){
            chessBoard[w][x]=blank;
            chessBoard[y][z]=Rsilver;
            print_chessBoard();
            printf("Y贏了！\n");
            i=-1;
        } 
        chessBoard[w][x]=blank;
        chessBoard[y][z]=Rsilver;
    }
    else
        printf("輸入錯誤！\n");
}
void Bsilverfunc(int w,int x,int y,int z){
    if(((abs(y-w)==1)&&(abs(x-z)==1))|(((y-w)==-1)&&(x==z))&(chessBoard[y][z]>(Bsilver+3))){
        Push(w,x,chessBoard[y][z],y,z,Bsilver);
        fprintf(new_game,"%-8d%-8d%-11d%-6d%-6d%-9d\n",w,x,chessBoard[y][z],y,z,Bsilver);
        if(chessBoard[y][z]==Rking){
            chessBoard[w][x]=blank;
            chessBoard[y][z]=Bsilver;
            print_chessBoard();
            printf("X贏了！椰以～～\n");
            i=-1;
        }
        chessBoard[w][x]=blank;
        chessBoard[y][z]=Bsilver;
    }
    else
        printf("輸入錯誤！\n");
}

void Rgoldfunc(int w,int x,int y,int z){
    if((((y-w)==1)&&(abs(x-z)==1))|((abs(y-w)==1)&&(x==z))|((y==w)&&(abs(x-z)==1))&(chessBoard[y][z]<(Rgold-2))){
        Push(w,x,chessBoard[y][z],y,z,Rgold);
        fprintf(new_game,"%-8d%-8d%-11d%-6d%-6d%-9d\n",w,x,chessBoard[y][z],y,z,Rgold);
        if(chessBoard[y][z]==Bking){
            chessBoard[w][x]=blank;
            chessBoard[y][z]=Rgold;
            print_chessBoard();
            printf("Y贏了！\n");
            i=-1;
        } 
        chessBoard[w][x]=blank;
        chessBoard[y][z]=Rgold;
    }
    else
        printf("輸入錯誤！\n");
}
void Bgoldfunc(int w,int x,int y,int z){
    if((((y-w)==-1)&&(abs(x-z)==1))|((abs(y-w)==1)&&(x==z))|((y==w)&&(abs(x-z)==1))&(chessBoard[y][z]>(Bgold+5))){
        Push(w,x,chessBoard[y][z],y,z,Bgold);
        fprintf(new_game,"%-8d%-8d%-11d%-6d%-6d%-9d\n",w,x,chessBoard[y][z],y,z,Bgold);
        if(chessBoard[y][z]==Rking){
            chessBoard[w][x]=blank;
            chessBoard[y][z]=Bgold;
            print_chessBoard();
            printf("X贏了！椰以～～\n");
            i=-1;
        }
        chessBoard[w][x]=blank;
        chessBoard[y][z]=Bgold;
    }
    else
        printf("輸入錯誤！\n");
}

void Rcornerfunc(int w,int x,int y,int z){
    if(((abs(y-w)/abs(x-z))==abs(1))&(chessBoard[y][z]<(Rcorner-5))){
        Push(w,x,chessBoard[y][z],y,z,Rcorner);
        fprintf(new_game,"%-8d%-8d%-11d%-6d%-6d%-9d\n",w,x,chessBoard[y][z],y,z,Rcorner);
        if(chessBoard[y][z]==Bking){
            chessBoard[w][x]=blank;
            chessBoard[y][z]=Rcorner;
            print_chessBoard();
            printf("Y贏了！\n");
            i=-1;
        } 
        chessBoard[w][x]=blank;
        chessBoard[y][z]=Rcorner;
    }
    else
        printf("輸入錯誤！\n");
}
void Bcornerfunc(int w,int x,int y,int z){
    if(((abs(y-w)/abs(x-z))==abs(1))&(chessBoard[y][z]>(Bcorner+2))){
        Push(w,x,chessBoard[y][z],y,z,Bcorner);
        fprintf(new_game,"%-8d%-8d%-11d%-6d%-6d%-9d\n",w,x,chessBoard[y][z],y,z,Bcorner);
        if(chessBoard[y][z]==Rking){
            chessBoard[w][x]=blank;
            chessBoard[y][z]=Bcorner;
            print_chessBoard();
            printf("X贏了！椰以～～\n");
            i=-1;
        }
        chessBoard[w][x]=blank;
        chessBoard[y][z]=Bcorner;
    }
    else
        printf("輸入錯誤！\n");
}
void Rflyfunc(int w,int x,int y,int z){
    if((w==y)|(x==z)&(chessBoard[y][z]<(Rfly-6))){
        Push(w,x,chessBoard[y][z],y,z,Rfly);
        fprintf(new_game,"%-8d%-8d%-11d%-6d%-6d%-9d\n",w,x,chessBoard[y][z],y,z,Rfly);
        if(chessBoard[y][z]==Bking){
            chessBoard[w][x]=blank;
            chessBoard[y][z]=Rfly;
            print_chessBoard();
            printf("Y贏了！\n");
            i=-1;
        }
        chessBoard[w][x]=blank;
        chessBoard[y][z]=Rfly;
    }
    else
        printf("輸入錯誤！\n");
}
void Bflyfunc(int w,int x,int y,int z){
    if((w==y)|(x==z)&(chessBoard[y][z]>(Bfly+1))){
        Push(w,x,chessBoard[y][z],y,z,Bfly); 
        fprintf(new_game,"%-8d%-8d%-11d%-6d%-6d%-9d\n",w,x,chessBoard[y][z],y,z,Bfly);   
        if(chessBoard[y][z]==Rking){
            chessBoard[w][x]=blank;
            chessBoard[y][z]=Bfly;
            print_chessBoard();
            printf("X贏了！椰以～～\n");
            i=-1;
        }
        chessBoard[w][x]=blank;
        chessBoard[y][z]=Bfly;
    }
    else
        printf("輸入錯誤！\n");
}
void Rkingfunc(int w,int x,int y,int z){
    if(((abs(y-w)==abs(x-z)==1)|((abs(y-w)==1)&&(x==z))|((abs(x-z)==1)&&(y==w)))&(chessBoard[y][z]<(Rking))){
        Push(w,x,chessBoard[y][z],y,z,Rking);
        fprintf(new_game,"%-8d%-8d%-11d%-6d%-6d%-9d\n",w,x,chessBoard[y][z],y,z,Rking);
        if(chessBoard[y][z]==Bking){
            chessBoard[w][x]=blank;
            chessBoard[y][z]=Rking;
            print_chessBoard();
            printf("Y贏了！\n");
            i=-1;
        } 
        chessBoard[w][x]=blank;
        chessBoard[y][z]=Rking;
    }
    else
        printf("輸入錯誤！\n");
}
void Bkingfunc(int w,int x,int y,int z){
    if(((abs(y-w)==abs(x-z)==1)|((abs(y-w)==1)&&(x==z))|((abs(x-z)==1)&&(y==w)))&(chessBoard[y][z]>(Bking+7))){
        Push(w,x,chessBoard[y][z],y,z,Bking);
        fprintf(new_game,"%-8d%-8d%-11d%-6d%-6d%-9d\n",w,x,chessBoard[y][z],y,z,Bking);
        if(chessBoard[y][z]==Rking){
            chessBoard[w][x]=blank;
            chessBoard[y][z]=Bking;
            print_chessBoard();
            printf("X贏了！椰以～～\n");
            i=-1;
        }
        chessBoard[w][x]=blank;
        chessBoard[y][z]=Bking;
    }
   // else
        //printf("輸入錯誤!!\n");
}