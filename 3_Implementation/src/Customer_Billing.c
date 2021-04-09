 #include<stdio.h>
 #include <string.h>
 #include<stdlib.h>
 void input();
 void search(int act_no);
 void addBill(int act_no);
 void printAll();
 void addBalance(int act_no);
  struct account {
	char name[100];
	int acct_no;
	long mobile_no;
	char city[100];
	float balance;
  }customer[1000];
int cust_count = 0,act_no = 0;
int i = 0;
char ch, decision;
void main(){
	    printf("   CUSTOMER BILLING SYSTEM:\n\n");
	    printf("===============================\n");
	    printf("\n1:    to add account on list\n");
	    printf("2:    to search customer account\n");
        printf("3:  TO pay a bill\n");
        printf("4: to print info of all customers\n");
        printf("5: Add balance\n");
        printf("6: exit\n");
	    printf("\n================================\n");
        printf("\nselect what do you want to do?\n");
	    scanf("%c", &ch);
        switch(ch){
            case '1':
                cust_count += 1;
                printf("%d", cust_count);
                input(i);
                i += 1;
                break;
            case '2':
                printf("Please enter the account number\n");
                scanf("%d", &act_no);
                search(act_no);
                break;
            case '3':
                printf("PLease enter the eccaount no");
                scanf("%d", &act_no);
                addBill(act_no);
                break;
            case '4':
                printAll();
                break;
            case '5':
                printf("Please enter account no\n");
                scanf("%d", &act_no);
                addBalance(act_no);
                break;
            case '6':
                exit(0);
            default:
                break;
        } 
        printf("Do you want ot do anything else?\n");
        scanf("%c", &decision);
        if(decision == 'Y'){
            main();
        } else {
            printf("Thank you!!");
        }
      return;
 }
      void input(int ind){
          customer[ind].acct_no = 1001;
          printf("Enther the name of the customer\n");
          scanf("%s", customer[ind].name);
          printf("mobile no.\n");
          scanf("%ld", &customer[ind].mobile_no);
          printf("city\n");
          scanf("%s", customer[ind].city);
          printf("Hoe much balance you want to maintain\n");
          scanf("%f", &customer[ind].balance);
          return;
      }
      void search(int act_no){
          for(int i = 0; i < cust_count; i++){
              if(customer[i].acct_no == act_no){
                  printf("Customer name: %s\n", customer[i].name);
                  printf("Customer mobile number: %ld\n", customer[i].mobile_no);
                  printf("customer city name: %s\n", customer[i].city);
                  printf("customer old bill amount %.2f\n", customer[i].balance);
              }
          }
          return;
      }
      void addBill(int act_no){
          float amount = 0;
          printf("Enter the bill amount: ");
          scanf("%f", &amount);
          for(int i = 0; i < cust_count; i++){
              if (customer[i].acct_no == act_no){
                  if (customer[i].balance >= amount){
                      customer[i].balance -= amount;
                  } else {
                      printf("please add balance\n");
                      addBalance(act_no);
                  }
              }
          }
          return;
      }
      void addBalance(int act_no){
          float amount = 0;
          printf("Enter the amount you want to add\n");
          scanf("%f", &amount);
          for(int i =0; i < cust_count; i++){
              if (customer[i].acct_no == act_no){
                  customer[i].balance += amount;
              }
          }
          return;
      }
      void printAll(){
          for(int i =0; i  <cust_count; i++){
              printf("CUSTOMER %d", (i+1));
              printf("\t customer name: %s\n", customer[i].name);
              printf("\t customer mobile: %d\n", customer[i].mobile_no);
          }
          return;
      }
