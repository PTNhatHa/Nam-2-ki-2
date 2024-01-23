//package Thread;
//
//import java.awt.*;
//import java.awt.Graphics;
//import java.awt.image.BufferedImage;
//import java.util.Random;
//
//import javax.swing.JFrame;
//
//public class BanBiA extends JFrame 
//{
//	public static void main(String[] args) 
//	{
//		new BanBiA();
//	}
//
//	int w = 400, h = 200;
//	int off = 50;
//	Ball b[] = new Ball[5];
//	BufferedImage img;
//	Graphics g;
//	Random rand = new Random();
//	
//	public BanBiA() 
//	{
//		this.setSize(w + 2 * off, h + 2 * off);
//		this.setDefaultCloseOperation(3);
//		img = new BufferedImage(w + 2 * off, h + 2 * off, 3);
//		g = img.getGraphics();
//		for (int i = 0; i < b.length; i++) 
//		{
//			b[i] = new Ball(this, 100, 100, rand.nextDouble()-0.5, rand.nextDouble()-0.5, 20);
//			b[i].start();
//		}
//		this.setVisible(true);
//	}
//
//	public void paint(Graphics g1) 
//	{
//		g.setColor(Color.WHITE);
//		g.fillRect(0, 0, this.getWidth(), this.getHeight());
//
//		g.setColor(Color.PINK);
//		g.fillRect(off, off, w, h);
//		g.setColor(Color.BLACK);
//		g.drawRect(off, off, w, h);
//
//		
//		for (int i=0;i<b.length;i++) 
//		{
//			g.setColor(Color.CYAN);
//			g.fillOval((int) (off + b[i].x - b[i].r), (int) (off + b[i].y - b[i].r), (int) (b[i].r * 2), (int) (b[i].r * 2));
//			g.setColor(Color.BLACK);
//			g.drawOval((int) (off + b[i].x - b[i].r), (int) (off + b[i].y - b[i].r), (int) (b[i].r * 2), (int) (b[i].r * 2));
//
//		}
//				
//		g1.drawImage(img, 0, 0, null);
//		try 
//		{
//			Thread.sleep(10);
//		} 
//		catch (Exception e) {
//		}
//		this.repaint();
//	}
//}
//
//class Ball extends Thread 
//{
//	BanBiA table;
//	double x, y;
//	double vx, vy;
//	double r;
//
//	public Ball(BanBiA table, double x, double y, double vx, double vy, double r) 
//	{
//		this.table = table;
//		this.x = x;
//		this.y = y;
//		this.vx = vx;
//		this.vy = vy;
//		this.r = r;
//	}
//
//	public void run() 
//	{
//		while (true) 
//		{
//			x = x + vx;
//			y = y + vy;
//
//			if (x - r <= 0 || x + r >= table.w)
//				vx = -vx;
//			if (y - r <= 0 || y + r >= table.h)
//				vy = -vy;
//
//			try {
//				Thread.sleep(1);
//			} catch (Exception e) {
//			}
//		}
//	}
//	
//}