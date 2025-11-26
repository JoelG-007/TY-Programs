/*
a)  Write a java program that works as a simple calculator. Use a grid layout to arrange 
    buttons for the digits and for the +, -, *, % operations. Add a text field to display the 
    result.
    Refer page 68  
*/

import java.awt.*;
import java.awt.event.*;

public class SimpleCalculator extends Frame implements ActionListener{
    TextField tf;
    String operator = "";
    double num1 = 0, num2 = 0, result = 0;

    SimpleCalculator(){
        setTitle("Simple Calculator");
        setLayout(new BorderLayout());

        tf = new TextField();
        add(tf, BorderLayout.NORTH);

        Panel p = new Panel();
        p.setLayout(new GridLayout(4, 4, 5, 5));

        String buttons[] = { "1", "2", "3", "+",
                             "4", "5", "6", "-",
                             "7", "8", "9", "*",
                             "0", ".", "=", "/" };

        for(String text : buttons){
            Button b = new Button(text);
            b.addActionListener(this);
            p.add(b);
        }

        add(p, BorderLayout.CENTER);

        setSize(250, 300);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e) {
        String s = e.getActionCommand();

        if(s.charAt(0) >= '0' && s.charAt(0) <= '9' || s.equals(".")){
            tf.setText(tf.getText() + s);
        }else if (s.equals("+") || s.equals("-") || s.equals("*") || s.equals("/") || s.equals("%")) {
            num1 = Double.parseDouble(tf.getText());
            operator = s;
            tf.setText("");
        }else if (s.equals("=")){
            num2 = Double.parseDouble(tf.getText());
            switch (operator) {
                case "+": result = num1 + num2; break;
                case "-": result = num1 - num2; break;
                case "*": result = num1 * num2; break;
                case "/": result = num1 / num2; break;
                case "%": result = num1 % num2; break;
            }
            tf.setText(String.valueOf(result));
        }
    }

    public static void main(String[] args){
        new SimpleCalculator();
    }
}
