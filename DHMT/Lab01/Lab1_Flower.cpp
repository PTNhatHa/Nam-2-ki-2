//#include <GL/glut.h>
//#include <Math.h>
//void initGL()
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	glOrtho(-320,320,-240,240,-1,1);	
//}
//
//void draw8point(int xc, int yc, int x, int y)
//{
//	glBegin(GL_POLYGON); 
//		glVertex3f(xc + x, yc + y, 0.0);  
//		glVertex3f(xc + y, yc + x, 0.0); 
//		glVertex3f(xc + y, yc - x, 0.0); 
//		glVertex3f(xc + x, yc - y, 0.0); 
//		glVertex3f(xc - x, yc - y, 0.0);  
//		glVertex3f(xc - y, yc - x, 0.0);
//		glVertex3f(xc - y, yc + x, 0.0);
//		glVertex3f(xc - x, yc + y, 0.0);
//	glEnd();
//}
//void CircleMidpoint(int xc,int yc,int R )	
//{	 
//   	float P;
//	int y = R; 
//	int x = 0;
//	P = 5/4 - R;
//	draw8point(xc, yc, x, y);
//	while (x < y) 
//    {
//		if (P < 0)	// Chon diem P
//        {
//			P += 2*x + 3;
//        }
//        else      // Chon diem S
//        {	
//            P += 2*(x - y) + 5;
//            y--;
//	    }
//   
//		x++;
//        draw8point(xc,yc,x,y);
//	}
//}
//
//
//void hoa(int xt, int yt, int r) 
//{
//	float x[5], y[5], grad = (float) ((72 * 3.14) / 180);
//	x[0] = xt;
//	y[0] = yt - r;
//	for (int i = 1; i < 5; i++) 
//	{
//		x[i] = (float) (x[0] * cos(i * grad) - y[0] * sin(i * grad) + yt * sin(i * grad) + xt * (1 - cos(i * grad)));
//		y[i] = (float) (x[0] * sin(i * grad) + y[0] * cos(i * grad) + yt * (1 - cos(i * grad)) - xt * sin(i * grad));
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		glColor3f (1.0, 1.0, 1.0);
//		glBegin(GL_POINTS);
//		glVertex3f(-x[i], -y[i], 0);
//		glEnd();
//	}
//	
//	glColor3f (0.0, 1.0, 0.7);
//	CircleMidpoint(-x[0], -y[0], 70 );
//	CircleMidpoint(-x[1], -y[1], 70 );
//	CircleMidpoint(-x[2], -y[2], 70 );
//	CircleMidpoint(-x[3], -y[3], 70 );
//	CircleMidpoint(-x[4], -y[4], 70 );	
//	
//	glColor3f (1.0, 1.0, 0.5);
//	CircleMidpoint(0, 0, 70 );	
//
//}
//void mydisplay()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//
//	hoa(0, 0, 100); 
//
//	glViewport(0,0,640,480);
//	glFlush();
//
//}
//
//int main(int argc, char** argv){
//	
//	glutInit(&argc, argv);
//	int mode=GLUT_SINGLE | GLUT_RGB;
//	glutInitDisplayMode(mode);
//	
//	glutInitWindowSize(640, 480);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Flower");
//	
//	initGL();
//	glutDisplayFunc(mydisplay);    
//	glutMainLoop();
//
//}
//

