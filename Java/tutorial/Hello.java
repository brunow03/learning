/*void main() {
    IO.println("Hello, World!");
}*/

/*void main() {
    IO.println("Hello world!");
    var name = IO.readln("What is your name? ");
    IO.println("Hello " + name);
}*/

import java.util.Scanner;

void main() {
    System.out.println("Hello world!");
    
    Scanner scanner = new Scanner(System.in);
    System.out.print("What is your name? ");
    var name = scanner.nextLine();
    
    System.out.println("Hello " + name);
}

