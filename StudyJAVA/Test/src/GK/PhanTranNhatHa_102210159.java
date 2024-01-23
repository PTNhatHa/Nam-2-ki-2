package GK;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

import javax.swing.*;

public class PhanTranNhatHa_102210159 extends JFrame {
	

	JPanel p2 = new JPanel();
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new ThiGK();
	}
	public void paint(Graphics g, int x, int y)
	{
		g.setColor(Color.WHITE);
		g.fillRect(0, 0, this.getWidth(), this.getHeight());
		
		g.setColor(Color.BLACK);
		
		
		g.drawOval(x, y, 5, 5);
		p2.paintComponents(g);
		
	}

	ThiGK()
	{
		this.setTitle("Kiểm tra giữa kì");
		this.setSize(500, 300);
		this.setDefaultCloseOperation(3);
		
		this.setLayout(new BorderLayout());
		
		JPanel pp = new JPanel();
		pp.setLayout(new BorderLayout());
		
		JPanel p = new JPanel();
		p.setLayout(new FlowLayout());
		
		JButton rp1 = new JButton("Rand Point");
		p.add(rp1);
		JTextField t1 = new JTextField("", 10);
		t1.setEditable(true);
		p.add(t1);
		
		JButton rp2 = new JButton("Rand Pair");
		p.add(rp2);
		JTextField t2 = new JTextField("", 10);
		t1.setEditable(true);
		p.add(t2);
		
		JPanel p1 = new JPanel();
		p1.setLayout(new FlowLayout());
		
		JButton check = new JButton("Check?");
		p1.add(check);
		JTextField c = new JTextField("", 10);
		c.setEditable(false);
		p1.add(c);
		
		JButton exit = new JButton("Exit");
		p1.add(exit);
		
		
		exit.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				System.exit(0);
			}
		});
		
		rp1.addActionListener(new ActionListener() {
			
			@Override
			public void actionPerformed(ActionEvent e) {
				// TODO Auto-generated method stub
				Double n = Double.parseDouble(t1.getText());
				Graphics g = null;
				for(int i=0; i<n; i++)
				{
					Random x = new Random();
					Random y = new Random();
					paint(g, x.nextInt(), y.nextInt());
					
				}
				
			}
		});
		
		p2.setBackground(Color.GRAY);
		
		pp.add(BorderLayout.NORTH, p);
		pp.add(BorderLayout.CENTER, p1);
		this.add(BorderLayout.NORTH, pp);
		this.add(BorderLayout.CENTER, p2);
		
		this.setVisible(true);
	}
}
