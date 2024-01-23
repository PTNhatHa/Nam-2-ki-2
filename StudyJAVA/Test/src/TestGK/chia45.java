package TestGK;

import java.util.Scanner;

public class chia45 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Nhập chuỗi bất kì: ");
		Scanner n = new Scanner(System.in);
		String s = n.next();
		check45(s);
		n.close();
	}
	
	public static void check45(String s)
	{
		int i, vt5=-1;
		int tong = 0;
		String kq="";
		Boolean check=false;
		for(i=0; i< s.length(); i++)
		{
			//kiểm tra kí tự có phải số hay không 0-9
			if(s.charAt(i) < '0' || s.charAt(i) > '9' )
			{
				System.out.println("-1");
				break;
			}
			else
			{
				tong += s.charAt(i) - 48;
				if(s.charAt(i) == '0' || s.charAt(i) == '5' )
				{
					check = true;
					vt5 = i;
				}
			}
		}
		if(tong%9==0 && check)
		{
			for(int j=0; j<s.length(); j++)
			{
				if(j!=vt5)
				{
					kq+=s.charAt(j);
				}
			}
			kq+=s.charAt(vt5);
			System.out.println(kq);
		}
		else
		{
			System.out.println(-1);
		}
	}

}
