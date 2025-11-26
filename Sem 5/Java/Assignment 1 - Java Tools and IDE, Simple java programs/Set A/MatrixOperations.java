/*
d)  Write a menu driven program to perform the following operations on 
    multidimensional array ie matrix : 
    i.   Addition 
    ii.  Multiplication 
    iii. Transpose of any matrix
    iv.  Exit 
*/

import java.util.Scanner;
public class MatrixOperations{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter rows and columns of matrix A: ");
        int r1 = sc.nextInt(), c1 = sc.nextInt();
        int[][] A = new int[r1][c1];
        System.out.println("Enter elements of matrix A:");
        for(int i = 0; i < r1; i++)
            for (int j = 0; j < c1; j++)
                A[i][j] = sc.nextInt();

        System.out.print("Enter rows and columns of matrix B: ");
        int r2 = sc.nextInt(), c2 = sc.nextInt();
        int[][] B = new int[r2][c2];
        System.out.println("Enter elements of matrix B:");
        for(int i = 0; i < r2; i++)
            for(int j = 0; j < c2; j++)
                B[i][j] = sc.nextInt();

        int choice;
        do{
            System.out.println("\nMenu:");
            System.out.println("1. Addition");
            System.out.println("2. Multiplication");
            System.out.println("3. Transpose of Matrix A");
            System.out.println("4. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch(choice){
                case 1:
                    if(r1 == r2 && c1 == c2){
                        int[][] sum = new int[r1][c1];
                        for(int i = 0; i < r1; i++)
                            for(int j = 0; j < c1; j++)
                                sum[i][j] = A[i][j] + B[i][j];

                        System.out.println("Addition Result:");
                        display(sum);
                    }else{
                        System.out.println("Matrix dimensions do not match for addition!");
                    }
                    break;

                case 2:
                    if(c1 == r2){
                        int[][] prod = new int[r1][c2];
                        for(int i = 0; i < r1; i++){
                            for(int j = 0; j < c2; j++){
                                prod[i][j] = 0;
                                for(int k = 0; k < c1; k++){
                                    prod[i][j] += A[i][k] * B[k][j];
                                }
                            }
                        }
                        System.out.println("Multiplication Result:");
                        display(prod);
                    }else{
                        System.out.println("Matrix dimensions not compatible for multiplication!");
                    }
                    break;

                case 3:
                    int[][] trans = new int[c1][r1];
                    for(int i = 0; i < r1; i++)
                        for(int j = 0; j < c1; j++)
                            trans[j][i] = A[i][j];
                    System.out.println("Transpose of Matrix A:");
                    display(trans);
                    break;

                case 4:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }
        }while(choice != 4);
    }

    static void display(int[][] M){
        for(int[] row : M){
            for(int val : row)
                System.out.print(val + " ");
            System.out.println();
        }
    }
}

/* 
// Modular Method (My Preferred Approach, makes it look organized)
import java.util.Scanner;
public class MatrixOperations{

    // Method to input a matrix
    static int[][] inputMatrix(Scanner sc, String name){
        System.out.print("Enter rows and columns of matrix " + name + ": ");
        int rows = sc.nextInt(), cols = sc.nextInt();
        int[][] M = new int[rows][cols];
        System.out.println("Enter elements of matrix " + name + ":");
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                M[i][j] = sc.nextInt();
        return M;
    }

    // Method to display matrix
    static void displayMatrix(int[][] M){
        for(int[] row : M){
            for(int val : row)
                System.out.print(val + " ");
            System.out.println();
        }
    }

    // Matrix Addition
    static int[][] addMatrices(int[][] A, int[][] B){
        if(A.length != B.length || A[0].length != B[0].length){
            System.out.println("Matrix dimensions do not match for addition!");
            return null;
        }
        int[][] result = new int[A.length][A[0].length];
        for(int i = 0; i < A.length; i++)
            for(int j = 0; j < A[0].length; j++)
                result[i][j] = A[i][j] + B[i][j];
        return result;
    }

    // Matrix Multiplication
    static int[][] multiplyMatrices(int[][] A, int[][] B){
        if(A[0].length != B.length){
            System.out.println("Matrix dimensions not compatible for multiplication!");
            return null;
        }
        int[][] result = new int[A.length][B[0].length];
        for(int i = 0; i < A.length; i++){
            for(int j = 0; j < B[0].length; j++){
                result[i][j] = 0;
                for(int k = 0; k < A[0].length; k++)
                    result[i][j] += A[i][k] * B[k][j];
            }
        }
        return result;
    }

    // Matrix Transpose
    static int[][] transposeMatrix(int[][] A){
        int[][] trans = new int[A[0].length][A.length];
        for(int i = 0; i < A.length; i++)
            for(int j = 0; j < A[0].length; j++)
                trans[j][i] = A[i][j];
        return trans;
    }

    // Main Menu
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int[][] A = inputMatrix(sc, "A");
        int[][] B = inputMatrix(sc, "B");

        int choice;
        do{
            System.out.println("\n--- Matrix Operations Menu ---");
            System.out.println("1. Addition");
            System.out.println("2. Multiplication");
            System.out.println("3. Transpose of Matrix A");
            System.out.println("4. Exit");
            System.out.print("Enter choice: ");
            choice = sc.nextInt();

            switch(choice){
                case 1:
                    int[][] sum = addMatrices(A, B);
                    if (sum != null) {
                        System.out.println("Addition Result:");
                        displayMatrix(sum);
                    }
                    break;

                case 2:
                    int[][] prod = multiplyMatrices(A, B);
                    if(prod != null){
                        System.out.println("Multiplication Result:");
                        displayMatrix(prod);
                    }
                    break;

                case 3:
                    int[][] trans = transposeMatrix(A);
                    System.out.println("Transpose of Matrix A:");
                    displayMatrix(trans);
                    break;

                case 4:
                    System.out.println("Exiting...");
                    break;

                default:
                    System.out.println("Invalid choice!");
            }
        }while(choice != 4);
    }
}
*/