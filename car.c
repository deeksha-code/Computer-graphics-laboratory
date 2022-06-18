Q8.Draw a car and move it using OpenGL transformation matrices

#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
float x;
void timer(int e)
{
     if(x==700)
     {
         x=0;
     }
     x=x+10;
     glutPostRedisplay();//drawing the car again in new position
     glutTimerFunc(100,timer,0);

}
void car()
{
	 glColor3f(0.0,1.0,1.0);
	 glBegin(GL_POLYGON);
	 glVertex2f(0,100);
	 glVertex2f(300,100);
	 glVertex2f(300,200);
	 glVertex2f(0,200);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glVertex2f(50,200);
	 glVertex2f(250,200);
	 glVertex2f(200,250);
	 glVertex2f(100,250);
	 glEnd();
	 glPushMatrix();
	 glColor3f(0.0,0.0,1.0);
	 glTranslatef(50.0,100.0,0.0);
	 glutSolidSphere(20,20,20);
	 glPopMatrix();
	 glPushMatrix();
	 glColor3f(0.0,0.0,1.0);
	 glTranslatef(250.0,100.0,0.0);
	 glutSolidSphere(20,20,20);
	 glPopMatrix();
	 glColor3f(0.0,0.0,1.0);
	 glBegin(GL_POLYGON);
	 glVertex2f(90,150);
	 glVertex2f(110,150);
	 glVertex2f(110,170);
	 glVertex2f(90,170);
	 glEnd();
	 glBegin(GL_POLYGON);
	 glVertex2f(190,150);
	 glVertex2f(210,150);
	 glVertex2f(210,170);
	 glVertex2f(190,170);
	 glEnd();
}
void display(void)
{
	 glClear(GL_COLOR_BUFFER_BIT);
	 glPushMatrix();
	 glTranslatef(0+x,0.0,0.0);
	 car();
	 glPopMatrix();
	 glPushMatrix();
	 glTranslatef(10-x,10.0,0.0);
	 glScalef(0.2,0.2,1);
	 car();
	 glPopMatrix();
	 glutSwapBuffers();
	 glFlush();
}
int main(int argc,char **argv)
{
	 glutInit(&argc,argv);
	 glutInitDisplayMode(GLUT_DOUBLE |GLUT_RGB);
	 glutInitWindowSize(800,800);
	 glutInitWindowPosition(0,0);
	 glutCreateWindow("car");
	 glClearColor(1.0,1.0,1.0,0.0);
	 glMatrixMode(GL_MODELVIEW);
	 glLoadIdentity();
	 glOrtho(0.0,700.0,0.0,700.0,-500,500);
	 glutDisplayFunc(display);
	 timer(0);
	 glutMainLoop();
}
