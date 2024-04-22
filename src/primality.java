import java.math.BigInteger;
import java.util.Scanner;

////////////////////////////////////////////////////////
// Problem: https://open.kattis.com/problems/primality /
////////////////////////////////////////////////////////

class Main {

    static boolean partOne(long n) {
        // Use a simple primality test for part 1
        if(n <= 1) return false;
        if(n <= 3) return true;
        if(n % 2 == 0 || n % 3 == 0) return false;
        // Try all candidate factors of 6k +/- 1 up to sqrt(n)
        for(long i = 5; i * i <= n; i += 6) {
            if(n % i == 0 || n % (i + 2) == 0) return false;
        }
        // Return true since value was prime
        return true;
    }

    static boolean partTwo(BigInteger n) {
        // Use java probabilistic primality test for part 2
        return n.isProbablePrime(1);
    }

    public static void main(String[] args) {
        // Initialize a scanner for reading input number
        Scanner s = new Scanner(System.in);
        // Read the input and store as a BigInteger
        BigInteger n = s.nextBigInteger();
        s.close();
        // Check if the number is prime and output the proper result
        // if(partOne(n.longValue())) System.out.println("YES");
        // else System.out.println("NO");
        if(partTwo(n)) System.out.println("YES");
        else System.out.println("NO");
    }
}