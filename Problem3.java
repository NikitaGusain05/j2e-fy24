
import java.util.*;
import java.util.Arrays;
public class Problem3 
{
    public static int threeSumClosest(int[] nums, int target) 
    {
        Arrays.sort(nums);
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.length - 2; i++) 
        {
            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) 
            {
                int currentSum = nums[i] + nums[left] + nums[right];

                if (currentSum == target) 
                {
                    return currentSum;
                }

                if (Math.abs(currentSum - target) < Math.abs(closestSum - target)) 
                {
                    closestSum = currentSum;
                }

                if (currentSum < target) 
                {
                    left++;
                } 
                else 
                {
                    right--;
                }
            }
        }
        return closestSum;
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
        System.out.println("Enter the target number:");
        int target = sc.nextInt();
        int result = threeSumClosest(nums, target);
        System.out.println(result);
    }
}
