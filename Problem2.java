public class Problem2 
{
    public static int maxArea(int[] height) 
    {
        int left = 0;
        int right = height.length - 1;
        int maxArea = 0;

        while (left < right) 
        {
            int currentArea = Math.min(height[left], height[right]) * (right - left);
            maxArea = Math.max(maxArea, currentArea);

            if (height[left] < height[right]) 
            {
                left++;
            } else 
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
        int maxArea = maxArea(height);
        System.out.println(maxArea);
    }
}
