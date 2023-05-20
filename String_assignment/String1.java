import java.io.*;

public class problem1 {

public static String removeBackspaces(String s) {
	int n = s.length();

	
	int idx = 0;

	for (int i = 0; i < n; i++) {
	if (s.charAt(i) != '#') {
		s = s.substring(0, idx) + s.charAt(i) + s.substring(idx + 1);
		idx++;
	}
	else if (s.charAt(i) == '#' && idx >= 0) {
		idx--;
	}

	
	if (idx < 0)
		idx = 0;
	}

	return s.substring(0, idx);
}


public static void main(String[] args) {
	
	String s = "equ#ual";
	String t = "gee##eeks";

	if (removeBackspaces(s).equals(removeBackspaces(t)))
	System.out.println("True");
	else
	System.out.println("False");
}


@Override
public String toString() {
    return "string1 []";
}
}



