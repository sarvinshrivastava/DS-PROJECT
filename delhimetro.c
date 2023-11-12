#include <stdio.h>
#include <stdlib.h>
#include "user.h"

struct userlogindata {
      char login_name[20], login_psw[20], status;
      struct userlogindata * next;
};

struct userlogindata * start;

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

void read_from_file() {
      FILE *f = fopen("userDataBase/UserData.txt", "r");
      struct userlogindata * ptr, * temp;
      int a = 0;

      while(feof(f) == 0) {
            ptr = (struct userlogindata *)malloc(sizeof(struct userlogindata));

            if(a == 0) {
                  start = ptr;
                  temp = ptr;
                  a++;
            }
            else{
                  /*
                  temp = start;
                  while(temp -> next != NULL) {
                        temp = temp -> next;
                  }
                  */
                  temp->next = ptr;
                  temp = ptr;
            }
            fscanf(f, "%s  %s  %c", &ptr -> login_name, &ptr -> login_psw, &ptr -> status);
            ptr -> next = NULL;
      }

      fclose(f);
}

void write_to_file() {
      FILE *f = fopen("userDataBase/UserData.txt", "w");
      struct userlogindata * ptr, * temp;

      ptr = start;
      temp = start;
      while(ptr != NULL) {
            fprintf(f, "%s  %s  %c\n", ptr -> login_name, ptr -> login_psw, ptr -> status);
            ptr = ptr -> next;
            free(temp);
            temp = ptr;
      }

      fclose(f);
}


void adduser() {
      struct userlogindata * ptr, * temp;
      ptr = (struct userlogindata *)malloc(sizeof(struct userlogindata));
      temp = start;
      while(temp -> next != NULL)
            temp = temp -> next;

      temp -> next = ptr;
      ptr -> status = 'a';
      ptr -> next = NULL;
      
      printf("Enter User Id: ");
      scanf("%s", &ptr -> login_name);
      printf("Enter User Pasword: ");
      scanf("%s", &ptr -> login_psw);
}

void removeuser() {

}

void updateuserlogin() {
      /*
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
      */
}

void updateuserstatus() {

}

void moniteruser() {

}

void showuser() {
      struct userlogindata * ptr;

      ptr = start;
      while(ptr != NULL) {
            printf("%s  %c\n", ptr->login_name, ptr -> status);
            ptr = ptr -> next;
      }
}

void login() {
      read_from_file();
      
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
            }
      } 
      else {
            printf("LoginFailed :( \n");
      }

      write_to_file();
}

void main() {
      login();

      //homepg();
}