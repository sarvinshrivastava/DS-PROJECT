// defining customer structure
struct customerdata {
      char name[20];
      float account_balance;
      struct customerdata * next;
};

// declaring customer start point
struct customerdata * start_customer;

// defining global variables
char customerName[15];

// customer functions
void read_from_file_customer() {
      FILE *f = fopen("customerDataBase/ConsumerData.txt", "r");
      struct customerdata * ptr, * temp;
      int a = 0;

      while(feof(f) == 0) {
            ptr = (struct customerdata *)malloc(sizeof(struct customerdata));

            if(a == 0) {
                  start_customer = ptr;
                  temp = ptr;
                  a++;
            }
            else{
                  temp->next = ptr;
                  temp = ptr;
            }
            fscanf(f, "%s\t%f", &ptr -> name, &ptr -> account_balance);
            ptr -> next = NULL;
      }

      temp = start_customer;
      while(temp -> next != ptr)
            temp = temp -> next;
      temp->next = NULL;
      free(ptr);

      fclose(f);
}

void addcustomer() {
      struct customerdata * ptr = start_customer, * pt;
      pt = (struct customerdata *)malloc(sizeof(struct customerdata));

      while (ptr -> next != NULL) {
            ptr = ptr -> next;
      }

      printf("Enter the name: ");
      scanf("%s", &pt -> name);
      strcpy(customerName, ptr -> name);
      pt -> account_balance = NEW_ACCOUNT_BALANCE;
      pt -> next = NULL;
      ptr -> next = pt;
}

void removecustomer() {
      struct customerdata * ptr = start_customer, * temp;
      char username[20];
      int flag = 0;

      printf("Enter the name of customer to be removed: ");
      scanf("%s", &username);
      strcpy(customerName, username);

      temp = ptr;
      while(temp != NULL) {
            if(strcmp(temp -> name, username) == 0) {
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

void showcustomerbalance() {
      struct customerdata * temp;
      char username[20], choice[2], str[2] = {'y', '\0'};
      int flag = 0;
      float amt;

      here:
      printf("Enter the name of customer: ");
      scanf("%s", &username);
      strcpy(customerName, username);

      temp = start_customer;
      while(temp != NULL) {
            if(strcmp(temp -> name, username) == 0) {
                  flag = 1;
                  break;
            }
            temp = temp -> next;
      }

      if(flag == 0) {
            printf("Consumer not found! Please check the spelling again...\n");
            goto here;
      }
      else {
            printf("Card balance of customer is %f\n", temp -> account_balance);
            printf("Do you want to recharge it? y/n\n");
            scanf("%s", &choice);

            if(strcmp(choice, str) == 0) {
                  printf("Enter the amount for recharge");
                  scanf("%f", &amt);
                  temp -> account_balance += amt;
            }
      }
}

void write_to_file_customer() {
      FILE *f = fopen("customerDataBase/ConsumerData.txt", "w");
      struct customerdata * ptr, * temp;

      ptr = start_customer;
      temp = ptr;
      while(ptr != NULL) {
            fprintf(f, "%s\t%f\n", ptr -> name, ptr -> account_balance);
            ptr = ptr -> next;
            free(temp);
            temp = ptr;
      }
      start_customer = NULL;

      fclose(f);
}

void write_to_file_log(char functioncalled[]) {
      FILE *f = fopen("userLogs/Logs.txt", "a");

      struct tm* local;
      time_t t = time(NULL);

      // Get the localtime
      local = localtime(&t);

      fprintf(f,"%s -> %s  %s  %s\n", asctime(local), inp_name, functioncalled, customerName);

      fclose(f);
}


// main customer function
int customer() {
      int inp_ans;

      printf("\n");
      printf("*************************************************************************************************************\n");
      printf("\t\t\t\t\t\tCONSUMER PAGE\n");
      printf("*************************************************************************************************************\n");

      read_from_file_customer();

      while(1) 
      { // never ending loop starts
            printf("\n\n\n");
            printf("\t\t1. Add Consumer\n");
            printf("\t\t2. Delete Consumer\n");
            printf("\t\t3. Show Consumer Card Balance\n");
            printf("\t\t4. Return\n");
            printf("\n\n\n");

            scanf("%d", &inp_ans);
            switch (inp_ans) {
                  case 1:
                        addcustomer();
                        write_to_file_log("add user\0");
                        break;
                  case 2:
                        removecustomer();
                        write_to_file_log("remove user\0");
                        break;
                  case 3:
                        showcustomerbalance();
                        write_to_file_log("show user\0");
                  case 4:
                        write_to_file_customer();
                        return 0;
                        
                  default:
                        printf("Enter correct choice!!!");
                        break;
            }
      } //never ending loop ends
}