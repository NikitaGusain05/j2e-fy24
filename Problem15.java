import java.util.*;
public class Problem15 
{
    private Random random = new Random();

    public int findKthLargest(int[] nums, int k) 
    {
        int left = 0;
        int right = nums.length - 1;
        int targetIndex = nums.length - k; // Convert kth largest to index

        while (left <= right) 
        {
            int pivotIndex = partition(nums, left, right);

            if (pivotIndex == targetIndex) 
            {
                return nums[pivotIndex];
            } 
            else if (pivotIndex < targetIndex) 
            {
                left = pivotIndex + 1;
            } 
            else 
            {
                right = pivotIndex - 1;
            }
        }

        return -1; // Error condition, kth largest element not found
    }

    private int partition(int[] nums, int left, int right) 
    {
        int pivotIndex = random.nextInt(right - left + 1) + left;
        int pivotValue = nums[pivotIndex];

        swap(nums, pivotIndex, right); // Move pivot to the end

        int i = left;
        for (int j = left; j < right; j++) 
        {
            if (nums[j] < pivotValue) 
            {
                swap(nums, i, j);
                i++;
            }
        }

        swap(nums, i, right); // Move pivot to its final position

        return i;
    }

    private void swap(int[] nums, int i, int j) 
    {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
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
        System.out.println("Enter the value of 'k':");
        int k=sc.nextInt();

        Problem15 solution = new Problem15();
        int kthLargest = solution.findKthLargest(nums, k);

        // Print the kth largest element
        System.out.println(k+"th Largest Element: " + kthLargest);
    }
}
