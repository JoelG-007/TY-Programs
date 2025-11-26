/*
a)  Create the following GUI screen using appropriate layout managers. Accept the name, 
    class , hobbies of the user and apply the changes and display the selected options in a 
    text box.
    Refer page 68
*/

import java.awt.*;
import java.awt.event.*;

public class UserForm extends Frame implements ActionListener{
    TextField nameField, classField;
    Checkbox c1, c2, c3;
    Choice fontChoice;
    TextArea output;
    Button submit;

    UserForm(){
        setTitle("User Info Form");
        setLayout(new FlowLayout());

        add(new Label("Name:"));
        nameField = new TextField(15);
        add(nameField);

        add(new Label("Class:"));
        classField = new TextField(10);
        add(classField);

        add(new Label("Hobbies:"));
        c1 = new Checkbox("Reading");
        c2 = new Checkbox("Gaming");
        c3 = new Checkbox("Music");
        add(c1); add(c2); add(c3);

        fontChoice = new Choice();
        fontChoice.add("Arial");
        fontChoice.add("Times New Roman");
        fontChoice.add("Courier New");
        add(fontChoice);

        submit = new Button("Apply");
        submit.addActionListener(this);
        add(submit);

        output = new TextArea(5, 30);
        add(output);

        setSize(400, 300);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e){
        String name = nameField.getText();
        String cls = classField.getText();
        String hobbies = "";
        if (c1.getState()) hobbies += "Reading ";
        if (c2.getState()) hobbies += "Gaming ";
        if (c3.getState()) hobbies += "Music ";

        output.setText("Name: " + name + "\nClass: " + cls +
                       "\nHobbies: " + hobbies +
                       "\nFont: " + fontChoice.getSelectedItem());
    }

    public static void main(String[] args){
        new UserForm();
    }
}