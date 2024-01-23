//package Test_CSDL;
//
//import java.awt.Color;
//import java.awt.FlowLayout;
//import java.awt.Font;
//import java.awt.GridLayout;
//import java.awt.event.ActionEvent;
//import java.awt.event.ActionListener;
//
//import javax.swing.JButton;
//import javax.swing.JFrame;
//import javax.swing.JLabel;
//import javax.swing.JPanel;
//import javax.swing.JTextField;
//
//public class ThiThu_Cau1 extends JFrame {
//
//	public static void main(String[] args) {
//		new ThiThu_Cau1();
//
//	}
//	public ThiThu_Cau1()
//	{
//		this.setTitle("Thi Thử Câu 1");
//		this.setSize(500, 400);
//		this.setDefaultCloseOperation(3);
//		
//		this.setLayout(new GridLayout(5,1));
//		
//		JLabel tieude = new JLabel("Minh Hoa Cac Phep Toan");
//		tieude.setFont(new Font("arial", Font.BOLD, 15));
//		tieude.setHorizontalAlignment(JLabel.CENTER);
//		this.add(tieude);
//		
//		JPanel p = new JPanel();
//		p.setLayout(new GridLayout(3, 2));
//		
//		JLabel nhapa = new JLabel("Nhap a:");
//		p.add(nhapa);
//		JTextField nhapa1 = new JTextField("");
//		nhapa1.setEditable(true);
//		p.add(nhapa1);
//		
//		JLabel nhapb = new JLabel("Nhap b:");
//		p.add(nhapb);
//		JTextField nhapb1 = new JTextField("");
//		nhapb1.setEditable(true);
//		p.add(nhapb1);
//		
//		JLabel nhapc = new JLabel("Nhap c:");
//		p.add(nhapc);
//		JTextField nhapc1 = new JTextField("");
//		nhapc1.setEditable(true);
//		p.add(nhapc1);
//		this.add(p);
//		
//		JPanel p1 = new JPanel();
//		p1.setLayout(new GridLayout(2, 1));
//		JButton dt = new JButton("Tính Diện Tích");
//		p1.add(dt);
//		JButton cv = new JButton("Tính Chu Vi");
//		p1.add(cv);
//		this.add(p1);
//		
//
//		
//		JPanel p2 = new JPanel();
//		p2.setLayout(new GridLayout(1, 2));
//		
//		JLabel kq = new JLabel("Kết Quả: ");
//		p2.add(kq);
//		JTextField kq1 = new JTextField("kq");
//		kq1.setBackground(Color.white);
//		kq1.setEditable(false);
//		p2.add(kq1);
//		this.add(p2);
//		
//		dt.addActionListener(new ActionListener() {
//			
//			@Override
//			public void actionPerformed(ActionEvent e) {
//				try 
//				{
//					Double a = Double.parseDouble(nhapa1.getText());
//					Double b = Double.parseDouble(nhapb1.getText());
//					Double c = Double.parseDouble(nhapc1.getText());
//					Double p = (a+b+c)/2;
//					kq1.setText(""+(Math.sqrt(p*(p-a)*(p-b)*(p-c))));
//				} 
//				catch (Exception e1) 
//				{
//					kq1.setText("Nhap lai ik");
//				}
//				
//			}
//		});
//		
//		cv.addActionListener(new ActionListener() {
//			
//			@Override
//			public void actionPerformed(ActionEvent e) {
//				try 
//				{
//					Double a = Double.parseDouble(nhapa1.getText());
//					Double b = Double.parseDouble(nhapb1.getText());
//					Double c = Double.parseDouble(nhapc1.getText());
//					kq1.setText(""+(a+b+c));
//				} 
//				catch (Exception e1) 
//				{
//					kq1.setText("Nhap lai ik");
//				}
//			}
//		});
//		
//		setVisible(true);
//	}
//
//}
