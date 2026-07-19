#include <stdio.h>
#include <stdlib.h>

int pin = 1234;
float balance = 10000.0;

int login();
void atmMenu();

int main()
{
    int choice;

    while(1)
    {
        printf("\n=============================\n");
        printf("      ATM MANAGEMENT\n");
        printf("=============================\n");
        printf("1. Login\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                if(login())
                    atmMenu();
                break;

            case 2:
                printf("\nThank you for using our ATM!\n");
                exit(0);

            default:
                printf("\nInvalid Choice!\n");
        }
    }

    return 0;
}

int login()
{
    int enteredPin;

    printf("\nEnter PIN: ");
    scanf("%d", &enteredPin);

    if(enteredPin == pin)
    {
        printf("\nLogin Successful!\n");
        return 1;
    }
    else
    {
        printf("\nIncorrect PIN!\n");
        return 0;
    }
}

void atmMenu()
{
    int choice;
    float amount;
    int newPin;

    while(1)
    {
        printf("\n========== ATM MENU ==========\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Change PIN\n");
        printf("5. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("\nCurrent Balance: Rs %.2f\n", balance);
                break;

            case 2:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);

                if(amount > 0)
                {
                    balance= balance + amount;
                    printf("Deposit Successful!\n");
                }
                else
                {
                    printf("Invalid Amount!\n");
                }
                break;

            case 3:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);

                if(amount <= balance && amount > 0)
                {
                    balance = balance - amount;
                    printf("Withdrawal Successful!\n");
                }
                else
                {
                    printf("Insufficient Balance or Invalid Amount!\n");
                }
                break;

            case 4:
                printf("Enter New 4-digit PIN: ");
                scanf("%d", &newPin);

                pin = newPin;

                printf("PIN Changed Successfully!\n");
                break;

            case 5:
                printf("Logged Out Successfully!\n");
                return;

            default:
                printf("Invalid Choice!\n");
        }
    }
}