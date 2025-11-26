/*
b)  Design a screen to handle the Mouse Events such as MOUSE_MOVED and 
    MOUSE_CLICK and display the position of the Mouse_Click in a TextField.
*/

import java.awt.*;
import java.awt.event.*;

public class MouseEventDemo extends Frame implements MouseListener, MouseMotionListener{
    TextField tf;

    MouseEventDemo(){
        setLayout(new FlowLayout());
        tf = new TextField(30);
        add(new Label("Click or Move Mouse"));
        add(tf);

        addMouseListener(this);
        addMouseMotionListener(this);

        setSize(400, 200);
        setVisible(true);
    }

    public void mouseClicked(MouseEvent e){
        tf.setText("Mouse Clicked at: " + e.getX() + ", " + e.getY());
    }
    public void mouseMoved(MouseEvent e){
        tf.setText("Mouse Moved at: " + e.getX() + ", " + e.getY());
    }

    public void mousePressed(MouseEvent e){}
    public void mouseReleased(MouseEvent e){}
    public void mouseEntered(MouseEvent e){}
    public void mouseExited(MouseEvent e){}
    public void mouseDragged(MouseEvent e){}

    public static void main(String[] args){
        new MouseEventDemo();
    }
}
