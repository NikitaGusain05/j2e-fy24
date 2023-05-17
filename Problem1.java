public class Problem1 
{
    public static List<Boolean> kidsWithCandies(int[] candies, int extraCandies) 
    {
        int maxCandies = getMaxCandies(candies);
        List<Boolean> result = new ArrayList<>();

        for (int i = 0; i < candies.length; i++) 
        {
            int totalCandies = candies[i] + extraCandies;
            result.add(totalCandies >= maxCandies); //will store true in result if condition satisfies else will store false
        }

        return result;
    }

    public static int getMaxCandies(int[] candies) 
    {
        int max = candies[0];
        for (int i = 1; i < candies.length; i++) 
        {
            if (candies[i] > max) 
            {
                max = candies[i];
            }
        }
        return max;
    }

    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of kids 'n':");
        int n=sc.nextInt();
        int[] candies=new int[n];
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter the number of candies with kid "+(i+1));
            candies[i]=sc.nextInt();
        }
        System.out.println("Enter the number of extra candies:");
        int extraCandies = sc.nextInt();
        List<Boolean> result = kidsWithCandies(candies, extraCandies);
        System.out.println(result);
    }
}

