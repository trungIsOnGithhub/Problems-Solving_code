import java.util.*;
import java.lang.*;
import java.io.*;


public class Pasha_And_Sticks{
    static long solve(){
        long ways=0;    //output
        long n=0;  //input
        
        //Getting input
        Scanner sc = new Scanner(System.in);
        n=sc.nextLong();
        sc.close();
        
        if (n%2==1){
            ways=0;
        }
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
