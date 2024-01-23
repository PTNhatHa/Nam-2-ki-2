//package Test_CSDL;
//
//import java.io.BufferedReader;
//import java.io.BufferedWriter;
//import java.io.FileReader;
//import java.io.FileWriter;
//import java.sql.Connection;
//import java.sql.Date;
//import java.sql.DriverManager;
//import java.sql.Statement;
//import java.text.SimpleDateFormat;
//
//public class ThiThuCau2_LamLai {
//
//	public static void main(String[] args) throws Exception {
//		
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
//		String line = "";
//		int index = 1;
//		Statement sttm;
//		sttm = cnn.createStatement();
//	    while((line = br.readLine()) != null)
//	    {
//	    	boolean a = true,b = true,c = true;
//	
//	        String MaHV = line.substring(0, 10);
//	        String TenHV = line.substring(10, 59).trim();
//	        String NS = line.substring(59, 69).trim();
//	        String GT = line.substring(69, 72).trim();
//	        String Diem = line.substring(72, 76).trim();
//	        
//            Date NgaySinh = null;
//			SimpleDateFormat dateF = new SimpleDateFormat("dd/MM/yyyy");
//			dateF.setLenient(false);
//			try
//			{
//				NgaySinh = new Date(dateF.parse(NS).getTime());
//			}
//			catch(Exception ex)
//			{
//				a = false;
//			}
//			
//			Double DiemThi = null;
//			try
//			{
//				DiemThi = Double.parseDouble(Diem);
//			}
//			catch(Exception ex)
//			{
//				c = false;
//			}
//			
//			if(a && c)
//			{
//				String query = "INSERT INTO HOCVIEN VALUES (N'" + MaHV + "', N'" + TenHV + "', '" + NgaySinh + "', N'" + GT + "', " + DiemThi + ")";
//	    		sttm.executeUpdate(query);
//	    		String err = "Dong " + index + ": khong co loi \n";
//				bw.write(err);
//			}
//			else
//			{
//				String bug = "";
//				if(!a)
//				{
//					bug += "Sai dinh dang ngay sinh    ||\n";
//				}
//				if(!c)
//				{
//					bug += "Sai dinh dang diem thi    ||\t";
//				}
//				String err = "Dong " + index + ": " + bug;
//				bw.write(err);
//			}
//			index++;
//			//line = "";
//	    }
//		bw.close();
//		br.close();
//		System.out.println("Hoan thanh!");
//	}
//
//}
