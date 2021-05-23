// package com.company;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        System.out.println("\t\t\tWelcome to My shopping management \n");
        System.out.println("***************************************************************");
        System.out.println("\n\n\t\t\t\t1. Log in");
        System.out.println("\n\n\t\t\t\t2. Exit\n");
        System.out.println("***************************************************************");
        System.out.print("\nEnter a number: ");

        Scanner sc = new Scanner(System.in);
        var input = sc.nextInt();

        System.out.println("\n");

        switch (input) {
            case 1: {
                System.out.println("\n1. customer information management");
                System.out.println("\n2. Shopping and checkout");
                System.out.println("\n3. Sincerely give back to our customers with rewards");
                System.out.println("\n4. log out\n");
                System.out.print("\n\nEnter a number: ");

                input = sc.nextInt();

                System.out.println("\n");
                
                switch (input){
                    case 1:{
                        System.out.println("\n1. Show all customer information");
                        System.out.println("\n2. Add customer information");
                        System.out.println("\n3. Modify customer information");
                        System.out.println("\n4. Query customer information\n");
                    }break;
                    case 2: System.out.println("going to Shopping and checkout page\n");break;
                    case 3: {
                        System.out.println("\n1. Lucky");
                        System.out.println("\n2. Lucky draw");
                        System.out.println("\n3. Birthday greeting\n");
                    }break;
                    case 4 : System.out.println("login out");
                    break;
                    default: break;
                }
            }break;
            case 2: System.out.println("Thank you!");
                break;
            default:
                break;
        }
        sc.close();
    }
}