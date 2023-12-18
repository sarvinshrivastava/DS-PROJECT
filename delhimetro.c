// system defined header files
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// universal constants
#define MIN_ACCOUNT_BALANCE -1000
#define NEW_ACCOUNT_BALANCE 100

// developer defined header files
#include "route.h"
#include "consumer.h"
#include "user.h"

// homepage function
void homepage() {
      int X;
      for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 150; j++)
                  printf("#");
            printf("\n");
      }
      
      printf("\n\n\n\n");
      
      printf("\t\t\t\t\t\t\t\tDELHI METRO ROUTE PLANER");

      printf("\n\n\n\n");
      
      for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 150; j++)
                  printf("#");
            printf("\n");
      }
      
      int inp;
      
      while (1) {
            printf("\n\n");
            printf("Main Menu:\n");
            printf("\t 1. Login\n");
            printf("\t 2. About\n");
            printf("\t 3. Devloper\n");
            printf("\t 4. Exit\n");
            
            scanf("%d", &inp);
            switch (inp) {
                  case 1:
                        X = login();
                        break;
                  case 2:
                        printf("This is a console based project used for finding shortest route between 2 stations of Delhi Metro.\n");
                        break;
                  case 3:
                        printf("\tHello! I'm Sarvin Shrivastava, currently pursuing a B.Tech degree in Computer Science and Engineering at K.I.E.T Group of Institutions in Ghaziabad. My academic\nfocus provides a robust foundation in computer science, and I'm particularly intrigued by Augmented Reality (AR) and Virtual Reality (VR). Actively exploring these\nrealms, I'm excited about the transformative potential they hold.\n\n\tAlongside my tech pursuits, I'm in a learning phase in Machine Learning, eager to apply data-driven insights to real-world challenges. Beyond academics, my passion\n for photography allows me to capture and savor life's fleeting moments. Join me as I navigate the exciting intersections of computer science, AR/VR, Machine Learning,\n and the art of photography, eager to contribute and innovate in these dynamic fields.");
                        break;
                  case 4:
                        exit(0);

                  default:
                        printf("Choose correct option!!!\n");
                        break;
            }
      }
}

// main function
int main() {
      homepage();

      return 0;
}