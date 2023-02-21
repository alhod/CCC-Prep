// Works for all n-values up until a bit below 100 (fibonacci value exceeds Long.MAX_VALUE if greater)
// If add modulus (e.g. %1000, so only see last 3 digits), works for n up to around 7000 (stack overflow if greater, due to recursion)
// To go greater, only call fibTab (but keep the modulus)

// imports
import java.util.Scanner;
import java.util.HashMap;

public class Fibonacci
{
    
    public class Global{

        // Create memo table
        public static HashMap<Integer, Long>memo=new HashMap<Integer, Long>();

        // important to do this in global scope due to "pass-by-value",
        // which means we copy the entire HashMap every time we pass it
        // into a function. By defining in global scope, we can access
        // without copying all its entries.
    }


    // Memoization
    public static long fibMemo(int n){


        // Check if already computed this subproblem
        if(Global.memo.containsKey(n)==true){

            // if so, return stored value
            return Global.memo.get(n);
        }
        

        // fib(1)=1 and fib(2)=1, so we used them as base cases
        if(n==1||n==2){
            return 1;
        }
        

        // add nth fibonacci value to memo table
        Global.memo.put(n, (fibMemo(n-1)+fibMemo(n-2))%1000);


        // return nth fibonacci value
        return Global.memo.get(n);
    }
    // Memoization


    // Tabulation
    public static long fibTab(int n){


        // Create tabulation table
        long[] tab;
        tab = new long[n+1];


        // Add base cases
        tab[1]=tab[2]=1;


        // Iterate from 3 to n and use formula fib(i)=fib(i-1)+fib(i-2)
        for(int i=3; i<=n; i++){
            tab[i]=(tab[i-1]+tab[i-2])%1000;
        }


        // Return answer
        return tab[n];  // *We must cast to int type*
    }
    // Tabulation


    public static void main(String args[]){
        
        // Input
        Scanner input = new Scanner(System.in);
        System.out.println("Index of Fibonacci number: ");
        int n = input.nextInt();

        // Print answer
        //System.out.println("Memoized solution: "+fibMemo(n));
        System.out.println("Tabulated solution: "+fibTab(n));

        // Close Scanner
        input.close();
        
    }
}