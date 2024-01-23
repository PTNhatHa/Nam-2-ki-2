//package Test;
//
//import java.math.BigInteger;
//import java.util.Scanner;
//
//class Test {
//
//	public static void ptb1(double a, double b)
//	{
//
//		if (a==0)
//		{
//			if (b==0) 
//			{
//				System.out.println("Vo so nghiem");
//			}
//			else
//			{
//				System.out.println("Vo nghiem");
//			}
//		}
//		else
//		{
//			System.out.println("Pt co nghiem la: " + (-b/a));
//		}
//	}
//	
//	public static void ptb2(double a, double b, double c)
//	{
//		if (a==0)
//		{
//			if (b==0) 
//			{
//				if (c==0)
//				{
//					System.out.println("Vo so nghiem");	
//				}
//				else
//				{
//					System.out.println("Vo nghiem");
//				}
//			}
//			else
//			{
//				ptb1(b,c);
//			}
//		}
//		else
//		{
//			double d = b*b - 4*a*c;
//			if (d<0) 
//			{
//				System.out.println("Vo nghiem");
//			}
//			if (d==0)
//			{
//				System.out.println("Pt co nghiem la: " + (-b/(2*a)));
//			}
//			if (d>0)
//			{
//				System.out.println("Pt co 2 nghiem: ");
//				System.out.println((-b - Math.sqrt(d)/(2*a)));
//				System.out.println((-b + Math.sqrt(d)/(2*a)));
//			}
//		}
//	}
//	
//	
//	public static void main(String[] args) 
//	{
//		Scanner sc = new Scanner(System.in); //nhap dl tu ban phim
////		double a = sc.nextDouble();
////		double b = sc.nextDouble();
////		double c = sc.nextDouble();
////		ptb2(a,b,c);
//		
//		BigInteger n = sc.nextBigInteger();
//		System.out.println(n.isProbablePrime(1000));
//	}
//
//}


