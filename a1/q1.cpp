#include <GL/gl.h> 
#include <GL/glu.h> 
#include <GL/glut.h> // (or others, depending on the system in use)
#include <iostream>
using namespace std;

void init (void){
	glClearColor (1.0, 1.0, 1.0, 0.0); // Set display-window color to white.
	glMatrixMode (GL_PROJECTION); // Set projection parameters.
	gluOrtho2D (0, 400, 400, 1);// Orthogonal projection: [x,y,z]--->[x,y,0]
}

void midPoint(void){
    glClear (GL_COLOR_BUFFER_BIT); // Clear display window.
	glColor3f (0.0, 0.0, 1.0);
	glPointSize(2.0f); // Set point size
	glBegin(GL_POINTS);// Marks the beginning of the vertices list

    int X1 = 50;
    int Y1 = 50;
    int X2 = 200;
    int Y2 = 200;

    int dx = X2 - X1;
    int dy = Y2 - Y1;
   
    if(dy<=dx){
        int d = dy - (dx/2);
        int x = X1, y = Y1;
 
        // Plot initial given point
        glVertex2i(x, y);

        // iterate through value of X
        while (x < X2){
            x++;
 
            // E or East is chosen
            if (d < 0)
                d = d + dy;
 
            // NE or North East is chosen
            else{
                d += (dy - dx);
                y++;
            }
 
            // Plot intermediate points
            glVertex2i(x, y);
        
        }
    } else if(dx<dy){
        // initial value of decision parameter d
        int d = dx - (dy/2);
        int x = X1, y = Y1;
    
        // Plot initial given point
        glVertex2i(x, y);

        // iterate through value of X
        while (y < Y2){
            y++;
    
            // E or East is chosen
            if (d < 0)
                d = d + dx;
    
            // NE or North East is chosen
            // NE or North East is chosen
            else{
                d += (dx - dy);
                x++;
            }
    
            // Plot intermediate points
            glVertex2i(x, y);
        }
    }
    glEnd();
    glFlush(); 
}

int main(int argc, char** argv){
	glutInit(&argc, argv); // Initialize GLUT.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set display mode.
	glutInitWindowPosition(10, 30); // Set top-left display-window position.
	glutInitWindowSize(500, 500); // Set display-window width and height.
	glutCreateWindow("Assignment 1: Q1"); // Create display window.
	init(); // Execute initialization procedure.
	glutDisplayFunc(midPoint); // Send graphics to display window.
	glutMainLoop(); // Display everything and wait.
}
