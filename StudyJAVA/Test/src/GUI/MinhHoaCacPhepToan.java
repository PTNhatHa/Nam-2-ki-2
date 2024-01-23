package GUI;

import java.awt.*;

import javax.swing.*;

public class MinhHoaCacPhepToan extends JFrame {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new MinhHoaCacPhepToan();

	}
	
	public MinhHoaCacPhepToan()
	{
		this.setTitle("Minh Hoa Cac Phep Toan");
		this.setSize(500, 400);
		this.setDefaultCloseOperation(3);
		
		this.setLayout(new GridLayout(4,1));
		
		JLabel tieude = new JLabel("Minh Hoa Cac Phep Toan");
		tieude.setFont(new Font("arial", Font.BOLD, 15));
		tieude.setHorizontalAlignment(JLabel.LEFT);
		this.add(tieude);
		
		JPanel p = new JPanel();
		p.setLayout(new GridLayout(3, 2));
		JLabel nhapa = new JLabel("Nhap a:");
		p.add(nhapa);
		JTextField nhapa1 = new JTextField("");
		nhapa1.setEditable(true);
		p.add(nhapa1);
		
		JLabel nhapb = new JLabel("Nhap b:");
		p.add(nhapb);
		JTextField nhapb1 = new JTextField("");
		nhapb1.setEditable(true);
		p.add(nhapb1);
		
		JLabel ketqua = new JLabel("Ket Qua:");
		p.add(ketqua);
		JTextField kq = new JTextField("");
		kq.setEditable(true);
		p.add(kq);
		
		this.add(p);
		
		JPanel pt = new JPanel();
		pt.setLayout(new FlowLayout());
		pt.add(new JButton("Cong"));
		pt.add(new JButton("Tru"));
		pt.add(new JButton("Nhan"));
		pt.add(new JButton("Chia"));
		this.add(pt);
		
		JPanel c = new JPanel();
		c.setLayout(new FlowLayout());
		c.add(new JButton("Exit"));
		c.add(new JButton("Reset"));
		this.add(c);
		
		setVisible(true);
	}

}
