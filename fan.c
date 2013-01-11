#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>

//declared a static GLfloat variable
static GLfloat spin = 0.0;

void init()
{

//sets the bg color white
  glClearColor(1.0,1.0,1.0,1.0);
  glShadeModel(GL_SMOOTH);
 }

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glPushMatrix();


// glRotatef(GLfloat angle,GLfloat x,GLfloat y,GLfloat z);
glColor3f(0.0, 0.0, 0.0);
glRectf(-0.5, 0.0, 0.5, -35.0);
glRotatef(spin,0.0,0.0,1.0);


glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);glVertex3f(0.0, 0.0, 0.0);
glColor3f(0.5,0.5,0.5);glVertex3f(10.0, 15.0, 0.0);
glColor3f(0.5,0.5,0.5);glVertex3f(-10.0, 15.0, 0.0);

glColor3f(1.0,1.0,1.0);glVertex3f(0.0, 0.0, 0.0);
glColor3f(0.5,0.5,0.5);glVertex3f(10.0, -15.0, 0.0);
glColor3f(0.5,0.5,0.5);glVertex3f(-10.0, -15.0, 0.0);

glEnd();


//glPushMatrix saves the current screen to stack and glPopMatrix is to load the data from the stack.
// Pop the old matrix without the transformations
glPopMatrix();

//buffer swap on the layer in use in current window
glutSwapBuffers();

}


void spinDisplay()
{
spin = spin - 25.0;
if(spin > 360.0)
spin = spin - 360.0;
//mark the normal plane of current window as needing to redisplayed
glutPostRedisplay();

}

void reshape(int w, int h)
{
//glViewport(GLint x,GLint y,GLsizei width,GLsizei height);
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void mouse(int button, int state, int x, int y)
{
switch(button) 
{
  case GLUT_LEFT_BUTTON: if(state == GLUT_DOWN)
  		glutIdleFunc(spinDisplay);
			break;

  case GLUT_RIGHT_BUTTON: if(state == GLUT_DOWN)
			glutIdleFunc(NULL);
			break;
  default :  break;
 }
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);

//size of the window appearing
   glutInitWindowSize (1600, 1200); 
//position of the window appearing
   glutInitWindowPosition (250, 250);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape); 
   glutMouseFunc(mouse);
   glutMainLoop();
   return 0;
}









