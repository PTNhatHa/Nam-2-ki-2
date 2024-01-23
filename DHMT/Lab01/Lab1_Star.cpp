//#include <GL/glut.h>
//#include <Math.h>
//void initGL()
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	glOrtho(-320,320,-240,240,-1,1);	
//}
//
//void ngoisao(int xt, int yt, int r) 
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
//		glColor3f (1.0, 0.3, 0.0);
//		glBegin(GL_POINTS);
//		glVertex3f(-x[i], -y[i], 0);
//		glEnd();
//	}
//	
//	glColor3f (1.0, 0.3, 0.0);
//	glBegin(GL_LINE_STRIP);
//		    glVertex3f(-x[0], -y[0], 0);  
//		    glVertex3f(-x[2], -y[2], 0);  
//		    glVertex3f(-x[4], -y[4], 0);  
//			glVertex3f(-x[1], -y[1], 0);  
//			glVertex3f(-x[3], -y[3], 0); 
//			glVertex3f(-x[0], -y[0], 0);  
//	glEnd();
//
//}
//
//void mydisplay()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//
//	ngoisao(0, 0, 100); 
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
//	glutCreateWindow("Star");
//	
//	initGL();
//	glutDisplayFunc(mydisplay);    
//	glutMainLoop();
//
//}

