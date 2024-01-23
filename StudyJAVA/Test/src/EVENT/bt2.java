package EVENT;

import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import GUI.MinhHoaCacPhepToan;

public class bt2 extends JFrame {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new bt2();

	}
	
	public bt2()
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
		JTextField hienkq = new JTextField("");
		hienkq.setEditable(true);
		p.add(hienkq);
		
		this.add(p);
		
		JPanel pt = new JPanel();
		pt.setLayout(new FlowLayout());
		
		JButton c = new JButton("Cong");
		pt.add(c);
		JButton t = new JButton("Tru");
		pt.add(t);
		JButton n = new JButton("Nhan");
		pt.add(n);
		JButton ch = new JButton("Chia");
		pt.add(ch);
		
		
		this.add(pt);
		
		JPanel o = new JPanel();
		o.setLayout(new FlowLayout());
		JButton exit = new JButton("Exit");
		o.add(exit);
		JButton reset = new JButton("Reset");
		o.add(reset);
		this.add(o);
		
		c.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				try 
				{
					Double a = Double.parseDouble(nhapa1.getText());
					Double b = Double.parseDouble(nhapb1.getText());
					hienkq.setText(""+(a+b));
				} 
				catch (Exception e1) 
				{
					hienkq.setText("Nhap lai ik");
				}
				
			}
		});
		
		t.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				try 
				{
					Double a = Double.parseDouble(nhapa1.getText());
					Double b = Double.parseDouble(nhapb1.getText());
					hienkq.setText(""+(a-b));
				} 
				catch (Exception e1) 
				{
					hienkq.setText("Nhap lai ik");
				}
			}
		});
		
		n.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				try 
				{
					Double a = Double.parseDouble(nhapa1.getText());
					Double b = Double.parseDouble(nhapb1.getText());
					hienkq.setText(""+(a*b));
				} 
				catch (Exception e1) 
				{
					hienkq.setText("Nhap lai ik");
				}
			}
		});
		
		ch.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				try 
				{
					Double a = Double.parseDouble(nhapa1.getText());
					Double b = Double.parseDouble(nhapb1.getText());
					hienkq.setText(""+(a/b));
				} 
				catch (Exception e1) 
				{
					hienkq.setText("Nhap lai ik");
				}
			}
		});

		exit.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		
		reset.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				nhapa1.setText("");
				nhapb1.setText("");
				hienkq.setText("");
			}
		});

		setVisible(true);
	}

}
