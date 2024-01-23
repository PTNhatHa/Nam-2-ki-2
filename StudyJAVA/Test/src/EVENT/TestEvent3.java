package EVENT;



import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;

public class TestEvent3 extends JFrame{
	public static void main(String[] args) {
		new TestEvent3();
	}
	
	public TestEvent3() {
		this.setSize(300, 200);
		this.setDefaultCloseOperation(3);
		
		JButton b = new JButton("Bam");
		this.add(BorderLayout.WEST,b);
		JButton b1 = new JButton("Bam");
		this.add(BorderLayout.EAST,b1);
		JTextArea t = new JTextArea();
		this.add(t);
		
		b.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				t.setText("");
				
			}
		});
		b1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				t.setText("hello");
				
			}
		});
		this.setVisible(true);
	}
}
