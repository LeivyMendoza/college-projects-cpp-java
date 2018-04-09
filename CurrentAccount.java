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

/**
 *
 * @author Leivy Mendoza
 */
public class CurrentAccount extends BankAccount {

    private double overdraftLimit;

    public CurrentAccount(String name, double balance) {
        super(name, balance);
    }

    public void setOverdraftLimit(double limit) {
        overdraftLimit = limit;
    }

    public double getOverdraftLimit() {
        return overdraftLimit;
    }

    @Override
    public void withdraw(double amount) {
        if (getAccountBalance() + overdraftLimit < amount) {
            System.out.print("Sorry insufficient funds");
        } else {
            super.withdraw(amount);
        }
    }
}
