//package Test_CSDL;
//
//import java.io.BufferedReader;
//import java.io.BufferedWriter;
//import java.io.FileReader;
//import java.io.FileWriter;
//import java.sql.Connection;
//import java.sql.Date;
//import java.sql.DriverManager;
//import java.sql.PreparedStatement;
//import java.text.SimpleDateFormat;
//import java.time.format.DateTimeFormatter;
//
//
//public class ThiThu_Nhung {
//
//	public static void main(String[] args) throws Exception {
//		Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
//		System.out.println("Tai driver thanh cong!");
//		Connection cnn = DriverManager.getConnection("jdbc:sqlserver://NHATHA:1433;databaseName=JAVA_THITHU2;integratedSecurity=true");
//		System.out.println("Ket noi co so du lieu thanh cong");
//		
//		FileReader fr = new FileReader("D:\\LEARNING\\HK4\\JAVA\\input.txt");
//		BufferedReader br = new BufferedReader(fr);
//		FileWriter fw = new FileWriter("D:\\LEARNING\\HK4\\JAVA\\error.txt");
//		BufferedWriter bw = new BufferedWriter(fw);
//		
//		String s = null;
//		int index = 1;
//		while((s = br.readLine())!= null)
//		{
//			boolean a = true,b = true,c = true;
//			String MaHocVien = s.substring(0,10);
//			String TenHocVien = s.substring(10,59).trim();
//			
//			String ns = s.substring(59,69);
//			Date NgaySinh = null;
//			SimpleDateFormat dateF = new SimpleDateFormat("dd/MM/yyyy");
//			try
//			{
//				NgaySinh = new Date(dateF.parse(ns).getTime());
//			}
//			catch(Exception ex)
//			{
//				a = false;
//			}
//			
//			String GioiTinh = s.substring(69,72).trim();
//			b = (GioiTinh.equals("Nam") || GioiTinh.equals("Nu") || GioiTinh.equals("nam") || GioiTinh.equals("nu"));
//			Double DiemThi = null;
//			try
//			{
//				DiemThi = Double.parseDouble(s.substring(72,76));
//			}
//			catch(Exception ex)
//			{
//				c = false;
//			}
//			
//			if(a && b && c)
//			{
//				String query = "insert into hocvien values(?,?,?,?,?)";
//				PreparedStatement pS = cnn.prepareStatement(query);
//				pS.setString(1, MaHocVien);
//				pS.setString(2, TenHocVien);
//				pS.setDate(3, NgaySinh);
//				pS.setString(4, GioiTinh);
//				pS.setDouble(5, DiemThi);
//				pS.executeUpdate();
//				pS.close();
//			}
//			else
//			{
//				String bug = "";
//				if(!a)
//				{
//					bug += "Sai dinh dang ngay sinh    ||\t";
//				}
//				if(!b)
//				{
//					bug += "Sai dinh dang gioi tinh    ||\t";
//				}
//				if(!c)
//				{
//					bug += "Sai dinh dang diem thi    ||\t";
//				}
//				String err = "Dong " + index + ": " + bug;
//				bw.write(err);
//			}
//			index++;
//		}
//		bw.close();
//		br.close();
//		System.out.println("Hoan thanh!");
//	}
//	}
