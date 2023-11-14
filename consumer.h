// defining consumer structure
struct consumerdata {
      char name[20];
      float account_balance;
      struct consumerdata * next;
};

struct consumerdata * start_consumer;

// consumer functions
void read_from_file_consumer() {
      FILE *f = fopen("consumerDataBase/ConsumerData.txt", "r");
      struct consumerdata * ptr, * temp;
      int a = 0;

      while(feof(f) == 0) {
            ptr = (struct consumerdata *)malloc(sizeof(struct consumerdata));

            if(a == 0) {
                  start_consumer = ptr;
                  temp = ptr;
                  a++;
            }
            else{
                  temp->next = ptr;
                  temp = ptr;
            }
            fscanf(f, "%s %f", &ptr -> name, &ptr -> account_balance);
            ptr -> next = NULL;
      }

      temp = start_consumer;
      while(temp -> next != ptr)
            temp = temp -> next;
      temp->next = NULL;
      free(ptr);

      fclose(f);
}

void addconsumer() {
      struct consumerdata * ptr = start_consumer, * pt;
      pt = (struct consumerdata *)malloc(sizeof(struct consumerdata));

      while (ptr -> next != NULL) {
            ptr = ptr -> next;
      }

      printf("Enter the name: ");
      scanf("%s", &pt -> name);
      pt -> account_balance = NEW_ACCOUNT_BALANCE;
      pt -> next = NULL;
      ptr -> next = pt;
}

void removeconsumer() {
      struct consumerdata * ptr = start_consumer, * temp;
      char username[20];
      int flag = 0;

      printf("Enter the name of consumer to be removed: ");
      scanf("%s", &username);

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

void showconsumerbalance() {
      struct consumerdata * temp;
      char username[20], choice;
      int flag = 0;
      float amt;

      printf("Enter the name of consumer: ");
      scanf("%s", &username);

      temp = start_consumer;
      while(temp != NULL) {
            if(strcmp(temp -> name, username) == 0) {
                  flag = 1;
                  break;
            }
            temp = temp -> next;
      }

      if(flag == 0) {
            printf("Consumer not found! Please check the spelling again...\n");
      }
      else {
            printf("Card balance of consumer is %d\n", temp -> account_balance);
            printf("Do you want to recharge it? y/n\n");
            scanf("%c", &choice);
            if(choice == 'y') {
                  printf("Enter the amount for recharge");
                  scanf("%d", &amt);
                  temp -> account_balance += amt;
            }
      }
}

void write_to_file_consumer() {
      FILE *f = fopen("consumerDataBase/ConsumerData.txt", "w");
      struct consumerdata * ptr, * temp;

      ptr = start_consumer;
      temp = start_consumer;
      while(ptr != NULL) {
            fprintf(f, "%s  %d\n", ptr -> name, ptr -> account_balance);
            ptr = ptr -> next;
            free(temp);
            temp = ptr;
      }

      fclose(f);
}


// main consumer function
int consumer() {
      int inp_ans;

      printf("*************************************************************************************************************\n");
      printf("\t\t\t\t\t\tCONSUMER PAGE\n");
      printf("*************************************************************************************************************\n");

      read_from_file_consumer();

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
                        addconsumer();
                        break;
                  case 2:
                        removeconsumer();
                        break;
                  case 3:
                        showconsumerbalance();
                  case 4:
                        write_to_file_consumer();
                        return 0;
                        
                  default:
                        printf("Enter correct choice!!!");
                        break;
            }
      } //never ending loop ends
}