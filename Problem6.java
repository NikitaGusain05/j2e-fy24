
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
public class Problem6 
{
    public List<List<Integer>> permuteUnique(int[] nums) 
    {
        List<List<Integer>> result = new ArrayList<>();
        boolean[] used = new boolean[nums.length];
        List<Integer> current = new ArrayList<>();
        
        // Sort the array to handle duplicates
        Arrays.sort(nums);
        
        backtrack(nums, used, current, result);
        
        return result;
    }
    
    private void backtrack(int[] nums, boolean[] used, List<Integer> current, List<List<Integer>> result) 
    {
        // Base case: if the current permutation has the same length as the input array
        if (current.size() == nums.length) 
        {
            result.add(new ArrayList<>(current));
            return;
        }
        
        for (int i = 0; i < nums.length; i++) 
        {
            // Skip used elements or duplicates
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])) 
            {
                continue;
            }
            
            used[i] = true; // Mark the current element as used
            current.add(nums[i]); // Add the current element to the current permutation
            
            backtrack(nums, used, current, result); // Recursive call
            
            used[i] = false; // Backtrack: mark the current element as unused
            current.remove(current.size() - 1); // Backtrack: remove the current element
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

        Problem6 solution = new Problem6();
        List<List<Integer>> permutations = solution.permuteUnique(nums);

        // Print the permutations
        for (List<Integer> permutation : permutations) 
        {
            System.out.println(permutation);
        }
    }
}
