import java.util.*;

public class Main{
    static void solve(){   
        //getting input and get answer
        long kmax=0,kmin=0; //result
        long m,n; //input (lossiness can occur if we use normal int)
        
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        sc.close();
        
        // the two-combinator of n can be reduced to (n/2)*(n-1)
        if (m==1){
            kmax = (n*(n-1))/2;
            kmin = kmax;
        }
        else{
            long rem = n%m;
            long avg = n/m;
            n=n-m+1;
            kmax = (n*(n-1))/2;
            
            kmin = kmin + (rem*(avg+1)*avg)/2;
            kmin = kmin + ((m-rem)*avg*(avg-1))/2;
        }
    
        System.out.println(kmin+" "+kmax);    
    }
	public static void main(String[] args){
	    solve();
	}
}
