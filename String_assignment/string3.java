import java.util.*;

public class problem3 
{
	

static boolean valid(int []cnt)
{
	
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] >= 2)
			return false;
	}

	return true;
}


static String getGoodString(String ss, int n)
{
	char[] s=ss.toCharArray();
	
	
	if (n < 26)
		return "-1";
		
	
		int[] cnt = new int[27];
		
	
	for (int i = 25; i < n; i++)
	{

		

		
		for (int j = i; j >= i - 25; j--)
		{
			if (s[j] != '?')
			cnt[((int)s[j] - (int)'a')]++;
		}

		
		if (valid(cnt))
		{

			
			int cur = 0;
			while (cnt[cur] > 0)
				cur++;

			for (int j = i - 25; j <= i; j++)
			{

				
				if (s[j] == '?')
				{
					s[j] = (char)(cur + (int)('a'));
					cur++;

					
					while (cnt[cur] > 0)
						cur++;
				}
			}

			
			return new String(s);
		}
	}

	return "-1";
}


public static void main (String[] args)
{
	String s = "abcdefghijkl?nopqrstuvwxy?";
	int n = s.length();

	System.out.println(getGoodString(s, n));
}
}