
import java.util.*;
import java.util.Arrays;
public class Problem4 
{
    public static void nextPermutation(int[] nums) 
    {
        // Find the first decreasing element from the right
        int i = nums.length - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) 
        {
            i--;
        }

        if (i >= 0) 
        {
            // Find the first element greater than the decreasing element
            int j = nums.length - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }

            // Swap the decreasing element with the next greater element
            swap(nums, i, j);
        }

        // Reverse the remaining elements to get the next permutation
        reverse(nums, i + 1);
    }

    public static void swap(int[] nums, int i, int j) 
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    public static void reverse(int[] nums, int start) 
    {
        int i = start;
        int j = nums.length - 1;
        while (i < j) 
        {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the length of the array 'nums' - 'n' between 1 and 100:");
        int n=sc.nextInt();
        int[] nums=new int[n];
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter the element between 0 and 100"+(i+1));
            nums[i]=sc.nextInt();
        }
        nextPermutation(nums);
        System.out.println(Arrays.toString(nums));
    }
}
