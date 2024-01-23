package EVENT;

import java.awt.*;
import javax.swing.*;

public class bt3 extends JFrame {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new bt3();
	}
	
	public bt3()
	{
		this.setTitle("Calculator");
		this.setSize(400, 500);
		this.setDefaultCloseOperation(3);
		
		this.setLayout(new BorderLayout());
		
		JTextField tf = new JTextField("0");
		tf.setEditable(false);
		tf.setFont(new Font("arial", Font.BOLD, 50));
		tf.setHorizontalAlignment(JTextField.RIGHT);
		this.add(BorderLayout.NORTH, tf);
		
		JPanel p = new JPanel();
		p.setLayout(new GridLayout(5, 4));
		String t[][] = {
							{"CE", "C", "B", "/"},
							{"7", "8", "9", "x"},
							{"4", "5", "6", "-"},
							{"1", "2", "3", "+"},
							{"+/-", "0", ".", "="} 
						};
		
		for (int i=0; i<5; i++)
		{
			for (int j=0; j<4; j++)
			{
				JButton b = new JButton(t[i][j]);
				tf.setFont(new Font("arial", Font.BOLD, 20));
				p.add(b);
			}
		}
		
		this.add(BorderLayout.CENTER, p);
		
		setVisible(true);
		
	};

}
