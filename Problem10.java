
public class Problem10 
{
    public int maxProfit(int[] prices) 
    {
        int n = prices.length;
        int maxProfit = 0;
        int minPrice = Integer.MAX_VALUE;
        
        for (int i = 0; i < n; i++) 
        {
            // Update the minimum price encountered so far
            minPrice = Math.min(minPrice, prices[i]);
            
            // Calculate the current profit by selling at the current price
            int currentProfit = prices[i] - minPrice;
            
            // Update the maximum profit if the current profit is higher
            maxProfit = Math.max(maxProfit, currentProfit);
        }
        
        return maxProfit;
    }
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the length of the array 'pricess' - 'n':");
        int n=sc.nextInt();
        int[] prices=new int[n];
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter the price of the given stock on the "+(i+1)+"th day:");
            prices[i]=sc.nextInt();
        }

        Problem10 solution = new Problem10();
        int maxProfit = solution.maxProfit(prices);

        // Print the maximum profit
        System.out.println("Max Profit: " + maxProfit);
    }
}
