
#include <Windows.h>
#include <GL/freeglut.h>
#include <iostream>
#include "math.h"
#define DUZELT 0.0174532925
float derece = 0;
float xgotur = 0, ygotur = 0, zgotur = 0;
int en = 500, boy = 200;
float solKolAci = 0.0f;
float sagKolAci = 0.0f;
float solBacakAci = 0.0f;
float sagBacakAci = 0.0f;
bool ileri = true;

void robotGogsu(void)
{	
	glPushMatrix();
	glColor3f(0.8, 0.8, 0.8); 
	glTranslatef(0, 0.7, 0.0); 
	glScalef(1.0, 1.5, 1); 
	glutSolidSphere(0.2, 30, 30); 
	glPopMatrix();
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(0.1, 0.8, -0.17);
	glScalef(1.0, 1.5, 1);
	glutSolidSphere(0.02, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(-0.1, 0.8, -0.17);
	glScalef(1.0, 1.5, 1);
	glutSolidSphere(0.02, 30, 30);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f); 
	glTranslatef(0.0f, 0.9f, 0.0f); 
	glScalef(0.02f, 0.5f, 0.02f); 
	glutSolidCube(1.0f); 
	glPopMatrix();

	// Gövde
	glPushMatrix();
	glColor3f(0.8, 0.8, 0.8); 
	glScalef(1.0, 1.5, 0.5); 
	glutSolidSphere(0.3, 30, 30); 
	glPopMatrix();

	//bel
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(0, -0.4, 0.0); 
	glScalef(0.6, 0.5, 0.3); 
	glutSolidSphere(0.3, 30, 30);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7); 
	glTranslatef(0, -0.6, 0.0); 
	glScalef(0.6, 0.2, 0.2); 
	glutSolidCube(1.0);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(0, -0.8, 0.0); 
	glScalef(0.2, 0.2, 0.2);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(-0.2, -0.8, 0); 
	glutSolidSphere(0.1, 20, 20); 
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.7, 0.7, 0.7);
	glTranslatef(0.2, -0.8, 0);
	glutSolidSphere(0.1, 20, 20);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1); 
	glTranslatef(-0.4, 0.4, 0); 
	glutSolidSphere(0.18, 20, 20); 
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.1, 0.1, 0.1); 
	glTranslatef(0.4, 0.4, 0); 
	glutSolidSphere(0.18, 20, 20); 
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3); 
	glTranslatef(0.2, 0.4, 0.0); 
	glScalef(0.4, 0.2, 0.1); 
	glutSolidCube(1.0); 
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3); 
	glTranslatef(-0.2, 0.4, 0.0); 
	glScalef(0.4, 0.2, 0.1); 
	glutSolidCube(1.0); 
	glPopMatrix();
}

void robotKollar(void)
{
	// Sol kol
	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(-0.4, 0.2, 0.0); 
	glRotatef(solKolAci, 1.0, 0.0, 0.0); 

	// Üst kol
	glPushMatrix();
	glScalef(0.1, 0.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	// Dirsek
	glTranslatef(0.0, -0.3, 0.0); 
	glutSolidSphere(0.1, 20, 20);

	// Alt kol
	glPushMatrix();
	glRotatef(-solKolAci, 1.0, 0.0, 0.0); 
	glTranslatef(0.0, -0.25, 0.0); 
	glScalef(0.1, 0.5, 0.1);
	glutSolidCube(1.0);

	// Bilek
	glTranslatef(0.0, -0.3, 0.0); 
	glutSolidSphere(0.5, 20, 20);


	glPopMatrix(); 
	glPopMatrix(); 

	// Sað kol
	glPushMatrix();
	glColor3f(0.3, 0.3, 0.3);
	glTranslatef(0.4, 0.2, 0.0); 
	glRotatef(sagKolAci, 1.0, 0.0, 0.0); 

	// Üst kol
	glPushMatrix();
	glScalef(0.1, 0.5, 0.1);
	glutSolidCube(1.0);
	glPopMatrix();

	// Dirsek
	glTranslatef(0.0, -0.3, 0.0); 
	glutSolidSphere(0.1, 20, 20);

	// Alt kol
	glPushMatrix();
	glRotatef(-sagKolAci, 1.0, 0.0, 0.0); 
	glTranslatef(0.0, -0.25, 0.0); 
	glScalef(0.1, 0.5, 0.1);
	glutSolidCube(1.0);

	// Bilek
	glTranslatef(0.0, -0.3, 0.0); 
	glutSolidSphere(0.5, 20, 20);


	glPopMatrix(); 
	glPopMatrix(); 
}
void robotbacaklar(void)
{
	// Sol bacak
	glPushMatrix();
	glColor3f(0.2f, 0.2f, 0.2f); 
	glTranslatef(-0.2f, -0.8f, 0.0f); 
	glRotatef(solBacakAci, 1.0f, 0.0f, 0.0f); 

	// Üst bacak
	glPushMatrix();
	glTranslatef(0.0f, -0.3f, 0.0f); 
	glScalef(0.2f, 0.6f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Diz
	glPushMatrix();
	glColor3f(0, 0, 0); 
	glTranslatef(0.0f, -0.6f, 0.0f); 
	glutSolidSphere(0.15f, 20, 20); 
	glPopMatrix();

	// Alt bacak
	glPushMatrix();
	glColor3f(0.2f, 0.2f, 0.2f); 
	glTranslatef(0.0f, -0.9f, 0.0f);
	glScalef(0.3f, 0.6f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Ayak
	glPushMatrix();
	glTranslatef(0.0f, -1.2f, 0.0f); 
	glScalef(0.4f, 0.1f, 0.3f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPopMatrix();

	// Sað bacak
	glPushMatrix();
	glColor3f(0.2f, 0.2f, 0.2f); 
	glTranslatef(0.2f, -0.8f, 0.0f); 
	glRotatef(sagBacakAci, 1.0f, 0.0f, 0.0f); 

	// Üst bacak
	glPushMatrix();
	glTranslatef(0.0f, -0.3f, 0.0f);
	glScalef(0.2f, 0.6f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Diz
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0.0f, -0.6f, 0.0f); 
	glutSolidSphere(0.15f, 20, 20); 
	glPopMatrix();

	// Alt bacak
	glColor3f(0.2f, 0.2f, 0.2f); 
	glPushMatrix();
	glTranslatef(0.0f, -0.9f, 0.0f); 
	glScalef(0.3f, 0.6f, 0.2f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Ayak
	glPushMatrix();
	glTranslatef(0.0f, -1.2f, 0.0f);
	glScalef(0.4f, 0.1f, 0.3f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPopMatrix();
}

void robot(void)
{	

	glPushMatrix();
	glTranslatef(xgotur, ygotur, zgotur);
	glRotatef(derece, 0, 1, 0);
	robotGogsu();

	glPushMatrix();
	robotKollar();
	glPopMatrix();

	glPushMatrix();
	robotbacaklar();
	glPopMatrix();
	
	glPopMatrix();
}

void gotursol(void)
{
	derece += 5;


}
void gotursag(void)
{
	derece -= 5;
}
void goturil(void)
{
	xgotur -= (float)sin(derece * DUZELT) * 0.1;	
	zgotur -= (float)cos(derece * DUZELT) * 0.1;	
}
void goturger(void)
{
	xgotur += (float)sin(derece * DUZELT) * 0.1;
	zgotur += (float)cos(derece * DUZELT) * 0.1;
}
void masa(int konum)
{
		glPushMatrix();
        glColor3f(0.5, 0.25, 0); // Brown color
		glTranslatef(konum * -4, -0.0, -4);
		glScalef(3, 0.1, 3);
		glutSolidCube(1);
		glPopMatrix();

					// Ayaklar
		float ayakYuksekligi = 2.0f;
		float ayakGenisligi = 0.05f;
				
		glPushMatrix();
		glColor3f(0.5, 0.5, 1);
		glTranslatef(konum*-3.5, -1.2, -3.5);
		glScalef(ayakGenisligi, ayakYuksekligi, ayakGenisligi);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5, 0.5, 1);
		glTranslatef(konum * -5, -1.2, -3.5);
		glScalef(ayakGenisligi, ayakYuksekligi, ayakGenisligi);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5, 0.5, 1);
		glTranslatef(konum * -5, -1.2, -4);
		glScalef(ayakGenisligi, ayakYuksekligi, ayakGenisligi);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glColor3f(0.5, 0.5, 1);
		glTranslatef(konum * -3.5, -1.2, -4);
		glScalef(ayakGenisligi, ayakYuksekligi, ayakGenisligi);
		glutSolidCube(1);
		glPopMatrix();
    
}
void kapi() {

        glPushMatrix();
        glColor3f(0.2, 0.1, 0); 
        glTranslatef(0.0, -0.5, -12.50); 
        glScalef(1.0, 2.0, 0.1); 
        glutSolidCube(2.0); 
        glPopMatrix();



}
void yuru(void)
{
	if (ileri) {
		solKolAci += 5;
		sagKolAci -= 5;
		solBacakAci -= 5;
		sagBacakAci += 5;
		if (solKolAci >= 45) ileri = false;
	}
	else {
		solKolAci -= 5;
		sagKolAci += 5;
		solBacakAci += 5;
		sagBacakAci -= 5;
		if (solKolAci <= -45) ileri = true;
	}
}

void klavye(int dugme, int x, int y)
{
	switch (dugme)
	{
	case GLUT_KEY_LEFT: gotursol(); break;
	case GLUT_KEY_RIGHT: gotursag(); break;
	case GLUT_KEY_UP: goturil(); yuru(); break;
	case GLUT_KEY_DOWN: goturger(); yuru(); break;
	case GLUT_KEY_F1: exit(0); break;


	}
	glutPostRedisplay();
}
void klavyeNormal(unsigned char key, int x, int y)
{
	
	glutPostRedisplay();
}
void basla(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);
	//Isiklandirma
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	GLfloat light_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat light_diffuse[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_COLOR_MATERIAL);

	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
}

void cizimyeri(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//sonradan oyuncunun haraketine göre haraket eden kamera eklendi
	gluLookAt(0.0, 2.0, 5.0, xgotur, ygotur, zgotur, 0.0, 1.0, 0.0);
	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(0.2, -3, 0.0);
	glScalef(25, 25, 25);
	glutSolidCube(1);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1, 0.2, 0.2);
	glTranslatef(0.2, -3, 0.0);
	glScalef(25, 1, 25);
	glutSolidCube(1);
	glPopMatrix();
	robot();

	glPushMatrix();


	masa(-1);
	glPopMatrix();
	glPushMatrix();
	masa(1);
	glPopMatrix();

	glPushMatrix();
	kapi();
	glPopMatrix();

	glutSwapBuffers();
}

void tekrarboyut(int en, int boy)
{
	glViewport(0, 0, en, boy);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(40, (float)en / (float)boy, 1.0, 20000.0);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();w
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(en, boy);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("robot");

	basla();

	glutReshapeFunc(tekrarboyut);
	glutDisplayFunc(cizimyeri);
	glutSpecialFunc(klavye);
	glutKeyboardFunc(klavyeNormal);

	glutMainLoop();

	return 0;
}