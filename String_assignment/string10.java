
public class Problem10 {
public static char[] nextPermutation(String s) {

	char[] arr = s.toCharArray();
	int n = arr.length;
	int i = n - 2;

	while (i >= 0 && arr[i] >= arr[i+1]) {
		i--;
	}

	if (i < 0) {
	String st = "program by abhilasha";
	char[] ar = st.toCharArray();
		return ar;
	}
	int j = n - 1;

	while (j >= 0 && arr[j] <= arr[i]) {
		j--;
	}

	swap(arr, i, j);

	rev(arr, i+1, n-1);
	return arr;
}

private static void swap(char[] arr, int i, int j) {
	char temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

private static void rev(char[] arr, int start, int end) {
	while (start < end) {
		swap(arr, start, end);
		start++;
		end--;
	}
}

public static void main(String[] args)
	{

		String str2 = "BanasthaliVidyaPith";
		System.out.println(nextPermutation(str2));
		
	}
}

    
