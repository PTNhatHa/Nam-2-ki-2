//package Test_CSDL;
//
//import java.io.*;
//import java.sql.*;
//import java.text.DateFormat;
//import java.text.SimpleDateFormat;
//
//
//public class ThiThu_Cau2 {
//
//	public static void main(String[] args) throws SQLException, Exception 
//	{
//		// TODO Auto-generated method stub
//		Connection connection = null;
//		try 
//		{
//			Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
//			String connectionURL="jdbc:sqlserver://NHATHA:1433;databaseName=CSDL_JAVA;integratedSecurity=true";
//			connection = DriverManager.getConnection(connectionURL);
//			System.out.println("Kết nối thành công");
//		} 
//		catch (ClassNotFoundException e) 
//		{
//			// TODO Auto-generated catch block
//			System.out.println("Kết nối thất bại");
//			System.err.println(e.getMessage()+"\n"+e.getClass()+"\n"+e.getCause());
//		}
//		
//		//ĐỌC DL TỪ FILE
//		File fileInput = new File("D:\\LEARNING\\HK4\\JAVA\\input.txt");
//		InputStream inputStream = new FileInputStream(fileInput);
//		InputStreamReader inputStreamReader = new InputStreamReader(inputStream);
//		BufferedReader reader = new BufferedReader(inputStreamReader);
//		String line = "";
////        while((line = reader.readLine()) != null)
////        {
////            System.out.println(line);
////        }
//        
//        //GHI DL RA FILE
//        File fileOutput = new File("D:\\LEARNING\\HK4\\JAVA\\error.txt");
//        OutputStream outputStream = new FileOutputStream(fileOutput);
//        OutputStreamWriter outputStreamWriter = new OutputStreamWriter(outputStream);
////        
////        while((line = reader.readLine()) != null)
////        {
////            System.out.println(line);
////            outputStreamWriter.write(line);
////            outputStreamWriter.write("\n");
////        }
////        outputStreamWriter.flush();
////        // Đây là phương thức quan trọng!
////        // Nó sẽ bắt chương trình chờ ghi dữ liệu xong thì mới kết thúc chương trình.
//        
//        //TRUY VẤN
//		Statement sttm;
//		sttm = connection.createStatement();
//		int stt = 1;
//        while((line = reader.readLine()) != null)
//        {
//            //System.out.println(line);
//
//            String MaHV = line.substring(0, 10);
//            String TenHV = line.substring(10, 59);
//            String NS = line.substring(59, 69);
//            String GT = line.substring(69, 72);
//            String Diem = line.substring(72, 76);
//            
//            line = "";
//    		String query = "INSERT INTO HOCVIEN VALUES (N'" + MaHV + "', '" + TenHV + "', '" + NS + "', '" + GT + "', " + Diem + ")";
//    		sttm.executeUpdate(query);
//    		
//    		String er = "Dong" + stt + "\n";
//	        outputStreamWriter.write(er);
//	        stt++;
//        }
//      outputStreamWriter.flush();
//        
//	}
//}
