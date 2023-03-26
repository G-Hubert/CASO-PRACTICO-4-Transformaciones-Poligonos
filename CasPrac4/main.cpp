#include <GL/glut.h>
#include <cmath>

// variables para Traslación, Escalamiento y Rotación
float Rot = 0.0, TrasX = 0.0, TrasY = 0.0, EscalX = 1.0, EscalY = 1.0 ;

void DibujarPoligono() {
	glClear(GL_COLOR_BUFFER_BIT);
  	glBegin(GL_POLYGON);
  	glColor3f(0.0, 0.9, 1.0);
  	for (int i = 0; i < 5; ++i) { 
  		float theta = 2.0 * M_PI / 5.0 * i;
		//float theta = M_PI / 2.0 * i; 
  		float x = cos(theta);
  		float y = sin(theta);
    	glVertex2f(x, y);
  	}
   	glEnd();
  	glFlush();
}
void IniciarConfiguracion() {
	glClearColor(1, 1, 1, 0);
	glLineWidth(3.0);
    glOrtho(0, 800, 0, 600, 1, -1); 
}

void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef(TrasX, TrasY, 0.0);
  glRotatef(Rot, 0.0, 0.0, 1.0);
  glScalef(EscalX, EscalY, 1.0);
  DibujarPoligono();
  glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
  switch(key) {
    case 'w': // TRASLADAR HACIA ARRIBA
      TrasY += 0.1;
      break;
    case 's': // TRASLADAR HACIA ABAJO
      TrasY -= 0.1;
      break;
    case 'a': // TRASLADAR HACIA IZQUIERDA 
      TrasX -= 0.1;
      break;
    case 'd' : // TRASLADAR HACIA DERECHA
      TrasX += 0.1;
      break;
    case '+': // ESCALAR EN AUMENTO
      EscalX *= 1.1;
      EscalY *= 1.1;
      break;
    case '-': // ESCALAR EN DISMINUCION
      EscalX /= 1.1;
      EscalY /= 1.1;
      break;
    case 'r': // ROTAR A LA DERECHA 
      Rot -= 5.0;
      break;
    case 'l': // ROTAR A LA IZQUIERDA
      Rot += 5.0;
      break;
  }
  glutPostRedisplay();
}

int main(int argc, char** args) {
  glutInit(&argc, args);
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
  glutInitWindowSize(800, 600);
  glutInitWindowPosition(50, 50);
  glutCreateWindow("OMG!! Trasformaciones... :o");
  glutDisplayFunc(display);
  IniciarConfiguracion();
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
