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

import java.security.SecureRandom;
import java.text.SimpleDateFormat;
import java.util.Date;

public class BankAccount {

    private String name;
    private String accountId;
    private String password;
    private double accountBalance;
    private double annualInterestRate;
    private String Date;

    BankAccount() {
        this("", 0);
    }

    BankAccount(String name, double defaultAccountBalance) {
        SecureRandom random = new SecureRandom();

        this.name = name;
        accountBalance = defaultAccountBalance;
        password = generatePassword();
        accountId = Integer.toString(random.nextInt(9000) + 1000);
        annualInterestRate = 4.5;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getPassword() {
        return password;
    }

    public void setAccountBalance(double accountBalance) {
        this.accountBalance = accountBalance;
    }

    public double getAccountBalance() {
        return accountBalance;
    }

    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }

    public double getAnnualInterestRate() {
        return annualInterestRate;
    }

    public String getDateCreated() {
        Date date = new Date();
        SimpleDateFormat newFormat = new SimpleDateFormat("MM/DD/YYYY");
        String monthDayYear = newFormat.format(date);
        return monthDayYear;
    }

    public String getAccountId() {
        return accountId;
    }

    public double getMonthlyInterestRate() {
        return ((this.annualInterestRate / 12));
    }

    public void withdraw(double withdrawAmount) {
        accountBalance -= withdrawAmount;
    }

    public void deposit(double depositAmount) {
        accountBalance += depositAmount;
    }

    public String generatePassword() {
        String letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        StringBuilder tempPassword = new StringBuilder();
        SecureRandom random = new SecureRandom();
        while (tempPassword.length() < 4) { 
            int index = random.nextInt(letters.length());
            tempPassword.append(letters.charAt(index));
        }
        String password1 = tempPassword.toString();
        return password1;
    }
}
