
import java.util.*;
public class Problem8 
{
    public int[][] merge(int[][] intervals) 
    {
        // Sort the intervals based on the start time
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        List<int[]> mergedIntervals = new ArrayList<>();
        int[] currentInterval = intervals[0];

        for (int i = 1; i < intervals.length; i++) 
        {
            int[] interval = intervals[i];

            // If the current interval overlaps with the next interval
            if (currentInterval[1] >= interval[0]) 
            {
                // Merge the intervals by updating the end time
                currentInterval[1] = Math.max(currentInterval[1], interval[1]);
            } 
            else 
            {
                // Add the non-overlapping interval to the merged intervals list
                mergedIntervals.add(currentInterval);
                currentInterval = interval;
            }
        }

        // Add the last interval to the merged intervals list
        mergedIntervals.add(currentInterval);

        return mergedIntervals.toArray(new int[mergedIntervals.size()][]);
    }
    public static void main(String[] args) 
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the number of intervals:");
        int n=sc.nextInt();
        int[][] intervals=new int[n][2];
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter interval "+(i+1));
            for(int j=0;j<2;j++)
            {
               intervals[i][j]=sc.nextInt();
            }
        }

        Problem8 solution = new Problem8();
        int[][] mergedIntervals = solution.merge(intervals);

        // Print the merged intervals
        for (int[] interval : mergedIntervals) 
        {
            System.out.println(Arrays.toString(interval));
        }
    }
}


