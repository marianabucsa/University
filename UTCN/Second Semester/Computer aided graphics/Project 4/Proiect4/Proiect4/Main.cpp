#include <GL\glut.h> // declararea bibliotecii OpenGL

GLfloat angle; // declararea unei variabile de tip float

void initializareGL() // initializeaza OpenGL Graphics
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);// seteaza culoarea bakground-ului negru opac
    glClearDepth(1.0f);     // seteaza adancimea fundalului 
    glEnable(GL_DEPTH_TEST);// permite testarea adancimii
    glDepthFunc(GL_LEQUAL); // seteaza tipul testului pentru adancime
    glShadeModel(GL_SMOOTH);// permite adaugarea de umbre netede
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // corecteaza perspectiva
}
void displayAnimatie(void) //crearea desenului si animatiei
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // reseteaza culoarea si adancimea buffer-elor
    glMatrixMode(GL_MODELVIEW); //permite operarea pe matricea de vizualizare a modelului
    glLoadIdentity(); //reseteaza matricea de vizualizare a modelului
    glTranslatef(0.0f, 0.0f, -10.0f); //inmulteste matricea curentă cu o matrice de translatie (translateaza desenul)
    glRotatef(angle, 1.0f, 1.0f, 1.0f); // se roteste dupa (1,1,1) -inmulteste matricea curentă cu o matrice de rotatie
    glRotatef(angle, 0.0f, 0.0f, 0.0f); // se roteste dupa (0,0,0)- micsoreaza apoi mareste desenul
    glBegin(GL_TRIANGLES); // se începe desenarea
    //PARTEA DE SUS
    // se creeaza fata 1 din 3 puncte cu culori diferite
    glColor3f(1.0f, 1.0f, 0.0f);    // seteaza culoarea galben
    glVertex3f(0.0f, 1.0f, 0.0f);   //seteaza un punct de coordonate (0,1,0)
    glColor3f(0.0f, 1.0f, 1.0f);    // seteaza culoarea turcoaz
    glVertex3f(-1.0f, -1.0f, 1.0f); // seteaza un punct de coordonate (-1,-1,1)
    glColor3f(1.0f, 0.0f, 1.0f);    // seteaza culoarea mov
    glVertex3f(1.0f, -1.0f, 1.0f);  // seteaza un punct de coordonate (1,-1,1)
    // se creeaza fata 2 din 3 puncte cu culori diferite
    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 1.0f); 
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 1.0f); 
    glVertex3f(1.0f, -1.0f, -1.0f);
    // se creeaza fata 3 din 3 puncte cu culori diferite 
    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(1.0f, 0.0f, 1.0f); 
    glVertex3f(-1.0f, -1.0f, -1.0f);
    // se creeaza fata 4 din 3 puncte cu culori diferite
    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex3f(0.0f, 1.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 1.0f); 
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 1.0f); 
    glVertex3f(-1.0f, -1.0f, 1.0f);
    //PARTEA DE JOS
    //se creeaza fata 1 din 3 puncte cu culori diferite
    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex3f(0.0f, -3.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 1.0f); 
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glColor3f(1.0f, 0.0f, 1.0f); 
    glVertex3f(1.0f, -1.0f, 1.0f);
    // se creeaza fata 2 din 3 puncte cu culori diferite
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(0.0f, -3.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 1.0f); 
    glVertex3f(1.0f, -1.0f, 1.0f);
    glColor3f(0.0f, 1.0f, 1.0f); 
    glVertex3f(1.0f, -1.0f, -1.0f);
    // se creeaza fata 3 din 3 puncte cu culori diferite
    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex3f(0.0f, -3.0f, 0.0f);
    glColor3f(0.0f, 1.0f, 1.0f); 
    glVertex3f(1.0f, -1.0f, -1.0f);
    glColor3f(1.0f, 0.0f, 1.0f); 
    glVertex3f(-1.0f, -1.0f, -1.0f);
    // se creeaza fata 4 din 3 puncte cu culori diferite
    glColor3f(1.0f, 1.0f, 0.0f); 
    glVertex3f(0.0f, -3.0f, 0.0f);
    glColor3f(1.0f, 0.0f, 1.0f); 
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glColor3f(0.0f, 1.0f, 1.0f); 
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd(); //se termina desenarea
    glutSwapBuffers(); // schimbarea buffer-elor
    angle -= 0.40f; // updateaza unghiul de rotatie
}

void reshapeAnimatie(GLsizei width, GLsizei height)
{
    if (height == 0) height = 1; // previne impartirea cu 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;
    glViewport(0, 0, width, height); // seteaza viewport-ul pentru noua fereastra
    glMatrixMode(GL_PROJECTION); // pentru a opera pe matricea de proiectie
    glLoadIdentity(); //reseteaza desenul
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);// activeaza proiectia in perspectiva
}
void timer(int value)
{
    glutPostRedisplay(); // dupa redesenare se activeaza display-ului
    glutTimerFunc(15, timer, 0); // urmatorul cronometru se activeaza dupa cateva milisecunde
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv); // initializare GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // permite folosirea buffer-ului dublu
    glutInitWindowSize(800, 600); // seteaza dimensiunile ferestrei
    glutInitWindowPosition(50, 50); // seteaza pozitia ferestrei
    glutCreateWindow("Proiect 3D Animatie OpenGL"); // creeaza fereastra cu titlul dat
    glutDisplayFunc(displayAnimatie); // se reafiseaza continutul ferestrei
    glutReshapeFunc(reshapeAnimatie); // implimenteaza actiunile necesare odata cu redimensionarea ferestrei
    initializareGL(); // apeleaza initializareGL
    glutTimerFunc(0, timer, 0); // apelarea primului cronometru
    glutMainLoop(); // se intra intr-o bucla de procesare (pentru schimbarea continutului ferestrei)
}