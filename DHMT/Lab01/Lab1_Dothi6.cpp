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
//		x = 100*sin(3*t*3.14/180);  
//		y = 100*sin(4*t*3.14/180);
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
//	glutCreateWindow("Do thi ham 6");
//	
//	initGL();
//	glutDisplayFunc(mydisplay);    
//	glutMainLoop();
//
//}

