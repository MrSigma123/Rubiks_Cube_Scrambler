#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int choice = -2;
int *mode = &choice;
void logo(void);
void clear(void);
int menu(int *pointer);
char scrambler(void);
void printArray(char array[9][12]);

int main(void){
  clear();
  logo();
  int size;
  printf("\033[0m"); // default console color
  while (menu(mode) != 0);
  clear();
  return 0;
}

void logo(void){
  printf("ver. 1.01\n\n\n\n");
  /* COLOR DATABASE PALLETE
    printf("\033[0;31m"); // print red layer
    printf("\033[0;32m"); // print green layer
    printf("\033[0;33m"); // print yellow layer
    printf("\033[0;34m"); // print blue layer
    printf("\033[0;35m"); // print purple layer
    printf("\033[0;36m"); // print cyan layer
    printf("\033[0;37m"); // print white layer
  */
  printf("\033[0;33m #####  \033[0;31m  #####           \n");
  printf("\033[0;33m#     # \033[0;31m #     #  \033[0;37m ####   \033[0;32m#####   \033[0;34m  ##    \033[0;35m#    #  \033[0;33m#####   \033[0;31m#       \033[0;37m######  \033[0;32m##### \n");
  printf("\033[0;33m#       \033[0;31m #        \033[0;37m#    #  \033[0;32m#    #  \033[0;34m #  #   \033[0;35m##  ##  \033[0;33m#    #  \033[0;31m#       \033[0;37m#       \033[0;32m#    # \n");
  printf("\033[0;33m#       \033[0;31m  #####   \033[0;37m#       \033[0;32m#    #  \033[0;34m#    #  \033[0;35m# ## #  \033[0;33m#####   \033[0;31m#       \033[0;37m#####   \033[0;32m#    # \n");
  printf("\033[0;33m#       \033[0;31m       #  \033[0;37m#       \033[0;32m#####   \033[0;34m######  \033[0;35m#    #  \033[0;33m#    #  \033[0;31m#       \033[0;37m#       \033[0;32m##### \n");
  printf("\033[0;33m#     # \033[0;31m #     #  \033[0;37m#    #  \033[0;32m#   #   \033[0;34m#    #  \033[0;35m#    #  \033[0;33m#    #  \033[0;31m#       \033[0;37m#       \033[0;32m#   # \n");
  printf("\033[0;33m #####  \033[0;31m  #####   \033[0;37m ####   \033[0;32m#    #  \033[0;34m#    #  \033[0;35m#    #  \033[0;33m#####   \033[0;31m######  \033[0;37m######  \033[0;32m#    # \n");
  getchar();
  fflush(stdin);
  clear();
}

void clear(void){
  system("clear");
}

int menu(int *pointer){
  char confirm = '0';
  char flag = '0';
  if (*pointer > 5) // assuming the user won't input negative choices
    printf("There is any action for the choice No.%d\n", *pointer);
  if (*pointer == -2){
    printf("\n\n\n\n\n\tWelcome to the Rubik's cube scramble generator!\n");
    printf("\tEnter the value corresponding to desired action: \n\n");
  }
  else {
    printf("\n\n\n\n\n\tEnter the value corresponding to desired action: \n\n");
  }
  printf("\t             0 - exit the program\n");
  printf("\t             1 - scramble the cube\n");
  printf("\n\t\t\tYour choice: ");
  scanf("%d", &choice);
  if (*pointer == 0){
    printf("\n\t       Are you sure you want to quit?\n");
    printf("\t  Press 'y' to proceed or any key to abort: ");
    fflush(stdin);
    scanf("%c", &confirm);
    if (confirm == 'y')
      return 0;
    else {
      *pointer = -1; // default value to loop the menu
    }
  }
  if (*pointer == 1){
    do {
      flag = scrambler();
    } while (flag == '\n');
  }
  clear();
  return *pointer;
}

void printArray(char array[9][12]){
  int i, j;
  for (i = 0; i < 9; i++){
    printf("\t\t    ");
    for (j = 0; j < 12; j++){
      if (array[i][j] == 'w') {printf("\033[0;37m■ "); continue;}
      if (array[i][j] == 'o') {printf("\033[0;35m■ "); continue;}
      if (array[i][j] == 'g') {printf("\033[0;32m■ "); continue;}
      if (array[i][j] == 'r') {printf("\033[0;31m■ "); continue;}
      if (array[i][j] == 'b') {printf("\033[0;34m■ "); continue;}
      if (array[i][j] == 'y') {printf("\033[0;33m■ "); continue;}
      printf("  ");
    }
    printf("\n");
  }
  printf("\033[0m"); // default console color
}

char scrambler(void){
  int i;
  char tmp;
  int val1 = 0;
  int val2 = 0;
  int scrambleLength = 25; // standard scramble length
  int turnUContinuations[15] = {3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
  int turnDContinuations[15] = {0,1,2,6,7,8,9,10,11,12,13,14,15,16,17};
  int turnRContinuations[15] = {0,1,2,3,4,5,9,10,11,12,13,14,15,16,17};
  int turnLContinuations[15] = {0,1,2,3,4,5,6,7,8,12,13,14,15,16,17};
  int turnFContinuations[15] = {0,1,2,3,4,5,6,7,8,9,10,11,15,16,17};
  int turnBContinuations[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
  char net[9][12] = { // default solved cube
   {' ',' ',' ','w','w','w',' ',' ',' ',' ',' ',' '},
   {' ',' ',' ','w','w','w',' ',' ',' ',' ',' ',' '},
   {' ',' ',' ','w','w','w',' ',' ',' ',' ',' ',' '},
   {'o','o','o','g','g','g','r','r','r','b','b','b'},
   {'o','o','o','g','g','g','r','r','r','b','b','b'},
   {'o','o','o','g','g','g','r','r','r','b','b','b'},
   {' ',' ',' ','y','y','y',' ',' ',' ',' ',' ',' '},
   {' ',' ',' ','y','y','y',' ',' ',' ',' ',' ',' '},
   {' ',' ',' ','y','y','y',' ',' ',' ',' ',' ',' '}
  };
  char cubeTurn[3];
  srand(time(NULL));
  clear();
  printf("\t\t\tScramble:\n\n  ");
  for(i = 0; i < scrambleLength; i++){
    if (i == 0)
      val1 = rand() % 18; 
    switch (val1){
      case 0:
        strcpy(cubeTurn, "U\0");
        printf("%s ", cubeTurn);
        tmp = net[0][3];
        net[0][3] = net[2][3];
        net[2][3] = net[2][5];
        net[2][5] = net[0][5];
        net[0][5] = tmp;
        tmp = net[0][4];
        net[0][4] = net[1][3];
        net[1][3] = net[2][4];
        net[2][4] = net[1][5];
        net[1][5] = tmp;
        tmp = net[3][3];
        net[3][3] = net[3][6];
        net[3][6] = net[3][9];
        net[3][9] = net[3][0];
        net[3][0] = tmp;
        tmp = net[3][4];
        net[3][4] = net[3][7];
        net[3][7] = net[3][10];
        net[3][10] = net[3][1];
        net[3][1] = tmp;
        tmp = net[3][5];
        net[3][5] = net[3][8];
        net[3][8] = net[3][11];
        net[3][11] = net[3][2];
        net[3][2] = tmp;
        break;
      case 1:
        strcpy(cubeTurn, "U'\0");
        printf("%s ", cubeTurn);
        tmp = net[0][3];
        net[0][3] = net[0][5];
        net[0][5] = net[2][5];
        net[2][5] = net[2][3];
        net[2][3] = tmp;
        tmp = net[0][4];
        net[0][4] = net[1][5];
        net[1][5] = net[2][4];
        net[2][4] = net[1][3];
        net[1][3] = tmp;
        tmp = net[3][3];
        net[3][3] = net[3][0];
        net[3][0] = net[3][9];
        net[3][9] = net[3][6];
        net[3][6] = tmp;
        tmp = net[3][4];
        net[3][4] = net[3][1];
        net[3][1] = net[3][10];
        net[3][10] = net[3][7];
        net[3][7] = tmp;
        tmp = net[3][5];
        net[3][5] = net[3][2];
        net[3][2] = net[3][11];
        net[3][11] = net[3][8];
        net[3][8] = tmp;
        break;
      case 2:
        strcpy(cubeTurn, "U2\0");
        printf("%s ", cubeTurn);
        tmp = net[0][3];
        net[0][3] = net[2][5];
        net[2][5] = tmp;
        tmp = net[0][5];
        net[0][5] = net[2][3];
        net[2][3] = tmp;
        tmp = net[0][4];
        net[0][4] = net[2][4];
        net[2][4] = tmp;
        tmp = net[1][5];
        net[1][5] = net[1][3];
        net[1][3] = tmp;
        tmp = net[3][3];
        net[3][3] = net[3][9];
        net[3][9] = tmp;
        tmp = net[3][6];
        net[3][6] = net[3][0];
        net[3][0] = tmp;
        tmp = net[3][4];
        net[3][4] = net[3][10];
        net[3][10] = tmp;
        tmp = net[3][7];
        net[3][7] = net[3][1];
        net[3][1] = tmp;
        tmp = net[3][5];
        net[3][5] = net[3][11];
        net[3][11] = tmp;
        tmp = net[3][8];
        net[3][8] = net[3][2];
        net[3][2] = tmp;
        break;
      case 3:
        strcpy(cubeTurn, "D\0");
        printf("%s ", cubeTurn);
        tmp = net[6][3];
        net[6][3] = net[8][3];
        net[8][3] = net[8][5];
        net[8][5] = net[6][5];
        net[6][5] = tmp;
        tmp = net[6][4];
        net[6][4] = net[7][3];
        net[7][3] = net[8][4];
        net[8][4] = net[7][5];
        net[7][5] = tmp;
        tmp = net[5][3];
        net[5][3] = net[5][0];
        net[5][0] = net[5][9];
        net[5][9] = net[5][6];
        net[5][6] = tmp;
        tmp = net[5][4];
        net[5][4] = net[5][1];
        net[5][1] = net[5][10];
        net[5][10] = net[5][7];
        net[5][7] = tmp;
        tmp = net[5][5];
        net[5][5] = net[5][2];
        net[5][2] = net[5][11];
        net[5][11] = net[5][8];
        net[5][8] = tmp;
        break;
      case 4:
        strcpy(cubeTurn, "D'\0");
        printf("%s ", cubeTurn);
        tmp = net[6][3];
        net[6][3] = net[6][5];
        net[6][5] = net[8][5];
        net[8][5] = net[8][3];
        net[8][3] = tmp;
        tmp = net[6][4];
        net[6][4] = net[7][5];
        net[7][5] = net[8][4];
        net[8][4] = net[7][3];
        net[7][3] = tmp;
        tmp = net[5][3];
        net[5][3] = net[5][6];
        net[5][6] = net[5][9];
        net[5][9] = net[5][0];
        net[5][0] = tmp;
        tmp = net[5][4];
        net[5][4] = net[5][7];
        net[5][7] = net[5][10];
        net[5][10] = net[5][1];
        net[5][1] = tmp;
        tmp = net[5][5];
        net[5][5] = net[5][8];
        net[5][8] = net[5][11];
        net[5][11] = net[5][2];
        net[5][2] = tmp;
        break;
      case 5:
        strcpy(cubeTurn, "D2\0");
        printf("%s ", cubeTurn);
        tmp = net[6][3];
        net[6][3] = net[8][5];
        net[8][5] = tmp;
        tmp = net[6][5];
        net[6][5] = net[8][3];
        net[8][3] = tmp;
        tmp = net[6][4];
        net[6][4] = net[8][4];
        net[8][4] = tmp;
        tmp = net[7][5];
        net[7][5] = net[7][3];
        net[7][3] = tmp;
        tmp = net[5][3];
        net[5][3] = net[5][9];
        net[5][9] = tmp;
        tmp = net[5][6];
        net[5][6] = net[5][0];
        net[5][0] = tmp;
        tmp = net[5][4];
        net[5][4] = net[5][10];
        net[5][10] = tmp;
        tmp = net[5][7];
        net[5][7] = net[5][1];
        net[5][1] = tmp;
        tmp = net[5][5];
        net[5][5] = net[5][11];
        net[5][11] = tmp;
        tmp = net[5][8];
        net[5][8] = net[5][2];
        net[5][2] = tmp;
        break;
      case 6:
        strcpy(cubeTurn, "R\0");
        printf("%s ", cubeTurn);
        tmp = net[3][6];
        net[3][6] = net[5][6];
        net[5][6] = net[5][8];
        net[5][8] = net[3][8];
        net[3][8] = tmp;
        tmp = net[3][7];
        net[3][7] = net[4][6];
        net[4][6] = net[5][7];
        net[5][7] = net[4][8];
        net[4][8] = tmp;
        tmp = net[3][5];
        net[3][5] = net[6][5];
        net[6][5] = net[5][9];
        net[5][9] = net[0][5];
        net[0][5] = tmp;
        tmp = net[4][5];
        net[4][5] = net[7][5];
        net[7][5] = net[4][9];
        net[4][9] = net[1][5];
        net[1][5] = tmp;
        tmp = net[5][5];
        net[5][5] = net[8][5];
        net[8][5] = net[3][9];
        net[3][9] = net[2][5];
        net[2][5] = tmp;
        break;
      case 7:
        strcpy(cubeTurn, "R'\0");
        printf("%s ", cubeTurn);
        tmp = net[3][6];
        net[3][6] = net[3][8];
        net[3][8] = net[5][8];
        net[5][8] = net[5][6];
        net[5][6] = tmp;
        tmp = net[3][7];
        net[3][7] = net[4][8];
        net[4][8] = net[5][7];
        net[5][7] = net[4][6];
        net[4][6] = tmp;
        tmp = net[3][5];
        net[3][5] = net[0][5];
        net[0][5] = net[5][9];
        net[5][9] = net[6][5];
        net[6][5] = tmp;
        tmp = net[4][5];
        net[4][5] = net[1][5];
        net[1][5] = net[4][9];
        net[4][9] = net[7][5];
        net[7][5] = tmp;
        tmp = net[5][5];
        net[5][5] = net[2][5];
        net[2][5] = net[3][9];
        net[3][9] = net[8][5];
        net[8][5] = tmp;
        break;
      case 8:
        strcpy(cubeTurn, "R2\0");
        printf("%s ", cubeTurn);
        tmp = net[3][6];
        net[3][6] = net[5][8];
        net[5][8] = tmp;
        tmp = net[3][8];
        net[3][8] = net[5][6];
        net[5][6] = tmp;
        tmp = net[3][7];
        net[3][7] = net[5][7];
        net[5][7] = tmp;
        tmp = net[4][8];
        net[4][8] = net[4][6];
        net[4][6] = tmp;
        tmp = net[3][5];
        net[3][5] = net[5][9];
        net[5][9] = tmp;
        tmp = net[0][5];
        net[0][5] = net[6][5];
        net[6][5] = tmp;
        tmp = net[4][5];
        net[4][5] = net[4][9];
        net[4][9] = tmp;
        tmp = net[1][5];
        net[1][5] = net[7][5];
        net[7][5] = tmp;
        tmp = net[5][5];
        net[5][5] = net[3][9];
        net[3][9] = tmp;
        tmp = net[2][5];
        net[2][5] = net[8][5];
        net[8][5] = tmp;
        break;
      case 9:
        strcpy(cubeTurn, "L\0");
        printf("%s ", cubeTurn);
        tmp = net[3][0];
        net[3][0] = net[5][0];
        net[5][0] = net[5][2];
        net[5][2] = net[3][2];
        net[3][2] = tmp;
        tmp = net[3][1];
        net[3][1] = net[4][0];
        net[4][0] = net[5][1];
        net[5][1] = net[4][2];
        net[4][2] = tmp;
        tmp = net[3][3];
        net[3][3] = net[0][3];
        net[0][3] = net[5][11];
        net[5][11] = net[6][3];
        net[6][3] = tmp;
        tmp = net[4][3];
        net[4][3] = net[1][3];
        net[1][3] = net[4][11];
        net[4][11] = net[7][3];
        net[7][3] = tmp;
        tmp = net[5][3];
        net[5][3] = net[2][3];
        net[2][3] = net[3][11];
        net[3][11] = net[8][3];
        net[8][3] = tmp;
        break; 
      case 10:
        strcpy(cubeTurn, "L'\0");
        printf("%s ", cubeTurn);
        tmp = net[3][0];
        net[3][0] = net[3][2];
        net[3][2] = net[5][2];
        net[5][2] = net[5][0];
        net[5][0] = tmp;
        tmp = net[3][1];
        net[3][1] = net[4][2];
        net[4][2] = net[5][1];
        net[5][1] = net[4][0];
        net[4][0] = tmp;
        tmp = net[3][3];
        net[3][3] = net[6][3];
        net[6][3] = net[5][11];
        net[5][11] = net[0][3];
        net[0][3] = tmp;
        tmp = net[4][3];
        net[4][3] = net[7][3];
        net[7][3] = net[4][11];
        net[4][11] = net[1][3];
        net[1][3] = tmp;
        tmp = net[5][3];
        net[5][3] = net[8][3];
        net[8][3] = net[3][11];
        net[3][11] = net[2][3];
        net[2][3] = tmp;
        break;
      case 11:
        strcpy(cubeTurn, "L2\0");
        printf("%s ", cubeTurn);
        tmp = net[3][0];
        net[3][0] = net[5][2];
        net[5][2] = tmp;
        tmp = net[3][2];
        net[3][2] = net[5][0];
        net[5][0] = tmp;
        tmp = net[3][1];
        net[3][1] = net[5][1];
        net[5][1] = tmp;
        tmp = net[4][2];
        net[4][2] = net[4][0];
        net[4][0] = tmp;
        tmp = net[3][3];
        net[3][3]= net[5][11];
        net[5][11] = tmp;
        tmp = net[6][3];
        net[6][3] = net[0][3];
        net[0][3] = tmp;
        tmp = net[4][3];
        net[4][3] = net[4][11];
        net[4][11] = tmp;
        tmp = net[7][3];
        net[7][3] = net[1][3];
        net[1][3] = tmp;
        tmp = net[5][3];
        net[5][3] = net[3][11];
        net[3][11] = tmp;
        tmp = net[8][3];
        net[8][3] = net[2][3];
        net[2][3] = tmp;
        break;
      case 12:
        strcpy(cubeTurn, "F\0");
        printf("%s ", cubeTurn);
        tmp = net[3][3];
        net[3][3] = net[5][3];
        net[5][3] = net[5][5];
        net[5][5] = net[3][5];
        net[3][5] = tmp;
        tmp = net[3][4];
        net[3][4] = net[4][3];
        net[4][3] = net[5][4];
        net[5][4] = net[4][5];
        net[4][5] = tmp;
        tmp = net[2][3];
        net[2][3] = net[5][2];
        net[5][2] = net[6][5];
        net[6][5] = net[3][6];
        net[3][6] = tmp;
        tmp = net[2][4];
        net[2][4] = net[4][2];
        net[4][2] = net[6][4];
        net[6][4] = net[4][6];
        net[4][6] = tmp;
        tmp = net[2][5];
        net[2][5] = net[3][2];
        net[3][2] = net[6][3];
        net[6][3] = net[5][6];
        net[5][6] = tmp;
        break;
      case 13:
        strcpy(cubeTurn, "F'\0");
        printf("%s ", cubeTurn);
        tmp = net[3][3];
        net[3][3] = net[3][5];
        net[3][5] = net[5][5];
        net[5][5] = net[5][3];
        net[5][3] = tmp;
        tmp = net[3][4];
        net[3][4] = net[4][5];
        net[4][5] = net[5][4];
        net[5][4] = net[4][3];
        net[4][3] = tmp;
        tmp = net[2][3];
        net[2][3] = net[3][6];
        net[3][6] = net[6][5];
        net[6][5] = net[5][2];
        net[5][2] = tmp;
        tmp = net[2][4];
        net[2][4] = net[4][6];
        net[4][6] = net[6][4];
        net[6][4] = net[4][2];
        net[4][2] = tmp;
        tmp = net[2][5];
        net[2][5] = net[5][6];
        net[5][6] = net[6][3];
        net[6][3] = net[3][2];
        net[3][2] = tmp;
        break;
      case 14:
        strcpy(cubeTurn, "F2\0");
        printf("%s ", cubeTurn);
        tmp = net[3][3];
        net[3][3] = net[5][5];
        net[5][5] = tmp;
        tmp = net[3][5];
        net[3][5] = net[5][3];
        net[5][3] = tmp;
        tmp = net[3][4];
        net[3][4] = net[5][4];
        net[5][4] = tmp;
        tmp = net[4][5];
        net[4][5] = net[4][3];
        net[4][3] = tmp;
        tmp = net[2][3];
        net[2][3] = net[6][5];
        net[6][5] = tmp;
        tmp = net[3][6];
        net[3][6] = net[5][2];
        net[5][2] = tmp;
        tmp = net[2][4];
        net[2][4] = net[6][4];
        net[6][4] = tmp;
        tmp = net[4][6];
        net[4][6] = net[4][2];
        net[4][2] = tmp;
        tmp = net[2][5];
        net[2][5] = net[6][3];
        net[6][3] = tmp;
        tmp = net[5][6];
        net[5][6] = net[3][2];
        net[3][2] = tmp;
        break;
      case 15:
        strcpy(cubeTurn, "B\0");
        printf("%s ", cubeTurn);
        tmp = net[5][11];
        net[5][11] = net[3][11];
        net[3][11] = net[3][9];
        net[3][9] = net[5][9];
        net[5][9] = tmp;
        tmp = net[5][10];
        net[5][10] = net[4][11];
        net[4][11] = net[3][10];
        net[3][10] = net[4][9];
        net[4][9] = tmp;
        tmp = net[8][3];
        net[8][3] = net[3][0];
        net[3][0] = net[0][5];
        net[0][5] = net[5][8];
        net[5][8] = tmp;
        tmp = net[8][4];
        net[8][4] = net[4][0];
        net[4][0] = net[0][4];
        net[0][4] = net[4][8];
        net[4][8] = tmp;
        tmp = net[8][5];
        net[8][5] = net[5][0];
        net[5][0] = net[0][3];
        net[0][3] = net[3][8];
        net[3][8] = tmp;
        break;
      case 16:
        strcpy(cubeTurn, "B'\0");
        printf("%s ", cubeTurn);
        tmp = net[5][11];
        net[5][11] = net[5][9];
        net[5][9] = net[3][9];
        net[3][9] = net[3][11];
        net[3][11] = tmp;
        tmp = net[5][10];
        net[5][10] = net[4][9];
        net[4][9] = net[3][10];
        net[3][10] = net[4][11];
        net[4][11] = tmp;
        tmp = net[8][3];
        net[8][3] = net[5][8];
        net[5][8] = net[0][5];
        net[0][5] = net[3][0];
        net[3][0] = tmp;
        tmp = net[8][4];
        net[8][4] = net[4][8];
        net[4][8] = net[0][4];
        net[0][4] = net[4][0];
        net[4][0] = tmp;
        tmp = net[8][5];
        net[8][5] = net[3][8];
        net[3][8] = net[0][3];
        net[0][3] = net[5][0];
        net[5][0] = tmp;
        break;
      case 17:
        strcpy(cubeTurn, "B2\0");
        printf("%s ", cubeTurn);
        tmp = net[5][11];
        net[5][11] = net[3][9];
        net[3][9] = tmp;
        tmp = net[5][9];
        net[5][9] = net[3][11];
        net[3][11] = tmp;
        tmp = net[5][10];
        net[5][10] = net[3][10];
        net[3][10] = tmp;
        tmp = net[4][9];
        net[4][9] = net[4][11];
        net[4][11] = tmp;
        tmp = net[8][3];
        net[8][3] = net[0][5];
        net[0][5] = tmp;
        tmp = net[5][8];
        net[5][8] = net[3][0];
        net[3][0] = tmp;
        tmp = net[8][4];
        net[8][4] = net[0][4];
        net[0][4] = tmp;
        tmp = net[4][8];
        net[4][8] = net[4][0];
        net[4][0] = tmp;
        tmp = net[8][5];
        net[8][5] = net[0][3];
        net[0][3] = tmp;
        tmp = net[3][8];
        net[3][8] = net[5][0];
        net[5][0] = tmp;
        break;
    }
  
    if (val1==0 || val1==1 || val1==2){
      val2 = turnUContinuations[rand() % 15];
      val1 = val2;
      continue;
    }
    if (val1==3 || val1==4 || val1==5){
      val2 = turnDContinuations[rand() % 15];
      val1 = val2;
      continue;
    }
    if (val1==6 || val1==7 || val1==8){
      val2 = turnRContinuations[rand() % 15];
      val1 = val2;
      continue;
    }
    if (val1==9 || val1==10 || val1==11){
      val2 = turnLContinuations[rand() % 15];
      val1 = val2;
      continue;
    }
    if (val1==12 || val1==13 || val1==14){
      val2 = turnFContinuations[rand() % 15];
      val1 = val2;
      continue;
    }
    if (val1==15 || val1==16 || val1==17){
      val2 = turnBContinuations[rand() % 15];
      val1 = val2;
      continue;
    }
  }
  printf("\n\n");
  printArray(net);
  fflush(stdin);
  printf("\n          Press ENTER to generate another scramble or");
  printf("\n     type 0 and confirm with ENTER to come back to main menu");
  printf("\n                      Your choice: ");
  return getchar();
}
