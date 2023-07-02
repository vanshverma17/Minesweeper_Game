#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  printf("\n");
  printf("\t\t\t\t\t\t! WELCOME TO MINESWEEPER !\t\t\n");
  printf("\n");
  int a[16][16];
  srand(time(0));

  for(int i=0;i<16;i++){
    for(int j=0;j<16;j++){
      a[i][j] = rand() % 2;
    }
  }
  
  int k1=-1,k2=0;
  for(int i=0;i<17;i++){
    for(int j=0;j<17;j++){
      if(i==0){
        printf("%d\t",k1++);
      }
      else if(j==0){
        printf("%d\t",k2++);
      }
      else{
        printf("-\t");
      }
    }
    printf("\n");
  }

  // for(int i=0;i<16;i++){
  //   for(int j=0;j<16;j++){
  //     printf(" %d ",a[i][j]);
  //   }
  //   printf("\n");
  // }

  int i,j,n=1,x,move=1; 
  printf("\n");
  
  while(n!=0){
    int count=0;
    printf("Move %d\n",move);
    printf("Enter the row : ");
    scanf("%d",&i);
    printf("Enter the column : ");
    scanf("%d",&j);
    
    if(a[i][j] == 0){
      printf("You Stepped on the Mine!\n");
      printf("You played %d move!\n",move);
      printf("Game Over!!");
      break;
    }
    else{
      if(i==0 && j!=0 && j!=15){
        for(int r = i; r<=i+1 ; r++){
          for(int c = j-1; c<=j+1 ; c++){
            x = a[r][c];
            if(x==0){
              count++;
            }
          }
        }
      }
      else if(j==0 && i!=0 && i!=15){
        for(int r = i-1; r<=i+1 ; r++){
          for(int c = j; c<=j+1 ; c++){
            x = a[r][c];
            if(x==0){
              count++;
            }
          }
        }
      }
      else if(i==15 && j!=0 && j==15){
        for(int r = i-1; r<=i ; r++){
          for(int c = j-1; c<=j+1 ; c++){
            x = a[r][c];
            if(x==0){
              count++;
            }
          }
        }
      }
      else if(j==15 && i!=0 && i!=15){
        for(int r = i-1; r<=i+1 ; r++){
          for(int c = j-1; c<=j ; c++){
            x = a[r][c];
            if(x==0){
              count++;
            }
          }
        }
      }
      else if(i==0 && j==0){
        if(a[0][1]==0){
          count++;
        }
        if(a[1][1]==0){
          count++;
        }
        if(a[1][0]==0){
          count++;
        }
      }
      else if(i==0 && j==15){
        if(a[1][14]==0){
          count++;
        }
        if(a[0][14]==0){
          count++;
        }
        if(a[1][15]==0){
          count++;
        }
      }
      else if(i==15 && j==0){
        if(a[14][0]==0){
          count++;
        }
        if(a[14][1]==0){
          count++;
        }
        if(a[15][1]==0){
          count++;
        }
      }
      else if(i==15 && j==15){
        if(a[14][14]==0){
          count++;
        }
        if(a[0][14]==0){
          count++;
        }
        if(a[15][14]==0){
          count++;
        }
      }
      else{
        for(int r = i-1; r<=i+1 ; r++){
          for(int c = j-1; c<=j+1 ; c++){
            x = a[r][c];
            if(x==0){
              count++;
            }
          }
        }
      }
      printf("There are %d tiles which contain a mine!\n",count);
      move++;
      printf("\n");
      continue;
    }
  }
  return 0;
}                    