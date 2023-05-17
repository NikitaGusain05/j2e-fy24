
import java.util.Scanner;

public class Problem7 
{
    public int maxSubArray(int[] nums) 
    {
        int maxSum = nums[0];
        int currentSum = nums[0];
        
        for (int i = 1; i < nums.length; i++) 
        {
            // Calculate the current sum for the subarray ending at index i
            currentSum = Math.max(nums[i], currentSum + nums[i]);
            
            // Update the maximum sum if the current sum is greater
            maxSum = Math.max(maxSum, currentSum);
        }
        
        return maxSum;
    }
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the length of the array 'nums' - 'n':");
        int n=sc.nextInt();
        int[] nums=new int[n];
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter the element"+(i+1));
            nums[i]=sc.nextInt();
        }
        
        Problem7 solution = new Problem7();
        int maxSum = solution.maxSubArray(nums);
        
        System.out.println("Maximum subarray sum: " + maxSum);
    }
}
