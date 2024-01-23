package GAME_TEST;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Rectangle;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;
import javax.swing.JFrame;

public class KhungLong extends JFrame implements KeyListener {
	public static void main(String arg[]) {
		new KhungLong();
	}
	NhanVat nhanvat;
	BufferedImage img;
	Graphics g;
	public KhungLong() {
		this.addKeyListener(this);
		nhanvat = new NhanVat();
		nhanvat.start();
		this.setSize(400, 300);
		img = new BufferedImage(400, 300,3);
		g = img.getGraphics();
		this.setDefaultCloseOperation(3);
		this.setVisible(true);
	}
	Rectangle vitri(Rectangle r,int nx, int ny,int ix,int iy) {
		double w = (double)(r.width+20)/nx;
		double h = (double)r.height/ny;
		return new Rectangle(r.x+(int)(w*ix+0.5), r.y+(int)(w*iy+0.5), (int)(w+0.5), (int)(h+0.5));
	}
	public void paint(Graphics g1) {
		g.setColor(Color.WHITE);
		g.fillRect(0, 0, getWidth(), getHeight());
		
		Rectangle nv = vitri(new Rectangle(0, 0, nhanvat.imgs.getWidth(), nhanvat.imgs.getHeight()),5,2,nhanvat.getstate(),0);
		g.drawImage(nhanvat.imgs, 50, 250-100-(int)nhanvat.h, 50+100*nv.width/nv.height,250-(int)nhanvat.h, nv.x,nv.y,nv.x+nv.width,nv.y+nv.height,null);
		g1.drawImage(img, 0, 0, null);
		repaint();
	}
	@Override
	public void keyTyped(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
	@Override
	public void keyPressed(KeyEvent e) {
		if(e.getKeyCode() == KeyEvent.VK_SPACE)
		{
			nhanvat.setJump();
		}
		
	}
	@Override
	public void keyReleased(KeyEvent e) {
		// TODO Auto-generated method stub
		
	}
	

}

class NhanVat extends Thread{
	BufferedImage imgs;
	double a = -0.1;
	double v = 0;
	double h = 0;
	public NhanVat() {
		try {
			imgs = ImageIO.read(new File("C:\\Users\\PhanHa\\Pictures\\Ni\\NhanVat.png"));
		} catch (IOException e) {
		}
	}
	public int getstate() {
		if (h==0) return 0;
		else if (h<20) return 1;
		else if (v>0) return 2;
		else if (h>20) return 3;
		else return 4;
	}
	public void setJump() {
		if (h==0)
			this.v = 5.0;
	}
	public void run() {
		while (true) {
			v = v + a;
			h = h + v;
			if (h<=0) {
				h = 0;
				v = 0;
			}
			try {
				Thread.sleep(10);
			} catch (Exception e) {
			}
		}
	}

	
}

class Cay extends Thread{
	BufferedImage imgs;
	double a = -0.1;
	double v = 0;
	double h = 0;
	public Cay() {
		try {
			imgs = ImageIO.read(new File("C:\\Users\\PhanHa\\Pictures\\Ni\\NhanVat.png"));
		} catch (IOException e) {
		}
	}
	public int getstate() {
		if (h==0) return 0;
		else if (h<20) return 1;
		else if (v>0) return 2;
		else if (h>20) return 3;
		else return 4;
	}
	public void setJump() {
		if (h==0)
			this.v = 5.0;
	}
	public void run() {
		while (true) {
			v = v + a;
			h = h + v;
			if (h<=0) {
				h = 0;
				v = 0;
			}
			try {
				Thread.sleep(10);
			} catch (Exception e) {
			}
		}
	}

	
}