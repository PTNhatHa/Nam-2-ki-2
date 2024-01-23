package Graphics;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JFrame;

public class TestGraphics extends JFrame {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new TestGraphics();

	}
	
	public TestGraphics()
	{
		this.setSize(400, 300);
		this.setDefaultCloseOperation(3);
		
		this.setVisible(true);
	}
	
	public void paint(Graphics g)
	{
		//trước khi vẽ nên tạo lớp nền trắng để tránh bị lem màu
		g.setColor(Color.WHITE);
		g.fillRect(0, 0, this.getWidth(), this.getHeight());
		
		g.setColor(Color.RED);
		g.fillRect(50, 50, 300, 200);
		
//		g.setColor(Color.YELLOW);
//		g.fillOval(150, 100, 100, 100);
		

		int x[] = new int[5], y[] = new int[5], grad = (int) ((72 * 3.14) / 180);
		x[0] = 15;
		y[0] = 20 - 10;
		for (int i = 1; i < 5; i++) 
		{
		x[i] = (int) (x[0] * Math.cos(i * grad) - y[0] * Math.sin(i * grad) + 20 * Math.sin(i * grad) + 20 * (1 - Math.cos(i * grad)));
		y[i] = (int) (x[0] * Math.sin(i * grad) + y[0] * Math.cos(i * grad) + 20 * (1 - Math.cos(i * grad)) - 20 * Math.sin(i * grad));
		}
		
		g.setColor(Color.BLACK);
		g.fillPolygon(x, y, 10);
	}

}
