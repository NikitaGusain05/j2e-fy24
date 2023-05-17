public class Problem11 
{
    public int findPeakElement(int[] nums) 
    {
        int left = 0;
        int right = nums.length - 1;
        
        while (left < right) 
        {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] < nums[mid + 1]) 
            {
                // Peak is on the right side
                left = mid + 1;
            } 
            else 
            {
                // Peak is on the left side or at the mid index
                right = mid;
            }
        }
        
        return left;
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

        Problem11 solution = new Problem11();
        int peakIndex = solution.findPeakElement(nums);

        // Print the peak index
        System.out.println("Peak Index: " + peakIndex);
    }
}
