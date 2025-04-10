#include<stdio.h>

typedef struct {
    int accNum;
    char name[50];
    float balance;
} bankAccount;

void deposit(bankAccount *acc, float amount) {
    if (amount <= 0) {
        printf("Enter a valid amount to deposit.\n");
    } else {
        acc->balance += amount;
        printf("Successfully Deposited!\n");
    }
}

void withdraw(bankAccount *acc, float amount) {
    if (amount <= 0 || acc->balance < amount) {
        printf("Enter a valid amount to withdraw.\n");
    } else {
        acc->balance -= amount;
        printf("Successfully Withdrawed!\n");
    }
}

void display(bankAccount acc) {
    printf("--------------------------------------------------\n");
    printf("Account Details\n");
    printf("--------------------------------------------------\n");
    printf("%-12s|%-30s|%-15s\n", "Account No.", "Account Name", "Balance");
    printf("%-12d|%-30s|%-15.2f\n", acc.accNum, acc.name, acc.balance);
}

int main() {
    bankAccount bankAccounts[50];
    int accNumber, choice, numOfAccounts = 0, found, i;
    float amount;

    while (1) {
        printf("\nWelcome to AB Bank Digital Banking System.\n");
        printf("Menu : \n");
        printf("1. Create an Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your Choice :\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter your preferred 4 digit Account Number :\n");
                scanf("%d", &bankAccounts[numOfAccounts].accNum);
                printf("Enter Your Name :\n");
                scanf(" %[^\n]", bankAccounts[numOfAccounts].name);
                printf("Enter Your Initial Balance :\n");
                scanf("%f", &bankAccounts[numOfAccounts].balance);
                printf("Account Successfully Created!\n");
                numOfAccounts++;
                break;

            case 2:
                printf("Enter your Account Number :\n");
                scanf("%d", &accNumber);
                found = 0;
                for (i = 0; i < numOfAccounts; i++) {
                    if (bankAccounts[i].accNum == accNumber) {
                        printf("Amount to Deposit :\n");
                        scanf("%f", &amount);
                        deposit(&bankAccounts[i], amount);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("There's no Account Like That!\n");
                }
                break;

            case 3:
                printf("Enter your Account Number :\n");
                scanf("%d", &accNumber);
                found = 0;
                for (i = 0; i < numOfAccounts; i++) {
                    if (bankAccounts[i].accNum == accNumber) {
                        printf("Amount to Withdraw :\n");
                        scanf("%f", &amount);
                        withdraw(&bankAccounts[i], amount);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("There's no Account Like That!\n");
                }
                break;

            case 4:
                printf("Enter your Account Number:\n");
                scanf("%d", &accNumber);
                found = 0;
                for (i = 0; i < numOfAccounts; i++) {
                    if (bankAccounts[i].accNum == accNumber) {
                        display(bankAccounts[i]);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("There's no Account Like That!\n");
                }
                break;

            case 5:
                printf("Thank you for Banking With us.\n");
                return 0;

            default:
                printf("Enter the correct value according to the menu.\n");
        }
    }

    return 0;
}
