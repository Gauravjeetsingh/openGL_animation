#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

static GLfloat spin = 0.0;
void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);
   glShadeModel (GL_SMOOTH);
   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);
   glEnable(GL_DEPTH_TEST);
}

void display(void)
{
   GLfloat position[] = { 0.0, 0.0, 1.5, 1.0 };

   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glPushMatrix ();
   glTranslatef (0.0, 0.0, -5.0);

   glPushMatrix ();
   glRotatef(spin, 0.0, 1.0, 0.0);
   glLightfv (GL_LIGHT0, GL_POSITION, position);

   glTranslated (0.0, 0.0, 1.5);
   glDisable (GL_LIGHTING);
   glColor3f (1.0, 1.0,1.0);
   glutSolidCube(0.1); 
   glEnable (GL_LIGHTING);
   glPopMatrix ();
   glRotatef(spin, 0.0, 0.0, 1.0);
   glutSolidTorus (0.1, 1.0, 35.0, 20);
   glPopMatrix ();
   glFlush ();
}

void spinn()
{
spin = spin + 1.0;
if(spin > 360.0)
spin = spin - 360.0;;
glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
switch(key)
{
case 'w': glutIdleFunc(spinn);
    break;

case 's': glutIdleFunc(NULL);
	  break;

default : break;
}
}

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity();
   gluPerspective(40.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}



int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMainLoop();
   return 0;
}
