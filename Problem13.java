import java.util.Scanner;

public class Problem13 
{
    public int maxArea(int[] height) 
    {
        int maxArea = 0;
        int left = 0;
        int right = height.length - 1;
        
        while (left < right) 
        {
            int area = Math.min(height[left], height[right]) * (right - left);
            maxArea = Math.max(maxArea, area);
            
            if (height[left] < height[right]) 
            {
                left++;
            } 
            else 
            {
                right--;
            }
        }
        
        return maxArea;
    }
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the length of the array 'height'- 'n':");
        int n=sc.nextInt();
        int[] height=new int[n];
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter height "+(i+1));
            height[i]=sc.nextInt();
        }

        Problem13 solution = new Problem13();
        int maxWater = solution.maxArea(height);

        // Print the maximum amount of water
        System.out.println("Max Water: " + maxWater);
    }
}
