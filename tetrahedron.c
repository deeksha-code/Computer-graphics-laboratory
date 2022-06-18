Q5.Design, develop and implement recursively subdivide a tetrahedron to form 3D sierpinski
gasket. The number of recursive steps is to be specified by the user. 

#include<stdio.h>
#include<GL/glut.h>
int n;
float v[4][3]={{0,1,1},{1,0,0},{0,2,0},{-1,0,0}};

void triangle(float a[3],float b[3],float c[3])
{
   glBegin(GL_TRIANGLES);
   glVertex3fv(a);
   glVertex3fv(b);
   glVertex3fv(c);
   glEnd();
}



void dividetriangle(float a[3],float b[3],float c[3],int m)
{ 
	int j;
    	float v1[3],v2[3],v3[3];
	if(m>0)
	   {
	           for(j=0;j<3;j++)
		   {
			v1[j]=(a[j]+b[j])/2;
			v2[j]=(a[j]+c[j])/2;
			v3[j]=(b[j]+c[j])/2;
		    }
		dividetriangle(a,v1,v2,m-1);
		dividetriangle(v1,b,v3,m-1);
		dividetriangle(v2,v3,c,m-1);
           }
         else
	    triangle(a,b,c);	
}

void tetrahedral(int m)
{
	glColor3f(1.0,0.0,0.0);
	dividetriangle(v[0],v[1],v[3],m);
	glColor3f(0.0,1.0,0.0);
	dividetriangle(v[0],v[2],v[3],m);
	glColor3f(0.0,0.0,1.0);
	dividetriangle(v[0],v[1],v[2],m);
	glColor3f(0.0,0.0,0.0);
	dividetriangle(v[1],v[2],v[3],m);
}


void display()
{
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   tetrahedral(n);
   glFlush();
}


void myInit()
   {
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-3.0,3.0,-3.0,3.0,-10.0,10.0);
   }

int main(int argc,char**argv)
   {
	printf("enter the number of division\n");
	scanf("%d",&n);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("4MT19CS044_tetrahedral");
	glutDisplayFunc(display);
	myInit();
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
   }
