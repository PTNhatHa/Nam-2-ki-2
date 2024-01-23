//#include <GL/glut.h>
//#include <math.h>
//#include "stdio.h"
//
//#define M_PI    3.14159265358979323846
//static GLfloat gocX = 0.0f;
//static GLfloat gocY = 0.0f;
//static GLfloat gocZ = 0.0f;
//static GLfloat size = 0.5;
//int HinhVe = 1;
//
//void veTuDien(float r)
//{
//    float x, y, z, Delta_U, Delta_V, u, v, Pi_2;
//    Pi_2 = M_PI / 2;
//    Delta_U = 0.1;
//    Delta_V = 0.1;
//
//    glColor3f(1.0, 0.2, 0.5);
//    glBegin(GL_POLYGON);
//    glVertex3f(r, 0.0f, 0.0f);
//    glVertex3f(0.0f, r, 0.0f);
//    glVertex3f(-r, 0.0f, 0.0f);
//    glEnd();
//    glFlush ();
//
//    glColor3f(0.3, 1.0, 0.5);
//    glBegin(GL_POLYGON);
//    glVertex3f(-r, 0.0f, 0.0f);
//    glVertex3f(0.0f, r, 0.0f);
//    glVertex3f(0.0f, 0.0f, -r);
//    glEnd();
//    glFlush ();
//
//    glColor3f(1.0, 0.0, 0.5); 
//    glBegin(GL_POLYGON);
//    glVertex3f(0.0f, 0.0f, -r);
//    glVertex3f(0.0f, r, 0.0f);
//    glVertex3f(r, 0.0f, 0.0f);
//    glEnd();
//    glFlush ();
//
//    glColor3f(0.5, 0.0, 1.8);
//    glBegin(GL_POLYGON);
//    glVertex3f(-r, 0.0f, 0.0f);    
//    glVertex3f(0.0f, 0.0f, -r);    
//    glVertex3f(r, 0.0f, 0.0f);    
//    glEnd();
//    
//    glFlush ();
//}
//
//void myDisplay(void)
//{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glPushMatrix();
//    glRotatef(gocX, 1.0f, 0.0f, 0.0f);
//    glRotatef(gocY, 0.0f, 1.0f, 0.0f);
//    glRotatef(gocZ, 0.0f, 0.0f, 1.0f);
//
//    veTuDien(size);
//
//    glPopMatrix();
//    glutSwapBuffers();
//}
//
//void myKeyboard(int key, int x, int y)
//{
//    if (key == GLUT_KEY_END)           exit(0);
//    if (key == GLUT_KEY_DOWN)          gocX -= 5.0f;
//    if (key == GLUT_KEY_UP)                   gocX += 5.0f;
//    if (key == GLUT_KEY_RIGHT)         gocY -= 5.0f;
//    if (key == GLUT_KEY_LEFT)          gocY += 5.0f;
//    if (key == GLUT_KEY_PAGE_DOWN)            gocZ -= 5.0f;
//    if (key == GLUT_KEY_PAGE_UP)       gocZ += 5.0f;
//    glutPostRedisplay();
//}
//
//void myColor(unsigned char k, int x, int y)
//{
//    printf("k= %d", k);
//    switch (k) {
//
//        case 114:    glColor3f(1, 0, 0);   
//            glutPostRedisplay();
//            break;
//        case  103: glColor3f(0, 1, 0); 
//            glutPostRedisplay();
//            break;
//        case  98:    glColor3f(0, 0, 1); 
//            glutPostRedisplay();
//            break;
//        case 49:     HinhVe = 1;
//            glutPostRedisplay();
//            break;
//        case 50:     HinhVe = 2;
//            glutPostRedisplay();
//            break;
//        default:      break;
//    }
//}
//
//void myMouse(int button, int state, int x, int y)
//{
//    if ((button == GLUT_LEFT_BUTTON) & (state == GLUT_DOWN))  size = size + 0.05;
//    if ((button == GLUT_RIGHT_BUTTON) & (state == GLUT_DOWN))  size = size - 0.05;
//    glutPostRedisplay();
//}
//
//int main(int argc, char** argv)
//{
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(600, 600);
//    glutInitWindowPosition(50, 50);
//    glutCreateWindow("Khoi tu dien");
//    glClearColor(0.0, 0.0, 0.0, 0.0);
//    glColor3f(0, 0, 0);
//    glutDisplayFunc(myDisplay);

//    glutSpecialFunc(myKeyboard);

//    glutKeyboardFunc(myColor);
//    glutMouseFunc(myMouse);
//    glutMainLoop();
//    return 0;
//}
