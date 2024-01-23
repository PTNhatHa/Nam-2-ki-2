package Graphics;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JFrame;

public class CoCaro extends JFrame implements MouseListener {

	public static void main(String[] args)
	{
		new CoCaro();
	}
	int n = 10;
	int s = 25;
	int of = 50;
	public CoCaro()
	{  
		this.setSize(s*n+2*of, s*n+2*of);
		this.setDefaultCloseOperation(3);
		this.addMouseListener(this);
		this.setVisible(true);
	}
	
	public void paint(Graphics g)
	{
		g.setColor(Color.WHITE);
		g.fillRect(0, 0, this.getWidth(), this.getHeight());
		
		g.setColor(Color.BLACK);
		for (int i=0; i<=n; i++)
		{
			g.drawLine(of, of+s*i, of+s*n, of+s*i);
			g.drawLine( of+s*i,of, of+s*i, of+s*n);
		}
		
	}

	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		int x = e.getX();
		int y = e.getY();
		if (x<of || x>=of+s*n) return;
		if (y<of || y>=of+s*n) return;
		int ix = (x-of)/s;
		int iy = (x-of)/s;
		Graphics g = this.getGraphics();
		System.out.println(x+","+y);
		
	}

	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		
	}
}
