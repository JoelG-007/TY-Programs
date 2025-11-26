/*
b)  Write a Java program to design a screen using Awt that will take a user name and 
    password. If the user name and password are not same, raise an Exception with 
    appropriate message. User can have 3 login chances only. Use clear button to clear 
    the TextFields. 
*/

import java.awt.*;
import java.awt.event.*;

class InvalidLoginException extends Exception{
    InvalidLoginException(String msg){
        super(msg);
    }
}

public class LoginScreen extends Frame implements ActionListener{
    TextField userField, passField;
    Button loginBtn, clearBtn;
    Label msg;
    int attempts = 0;

    LoginScreen(){
        setTitle("Login Form");
        setLayout(new GridLayout(4, 2, 5, 5));

        add(new Label("Username:"));
        userField = new TextField(15);
        add(userField);

        add(new Label("Password:"));
        passField = new TextField(15);
        passField.setEchoChar('*');
        add(passField);

        loginBtn = new Button("Login");
        clearBtn = new Button("Clear");
        add(loginBtn);
        add(clearBtn);

        msg = new Label("");
        add(msg);

        loginBtn.addActionListener(this);
        clearBtn.addActionListener(this);

        setSize(300, 200);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e){
        if(e.getSource() == loginBtn){
            try{
                String user = userField.getText();
                String pass = passField.getText();
                if (!user.equals(pass)){
                    attempts++;
                    throw new InvalidLoginException("Invalid username or password");
                }
                msg.setText("Login Successful!");
            } catch (InvalidLoginException ex) {
                msg.setText(ex.getMessage() + " (" + attempts + "/3)");
                if (attempts >= 3) {
                    msg.setText("3 Attempts Over! Access Denied.");
                    loginBtn.setEnabled(false);
                }
            }
        }else if(e.getSource() == clearBtn){
            userField.setText("");
            passField.setText("");
            msg.setText("");
        }
    }

    public static void main(String[] args){
        new LoginScreen();
    }
}
