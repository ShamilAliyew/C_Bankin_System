#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_NAME_LENGTH 20
#define MAX_SURNAME_LENGTH 20
#define MAX_GMAIL_LENGTH 50
#define MAX_PASSWORD_LENGTH 20
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_CARD_NUMBER_LENGTH 16
#define FILE_NAME "Data.txt"
float balance=0.0;

void clearScreen() {
    #ifdef _WIN32
       system("cls");
    #else
        system("clear");
    #endif
}



struct Account {

    char UserName[MAX_USERNAME_LENGTH];
    char Name[MAX_NAME_LENGTH];
    char Surname[MAX_SURNAME_LENGTH];
    char Gmail[MAX_GMAIL_LENGTH];
    char Password[MAX_PASSWORD_LENGTH];
    char PhoneNumber[MAX_PHONE_NUMBER_LENGTH];
    char CardNumber[MAX_CARD_NUMBER_LENGTH];

};




int login(const char *username, const char *password) {
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("Error opening file!\n");
        return 0;
    }

    struct Account account;
    while (fscanf(file, "%s %s %s %s %s %s %s",account.UserName, account.Name, account.Surname, account.Gmail, account.Password, account.PhoneNumber, account.CardNumber) != EOF) {
        if (strcmp(account.UserName, username) == 0 &&
            strcmp(account.Password, password) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}








void displayBanner(const char *message) {
      printf("\n\n                                  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,187);
    printf("\n                                  %c                                             %c",186,186);
    printf("\n                                  %c          WELCOME TO OUR BANK                %c",186,186);
    printf("\n                                  %c                                             %c",186,186);
    printf("\n                                  %c                                             %c",186,186);
    printf("\n                                  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,205,188);

}





void switchScreen() {
    displayBanner("WELCOME TO OUR BANK");
    printf("\n\n                                               <<< TRANSITION >>>");
    printf("\n\n                                            1. REGISTER        2. LOGIN");
    printf("\n\n                                         Please Select The Transition...");
}



/*void checkUsername(const char *username){
    FILE *file=fopen(FILE_NAME,"r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    struct Account newAccount;
    while (fscanf(file, "%s %s %s %s %s %s %s",newAccount.UserName, newAccount.Name, newAccount.Surname, newAccount.Gmail, newAccount.Password, newAccount.PhoneNumber, newAccount.CardNumber) != EOF) {
        if (strcmp(newAccount.UserName, username) == 0 ){
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;

    }*/





void createAccount() {
     printf("\n\n<<< CREATE ACCOUNT >>>\n");

    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    struct Account newAccount;

    printf("\nEnter Your Username: ");
    scanf("%s", newAccount.UserName);
   //  checkUsername(newAccount.UserName);


    printf("\nEnter Your Name: ");
    scanf("%s", newAccount.Name);

    printf("Enter Your Surname: ");
    scanf("%s", newAccount.Surname);

    printf("Enter Your Gmail Address: ");
    scanf("%s", newAccount.Gmail);

    printf("Enter Your Password: ");
    scanf("%s", newAccount.Password);

    printf("Enter Your Card Number(16 digits): ");
    scanf("%s", newAccount.CardNumber);
    /*fgets(newAccount.CardNumber,sizeof(newAccount.CardNumber),stdin);

    size_t len=strlen(newAccount.CardNumber);
    if(len==16){
        printf("You Entered Suitable Card Number %s",newAccount.CardNumber);
    }
    else{
        printf("Invalid Card Number. It Should be 16 digits. ");
    }*/

      while (strlen(newAccount.CardNumber) != 17){

        printf("Card Number isn't correct. It should be 16 digits.\n");
        printf("Enter Your Card Number: ");
        scanf("%s",newAccount.CardNumber);

     }



    printf("Enter Your Phone Number: ");
    scanf("%s", newAccount.PhoneNumber);

    fprintf(file, "%s %s %s %s %s %s %s ",newAccount.UserName, newAccount.Name, newAccount.Surname, newAccount.Gmail, newAccount.Password, newAccount.CardNumber, newAccount.PhoneNumber );
    fclose(file);

    printf("\nAccount Successfully Created...\n");
}





int deposit(){
    printf("\n\n<<< DEPOSIT >>>\n");
    float amount;
    printf("\nEnter Your Card Number: ");
    char cardnumber[MAX_CARD_NUMBER_LENGTH];
    scanf("%s",cardnumber);
    printf("Your Balance: %.2f\n", balance);
    printf("\nEnter the amount: ");
    scanf("%f", &amount);
    balance += amount;
    clearScreen();
    printf("The balance has been successfully increased..\n\n");
    printf("Your Balance: %.2f\n", balance);
    return balance;
}




void withdraw(){
    float amount;
    printf("\n\n<<< DEPOSIT >>>\n");
    printf("Your Current Balance: %.2f",balance);
    printf("\nEnter Your Card Number: ");
    char cardnumber[MAX_CARD_NUMBER_LENGTH];
    scanf("%s",cardnumber);
    printf("Enter The Amount: ");
    scanf("%f",&amount);
    while (amount>balance){
        printf("Not Enough Balance.");
        printf("Enter The Amount: ");
        scanf("%f",&amount);
    }
    balance-=amount;
    printf("The Operation Completed\nYourBalance: %.2f",balance);
}





void listAccounts(){
    printf("\n\n                         <<< LIST ACCOUNTS  >>>\n\n");
    printf(" USERNAME          NAME          SURNAME             GMAIL                       PASSWORD          CARD NO            PHONE NO\n");
       for (int i = 0; i <127 ; i++) {
        printf("%c", 205);
    }
    printf("\n");

    FILE *file = fopen(FILE_NAME, "r");
    if (file == NULL) {
        printf("File could not be opened.\n");
        return;
    }

    char username[MAX_USERNAME_LENGTH], name[MAX_NAME_LENGTH], surname[MAX_SURNAME_LENGTH], gmail[MAX_GMAIL_LENGTH], password[MAX_PASSWORD_LENGTH], cardNo[MAX_CARD_NUMBER_LENGTH], phoneNo[MAX_PHONE_NUMBER_LENGTH];
    while (fscanf(file, "%s %s %s %s %s %s %s",username, name, surname, gmail, password, cardNo, phoneNo) != EOF) {

        printf("\n%s\t\t%s\t\t%s\t\t%s\t\t%s\t%s\t\t%s",username, name, surname, gmail, password, cardNo, phoneNo);
    }

    fclose(file);
}





void transfer() {
    char sender[MAX_CARD_NUMBER_LENGTH],receiver[MAX_CARD_NUMBER_LENGTH];
    float amount,receiverBalance=0;
    printf("\n\n\t\t\t <<< TRANSFER  >>>\n\n");
    printf("Enter The Sender Card Number: ");
    scanf("%s",sender);
    printf("\nSender Card Balance: %.2f",balance);
    printf("\nEnter The Receiver Card Number: ");
    scanf("%s",receiver);
    printf("\nEnter The Amount: ");
    scanf("%f",&amount);
    while(balance<amount){
        printf("\nNot Enough Money To Send...Please Enter Suitable Amount.");
        printf("\nEnter The Amount: ");
        scanf("%f",&amount);

    }
    receiverBalance+=amount;
    balance-=amount;
    printf("Sender Card Balance: %.2f",balance);
    printf("\nReceiver Card Balance: %.2f",receiverBalance);
}






void menu() {
     printf("\n\n                                               <<< MENU >>>\n");
    printf("   1. Create Account\n");
    printf("   2. Deposit\n");
    printf("   3. Withdraw Money\n");
    printf("   4. List Accounts\n");
    printf("   5. Transfer(Cart to Card)\n");
    printf("   6. Balance\n");
    printf("   7. Exit\n");
    printf("\n Select Operation!\n");
}





int main() {
    int transition, operation;
    clearScreen();
    switchScreen();
    scanf("%d", &transition);

    switch (transition) {
        case 1:
            clearScreen();
            createAccount();
            break;
        case 2:
            clearScreen();
            printf("\n\n                              <<< LOGIN >>>\n");
            char loginUserName[MAX_USERNAME_LENGTH],loginPassword[MAX_PASSWORD_LENGTH];
            printf("Enter Your Username: ");
            scanf("%s", loginUserName);

            printf("Enter Your Password: ");
            scanf("%s", loginPassword);

            if (login(loginUserName, loginPassword)) {
                printf("Login successful!\n");
               printf("\nPress any key to go to the menu...");
                getchar();
                getchar();

            } else {
                printf("Login failed. Please check your credentials and try again.\n");
                printf("\nPress any key to return to the back...");
                getchar();
                getchar();
                clearScreen();
                main();

            }
            break;
        default:
            printf("Invalid transition selection!\n");
            return 1;
    }

    do {
        clearScreen();
        menu();
        scanf("%d", &operation);
        switch(operation){
        case 1:
            clearScreen();
            createAccount();
            break;
        case 2:
            clearScreen();
            deposit();
            printf("\nPress any key to return to the menu...");
            getchar();
            getchar();
            clearScreen();


            break;
        case 3:
            clearScreen();
            withdraw();
            printf("\nPress any key to return to the menu...");
            getchar();
            getchar();
            clearScreen();
            break;
        case 4:
            clearScreen();
            listAccounts();
            printf("\nPress any key to return to the menu...");
            getchar();
            getchar();
            clearScreen();
            break;
        case 5:
             clearScreen();
             transfer();
             printf("\nPress any key to return to the menu...");
            getchar();
            getchar();
            clearScreen();

            break;
        case 6:
            clearScreen();
            printf("\n\n<<<  BALANCE  >>>\n");
            printf("YOUR CURRENT BALANCE: %.2f\n", balance);
            printf("\nPress any key to return to the menu...");
            getchar();
            getchar();
            clearScreen();


            break;
        case 7:
            clearScreen();
            printf("The Program is Closing...");
            printf("\nPress any key to return to the menu...");
            getchar();
            getchar();
            clearScreen();
            break;
        default:
            printf("Invalid Operation Selection. Please select correct operartion.");
}

    } while (operation !=10);

    return 0;
}


