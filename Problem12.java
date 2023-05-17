import java.util.Scanner;

public class Problem12 
{
    public double findMedianSortedArrays(int[] nums1, int[] nums2) 
    {
        int m = nums1.length;
        int n = nums2.length;
        int[] merged = new int[m + n];
        
        int i = 0; // Pointer for nums1
        int j = 0; // Pointer for nums2
        int k = 0; // Pointer for merged array
        
        while (i < m && j < n) 
        {
            if (nums1[i] <= nums2[j]) 
            {
                merged[k++] = nums1[i++];
            } 
            else 
            {
                merged[k++] = nums2[j++];
            }
        }
        
        // Copy remaining elements from nums1, if any
        while (i < m) 
        {
            merged[k++] = nums1[i++];
        }
        
        // Copy remaining elements from nums2, if any
        while (j < n) 
        {
            merged[k++] = nums2[j++];
        }
        
        // Calculate median
        int medianIndex = (m + n) / 2;
        if ((m + n) % 2 == 0) 
        {
            return (merged[medianIndex - 1] + merged[medianIndex]) / 2.0;
        } 
        else 
        {
            return merged[medianIndex];
        }
    }
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the length of the array 'nums1' - 'm':");
        int m=sc.nextInt();
        int[] nums1=new int[m];
        System.out.println("Please enter the array in sorted order:");
        for(int i=0;i<m;i++)
        {
            System.out.println("Enter the element"+(i+1));
            nums1[i]=sc.nextInt();
        }
        System.out.println("Enter the length of the array 'nums2' - 'n':");
        int n=sc.nextInt();
        int[] nums2=new int[n];
        System.out.println("Please enter the array in sorted order:");
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter the element"+(i+1));
            nums2[i]=sc.nextInt();
        }

        Problem12 solution = new Problem12();
        double median = solution.findMedianSortedArrays(nums1, nums2);

        // Print the median
        System.out.println("Median: " + median);
    }
}