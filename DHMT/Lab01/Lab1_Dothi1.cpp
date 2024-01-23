//#include <GL/glut.h>
//#include <Math.h>
//void initGL()
//{
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	glOrtho(-320,320,-240,240,-1,1);	
//}
//
//
//
//void mydisplay()
//{
//    glClear(GL_COLOR_BUFFER_BIT);
//	int x, y, t;
//	
//	glColor3f (1.0, 1.0, 0.0);
//	glBegin(GL_LINE_STRIP);
//	for(t=-720; t<=720; t++)
//	{
//		x = t + 50*2.0*sin(2.0*t*3.14/180); 
//		y = t + 50*2.0*cos(5.0*t*3.14/180);
//		glVertex3f(x, y, 0);
//	}
//	glEnd();
//
//	glViewport(0,0,1500,700);
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
//	glutInitWindowSize(1500, 700);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Do thi ham 1");
//	
//	initGL();
//	glutDisplayFunc(mydisplay);    
//	glutMainLoop();
//
//}

