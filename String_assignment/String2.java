import java.util.*;
import java.lang.*;
import java.io.*;

public class String2 
{
	
	public static void print(char str[], int index)
	{
		if (index == str.length)
		{
			System.out.println(str);
			return;
		}

		if (str[index] == '?')
		{
			
			str[index] = '0';
			print(str, index + 1);
			
			
			str[index] = '1';
			print(str, index + 1);
			
			
			str[index] = '?';
		}
		else
			print(str, index + 1);
	}


	public static void main (String[] args)
	{
		String input = "1??0?101";
		char[] str = input.toCharArray();
		print(str, 0);
	}
}

