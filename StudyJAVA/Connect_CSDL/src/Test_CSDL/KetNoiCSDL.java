package Test_CSDL;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class KetNoiCSDL {

	public static void main(String[] args) throws SQLException {
		// TODO Auto-generated method stub
		Connection connection = null;
		try {
			Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
			String connectionURL="jdbc:sqlserver://NHATHA:1433;databaseName=CSDL_JAVA;integratedSecurity=true";
			connection = DriverManager.getConnection(connectionURL);
			System.out.println("Kết nối thành công");
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			System.out.println("Kết nối thất bại");
			System.err.println(e.getMessage()+"\n"+e.getClass()+"\n"+e.getCause());
		}
	}

}
