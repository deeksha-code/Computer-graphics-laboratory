Q2. Create and rotate a triangle about the origin and a fixed point

#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

int x=0,choice,h,k;
float theta;
void myInit()
{
	
        glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100.0,100.0,-100.0,100.0,-100.0,100.0);
}
void timer(int e)
{
	theta++;
	glutPostRedisplay();
	glutTimerFunc(100,timer,0);
}

void rotate_triangle()
{
	 glRotatef(theta,0.0,0.0,1.0);
}
/*
void rotate_origin()
{
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(theta,1.0,0.0,0.0);
	
}
void rotate_fixed()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(h,k,0);
	glRotatef(theta,0.0,0.0,1.0);
	glTranslatef(-h,-k,0);
	
}
*/
void draw_triangle()
{
	glColor3f(1.0,0.0,0.0);
	glLineWidth(10.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(20,40);
	glVertex2f(40,40);
	glVertex2f(30,60);
	glEnd();
}
void Display_Origin(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw_triangle();
	glPushMatrix();
	rotate_triangle();
	draw_triangle();
	glPopMatrix();
	glFlush();
	
	
}
void Display_Fixed(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw_triangle();
	glPushMatrix();
	glTranslatef(theta,k,0);
	rotate_triangle();
	glTranslatef(-theta,-k,0);
	draw_triangle();
	glPopMatrix();
	glFlush();
	
}
/*void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glLineWidth(10.0);
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glRotatef(x,1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(20,40);
	glVertex2f(40,40);
	glVertex2f(30,60);
	glEnd();
	glPopMatrix();
	
	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(20,40,0);
	glRotatef(x,1.0,0.0,0.0);
	glTranslatef(-20,-40,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(20,40);
	glVertex2f(40,40);
	glVertex2f(30,60);
	glEnd();
	glPopMatrix();
	glFlush();
	
}*/
int main(int argc,char **argv)
{
         printf("enter your choice\n 1.Fixed point\n 2.Rotation with respect to    origin\n");
	 scanf("%d",&choice);
	 printf("enter angle of rotation\n");
	 scanf("%f",&theta);
	 glutInit(&argc,argv);
	 glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
	 glutInitWindowSize(800,800);
	 glutInitWindowPosition(10,20);
	 
	 if(choice==1)
	 {
	 	printf("Enter the fixed point\n");
	 	scanf("%d%d",&h,&k);
	        glutCreateWindow("Fixed point rotation\n");
	        myInit();
	        glutDisplayFunc(Display_Fixed);
	 }
	 if(choice==2)
	 {
	        glutCreateWindow("Rotation with respect to origin\n");
	        myInit();
	        glutDisplayFunc(Display_Origin);
	 }
	 else
	 {
	      printf("Invalid choice\n");   
	 }
	 timer(0);
	 glutMainLoop();
	 return 0;
	
}   
