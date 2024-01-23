package EVENT;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;

public class bt1 extends JFrame {

	public static void main(String[] args) {
		new bt1();

	}
	
	public bt1()
	{
		this.setSize(300, 200);
		this.setDefaultCloseOperation(3);
		this.setBackground(Color.green);
		this.getContentPane().setBackground(Color.black);
		
		this.setLayout(new FlowLayout());
		JButton gr = new JButton("Green");
		this.add(gr);
		JButton bl = new JButton("Blue");
		this.add(bl);
		JButton r = new JButton("Red");
		this.add(r);
		JButton ex = new JButton("Exit");
		this.add(ex);
		
		gr.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				getContentPane().setBackground(Color.green);
			}
		});
			
		bl.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				getContentPane().setBackground(Color.blue);
			}
		});
		r.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				getContentPane().setBackground(Color.red);
			}
		});
		ex.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.exit(0);
			}
		});
		
		this.setVisible(true);
	}

}
