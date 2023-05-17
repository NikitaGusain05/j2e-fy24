import java.util.Scanner;

public class Problem14 
{
    public int findMaxConsecutiveOnes(int[] nums) 
    {
        int maxCount = 0;
        int currentCount = 0;

        for (int i = 0; i < nums.length; i++) 
        {
            if (nums[i] == 1) 
            {
                currentCount++;
                maxCount = Math.max(maxCount, currentCount);
            } 
            else 
            {
                currentCount = 0;
            }
        }

        return maxCount;
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

        Problem14 solution = new Problem14();
        int maxConsecutiveOnes = solution.findMaxConsecutiveOnes(nums);

        // Print the maximum number of consecutive 1's
        System.out.println("Max Consecutive Ones: " + maxConsecutiveOnes);
    }
}

