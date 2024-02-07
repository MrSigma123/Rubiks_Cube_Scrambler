// Writing the code 06:36PM 24.12.2023
// Sketch and design of the project
// Plan : Menu
// two modes, scrambler and cube solver (2*2 and 3*3)
// (recursively you can develop the program for n*n cube)
// Notes in the notebook
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int choice = -2;
int *mode = &choice;
void logo(void);
void clear(void);
int menu(int *pointer);
void scramblerTimer(void);
void printArray(char array[9][12]);
int main(void){
  clear();
  logo();
  // for c99 compiler - variable length array (VLA)
  // this program will allocate the certain memory for cubes 2x2, 3x3, 4x4, 5x5
  // this have to be done dynamically to enable the functionality of changing the size
  // cube size while using the program
  //
  // testing purposes for 3x3x3 cube
  int size;
  // printf("Enter cube size: ");
  // scanf("%d", &size);
  // const int row = size*3;
  // const int column = size*4;
  
  printf("\033[0m"); // default console color
  //
  //
  //

  while (menu(mode) != 0);
  clear();
  return 0;
}
/*
void printArray(char array[9][12]){
  int i, j;
  //printf("\033[0;37m");
  for (i = 0; i < 9; i++){
    for (j = 0; j < 12; j++){
      //if (i==3&&j==0||i==3&&j==1||i==3&&j==2) printf("\033[0;35m");
      //if (==3&&) printf("\033[0;32m");
      if ((i==0||i==1||i==2)&&(j==3||j==4||j==5)) printf("\033[0;37m"); // white
      if ((i==3||i==4||i==5)&&(j==0||j==1||j==2)) printf("\033[0;35m"); // purple
      if ((i==3||i==4||i==5)&&(j==3||j==4||j==5)) printf("\033[0;32m"); // green
      if ((i==3||i==4||i==5)&&(j==6||j==7||j==8)) printf("\033[0;31m"); // red
      if ((i==3||i==4||i==5)&&(j==9||j==10||j==11)) printf("\033[0;34m"); // blue
      if ((i==6||i==7||i==8)&&(j==3||j==4||j==5)) printf("\033[0;33m"); // yellow
      printf("%c ", array[i][j]);
    }
  printf("\n");
  }
}
*/

int menu(int *pointer){
  char confirm = '0';
  if (*pointer > 5) // assuming the user won't input negative choices
    printf("There is any action for the choice No.%d\n", *pointer);
  if (*pointer == -2)
    printf("Welcome to cube timer with scramble generator!\n");
  printf("Enter the value corresponding to desired action: ");
  printf("0 - exit the program\n");
  printf("1 - 2x2x2 cube scrambler\n");
  printf("2 - 3x3x3 cube scrambler\n");

  scanf("%d", &choice);
  if (*pointer == 0){
    printf("Are you sure you want to quit?\n");
    printf("Press 'y' to proceed or any key to abort: ");
    fflush(stdin);
    scanf("%c", &confirm);
    if (confirm == 'y')
      return 0;
    else {
      *pointer = -1; // default value to loop the menu
    }
  }
  if (*pointer == 2){
    scramblerTimer();
  }
  clear();
  return *pointer;
}

void logo(void){
  printf("Here the logo will be stored");
  getchar();
  clear();
}

void printArray(char array[9][12]){
  int i, j;
  for (i = 0; i < 9; i++){
    for (j = 0; j < 12; j++){
      if (array[i][j] == 'w') {printf("\033[0;37m* "); continue;}
      if (array[i][j] == 'o') {printf("\033[0;35m* "); continue;}
      if (array[i][j] == 'g') {printf("\033[0;32m* "); continue;}
      if (array[i][j] == 'r') {printf("\033[0;31m* "); continue;}
      if (array[i][j] == 'b') {printf("\033[0;34m* "); continue;}
      if (array[i][j] == 'y') {printf("\033[0;33m* "); continue;}
      printf("  ");
    }
    printf("\n");
  }
  printf("\033[0m"); // default console color
}

void scramblerTimer(void){
  int i;
  char tmp;
  int val1 = 0;
  int val2 = 0;
  int scrambleLength = 25;
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
  // the key is to generate 25 random move occurences
  // it has to be done by drawing the strings and putting them to the screen and file
  // implement moves and assign numbers from 0 to 17
  //
  // ...
  //

  // printArray(net);
  printf("Scramble:\n");
  for(i = 0; i < scrambleLength; i++){
    if (i == 0)
      val1 = rand() % 18;
    //val2 = rand() % 18;
    //printf("%d ", val1);
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
        break;
      case 2:
        strcpy(cubeTurn, "U2\0");
        printf("%s ", cubeTurn);
        break;
      case 3:
        strcpy(cubeTurn, "D\0");
        printf("%s ", cubeTurn);
        break;
      case 4:
        strcpy(cubeTurn, "D'\0");
        printf("%s ", cubeTurn);
        break;
      case 5:
        strcpy(cubeTurn, "D2\0");
        printf("%s ", cubeTurn);
        break;
      case 6:
        strcpy(cubeTurn, "R\0");
        printf("%s ", cubeTurn);
        break;
      case 7:
        strcpy(cubeTurn, "R'\0");
        printf("%s ", cubeTurn);
        break;
      case 8:
        strcpy(cubeTurn, "R2\0");
        printf("%s ", cubeTurn);
        break;
      case 9:
        strcpy(cubeTurn, "L\0");
        printf("%s ", cubeTurn);
        break; 
      case 10:
        strcpy(cubeTurn, "L'\0");
        printf("%s ", cubeTurn);
        break;
      case 11:
        strcpy(cubeTurn, "L2\0");
        printf("%s ", cubeTurn);
        break;
      case 12:
        strcpy(cubeTurn, "F\0");
        printf("%s ", cubeTurn);
        break;
      case 13:
        strcpy(cubeTurn, "F'\0");
        printf("%s ", cubeTurn);
        break;
      case 14:
        strcpy(cubeTurn, "F2\0");
        printf("%s ", cubeTurn);
        break;
      case 15:
        strcpy(cubeTurn, "B\0");
        printf("%s ", cubeTurn);
        break;
      case 16:
        strcpy(cubeTurn, "B'\0");
        printf("%s ", cubeTurn);
        break;
      case 17:
        strcpy(cubeTurn, "B2\0");
        printf("%s ", cubeTurn);
        break;
    }
    //while (val1 == val2)
    //  val2 = rand() % 18;
    //val1 = val2;
  
    if (val1==0 || val1==1 || val1==2){
      val2 = turnUContinuations[rand() % 15];
      val1 = val2;
      if (val1==0){
        //tmp = net[0][3];
        //net[0][3] = net[2][3];
        //net[2][3] = net[2][5];
        //net[2][5] = net[0][5];
        //net[0][5] = tmp;
        //tmp = net[0][4];
        //net[0][4] = net[1][3];
        //net[1][3] = net[2][4];
        //net[2][4] = net[1][5];
        //net[1][5] = tmp;
        //tmp = net[3][3];
        //net[3][3] = net[3][6];
        //net[3][6] = net[3][9];
        //net[3][9] = net[3][0];
        //net[3][0] = tmp;
        //tmp = net[3][4];
        //net[3][4] = net[3][7];
        //net[3][7] = net[3][10];
        //net[3][10] = net[3][1];
        //net[3][1] = tmp;
        //tmp = net[3][5];
        //net[3][5] = net[3][8];
        //net[3][8] = net[3][11];
        //net[3][11] = net[3][2];
        //net[3][2] = tmp;
      }
      //if (val1==1)
      //if (val1==2)
      continue;
    }
    if (val1==3 || val1==4 || val1==5){
      val2 = turnDContinuations[rand() % 15];
      val1 = val2;
      // ... if(val1==3) etc
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
  getchar();
}

void clear(void){
  system("clear");
}
// to print the stars with the colors after the cube scramble
// you have to use the function, which will read the letters
// and print the corresponding color accordind to the letter and
// replace the letter with te asterisk symbol
