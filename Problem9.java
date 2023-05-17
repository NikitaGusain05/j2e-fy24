
import java.util.*;
public class Problem9 
{
    public void sortColors(int[] nums) 
    {
        int n = nums.length;
        int low = 0; // pointer for 0
        int mid = 0; // pointer for 1
        int high = n - 1; // pointer for 2
        
        while (mid <= high) 
        {
            if (nums[mid] == 0) 
            {
                // Swap nums[low] and nums[mid]
                int temp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = temp;
                
                low++;
                mid++;
            } 
            else if (nums[mid] == 1) 
            {
                // No action needed for 1, just move mid pointer
                mid++;
            } 
            else if (nums[mid] == 2) 
            {
                // Swap nums[mid] and nums[high]
                int temp = nums[mid];
                nums[mid] = nums[high];
                nums[high] = temp;
                
                high--;
            }
        }
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
        Problem9 solution = new Problem9();
        solution.sortColors(nums);

        // Print the sorted colors
        System.out.println(Arrays.toString(nums));
    }
}
