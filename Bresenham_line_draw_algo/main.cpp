#include<windows.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include<iostream>
using namespace std;

double x1,y1,x2,y2,dx,dy,p;

// Function to display content on the screen
void display(void) {

    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0,1.0,1.0);

    dx = x2-x1;
    dy = y2-y1;

    double two_dy, del_d;
    two_dy = 2*dy;
    del_d = 2*(dy-dx);
    p = two_dy - dx;

    glPointSize(3.0);
    glBegin(GL_POINTS);


    while(x1 <= x2 and y1 <= y2){
        glVertex2f(x1,y1);
        cout << x1 <<" "<<y1<<'\n';

        if(p>=0){
            x1 += 1;
            y1 += 1;
            p += del_d;
        }
        else{
            x1 += 1;
            p  += two_dy;
        }

    }


    glEnd();

    glFlush();


}

void init(void){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,30.0, 0.0 , 30.0,-10.0,10.0);


}


int main(int argc, char** argv) {

    cout << "Enter x1 , y1 : ";
    cin >> x1 >> y1;
    cout << "Enter x2 , y2 : ";
    cin >> x2 >> y2;

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(1000,100);
    glutCreateWindow("Samid");
    init();
    glutDisplayFunc(display);
    glutMainLoop();


    return 0;
}
