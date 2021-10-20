#include <GL/gl.h> 
#include <GL/glu.h> 
#include <GL/glut.h>
#include <iostream>
using namespace std;

void init (void){
	glClearColor (1.0, 1.0, 1.0, 0.0); // Set display-window color to white.
	glMatrixMode (GL_PROJECTION); // Set projection parameters.
	gluOrtho2D (0, 400, 0, 400);// Orthogonal projection: [x,y,z]--->[x,y,0]
}

void triangle(void){
    glClear (GL_COLOR_BUFFER_BIT); // Clear display window.
	glColor3f (0.0, 1.0, 0.0); // Set point color to green.
	glPointSize(5.0f); // Set point size
	glBegin(GL_POINTS);// Marks the beginning of the vertices list

    int x0=100,y0=100,x1=200,y1=100,x2=100,y2=200;

    int dx0 = x1-x0, dy0 = y1-y0;
    int dx1 = x2-x1, dy1 = y2-y1;
    int dx2 = x0-x2, dy2 = y0-y2;

    int xmin = min(min(x0,x1), x2);
    int ymin = min(min(y0,y1), y2);

    int xmax = max(max(x0,x1), x2);
    int ymax = max(max(y0,y1), y2);

    int q = xmax - xmin;
    int f0 = (xmin - x0)*dy0 - (ymax - y0)*dx0;
    int f1 = (xmin - x1)*dy1 - (ymax - y1)*dx1;
    int f2 = (xmin - x2)*dy2 - (ymax - y2)*dx2;

    int g1 = (x0 - x1)*dy1 - (y0 - y1)*dx1;
    int g2 = (x1 - x2)*dy2 - (y1 - y2)*dx2;
    int g0 = (x2 - x0)*dy0 - (y2 - y0)*dx0;

    for(int i = ymax; i >= ymin; i--){
        for(int j = xmin; j <= xmax; j++){
            int a1 = f1/g1;
            int a2 = f2/g2;
            int a3 = f0/g0;

            if (a1 + a2 + a3 == 1 && a1 >= 0 && a2 >= 0 && a3 >= 0){
                glVertex2i(j, i);
            }
            f0+=dy0;
            f1+=dy1;
            f2+=dy2;
        }
        f0+=dx0 - q*dy0;
        f1+=dx1 - q*dy1;
        f2+=dx2 - q*dy2;
    }
    glEnd();
	glFlush(); 
}


int main(int argc, char** argv){
	glutInit(&argc, argv); // Initialize GLUT.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode.
	glutInitWindowPosition(0, 0); // Set top-left display-window position.
	glutInitWindowSize(500, 500); // Set display-window width and height.
	glutCreateWindow("Assignment 1: Q2"); // Create display window.
	init(); // Execute initialization procedure.
	glutDisplayFunc(triangle); // Send graphics to display window.
	glutMainLoop(); // Display everything and wait.
}
