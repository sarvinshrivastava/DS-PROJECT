// defining userlogin structure
struct userlogindata {
      char login_name[20], login_psw[20], status;
      struct userlogindata * next;
};

struct userlogindata * start_user;


// user functions
void read_from_file_user() {
      FILE *f = fopen("userDataBase/UserData.txt", "r");
      struct userlogindata * ptr, * temp;
      int a = 0;

      while(feof(f) == 0) {
            ptr = (struct userlogindata *)malloc(sizeof(struct userlogindata));

            if(a == 0) {
                  start_user = ptr;
                  temp = ptr;
                  a++;
            }
            else{
                  temp->next = ptr;
                  temp = ptr;
            }
            fscanf(f, "%s %s %c", &ptr -> login_name, &ptr -> login_psw, &ptr -> status);
            ptr -> next = NULL;
      }

      temp = start_user;
      while(temp -> next != ptr)
            temp = temp -> next;
      temp->next = NULL;
      free(ptr);

      fclose(f);
}

void write_to_file_user() {
      FILE *f = fopen("userDataBase/UserData.txt", "w");
      struct userlogindata * ptr, * temp;

      ptr = start_user;
      temp = start_user;
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
      temp = start_user;
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
      struct userlogindata * ptr = start_user, * temp;
      char username[20];
      int flag = 0;

      printf("Enter the name of user to be removed: ");
      scanf("%s", &username);

      temp = start_user;
      while(temp != NULL) {
            if(strcmp(temp -> login_name, username) == 0) {
                  ptr -> next = temp -> next;
                  free(temp);
                  flag = 1;
                  break;
            }
            ptr = temp;
            temp = temp -> next;
      }

      if(flag == 0) {
            printf("User not found! Please check the spelling again...\n");
      }
      else {
            printf("User found and removed!\n");
      }
}

void updateuserlogin() {
      int choice;
      char userda[20];
      struct userlogindata * ptr = start_user;

      printf("What do you want to update?\n");
      printf("\t1-> UserID\n");
      printf("\t2-> UserPsw\n");
      here:
      scanf("%d", &choice);

      switch (choice) {
            case 1:
                  printf("Enter previous UserID: ");
                  scanf("%s", &userda);

                  while (ptr != NULL) {
                        if(strcmp(userda, ptr -> login_name) == 0) {
                              printf("Enter New User ID: ");
                              scanf("%s", &ptr -> login_name);
                        }
                        ptr = ptr -> next;
                  }
                  
                  break;
      
            case 2:
                  printf("Enter previous UserID: ");
                  scanf("%s", &userda);

                  while (ptr != NULL) {
                        if(strcmp(userda, ptr -> login_name) == 0) {
                              printf("Enter New UserPsw: ");
                              scanf("%s", &ptr -> login_psw);
                        }
                        ptr = ptr -> next;
                  }

                  break;
            
            default:
                  printf("Enter correct choice!!!");
                  goto here;
                  break;
      }
      
}

void updateuserstatus() {
      char userda[20];
      struct userlogindata * ptr = start_user;
      
      printf("Enter UserID: ");
      scanf("%s", &userda);

      while (ptr != NULL) {
            if(strcmp(userda, ptr -> login_name) == 0) {
                  ptr -> status = 'b';
            }
            ptr = ptr -> next;
      }
}

void moniteruser() {

}

void showuser() {
      struct userlogindata * ptr;

      ptr = start_user;
      while(ptr != NULL) {
            printf("%s %s %c\n", ptr -> login_name, ptr -> login_psw, ptr -> status);
            ptr = ptr -> next;
      }
}

void freelinkedlist() {
      struct userlogindata * ptr1 = start_user, * ptr2;

      while(ptr1 != NULL) {
            ptr2 = ptr1;
            free(ptr2);
            ptr1 = ptr1 -> next;
      }
}

int supperuserlogin() {
      int inp_ans, flag = 1;

      while(flag) {
                  printf("\n\n\n");
                  printf("\t\t1. Add User\n");
                  printf("\t\t2. Delete User\n");
                  printf("\t\t3. Update User\n");
                  printf("\t\t5. Moniter User\n");
                  printf("\t\t6. Show Users\n");
                  printf("\t\t7. Return\n");
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
                              return 0;
                              break;
                        
                        default:
                              printf("Enter correct choice!!!");
                              break;
                  }
            }
}

int userlogin() {
      int X;

      printf("***********************************************************\n");
      printf("\t\t\tWelcome User\n");
      printf("***********************************************************\n");

      while(1) {
            printf("\n\n\t\tMenu:\n");
            printf("\t1. Consumer\n");
            printf("\t2. Route\n");
            printf("\t3. Return\n");

            int choice;
            scanf("%d", &choice);
            switch (choice) {
            case 1:
                  printf("\nCalled consumer....\n");
                  X = consumer();
                  break;
            case 2:
                  route();
                  break;
            case 3:
                  return 0;
            
            default:
                  printf("Enter correct input!!!");
                  break;
            }
      }
}

// main user function
int login() {
      int X;
      char inp_name[20], inp_psw[20];

      printf("*************************************************************************************************************\n");
      printf("\t\t\t\t\t\tLOGIN\n");
      printf("*************************************************************************************************************\n");

      char sup_user[] = {'s', 'u', 's', 'e', 'r', '\0'}, sup_psw[] = {'p', 'a', 's', 's', '1', '2', '3', '\0'};

      read_from_file_user();

      while(1) 
      { // never ending loop starts

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

      if(strcmp(inp_name, sup_user) == 0 && strcmp(inp_psw, sup_psw) == 0) {
            X = supperuserlogin();
            write_to_file_user();
            return 0;
      } 
      else {
            struct userlogindata * temp = start_user;
            int flag = 0;
            
            while(temp != NULL) {
                  if(strcmp(temp -> login_name, inp_name) == 0 && strcmp(temp -> login_psw, inp_psw) == 0) {
                        if(temp -> status == 'a') {
                              X = userlogin();
                              flag = 1;
                        }
                        else {
                              printf("Entered user status is deactivated! Pls contact admin.");
                              break;
                        }
                  }
                  temp = temp -> next;
            }

            if(flag == 0) {
                  printf("\nUser does not exist!!!\n");
            }

            freelinkedlist();
            return 0;
      }

      } //never ending loop ends
}