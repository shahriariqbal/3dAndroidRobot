/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

 #include <stdlib.h>
#include<Windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<math.h>

#include<stdio.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/GLAUX.h>

double a=0.0,b=0.0,c=5.0;
GLfloat	l_t=0;

// Simple QUAD Draw

void quad()
{
  // Draw A Quad
        glBegin(GL_QUADS);

            glColor3f(0.0f,1.0f,0.0f);

            glVertex3f(0.5f,0.5f,0.0f);					    // Top front Of The Quad (right)
            glVertex3f(0.5f,0.5f,-0.5f);					// Top back Of The Quad (right)
            glVertex3f(0.5f,-0.5f,-0.5f);					// Bottom back Of The Quad (right)
            glVertex3f(0.5f,-0.5f,0.0f);					// Bottom front Of The Quad (right)

            glColor3f(0.5f,0.5f,0.0f);
            glVertex3f(-0.5f,0.5f,0.0f);					// Top front Of The Quad (left)
            glVertex3f(-0.5f,0.5f,-0.5f);					// Top back Of The Quad (left)
            glVertex3f(-0.5f,-0.5f,-0.5f);					// Bottom back Of The Quad (left)
            glVertex3f(-0.5f,-0.5f,0.0f);					// Bottom front Of The Quad (left)


            glColor3f(0.5f,0.0f,0.5f);
            glVertex3f(0.5f,0.5f,0.0f);					    // Right front Of The Quad (top)
            glVertex3f(0.5f,0.5f,-0.5f);					// Right back Of The Quad (top)
            glVertex3f(-0.5f,0.5f,-0.5f);				    // Left back Of The Quad (top)
            glVertex3f(-0.5f,0.5f,0.0f);				    // Left front Of The Quad (top)


            glColor3f(0.0f,0.5f,0.5f);
            glVertex3f(0.5f,-0.5f,0.0f);					// Right front Of The Quad (bottom)
            glVertex3f(0.5f,-0.5f,-0.5f);					// Right back Of The Quad (bottom)
            glVertex3f(-0.5f,-0.5f,-0.5f);				    // Left back Of The Quad (bottom)
            glVertex3f(-0.5f,-0.5f,0.0f);				    // Left front Of The Quad (bottom)


            glColor3f(0.0f,0.0f,0.5f);
            glVertex3f(0.5f,0.5f,-0.5f);					// Top Right Of The Quad (Back)
            glVertex3f(-0.5f,0.5f,-0.5f);					// Top Left Of The Quad (Back)
            glVertex3f(-0.5f,-0.5f,-0.5f);					// Bottom Left Of The Quad (Back)
            glVertex3f(0.5f,-0.5f,-0.5f);				    // Bottom Right Of The Quad (Back)


            glColor3f(0.5f,0.0f,0.0f);
            glVertex3f(0.5f,0.5f,0.0f);					    // Top Right Of The Quad (Front)
            glVertex3f(-0.5f,0.5f,0.0f);					// Top Left Of The Quad (Front)
            glVertex3f(-0.5f,-0.5f,0.0f);					// Bottom Left Of The Quad (Front)
            glVertex3f(0.5f,-0.5f,0.0f);					// Bottom Right Of The Quad (Front)

            /////////////////////////////////////////////////////Hea////////////////////////////////////
            glColor3f(0.5f,0.0f,0.0f);
glVertex3f(0.2f,0.9f,0.0f);
            glVertex3f(-0.2f,0.9f,0.0f);

            glVertex3f(-0.3f,0.6f,0.0f);
            glVertex3f(0.3f,0.6f,0.0f);


            glColor3f(0.0f,1.0f,0.0f);

            glVertex3f(0.2f,0.9f,0.0f);					 // Top front Of The Quad (right)
            glVertex3f(0.2f,0.9f,-0.5f);					// Top back Of The Quad (right)
            glVertex3f(0.3f,0.6f,-0.5f);					// Bottom back Of The Quad (right)
            glVertex3f(0.3f,0.6f,0.0f);					// Bottom front Of The Quad (right)

            glColor3f(0.5f,0.5f,0.0f);

            glVertex3f(-0.2f,0.9f,0.0f);					// Top front Of The Quad (left)
            glVertex3f(-0.2f,0.9f,-0.5f);					// Top back Of The Quad (left)
            glVertex3f(-0.3f,0.6f,-0.5f);					// Bottom back Of The Quad (left)
            glVertex3f(-0.3f,0.6f,0.0f);					// Bottom front Of The Quad (left)


            glColor3f(0.5f,0.0f,0.5f);

            glVertex3f(0.2f,0.9f,0.0f);					    // Right front Of The Quad (top)
            glVertex3f(0.2f,0.9f,-0.5f);					// Right back Of The Quad (top)
            glVertex3f(-0.2f,0.9f,-0.5f);				    // Left back Of The Quad (top)
            glVertex3f(-0.2f,0.9f,0.0f);				    // Left front Of The Quad (top)


             glColor3f(0.0f,0.0f,0.5f);

            glVertex3f(0.2f,0.9f,-0.5f);					// Top Right Of The Quad (Back)
            glVertex3f(-0.2f,0.9f,-0.5f);					// Top Left Of The Quad (Back)
            glVertex3f(-0.3f,0.6f,-0.5f);					// Bottom Left Of The Quad (Back)
            glVertex3f(0.3f,0.6f,-0.5f);				    // Bottom Right Of The Quad (Back)


       glColor3f(0.0f,0.5f,0.5f);

            glVertex3f(0.3f,0.6f,0.0f);					// Right front Of The Quad (bottom)
            glVertex3f(0.3f,0.6f,-0.5f);					// Right back Of The Quad (bottom)
            glVertex3f(-0.3f,0.6f,-0.5f);				    // Left back Of The Quad (bottom)
            glVertex3f(-0.3f,0.6f,0.0f);				    // Left front Of The Quad (bottom)



            ////////////////////////////////////Right Hand///////////////////////////////////////









        glEnd();
}

void init(void)
{

   glClearColor (0, 0, 0, 0);
}

void display(void)
{

   glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT); // GL_COLOR_BUFFER_BIT indicates that the buffer is currently enabled for color writing
   glMatrixMode(GL_PROJECTION);       // Specify which matrix is the current matrix mode
   glLoadIdentity();                  // Replace the current matrix with the identity matrix
   int w=glutGet(GLUT_WINDOW_WIDTH);
   int h=glutGet(GLUT_WINDOW_HEIGHT);
   gluPerspective(40,w/h,0.1,100);    // fovy specifies the field of view angle in degrees in y direction, aspect specifies aspect ratio that determines the field of view in the x direction, znear and zfar specifies the distance from viewer to the near and far clipping plane respectively (always positive)
   glMatrixMode(GL_MODELVIEW);       //  To allow transformation on 3D object

   glLoadIdentity();
   gluLookAt(                       //  eyex, eyey, eyez specify the position of the eye point, centerx, centery, centerz specify the position of reference point, upx, upy, upz specify the direction of up vector
               a,b,c,
               0,0,0,
               0,1,0
             );
   glPushMatrix();
   glRotatef(l_t,0.0f,1.0f,0.0f);


   quad();


   glPopMatrix();

   glutSwapBuffers();

}
void my_keyboard(unsigned char key, int p, int q)
{
switch (key) {
    case 'f':  //front view
        a=0.0,b=0.0,c=5.0,l_t=0;
        glutPostRedisplay();
		break;
    case 'b':  //back view
        a=0.0,b=0.0,c=-5.0,l_t=0;
        glutPostRedisplay();
		break;
    case 'l':  //left view
        a=-5.0,b=0.0,c=0.0,l_t=0;
        glutPostRedisplay();
		break;
    case 'r':  //rightrr view
        a=5.0,b=0.0,c=0.0,l_t=0;
        glutPostRedisplay();
		break;
    case 't': //top view
        a=0.0,b=5.0,c=0.0001,l_t=0;
        glutPostRedisplay();
		break;
    case 'm': //bottom view
        a=0.0,b=-5.0,c=0.0001,l_t=0;
        glutPostRedisplay();
		break;
     default:
        break;
}
}

void spinDisplay_left(void)		//spin speed
{

    l_t =l_t-0.02;
    glutPostRedisplay();
}

void spinDisplay_right(void)		//spin speed
{

    l_t =l_t+0.02;
    glutPostRedisplay();
}

void specialKeys(int key,int x,int y)
{
    if(key==GLUT_KEY_RIGHT)
           a++;
    else if(key==GLUT_KEY_LEFT)
            a--;
    else if(key==GLUT_KEY_UP)
            c--;
    else if(key==GLUT_KEY_DOWN)
            c++;
    glutPostRedisplay();
}

void mouse(int button, int state, int s, int t)
{

   switch (button)
   {
      case GLUT_LEFT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_left);
         break;
      case GLUT_RIGHT_BUTTON:
         if (state == GLUT_DOWN)
            glutIdleFunc(spinDisplay_right);
          break;
      case GLUT_MIDDLE_BUTTON:
          if (state == GLUT_DOWN)
            glutIdleFunc(NULL);
         break;
      default:
         break;
   }
}

int main()
{
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (800, 800);
	glutInitWindowPosition (0, 0);
	glutCreateWindow ("3D View of a Quad");
	init();
	glEnable(GL_DEPTH_TEST);
    glutSpecialFunc(specialKeys);
    glutDisplayFunc(display);
    glutKeyboardFunc(my_keyboard);
    glutMouseFunc(mouse);
	glutMainLoop();
	return 0;
}
