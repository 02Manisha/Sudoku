#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 
#define A 9 

char S[A][A] ={{' ', ' ', ' ', '6', ' ', ' ', '4', ' ', ' '},
              {'7', ' ', ' ', ' ', ' ', '3', '6', ' ', ' '},
              {' ', ' ', ' ', ' ', '9', '1', ' ', '8', ' '},
              {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
              {' ', '5', ' ', '1', '8', ' ', ' ', ' ', '3'},
              {' ', ' ', ' ', '3', ' ', '6', ' ', '4', '5'},
              {' ', '4', ' ', '2', ' ', ' ', ' ', '6', ' '},
              {'9', ' ', '3', ' ', ' ', ' ', ' ', ' ', ' '},
              {' ', '2', ' ', ' ', ' ', ' ', '1', ' ', ' '}};


void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // EOF => End Of File
}

void fill(int r,int c,int n) {
    if (r >= 0 && r < A && c >= 0 && c < A) {
        S[r][c] = n + '0'; 
    } else {
        printf("Invalid input. The row and column numbers should be between 0 and 8.\n");
    }
}

bool isGameOver() {
    for (int i = 0; i < A; i++) {
        for (int j = 0; j < A; j++) {
            if (S[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int i,j;
    int moves=65;
  

int r=0,c=0;
char n='*';

     printf("\033[91mWelcome to Sudoku \n");
     printf("Here is your Sudoku puzzle:\n");

while(n!='#')
{
    
    printf("    0    1   2   3   4   5   6   7   8   \n");
    printf(" -----------------------------------------\n");
     for (int i = 0; i < 9; i++)
     {
        printf(" %d |", i);
        for (int j = 0; j < 9;j++)  
        printf(" %c |", S[i][j]);
        printf("\n -----------------------------------------\n");
     }

        printf("\033[36m enter the row and column number you want to fill\n");
        scanf("%d%d",&r,&c);

        clearInputBuffer();

        if(r<0||r>=A||c<0||c>=A)
        {
            printf("Invalid input. The row and column numbers should be between 0 and 8.\n");
            continue;
        }

        printf("\033[34m enter the number to be filled or # to stop\n");
        scanf("%c",&n);
        clearInputBuffer();

        if(n=='#')
        {
            printf("\033[91m ------EXITED------");
            break;
        }

        int num = n - '0'; 
        if (num < 1 || num > 9) {
            printf("Invalid input. The number should be between 1 - 9\n");
            continue;
        }

        system("cls");
        fill(r,c,num);
        moves--;

        if(moves ==0)
        {
            printf("\033[92m Out of moves! You've filled the entire puzzle\n");
            break;
        }

        
        if (isGameOver()) {
            printf("\033[92m Congratulations! You've solved the Sudoku puzzle\n");
            break;
        }
}

    return 0;
}