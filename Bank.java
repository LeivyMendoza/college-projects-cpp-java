/*--------------------------------------------------------------------

Name:  Leivy Mendoza

 Student ID: 1001100556

 COP 2800 - Java Programming 

 Spring 2018 - T Th 6:15PM - 9:30PM

 Project # 4

 Plagiarism Statement

 I certify that this assignment is my own work and that I
 have not copied in part or whole or otherwise plagiarized 
 the work of other students and/or persons.

1234567890123456789012345678901234567890123456789012345678901234567890
--------------------------------------------------------------------*/
package testbankaccount;

import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.Scanner;

/**
 *
 * @author Leivy Mendoza
 */
public class Bank {

    ArrayList<BankAccount> bankAccounts = new ArrayList<>();

    public ArrayList<BankAccount> getBankAccounts() {
        return bankAccounts;
    }

    public void openAccount() {
        int accountType = 0;
        String inputName;
        int initDeposit;
        boolean continueInput = true;
        Scanner input = new Scanner(System.in);
        Scanner input1 = new Scanner(System.in);

        System.out.println("Which type of account would you like to open?");
        System.out.println("1) Regular 2) Savings 3) Current");

        do {
            try {
                accountType = input.nextInt();
                continueInput = false;
            } catch (InputMismatchException ex) {
                System.out.println("Sorry incorrect input. Please enter a number");
                input.nextLine();
            }
        } while (continueInput);

        switch (accountType) {
            case 1: {
                System.out.println("Please enter your name");
                inputName = input1.nextLine();

                System.out.println("Please enter your initial deposit");
                initDeposit = input.nextInt();
                BankAccount regularAccount = new BankAccount(inputName, initDeposit);
                System.out.println("Your Account ID is " + regularAccount.getAccountId());
                System.out.println("Your Password is " + regularAccount.getPassword() + "\n");
                bankAccounts.add(regularAccount);
                break;
            }
            case 2: {
                System.out.println("Please enter your name");
                inputName = input1.nextLine();
                System.out.println("Please enter your initial deposit");
                initDeposit = input.nextInt();
                SavingsAccount savingsAccount = new SavingsAccount(inputName, initDeposit);
                System.out.println("Your Account ID is " + savingsAccount.getAccountId());
                System.out.println("Your Password is " + savingsAccount.getPassword() + "\n");
                bankAccounts.add(savingsAccount);
                break;
            }
            case 3: {
                System.out.println("Please enter your name");
                inputName = input1.nextLine();
                System.out.println("Please enter your initial deposit");
                initDeposit = input.nextInt();
                CurrentAccount currentAccount = new CurrentAccount(inputName, initDeposit);
                System.out.println("Your Account ID is " + currentAccount.getAccountId());
                System.out.println("Your Password is " + currentAccount.getPassword() + "\n");
                bankAccounts.add(currentAccount);
                break;
            }
        }
    }

    public void closeAccount(String accountID, String name) {
        for (BankAccount account : bankAccounts) {

            if (account.getAccountId().equals(accountID) && account.getName().equals(name)) {
                bankAccounts.remove(account);
                System.out.println("Account has been closed\n");
                return;
            }
        }
        System.out.println("Could not locate the account\n");
    }

    public void updateBankAccounts() {
        bankAccounts.forEach((account) -> {
            if (account instanceof SavingsAccount) {
                ((SavingsAccount) account).addInterest();
            } else if (account instanceof CurrentAccount) {
                if (account.getAccountBalance() < 0) {
                    System.out.println("Your account is overdrawn by " + ((CurrentAccount) account).getOverdraftLimit());
                }

            }
        });
    }

    public void deposit() {
        String accountID;
        String password;
        int depositAmount = 0;
        boolean continueInput = true;
        Scanner input = new Scanner(System.in);
        Scanner input1 = new Scanner(System.in);
        Scanner input2 = new Scanner(System.in);

        System.out.println("Enter how much do you wish to deposit?");
        
        do {
            try {
                depositAmount = input.nextInt();
                continueInput = false;
            } catch (InputMismatchException ex) {
                System.out.println("Sorry incorrect input. Please enter a number");
                input.nextLine();
            }
        } while (continueInput);
        
        

        System.out.println("Please enter your Account ID");
        accountID = Integer.toString(input1.nextInt());

        System.out.println("Please enter your password");
        password = input2.nextLine();

        for (BankAccount account : bankAccounts) {
            if (account.getAccountId().equals(accountID) && account.getPassword().equals(password)) {

                account.setAccountBalance(account.getAccountBalance() + depositAmount);
                System.out.println("Your deposit has been successfully completed\n");
                return;
            }
        }
        System.out.println("Could not locate the account\n");
    }

    public void withdraw() {
        String accountID;
        String password;
        int withdrawAmount = 0;
        boolean continueInput = true;
        Scanner input = new Scanner(System.in);
        Scanner input1 = new Scanner(System.in);
        Scanner input2 = new Scanner(System.in);

        System.out.println("Enter how much do you wish to withdraw?");
        
        do {
            try {
                withdrawAmount = input.nextInt();
                continueInput = false;
            } catch (InputMismatchException ex) {
                System.out.println("Sorry incorrect input. Please enter a number");
                input.nextLine();
            }
        } while (continueInput);
        
        

        System.out.println("Please enter your Account ID");
        accountID = Integer.toString(input1.nextInt());

        System.out.println("Please enter your password");
        password = input2.nextLine();

        for (BankAccount account : bankAccounts) {
            if (account.getAccountId().equals(accountID) && account.getPassword().equals(password)) {
                if (account.getAccountBalance() - withdrawAmount > 0) {
                    account.setAccountBalance(account.getAccountBalance() - withdrawAmount);
                    System.out.println("Please take your cash\n");
                    return;
                } else {
                    System.out.println("Insufficient Funds\n");
                    return;
                }
            }
        }
        System.out.println("Could not locate the account\n");
    }

    public void printBankAccountDetails() {
        String accountID;
        String password;
        String accountType;
        Scanner input = new Scanner(System.in);
        Scanner input1 = new Scanner(System.in);

        System.out.println("Please enter your Account ID");
        accountID = Integer.toString(input.nextInt());

        System.out.println("Please enter your password");
        password = input1.nextLine();

        for (BankAccount account : bankAccounts) {
            if (account.getAccountId().equals(accountID) && account.getPassword().equals(password)) {

                if (account instanceof SavingsAccount) {
                    accountType = "Savings Account";
                } else if (account instanceof CurrentAccount) {
                    accountType = "Current Account";
                } else {
                    accountType = "Regular Account";
                }

                System.out.println("Bank Account Details");
                System.out.println("---------------------");
                System.out.println("Name: " + account.getName());
                System.out.println("Account Type: " + accountType);
                System.out.println("Account ID: " + account.getAccountId());
                System.out.println("Balance: $" + account.getAccountBalance());
                System.out.println("Monthly Interest: " + account.getMonthlyInterestRate() + "%");
                System.out.println("Created On: " + account.getDateCreated() + "\n");
                return;
            }
        }
        System.out.println("Could not locate the account\n");

    }

    public void menu() {
        int userInput = 0;
        String ifExit;
        boolean exit = false;
        boolean continueInput = true;

        do {
            System.out.println("Please Choose an Action");
            System.out.println("---------------------");
            System.out.println("1-\t Create a New Account");
            System.out.println("2-\t Deposit");
            System.out.println("3-\t Withdraw");
            System.out.println("4-\t Display Balance");
            System.out.println("5-\t Exit");

            Scanner input = new Scanner(System.in);

            do {
                try {
                    userInput = input.nextInt();
                    continueInput = false;
                } catch (InputMismatchException ex) {
                    System.out.println("Sorry incorrect input. Please enter a number");
                    input.nextLine();
                }
            } while (continueInput);

            

            switch (userInput) {
                case 1: {
                    openAccount();
                    break;
                }
                case 2: {
                    deposit();
                    break;
                }
                case 3: {
                    withdraw();
                    break;
                }
                case 4: {
                    printBankAccountDetails();
                    break;
                }
                case 5: {
                    System.out.println("Do you want to exit?");
                    Scanner input1 = new Scanner(System.in);
                    ifExit = input1.nextLine();
                    if ("YES".equals(ifExit) || "yes".equals(ifExit)) {
                        exit = true;
                    }
                    break;
                }
            }
            updateBankAccounts();
        } while (!exit);
    }

}
