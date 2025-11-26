/*
b)  Define class EmailId with members ,username and password. Define default and 
    parameterized constructors. Accept values from the command line Throw user 
    defined exceptions – “InvalidUsernameException” or “InvalidPasswordException” if 
    the username and password are invalid.
*/

class InvalidUsernameException extends Exception{
    InvalidUsernameException(String msg){
        super(msg);
    }
}

class InvalidPasswordException extends Exception{
    InvalidPasswordException(String msg){
        super(msg);
    }
}
class EmailId{
    String username;
    String password;
    EmailId(String username, String password) throws InvalidUsernameException, InvalidPasswordException{
        if(!username.contains("@") || !username.contains(".")){
            throw new InvalidUsernameException("Invalid Username: must contain '@' and '.'");
        }
        if(password.length() < 6){
            throw new InvalidPasswordException("Invalid Password: must be at least 6 characters");
        }
        this.username = username;
        this.password = password;
    }
    void display(){
        System.out.println("Email Username: " + username);
        System.out.println("Password: " + password);
    }
}

public class EmailExceptionDemo{
    public static void main(String[] args){
        try {
            if(args.length < 2){
                System.out.println("Usage: java EmailExceptionDemo <username> <password>");
                return;
            }
            String user = args[0];
            String pass = args[1];
            EmailId email = new EmailId(user, pass);
            System.out.println("✅ Email ID created successfully!");
            email.display();
        }catch (InvalidUsernameException | InvalidPasswordException e){
            System.out.println(e.getMessage());
        }
    }
}

// java EmailExceptionDemo mymail@gmail.com secret123