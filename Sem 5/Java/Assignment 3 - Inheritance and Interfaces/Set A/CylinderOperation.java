/*
c)  Define an interface “Operation” which has methods area(),volume().Define a 
    constant PI having a value 3.142.Create a class cylinder which implements this 
    interface (members – radius, height) Create one object and calculate the area 
    and volume. 
*/

interface Operation{
    double PI = 3.142;
    double area();
    double volume();
}

class Cylinder implements Operation{
    double radius, height;

    Cylinder(double radius, double height){
        this.radius = radius;
        this.height = height;
    }

    public double area(){
        return 2 * PI * radius * (radius + height);
    }

    public double volume(){
        return PI * radius * radius * height;
    }
}

public class CylinderOperation{
    public static void main(String[] args){
        Cylinder c = new Cylinder(5, 10);
        System.out.println("Area of Cylinder: " + c.area());
        System.out.println("Volume of Cylinder: " + c.volume());
    }
}
