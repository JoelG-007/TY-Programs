/*
b)  Write a program to display the following menus and sub-menus.
*/

import java.awt.*;
import java.awt.event.*;

public class MenuDemo extends Frame{
    TextArea ta;

    MenuDemo(){
        setTitle("Menu Demo");
        setLayout(new BorderLayout());

        ta = new TextArea();
        add(ta, BorderLayout.CENTER);

        MenuBar mb = new MenuBar();

        // File Menu
        Menu file = new Menu("File");
        MenuItem newItem = new MenuItem("New");
        MenuItem openItem = new MenuItem("Open");
        MenuItem saveItem = new MenuItem("Save");
        MenuItem exitItem = new MenuItem("Exit");
        file.add(newItem); file.add(openItem); file.add(saveItem); file.addSeparator(); file.add(exitItem);

        // Edit Menu with Submenu
        Menu edit = new Menu("Edit");
        Menu findSub = new Menu("Find");
        MenuItem findItem = new MenuItem("Find...");
        MenuItem replaceItem = new MenuItem("Replace...");
        findSub.add(findItem);
        findSub.add(replaceItem);
        edit.add(findSub);

        // Help Menu
        Menu help = new Menu("Help");
        MenuItem aboutItem = new MenuItem("About");
        help.add(aboutItem);

        mb.add(file);
        mb.add(edit);
        mb.add(help);
        setMenuBar(mb);

        exitItem.addActionListener(e -> System.exit(0));

        addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){
                System.exit(0);
            }
        });
        setSize(400, 300);
        setVisible(true);
    }

    public static void main(String[] args){
        new MenuDemo();
    }
}
