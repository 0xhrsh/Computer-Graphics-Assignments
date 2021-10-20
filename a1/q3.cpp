#include <GL/gl.h> 
#include <GL/glu.h> 
#include <GL/glut.h>
#include<iostream>
using namespace std;

void init (void){
	glClearColor (1.0, 1.0, 1.0, 0.0); // Set display-window color to white.
	glMatrixMode (GL_PROJECTION); // Set projection parameters.
	gluOrtho2D (0, 400, 400, 1);// Orthogonal projection: [x,y,z]--->[x,y,0]
}

// Implementing Mid-Point Circle Drawing Algorithm
void midPointCircleDraw(void){
    glClear (GL_COLOR_BUFFER_BIT); // Clear display window.
	glColor3f (1.0, 0.0, 0.0); // Set point color to green.
	glPointSize(20.0f); // Set point size
	glBegin(GL_POINTS);// Marks the beginning of the vertices list

    int x_centre = 200;
    int y_centre = 200;
    int r = 100;

	int x = r, y = 0;
	
	// Printing the initial point on the axes
	// after translation
    glVertex2i(x+x_centre, y+y_centre);

    if (r > 0){
        glVertex2i(x+x_centre, -y+y_centre);
        glVertex2i(y+x_centre, x+y_centre);
        glVertex2i(-y+x_centre, x+y_centre);
	}
	
	// Initialising the value of P
	int P = 1 - r;
	while (x > y)
	{
		y++;
		
		// Mid-point is inside or on the perimeter
		if (P <= 0)
			P = P + 2*y + 1;
		// Mid-point is outside the perimeter
		else
		{
			x--;
			P = P + 2*y - 2*x + 1;
		}
		
		// All the perimeter points have already been printed
		if (x < y)
			break;
		
		// Printing the generated point and its reflection
		// in the other octants after translation
        glVertex2i(x+x_centre, y+y_centre);
        glVertex2i(-x+x_centre, y+y_centre);
        glVertex2i(x+x_centre, -y+y_centre);
        glVertex2i(-x+x_centre, -y+y_centre);
		
		// If the generated point is on the line x = y then
		// the perimeter points have already been printed
		if (x != y){
            glVertex2i(y+x_centre, x+y_centre);
            glVertex2i(-y+x_centre, x+y_centre);
            glVertex2i(y+x_centre, -x+y_centre);
            glVertex2i(-y+x_centre, -x+y_centre);
		}
	}
    glEnd();
	glFlush(); 

}

int main(int argc, char** argv){
	glutInit(&argc, argv); // Initialize GLUT.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode.
	glutInitWindowPosition(0, 0); // Set top-left display-window position.
	glutInitWindowSize(700, 700); // Set display-window width and height.
	glutCreateWindow("Assignment 1: Q2"); // Create display window.
	init(); // Execute initialization procedure.
	glutDisplayFunc(midPointCircleDraw); // Send graphics to display window.
	glutMainLoop(); // Display everything and wait.
}
