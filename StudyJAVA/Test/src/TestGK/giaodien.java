package TestGK;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;

public class giaodien extends JFrame {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new giaodien();
	}

	giaodien()
	{
		this.setTitle("Hello Clander");
		this.setSize(400, 300);
		this.setDefaultCloseOperation(3);
		
		this.setLayout(new GridLayout(2, 2));
		
		JButton b1 = new JButton("1, January");
		this.add(b1);
		JButton b2 = new JButton("2, February");
		this.add(b2);
		JButton b3 =new JButton("3, March");
		this.add(b3);
		
		JPanel p = new JPanel();
		p.setLayout(new GridLayout(2,2));
		JButton b4 = new JButton("4, April");
		p.add(b4);
		JButton b5 = new JButton("5, May");
		p.add(b5);
		JButton b6 = new JButton("6, June...");
		p.add(b6);
		this.add(p);
		
		b1.addActionListener(new click_button());
		b2.addActionListener(new click_button());
		b3.addActionListener(new click_button());
		b4.addActionListener(new click_button());
		b5.addActionListener(new click_button());
		b6.addActionListener(new click_button());
		
		setVisible(true);
	}
}

class click_button implements ActionListener
{

	@Override
	public void actionPerformed(ActionEvent e) {
		// TODO Auto-generated method stub
		JFrame n = new JFrame();
		n.setSize(200, 100);
		n.add(new JLabel("Hello Calender"));
		n.show();
	}
	
}
