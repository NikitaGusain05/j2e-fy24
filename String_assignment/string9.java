public class Problem9 {
    


	static void printRLE(String s)
	{
		for (int i = 0; i < s.length(); i++) {

			
			int count = 1;
			while (i + 1 < s.length()
				&& s.charAt(i)
						== s.charAt(i + 1)) {
				i++;
				count++;
			}
			System.out.print(s.charAt(i)
							+ "" + count + " ");
		}

		System.out.println();
	}


	public static void main(String args[])
	{
		printRLE("GeeeEEKKKss");
		printRLE("ccccOddEEE");
	}


    
}