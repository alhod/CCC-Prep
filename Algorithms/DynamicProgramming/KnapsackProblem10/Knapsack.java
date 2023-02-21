// imports
import java.util.Scanner;

public class Knapsack
{


    // Memoized solution
    public static int knapsackMemoization(int i, int j, int[]val, int[]wt, int[]memo[]){


        // check base cases
        if(i==-1||j==0){
            return 0;
        }


        // Check if already computed this state
        if(memo[i][j]!=-1){

            // if so, return stored value
            return memo[i][j];
        }
    

        // if ith item weight exceeds capacity j
        if(wt[i]>j){

            // get previous most optimal way to fill knapsack of capacity j
            // store in memo table
            memo[i][j]=knapsackMemoization(i-1, j, val, wt, memo);


            // return subproblem solution
            return memo[i][j];
        } 
        
        
        else {

            // use state transition, and store in memo table
            memo[i][j]=Math.max(knapsackMemoization(i-1, j, val, wt, memo), val[i]+knapsackMemoization(i-1, j-wt[i], val, wt, memo));
            

            // return subproblem solution
            return memo[i][j];
        }


    }
    // Memoized solution



    // Tabulated solution
    public static int knapsackTabulation(int n, int W, int[]val, int[]wt){


        // Create tabulation table with n+1 rows and W+1 columns
        int[] tab[];
        tab=new int[n+1][W+1];


        // Fill tabulation table with all 0s
        for(int i=0; i<n+1; i++){
            for(int j=0; j<W+1; j++){
                tab[i][j]=0;
            }
        }


        // Iterate through each item
        for(int i=1; i<n+1; i++){


            // Iterate through each knapsack capacity
            for(int j=1; j<W+1; j++){


                // If ith item weight exceeds capacity j
                if(wt[i-1]>j){

                    // get previous most optimal way to fill knapsack capacity of j
                    // store in tabulation table
                    tab[i][j]=tab[i-1][j];
                } 
                
                
                // If ith item weight fits in capacity j
                else {

                    // use state transition, store in tabulation table
                    tab[i][j]=Math.max(tab[i-1][j], val[i-1]+tab[i-1][j-wt[i-1]]);
                }
            }
        }


        // Return answer
        return tab[n][W];


    }
    // Tabulated solution



    // Tabulated solution (2*W space complexity)
    public static int knapsackTabulationOptimized(int n, int W, int[]val, int[]wt){


        // Only difference is the "%2" beside "i"s when indexing into tabulation table.
        // Notice how previous tabulated solution really only requires two rows at a time:
        // The current and previous rows. Therefore, we can manage with only two rows,
        // and bring the space complexity down from n*W to 2*W.


        int[] tab[];
        tab=new int[2][W+1];


        for(int i=0; i<n+1; i++){
            for(int j=0; j<W+1; j++){
                tab[i%2][j]=0;
            }
        }


        for(int i=1; i<n+1; i++){


            for(int j=1; j<W+1; j++){


                if(wt[i-1]>j){

                    tab[i%2][j]=tab[(i-1)%2][j];
                } 
                
                
                else {

                    tab[i%2][j]=Math.max(tab[(i-1)%2][j], val[i-1]+tab[(i-1)%2][j-wt[i-1]]);
                }
            }
        }


        // Return answer
        return tab[n%2][W];


    }
    // Tabulated solution (2*W space complexity)



    public static void main(String args[]){


        // create scanner
        Scanner input = new Scanner(System.in);


        // input number of items
        System.out.println("Number of items: ");
        int n = input.nextInt(); 


        // input weight capacity of knapsack
        System.out.println("Weight capacity of knapsack: ");
        int W = input.nextInt();


        // create value array
        int[]val;
        val = new int[n];


        // create weight array
        int[]wt;
        wt = new int[n];

        
        // create memo table
        int[]memo[];
        memo = new int[n+1][W+1];


        // fill memo table with -1s
        for(int i=0; i<n+1; i++){
            for(int j=0; j<W+1; j++){
                memo[i][j]=-1;
            }
        }

        
        // input values
        for(int i=1; i<n+1; i++){
            System.out.printf("Input the value of the %dth number: \n", i);
            int tmp=input.nextInt();
            val[i-1]=tmp;
        }

        // input weights
        for(int i=1; i<n+1; i++){
            System.out.printf("Input the weight of the %dth number: \n", i);
            int tmp=input.nextInt();
            wt[i-1]=tmp;
        }


        // Print answer
        System.out.println("Memoized solution: "+knapsackMemoization(n-1, W, val, wt, memo));
        System.out.println("Tabulated solution: "+knapsackTabulation(n, W, val, wt));
        System.out.println("Tabulated solution (2*W space complexity): "+knapsackTabulationOptimized(n, W, val, wt));


        // Close Scanner
        input.close();
        
    }
}