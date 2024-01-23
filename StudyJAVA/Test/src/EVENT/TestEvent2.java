package EVENT;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;

public class TestEvent2 extends JFrame{
	JTextArea t;
	public static void main(String[] args) {
		new TestEvent2();
	}
	
	public TestEvent2() {
		this.setSize(300, 200);
		this.setDefaultCloseOperation(3);
		
		JButton b = new JButton("Bam");
		this.add(BorderLayout.WEST,b);
		JButton b1 = new JButton("Bam");
		this.add(BorderLayout.EAST,b1);
		t = new JTextArea();
		this.add(t);
		
		b.addActionListener(new Giamsat1(t));
		b1.addActionListener(new Giamsat2(t));
		this.setVisible(true);
	}
}

class Giamsat1 implements ActionListener{
	JTextArea t;
	public Giamsat1(JTextArea t) {
		this.t = t;
	}
	public void actionPerformed(ActionEvent e) {
		t.setText("");
	}
}

class Giamsat2 implements ActionListener{
	JTextArea t;
	public Giamsat2(JTextArea t) {
		this.t = t;
	}
	public void actionPerformed(ActionEvent e) {
		t.setText("Hello world");
	}
}