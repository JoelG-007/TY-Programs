/*
a)  Define a class patient (patient_name, patient_age, 
    patient_oxy_level,patient_HRCT_report). Create an object of patient. Handle 
    appropriate exception while patient oxygen level less than 95% and HRCT scan report 
    greater than 10, then throw user defined Exception “Patient is Covid Positive(+) and 
    Need to Hospitalized” otherwise display its information. 
*/

import java.util.Scanner;

// User-defined Exception
class CovidPositiveException extends Exception{
    CovidPositiveException(String msg){
        super(msg);
    }
}

class Patient{
    String patient_name;
    int patient_age;
    int patient_oxy_level;
    int patient_HRCT_report;

    void accept() throws CovidPositiveException{
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Patient Name: ");
        patient_name = sc.nextLine();
        System.out.print("Enter Age: ");
        patient_age = sc.nextInt();
        System.out.print("Enter Oxygen Level (%): ");
        patient_oxy_level = sc.nextInt();
        System.out.print("Enter HRCT Report Score: ");
        patient_HRCT_report = sc.nextInt();

        // Check condition
        if(patient_oxy_level < 95 && patient_HRCT_report > 10) {
            throw new CovidPositiveException("Patient is Covid Positive(+) and Need to Hospitalized");
        }
    }

    void display(){
        System.out.println("\nPatient Information:");
        System.out.println("Name: " + patient_name);
        System.out.println("Age: " + patient_age);
        System.out.println("Oxygen Level: " + patient_oxy_level);
        System.out.println("HRCT Report: " + patient_HRCT_report);
    }
}

public class PatientDemo{
    public static void main(String[] args){
        Patient p = new Patient();
        try{
            p.accept();
            p.display();
        }catch(CovidPositiveException e){
            System.out.println(e.getMessage());
        }
    }
}
