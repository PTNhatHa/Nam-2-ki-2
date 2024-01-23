package TestGK;

import java.util.Scanner;

interface MonHoc 
{
	double diem(double BT, double GK, double CK);
}
class MonLapTrinhJava implements MonHoc
{
	public double diem(double BT, double GK, double CK)
	{
		return BT*0.2 + GK*0.2 + CK*0.6;
	}
}
class MonKyThuatLapTrinh implements MonHoc
{
	public double diem(double BT, double GK, double CK)
	{
		return BT*0.2 + GK*0.3 + CK*0.5;
	}
}

public class interfaceMonhoc {


	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner d = new Scanner(System.in);
		System.out.println("Nhập điểm bt: ");
		double bt = d.nextDouble();
		System.out.println("Nhập điểm gk: ");
		double gk = d.nextDouble();
		System.out.println("Nhập điểm ck: ");
		double ck = d.nextDouble();
		
		MonKyThuatLapTrinh KTLT = new MonKyThuatLapTrinh();
		MonLapTrinhJava LTJV = new MonLapTrinhJava();
		
		System.out.println("Điểm môn KTLT: " + KTLT.diem(bt, gk, ck));
		System.out.println("Điểm môn LT Java: " + LTJV.diem(bt, gk, ck));
		
		d.close();
	}

}
