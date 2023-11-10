#include <stdio.h>
#include <stdlib.h>
#include "user.h"

struct userdata {
      char name[20], psw[20], status;
};


/*
int homepg() {
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
      
      printf("\n\n\n\n");

      printf("Menu:\n");
      printf("\t 1. Login\n");
      printf("\t 2. About Project\n");
      printf("\t 3. About Me\n");
      
      int inp;
      
      while (1) 
      {
      
      scanf("%d", &inp);
      if(inp == 2) 
            printf("It's soul purpose is to determine the shortest route between any 2 stations of delhi metro. \n");
      else if(inp == 1) {
            loginpage();
      }
      else if(inp == 3) 
            printf("I am Sarvin Shrivastava pursuing my under-graduate degree form KIET Group of Institutions Ghaziabad in B.Tech. My opted branch is Computer Science & Engineering.\nPleased to meet u... ;-)\n");
      else 
            printf("Enter valid input!");
      }
}
*/

void adduser() {
      char user_name[20], user_psw[20];
      FILE *f = fopen("userDataBase/UserData.txt", "a");

      if(f == NULL) {
            printf("Error!!");
            exit(0);
      }
      
      printf("Enter UserId: ");
      scanf("%s", &user_name);
      printf("Enter User Pasword: ");
      scanf("%s", &user_psw);

      /*
      int i = 0; char ch;
      while((ch = getch()) != '`') {
            user_psw[i] = ch;
            i++;
            printf("*");
      }
      user_psw[i] = '\0';
      */

      fprintf(f, "%s  %s  a\n", user_name, user_psw);
      fclose(f);
}

void removeuser() {

}

void updateuserlogin() {
      int choice;
      char userda[20];
      FILE *f = fopen("userDataBase/UserData.txt", "a");
      struct userdata data;

      rewind(f);

      printf("What do you want to update?\n");
      printf("\t1-> UserID\n");
      printf("\t2-> UserPsw\n");
      scanf("%d", &choice);

      switch (choice) {
            case 1:
                  printf("Enter previous UserID");
                  scanf("%s", &userda);

                  while (feof(f) == 0) {
                        fscanf(f, "%s  %s  %c", &data.name, &data.psw, &data.status);
                        if(strcmp(userda, data.name) == 0) {
                              printf("Enter New User ID");
                              scanf("%s", &data.name);
                              
                        }
                  }
                  
                  break;
      
            default:
                  break;
      }
}

void updateuserstatus() {

}

void moniteruser() {

}

void showuser() {
      FILE *f = fopen("userDataBase/UserData.txt", "r");
      struct userdata data;

      while(feof(f) == 0) {
            fscanf(f, "%s  %s  %c", &data.name, &data.psw, &data.status);
            printf("%s  %c\n", data.name, data.status);
      }

      fclose(f);
}

void login() {
      char inp_name[20], inp_psw[20];

      printf("*******************************************************************\n");
      printf("\t\t\tUSER LOGIN\n");
      printf("*******************************************************************\n");

      char sup_user[] = {'s', 'u', 's', 'e', 'r', '\0'}, sup_psw[] = {'p', 'a', 's', 's', '1', '2', '3', '\0'};

      printf("Enter name: ");
      scanf("%s", &inp_name);
      printf("Enter pasword: ");

      int i = 0; char ch;
      while((ch = getch()) != ' ') {
            inp_psw[i] = ch;
            i++;
            printf("*");
      }
      inp_psw[i] = '\0';
      //printf("%s", inp_psw);

      int inp_ans, flag = 1;

      if(strcmp(inp_name, sup_user) == 0 && strcmp(inp_psw, sup_psw) == 0) {
            while(flag) {
                  printf("\n\n\n");
                  printf("\t\t1. Add User\n");
                  printf("\t\t2. Delete User\n");
                  printf("\t\t3. Update User\n");
                  printf("\t\t5. Moniter User\n");
                  printf("\t\t6. Show Users\n");
                  printf("\t\t7. Exit\n");
                  printf("\n\n\n");

                  scanf("%d", &inp_ans);
                  int choice;
                  switch (inp_ans) {
                        case 1:
                              adduser();
                              break;
                        case 2:
                              removeuser();
                              break;
                        case 3:
                              here:
                              printf("\tWhat do you want to update? \n");
                              printf("\t1--> User Login Details\n");
                              printf("\t2--> User Login Status\n");
                              scanf("%d", &choice);

                              switch (choice) {
                                    case 1:
                                          updateuserlogin();
                                          break;
                                    case 2:
                                          updateuserstatus();
                                          break;
                              
                                    default:
                                          printf("Enter correct choice!!!");
                                          goto here;
                                          break;
                              }

                        case 5:
                              moniteruser();
                              break;
                        case 6:
                              showuser();
                              break;
                        case 7:
                              flag = 0;
                              break;
                        
                        default:
                              printf("Enter correct choice!!!");
                              break;
                  }
                  //fflush(stdin);
            }
      } 
      else {
            printf("LoginFailed :( \n");
      }

}

void main() {
      login();

      //homepg();
}