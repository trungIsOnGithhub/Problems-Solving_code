import java.util.*;
import java.lang.*;
import java.io.*;

// Codeforces problem 610A-Pasha and Stick, 76/76 tests AC.
// Combinatorics(Repetition combination) approach

public class Pasha_And_Sticks{
    static long solve(){
        long ways=0;    //output
        long n=0;  //input
        
        //Getting input
        Scanner sc = new Scanner(System.in);
        n=sc.nextLong();
        sc.close();
        
        // if the legth of the initial stick is odd,it obviously cannot be divided into a rectangle
        if (n%2==1){
            ways=0;
        }
        // we can prove that if (n/2) is odd, just minus 1 and when (n/2) is even, we subtract it with 2.
        // both need to be divided by 2 before return result.
        else{
            n=n/2;
            if(n%2==0) n = n-2;
            else n = n-1;
            ways =n/2;
        }
        
        return ways;
    }
	public static void main (String[] args){
	    System.out.print(solve());
	}
}
