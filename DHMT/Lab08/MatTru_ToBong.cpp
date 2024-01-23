#include "GL/glut.h"
#include "Math.h"
float MatCong[300][300][3];
int N = 10, M = 10;
float gocquayx = 0;
float gocquayy = 0;
void Init(void)
{
    // Thiet lap mau nen
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
 
    // Thiet lap phep chieu
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(-width/2,width/2,-height/2,height/2,100,1000);
    glOrtho(-2.0, 2.0, -2.0, 2.0, -1.5, 1.5);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-400);
    glEnable(GL_DEPTH_TEST);
//    KhoiTaoMatTru();
//    KhoiTaoMoHinhChieuSang();
    return;
}
void KhoiTaoMatTru(void)
{
    int R = 70, A = 150;
    float PI = 4.0*atan(1.0);
    float u, du = 2*PI/M;
    float v, dv = 1.0/N;
    float x, y, z;
    int m, n;
    for (n=0; n<=N; n++) {
            v=n*dv;
            for (m=0; m<=M; m++) {
                   u=m*du;
                   x = R*cos(u);
                  y = A*v;
                   z = R*sin(u);
                   MatCong[n][m][0] = x;
                   MatCong[n][m][1] = y;
                   MatCong[n][m][2] = z;
            }
    }
    return;
}



void ChieuSangMatCong(void)
{
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glPushMatrix();
glRotatef(gocquayx,1,0,0);
glRotatef(gocquayy,0,1,0);
float mauden[] = {0.0, 0.0, 0.0, 1.0};
float mauvang[] = {0.8, 0.8, 0.0, 1.0};
float V[3];
int n, m;
for (n=0; n<=N-1; n++) {
            if (n%2 == 0) {
                   glMaterialfv(GL_FRONT,GL_AMBIENT,mauden);
                   glMaterialfv(GL_FRONT,GL_DIFFUSE,mauden);
                   glMaterialfv(GL_FRONT,GL_SPECULAR,mauden);
            }
            else {
                   glMaterialfv(GL_FRONT,GL_AMBIENT,mauvang);
                   glMaterialfv(GL_FRONT,GL_DIFFUSE,mauvang);
                   glMaterialfv(GL_FRONT,GL_SPECULAR,mauvang);
            }
            for (m=0; m<=M-1; m++) {
            glBegin(GL_QUADS);
	//PhapVector(MatCong[n][m],MatCong[n+1][m],MatCong[n+1][m+1],V);
                   glNormal3fv(V);
                   glVertex3fv(MatCong[n][m]);
                   glVertex3fv(MatCong[n+1][m]);
                   glVertex3fv(MatCong[n+1][m+1]);
                   glVertex3fv(MatCong[n][m+1]);
            glEnd();
            }
}
glPopMatrix();
glDisable(GL_LIGHT0);
glDisable(GL_LIGHTING);
return;
}//main

void KhoiTaoMoHinhChieuSang()
{
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
 
    GLfloat light_pos [] = {0.0, 0.0, 1.0, 0.0};
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
 
    GLfloat ambient [] = {1.0, 0.5, 0.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient);
 
    GLfloat diff_use [] = {0.0, 0.5, 1.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diff_use);
 
    GLfloat specular[] = {1.0, 1.0, 1.0, 1.0};
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
 
    GLfloat shininess = 50.0f;
    glMateriali(GL_FRONT, GL_SHININESS, shininess);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   Init ();
	KhoiTaoMatTru();
    KhoiTaoMoHinhChieuSang();
   glutMainLoop();
   return 0;
}

