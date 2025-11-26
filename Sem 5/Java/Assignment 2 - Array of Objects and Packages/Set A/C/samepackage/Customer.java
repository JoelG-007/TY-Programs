package samepackage;

public class Customer{
    public String name = "PublicName";
    private String accountNumber = "PrivateAccount123";
    protected String email = "customer@example.com";
    String phone = "9999999999"; // default

    public void showData() {
        System.out.println("Public Name: " + name);
        System.out.println("Private Account: " + accountNumber);
        System.out.println("Protected Email: " + email);
        System.out.println("Default Phone: " + phone);
    }
}
