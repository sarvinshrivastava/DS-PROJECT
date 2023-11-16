// system defined header files
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// universal constants
#define MIN_ACCOUNT_BALANCE -1000
#define NEW_ACCOUNT_BALANCE 100

// devloper defined header files
#include "route.h"
#include "consumer.h"
#include "user.h"

// homepg function
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
                        printf("I am Sarvin Shrivastava compleating my B.Tech degree from K.I.E.T Group of Institutions Ghaziabad in Computer Science and Enggniering branch.\n");
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
void main() {
      homepage();

}