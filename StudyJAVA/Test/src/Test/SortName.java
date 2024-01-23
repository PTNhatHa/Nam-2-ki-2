//package Test;
//
//import java.util.ArrayList;
//import java.util.Collections;
//import java.util.Scanner;
//
//
//public class SortName {
//
//	public static void main(String[] args) {
//		Scanner sc = new Scanner(System.in);
//		ArrayList<Name> listName = new ArrayList<Name>();
//		while (true)
//		{
//			String n = sc.nextLine();
//			if (n.equals(" ")) break;
//			listName.add(new Name(n));
//		}
//		Collections.sort(listName);
//		for (Name name:listName)
//		{
//			System.out.println(name.name);
//		}
//	}
//	
//
//}
//
//class Name implements Comparable<Name>
//{
//	String name;
//	
//	public Name(String name)
//	{
//		this.name=name.strip();
//	}
//	
//	public String[] getHoTen()
//	{
//		int i = this.name.lastIndexOf(" ");
//		String HoTen[] = new String[2];
//		HoTen[0] = this.name.substring(0, i);
//		HoTen[1] = this.name.substring(i+1);
//		return HoTen;
//	}
//	public int compareTo(Name p)
//	{
//		String[] t_HoTen = this.getHoTen();
//		String[] p_HoTen = p.getHoTen();
//		if (t_HoTen[1].equals(p_HoTen[1])) return t_HoTen[0].compareTo(p_HoTen[0]);
//		else return t_HoTen[1].compareTo(p_HoTen[1]);
//	}
//}
