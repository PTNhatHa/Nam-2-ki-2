package CK;

import java.awt.*;
import java.sql.*;
import java.io.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.*;

public class De_3_102210159_PhanTranNhatHa extends JFrame {

	public static void main(String[] args) throws Exception  {
		new De_3_102210159_PhanTranNhatHa();
		
		
		
	}
	
	public De_3_102210159_PhanTranNhatHa() throws Exception
	{
		Class.forName("com.microsoft.sqlserver.jdbc.SQLServerDriver");
		System.out.println("Tai driver thanh cong!");
		Connection cnn = DriverManager.getConnection("jdbc:sqlserver://NHATHA:1433;databaseName=CK_JAVA;integratedSecurity=true");
		System.out.println("Ket noi co so du lieu thanh cong");
		this.setTitle("Dong Ho");
		this.setSize(600, 400);
		this.setDefaultCloseOperation(3);
		
		this.setLayout(new GridLayout(1,2));
		JPanel p1 = new JPanel();
		this.add(p1);
		
		JPanel p2 = new JPanel();
		p2.setLayout(new GridLayout(2,1));
		
		JPanel a = new JPanel();
		a.setLayout(new GridLayout(3,1));
		
		JPanel a1 = new JPanel();
		a1.setLayout(new GridLayout(1,3));
		JLabel lb1 = new JLabel("Import data");
		a1.add(lb1);
		JTextField txt1 = new JTextField("import.txt");
		a1.add(txt1);
		JButton bt1 = new JButton("Import file");
		a1.add(bt1);
		
		JPanel a2 = new JPanel();
		a2.setLayout(new GridLayout(1,2));
		JLabel lb2 = new JLabel("Keyword");
		a2.add(lb2);
		JTextField txt2 = new JTextField("Day di hoc");
		txt2.setSize(500,20);
		a2.add(txt2);
		
		JPanel a3 = new JPanel();
		a3.setLayout(new FlowLayout());
		JButton del = new JButton("Delete");
		a3.add(del);
		JButton search = new JButton("Search");
		a3.add(search);
		JButton show = new JButton("Show All");
		a3.add(show);
		
		JTextArea area = new JTextArea();
		
		a.add(a1);
		a.add(a2);
		a.add(a3);
		p2.add(a);
		p2.add(area);
		this.add(p2);
		
		bt1.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				try 
				{
					System.out.println(txt1.getText()); //D:\\LEARNING\\HK4\\JAVA\\Input_ck.txt
					FileReader fr = new FileReader(txt1.getText());
					System.out.println(txt1.getText());
					BufferedReader br = new BufferedReader(fr);
					String line = "";
					String s = "";

				    while((line = br.readLine()) != null)
				    {
				    	s += line + "\n";
				    }
			    	area.setText(s);
//			    	while((line = br.readLine()) != null)
//				    {
//				    	area.append(line.trim() + "\n");
//		            	String[] data = line.split(",");
//		            	String query = "INSERT INTO Dongho (Name, Time, Duration) VALUES (?, ?, ?)";
//		            	PreparedStatement ps = cnn.prepareStatement(query);
//		            	ps.setString(1, data[0].trim());
//		            	ps.setString(2, data[1].trim());
//		            	ps.setInt(3, Integer.parseInt(data[2].trim()));
//		            	ps.executeUpdate();
//		            	ps.close();
//				    }
//				    br.close();
				} 
				catch (Exception e1) 
				{
					area.setText("Link co dang: ..\\..\\..\\.txt");
				}
				
			}
		});
		
		setVisible(true);
	}
}
