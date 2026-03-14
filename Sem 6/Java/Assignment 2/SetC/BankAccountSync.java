class BankAccount{
    private double balance;

    BankAccount(double balance){
        this.balance = balance;
    }

    public synchronized void deposit(String name, double amount){
        balance += amount;
        System.out.println(name + " deposited " + amount + " | Balance: " + balance);
    }

    public synchronized void withdraw(String name, double amount){
        if(balance >= amount){
            balance -= amount;
            System.out.println(name + " withdrew " + amount + " | Balance: " + balance);
        } else{
            System.out.println(name + " - Insufficient balance");
        }
    }
}

class BankThread extends Thread{
    BankAccount account;
    String type;
    double amount;

    BankThread(BankAccount account, String name, String type, double amount){
        setName(name);
        this.account = account;
        this.type = type;
        this.amount = amount;
    }

    public void run(){
        if(type.equals("deposit"))
            account.deposit(getName(), amount);
        else
            account.withdraw(getName(), amount);
    }
}

public class BankAccountSync{
    public static void main(String[] args){
        BankAccount account = new BankAccount(1000);

        new BankThread(account, "User-1", "deposit", 500).start();
        new BankThread(account, "User-2", "withdraw", 300).start();
        new BankThread(account, "User-3", "withdraw", 800).start();
        new BankThread(account, "User-4", "deposit", 200).start();
    }
}
