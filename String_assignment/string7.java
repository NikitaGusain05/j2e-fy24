import java.util.*;

public class problem7 {


static int distinctSubString(String P, int N)
{
	
	HashSet<String> S = new HashSet<String>();

	
	for (int i = 0; i < N; ++i) {

		
		boolean []freq = new boolean[26];

		
		String s = "";

		for (int j = i; j < N; ++j) {

			
			int pos = P.charAt(j) - 'a';

			
			if (freq[pos] == true)
				break;

			freq[pos] = true;

		
			s += P.charAt(j);

			
			S.add(s);
		}
	}

	return S.size();
}


public static void main(String[] args)
{
	String S = "abba";
	int N = S.length();

	System.out.print(distinctSubString(S, N));
}


    
}