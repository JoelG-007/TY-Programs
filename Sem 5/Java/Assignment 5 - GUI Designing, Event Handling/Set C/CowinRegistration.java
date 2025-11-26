/*
a)  Write a java program to create the following GUI for user registration form 

                            Co-WIN Registration 
            AdharCard No. : 

            Birth Year : 

            Mobile No. : 

            Age Group :     18 & above 45 & above 

            Select Hospital : 

            Vaccines :      Covishield,     Covaxin     Sputnik V. 

            Time Slot :     Morning     Afternoon   Evening
*/

import java.awt.*;
import java.awt.event.*;

public class CowinRegistration extends Frame implements ActionListener{
    Label title, l1, l2, l3, l4, l5, l6, l7, msg;
    TextField tf1, tf2, tf3;
    CheckboxGroup ageGroup, vaccineGroup, slotGroup;
    Checkbox age18, age45, covishield, covaxin, sputnik, morning, afternoon, evening;
    Choice hospitalChoice;
    Button submit, clear;

    CowinRegistration(){
        setTitle("Co-WIN Registration");
        setLayout(new GridLayout(10, 2, 10, 5));

        title = new Label("   Co-WIN Registration", Label.CENTER);
        title.setFont(new Font("Arial", Font.BOLD, 14));

        l1 = new Label("AdharCard No.: ");
        l2 = new Label("Birth Year: ");
        l3 = new Label("Mobile No.: ");
        l4 = new Label("Age Group: ");
        l5 = new Label("Select Hospital: ");
        l6 = new Label("Vaccines: ");
        l7 = new Label("Time Slot: ");
        msg = new Label("");

        tf1 = new TextField();
        tf2 = new TextField();
        tf3 = new TextField();

        // Age group
        ageGroup = new CheckboxGroup();
        age18 = new Checkbox("18 & above", ageGroup, false);
        age45 = new Checkbox("45 & above", ageGroup, false);

        // Hospital choice
        hospitalChoice = new Choice();
        hospitalChoice.add("Select");
        hospitalChoice.add("City Hospital");
        hospitalChoice.add("LifeCare Clinic");
        hospitalChoice.add("Sahyadri Hospital");

        // Vaccine type
        vaccineGroup = new CheckboxGroup();
        covishield = new Checkbox("Covishield", vaccineGroup, false);
        covaxin = new Checkbox("Covaxin", vaccineGroup, false);
        sputnik = new Checkbox("Sputnik V", vaccineGroup, false);

        // Time slot
        slotGroup = new CheckboxGroup();
        morning = new Checkbox("Morning", slotGroup, false);
        afternoon = new Checkbox("Afternoon", slotGroup, false);
        evening = new Checkbox("Evening", slotGroup, false);

        submit = new Button("Submit");
        clear = new Button("Clear");

        // Add components
        add(title); add(new Label(""));
        add(l1); add(tf1);
        add(l2); add(tf2);
        add(l3); add(tf3);
        add(l4);
        Panel agePanel = new Panel();
        agePanel.add(age18); agePanel.add(age45);
        add(agePanel);

        add(l5); add(hospitalChoice);

        add(l6);
        Panel vacPanel = new Panel();
        vacPanel.add(covishield); vacPanel.add(covaxin); vacPanel.add(sputnik);
        add(vacPanel);

        add(l7);
        Panel slotPanel = new Panel();
        slotPanel.add(morning); slotPanel.add(afternoon); slotPanel.add(evening);
        add(slotPanel);

        add(submit); add(clear);
        add(msg);

        submit.addActionListener(this);
        clear.addActionListener(this);

        addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){
                System.exit(0);
            }
        });

        setSize(450, 400);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e){
        if (e.getSource() == submit) {
            String adhar = tf1.getText().trim();
            String year = tf2.getText().trim();
            String mobile = tf3.getText().trim();
            String hospital = hospitalChoice.getSelectedItem();

            // Validation
            if(adhar.length() == 12 && mobile.length() == 10 && !hospital.equals("Select")){
                msg.setText("Registration Successful!");
                msg.setForeground(Color.GREEN);
            }else{
                msg.setText("Registration Failed!");
                msg.setForeground(Color.RED);
            }
        } else if(e.getSource() == clear){
            tf1.setText("");
            tf2.setText("");
            tf3.setText("");
            hospitalChoice.select("Select");
            ageGroup.setSelectedCheckbox(null);
            vaccineGroup.setSelectedCheckbox(null);
            slotGroup.setSelectedCheckbox(null);
            msg.setText("");
        }
    }
    public static void main(String[] args){
        new CowinRegistration();
    }
}
