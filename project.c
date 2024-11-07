#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple account number generation
    printf("Enter account holder name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;
    
    accounts[accountCount] = newAccount;
    accountCount++;
    
    printf("Account created successfully. Your account number is %d.\n", newAccount.accountNumber);
}

void deposit() {
    int accountNumber;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    accounts[accountNumber - 1].balance += amount;
    printf("Amount deposited successfully. New balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void withdraw() {
    int accountNumber;
    float amount;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    if (amount > accounts[accountNumber - 1].balance) {
        printf("Insufficient balance.\n");
    } else {
        accounts[accountNumber - 1].balance -= amount;
        printf("Amount withdrawn successfully. New balance: %.2f\n", accounts[accountNumber - 1].balance);
    }
}

void checkBalance() {
    int accountNumber;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Account holder: %s\n", accounts[accountNumber - 1].name);
    printf("Current balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void displayMenu() {
    printf("\nBanking Management System\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Check Balance\n");
    printf("5. Exit\n");
}

int main() {
    int choice;
    
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
		
        
        switch (choice) {
            case 1:
            	system("cls");
                createAccount();
                break;
            case 2:
			system("cls");
                deposit();
                break;
            case 3:
            	system("cls");
                withdraw();
                break;
            case 4:
            	system("cls");
                checkBalance();
                break;
            case 5:
            	system("cls");
                printf("Exiting the system. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}
