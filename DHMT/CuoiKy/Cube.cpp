#include <math.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;
 
typedef float Matrix3x3[3][3];
typedef float Matrix1x3[1][3];
 
//Khoi tao cac bien toan cuc
//Khoi tao mang chua toa do cac dinh cua hinh lap phuong
float points[8][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
float newpoints[8][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
float Oxy[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 0}};
float Oyz[3][3] = {{0, 0, 0}, {0, 1, 0}, {0, 0, 1}};
float Oxz[3][3] = {{1, 0, 0}, {0, 0, 0}, {0, 0, 1}};

//Tinh toan toa do cac dinh
void inputPoint(float a)
{
    points[0][0] = 2 * a + 100;
    points[0][1] = 2 * a + 100;
    points[0][2] = 2 * a + 100;
   
    points[1][0] = 100;
    points[1][1] = 2 * a + 100;
    points[1][2] = 2 * a + 100;
   
    points[2][0] = 100;
    points[2][1] = 100;
    points[2][2] = 2 * a + 100;
   
    points[3][0] = 2 * a + 100;
    points[3][1] = 100;
    points[3][2] = 2 * a + 100;
 
    points[4][0] = 2 * a + 100;
    points[4][1] = 2 * a + 100;
    points[4][2] = 100;
   
    points[5][0] = 100;
    points[5][1] = 2 * a + 100;
    points[5][2] = 100;
   
    points[6][0] = 100;
    points[6][1] = 100;
    points[6][2] = 100;
   
    points[7][0] = 2 * a + 100;
    points[7][1] = 100;
    points[7][2] = 100;
}

//In toa do cac dinh cua khoi lap phuong
void printPoint(float a[8][3])
{ 
  	for (int i=0; i<8; i++)
	{
        cout << fixed;
        cout << setprecision(2);
        cout << setw(10) << "Dinh " << (i+1) << ": ";
        cout << "(" << setw(3);
        for (int j=0;j<3;j++)
		{
            cout << setw(10);
            cout << a[i][j];
            if(j==2) cout << setw(3)<< ")" << endl;
            else cout << ",";
        }
  	}
  	cout << endl;
}
 
//Ve khoi lap phuong theo toa do cac dinh
void Draw(float a[8][3])
{
    int i;
    glColor3f(1.0, 0.6, 0.6); //hong
    glBegin(GL_POLYGON);
    glVertex3f(a[0][0], a[0][1], a[0][2]);
    glVertex3f(a[1][0], a[1][1], a[1][2]);
    glVertex3f(a[2][0], a[2][1], a[2][2]);
    glVertex3f(a[3][0], a[3][1], a[3][2]);
    glEnd();
    i = 0;
    glColor3f(0.6, 0.8, 1.0); //xanh-tim
    glBegin(GL_POLYGON);
    glVertex3s(a[0 + i][0], a[0 + i][1], a[0 + i][2]);
    glVertex3s(a[1 + i][0], a[1 + i][1], a[1 + i][2]);
    glVertex3s(a[5 + i][0], a[5 + i][1], a[5 + i][2]);
    glVertex3s(a[4 + i][0], a[4 + i][1], a[4 + i][2]);
    glEnd();
    glColor3f(0.6, 1.0, 0.7); //xanh la
    glBegin(GL_POLYGON);
    glVertex3f(a[0][0], a[0][1], a[0][2]);
    glVertex3f(a[3][0], a[3][1], a[3][2]);
    glVertex3f(a[7][0], a[7][1], a[7][2]);
    glVertex3f(a[4][0], a[4][1], a[4][2]);
    glEnd();
    i = 1;
    glColor3f(1.0, 1.0, 0.5); //vang 
    glBegin(GL_POLYGON);
    glVertex3s(a[0 + i][0], a[0 + i][1], a[0 + i][2]);
    glVertex3s(a[1 + i][0], a[1 + i][1], a[1 + i][2]);
    glVertex3s(a[5 + i][0], a[5 + i][1], a[5 + i][2]);
    glVertex3s(a[4 + i][0], a[4 + i][1], a[4 + i][2]);
    glEnd();
    i = 2;
    glColor3f(0.5, 0.6, 0.2);
    glBegin(GL_POLYGON);
    glVertex3s(a[0 + i][0], a[0 + i][1], a[0 + i][2]);
    glVertex3s(a[1 + i][0], a[1 + i][1], a[1 + i][2]);
    glVertex3s(a[5 + i][0], a[5 + i][1], a[5 + i][2]);
    glVertex3s(a[4 + i][0], a[4 + i][1], a[4 + i][2]);
    glEnd();
    i = 4;
    glColor3f(0.7, 0.3, 0.4);
    glBegin(GL_POLYGON);
    glVertex3f(a[0 + i][0], a[0 + i][1], a[0 + i][2]);
    glVertex3f(a[1 + i][0], a[1 + i][1], a[1 + i][2]);
    glVertex3f(a[2 + i][0], a[2 + i][1], a[2 + i][2]);
    glVertex3f(a[3 + i][0], a[3 + i][1], a[3 + i][2]);
    glEnd();
}
 
//Ve cac truc toa do
void drawCoordinateAxisZ()
{
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 2000.0f);
    glEnd();
    glLineWidth(1.0f);
}

void drawCoordinateAxisX()
{
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(2000.0f, 0.0f, 0.0f);
    glEnd();
    glLineWidth(1.0f);
}

void drawCoordinateAxisY()
{
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 2000.0f, 0.0f);
    glEnd();
    glLineWidth(1.0f);
}

void drawCoordinateAxis()
{
    glColor3f(0.0f, 0.0f, 1.0f);
    drawCoordinateAxisZ();
    glColor3f(0.0f, 1.0f, 0.0f);
    drawCoordinateAxisY();
    glColor3f(1.0f, 0.0f, 0.0f);
    drawCoordinateAxisX();
}

void nhan2MaTran(float a[1][3], float b[3][3], float c[1][3])
{
    for (int j = 0; j < 3; ++j) 
	{
        c[0][j] = 0;
        for (int k = 0; k < 3; ++k) 
		{
            c[0][j] += a[0][k] * b[k][j];
        }
    }
}

 
void PhepChieuTrucGiao()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    drawCoordinateAxis();
    glColor3f(1.0, 0.0, 0.0);
    Draw(points);
	cout <<"Phep chieu truc giao" <<endl;
	float p1[1][3], p2[1][3];
	//Oxy
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			p1[0][j] = points[i][j];
		}
		nhan2MaTran(p1, Oxy, p2);
		for(int j = 0; j < 3; j++)
		{
			newpoints[i][j] = p2[0][j];
		}
	}
	Draw(newpoints);
	cout<<"Chieu len Oxy:\n";
    printPoint(newpoints);
    
	//Oxz
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			p1[0][j] = points[i][j];
		}
		nhan2MaTran(p1, Oxz, p2);
		for(int j = 0; j < 3; j++)
		{
			newpoints[i][j] = p2[0][j];
		}
	}
	Draw(newpoints);
	cout<<"Chieu len Oxz:\n";
    printPoint(newpoints);
    
	//Oyz
	for(int i = 0; i < 8; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			p1[0][j] = points[i][j];
		}
		nhan2MaTran(p1, Oyz, p2);
		for(int j = 0; j < 3; j++)
		{
			newpoints[i][j] = p2[0][j];
		}
	}
    Draw(newpoints);
	cout<<"Chieu len Oyz:\n";
    printPoint(newpoints);
    glFlush();

} 

void ThayDoiGocQuanSat()
{
	
} 

void ThayDoiViTriQuanSat()
{
	
} 
 
 
//Hien thi
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //-----------------------------------------------------------
    gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    //-----------------------------------------------------------
    drawCoordinateAxis();
    glColor3f(1.0, 0.0, 0.0);
    Draw(points);
    glFlush();
    
    
//    glPushMatrix();
//    drawCoordinateAxis();
//    glColor3f(1.0, 0.0, 0.0);
//    Draw(points);
//    glPopMatrix();
//    glutSwapBuffers();
}
 
//Khoi tao
void init(void)
{
    glOrtho(-1000.0, 1000.0, -500.0, 500.0, -500.0, 500.0);
    glEnable(GL_DEPTH_TEST); //Hien thi theo chieu sau cua vat the
}
 
int main(int argc, char *argv)
{
    glutInit(&argc, &argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1362, 750);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Cube");
    init();
 
    //Nhap canh a
    float a;
    cout <<"Nhap do dai canh a = "; //Nhap a > 100 cho de nhin
    cin >>a;
    inputPoint(a/2.0);
    cout <<"\nCac dinh Cube:\n\n";
  	printPoint(points);
  	glutDisplayFunc(display);


	int option = 1;
	while(option != 0)
	{
		cout << "---------------------------------------------\n";
		cout <<" 1. Phep chieu truc giao\n";
		cout <<" 2. Thay doi goc quan sat\n";
		cout <<" 3. Thay doi vi tri quan sat (diem nhin)\n";
		cout <<" 0. Thoat\n";
		cout << "---------------------------------------------\n";
		cout << "Chon stt hanh dong: ";
		cin >> option;
		cout << "---------------------------------------------\n";
		if(option == 1)
		{
		  	glutDisplayFunc(PhepChieuTrucGiao);
		  	glutMainLoop();
		}
		
		if(option == 2)
		{
			glutDisplayFunc(ThayDoiGocQuanSat);
		  	glutMainLoop();
		}
		
		if(option == 3)
		{
			glutDisplayFunc(ThayDoiViTriQuanSat);
		  	glutMainLoop();
		}
	}

    glutMainLoop();
    return 0;
}//main


