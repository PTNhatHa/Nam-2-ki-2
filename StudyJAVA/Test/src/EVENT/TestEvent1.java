package EVENT;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;

public class TestEvent1 extends JFrame implements ActionListener{
	JTextArea t;
	public static void main(String[] args) {
		new TestEvent1();
	}
	
	public TestEvent1() {
		this.setSize(300, 200);
		this.setDefaultCloseOperation(3);
		
		JButton b = new JButton("OK");
		b.addActionListener(this);
		this.add(BorderLayout.WEST,b);
		
		JButton b1 = new JButton("OK");
		b1.addActionListener(this);
		this.add(BorderLayout.EAST,b1);
		
		t = new JTextArea();
		this.add(t);
		this.setVisible(true);
	}
	public void actionPerformed(ActionEvent e) {
		if (e.getActionCommand().equals("OK"))
			t.setText("");
		else
			t.setText("hello world");
	}
}