#include<stdlib.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#define PI 3.1415926535897932384626433832795
static GLfloat theta[]={270.0,0.0,0.0};
static GLint axis=1;
int oddeven;int hivePosition;
float size=1;int call_from=0;int height_decrement=1.5;
int mouseX,mouseY;
int bee_xpos=1130,bee_ypos=250;
GLuint df;
void leaf()
{
	glTranslatef(0.0,2.5,0.0);
	glRotatef(-40.0,1.0,0.0,0.0);
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.0,0.4,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.0,0.0);
	glVertex3f(1.0,0.8,0.0);
	glVertex3f(1.8,2.0,0.0);
	glVertex3f(2.0,3.0,0.0);
	glVertex3f(2.1,4.0,0.0);
	glVertex3f(2.0,4.5,0.0);
	glVertex3f(1.8,5.0,0.0);
	glVertex3f(1.4,6.0,0.0);
	glVertex3f(1.0,6.5,0.0);
	glVertex3f(0.4,7.0,0.0);
	glVertex3f(0.0,7.4,0.0);
	glVertex3f(-0.5,7.8,0.0);
	glVertex3f(-1.2,8.8,0.0);
	glVertex3f(-1.1,8.25,0.0);
	glVertex3f(-1.15,8.0,0.0);
	glVertex3f(-1.2,7.5,0.0);
	glVertex3f(-1.4,7.0,0.0);
	glVertex3f(-1.6,6.5,0.0);
	glVertex3f(-1.8,6.0,0.0);
	glVertex3f(-1.9,5.5,0.0);
	glVertex3f(-2.0,5.0,0.0);
	glVertex3f(-2.0,4.0,0.0);
	glVertex3f(-1.9,3.5,0.0);
	glVertex3f(-1.7,3.0,0.0);
	glVertex3f(-1.5,2.5,0.0);
	glVertex3f(-1.2,2.0,0.0);
	glVertex3f(-1.0,1.5,0.0);
	glVertex3f(-0.7,1.0,0.0);
	glVertex3f(-0.4,0.5,0.0);
	glVertex3f(-0.2,0.0,0.0);
	glEnd();
	glRotatef(40.0,1.0,0.0,0.0);
	glColor3f(0.0,01.0,0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.1,0.0,0.0);
	glVertex3f(-0.1,-2.5,0.0);
	glVertex3f(0.0,-2.5,0.0);
	glVertex3f(0.0,0.0,0.0);
	glEnd();
	glFlush();
	glTranslatef(0.0,-2.5,0.0);
}
void twig(float angle,int x,int y,int z,float radius,float height)
{
	glRotatef(angle,x,y,z);
	if(call_from==0)
	glColor3f(0.2929,0.0578,0.0078);
	else if(call_from==1)
		glColor3f(0,1,0);
	GLUquadricObj *quadratic;
	quadratic=gluNewQuadric();
	gluCylinder(quadratic,radius,radius*0.7,height,30,1);
	
	glScalef(height/20.0,height/20.0,height/20.0);
	for(int i=0;i<4;i++){
		glTranslatef(0.0,0.0,5.0);
		glRotatef(60.0,1.0,0.0,0.0);
		leaf();
		glRotatef(-60.0,1.0,0.0,0.0);
		glRotatef(180.0,0.0,0.0,1.0);
		glRotatef(60.0,1.0,0.0,0.0);
		leaf();
		glRotatef(-60.0,1.0,0.0,0.0);
		glRotatef(-180.0,0.0,0.0,1.0);
		glRotatef(70.0,0.0,0.0,1.0);	
}
	glRotatef(-280.0,0.0,0.0,1.0);
	
	glScalef(20.0/height,20.0/height,20.0/height);
	if(height>0.0){
		if(oddeven==0){
			oddeven=1;
			
			twig(30.0,1.0,0.0,0.0,radius*0.7,height-1.5);
			twig(-30.0,1.0,0.0,0.0,radius*0.7,height-1.5);
			

		}
		else if(oddeven==1){
			oddeven=0;
			twig(40.0,0.0,1.0,0.0,radius*0.7,height-1.5);
			twig(-40.0,0.0,1.0,0.0,radius*0.7,height-1.5);
		}
	}
	glTranslatef(0.0,0.0,0.0-height);
	glRotatef(0.0-angle,x,y,z);
	
}


void tree(float angle,int x,int y,int z,float radius,float height)
{   
	glRotatef(angle,x,y,z);
	if(call_from==0)
	glColor3f(0.2929,0.0578,0.0078);
	else if(call_from==1)
		glColor3f(0,0.2,0);
	GLUquadricObj *quadratic;
	quadratic=gluNewQuadric();
	gluCylinder(quadratic,radius,radius*0.7,height,30,1);
	glTranslatef(0.0,0.0,height);
	if(height>10.0){
		if(oddeven==0){
			oddeven=1;
			tree(30.0,1.0,0.0,0.0,radius*0.7,height-height_decrement);//radius*num gives the width and the number of branches is controlled by height-num
			tree(-30.0,1.0,0.0,0.0,radius*0.7,height-height_decrement);
		}
		else if(oddeven==1){
			oddeven=0;
			tree(40.0,0.0,1.0,0.0,radius*0.7,height-height_decrement);//oddeven i sbasically used to flag the side of the placement of the branch
			tree(-40.0,0.0,1.0,0.0,radius*0.7,height-height_decrement);
		}
	}
	
	else if(height >0.0)
	{
		if(oddeven==0){
			oddeven=1;
			twig(40.0,1.0,0.0,0.0,radius*0.7,height-1.5);
			twig(-40.0,1.0,0.0,0.0,radius*0.7,height-1.5);
		}
		else if(oddeven==1){
			oddeven=0;
			twig(40.0,0.0,1.0,0.0,radius*0.7,height-1.5);
			twig(-40.0,0.0,1.0,0.0,radius*0.7,height-1.5);
		}
	}
	if(call_from==0)
	{
	glTranslatef(0.0,0.0,0.0-height);
	glRotatef(0.0-angle,x,y,z);
	}
}


void bee(float x,float y)
{
	
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH);
	glLoadIdentity();
	glPushMatrix();
	glScalef(0.4,0.4,0.4);
	glPushMatrix();
			glColor3f(0.0,0.0,0.0);
			glTranslatef(x+15,y,12);
			glScalef(0.3,.3,0);
			glBegin(GL_POLYGON);
				for(double i = 0; i <=PI*2; i+= PI / 12) {
					glVertex3f(cos(i) * 10, sin(i) * 10,12);
					}
			glEnd();
			glPopMatrix();

glPushMatrix();
glTranslatef(x,y,12);
glScalef(2,1,0);
glColor3f(1.0,1.0,0);
int flag=0;
	glBegin(GL_POLYGON);
					for(double i = 0; i <=PI*2; i += PI / 12) {
						flag++;
 					glVertex3f(cos(i) * 10, sin(i) * 10,12);
					if(flag==10)
					{
					glColor3f(0.0,0.0,0.0);	
					}
					}
			glEnd();
			glPopMatrix();
//
			
			//
glColor3f(.2392,.67588,.67588);
		glPushMatrix();
		glTranslatef(x-2,y+10,12);
		glRotatef(35,0,0,1);
glScalef(.5,.5,0);
glScalef(1,3,0);
glBegin(GL_POLYGON);

					for(double i = 0; i <=PI+0.1; i += PI / 12) {
				
 					glVertex3f(cos(i) * 10, sin(i) * 10,12);
			
					}
					glEnd();
					glPopMatrix();
					//
	glPushMatrix();
	glTranslatef(x,y+10,12);
glRotatef(-35,0,0,1);
glScalef(.5,.5,0);

glScalef(1,3,0);
glBegin(GL_POLYGON);

					for(double i = 0; i <=PI; i += PI / 12) {
					
 					glVertex3f(cos(i) * 10, sin(i) * 10,12);
			
					}
					glPopMatrix();
//
glEnd();
glPopMatrix();

glFlush();
}
void keyboard(unsigned char key, int x, int y)
{
    

        if( key == 'x' )
            bee_xpos+= 10;
      
}
void display()
{   size=16.0;
	glClearColor(0.5273,0.8047,0.9700,1.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH);
	
	glLoadIdentity();
	oddeven=0;

	df=glGenLists(2);
	glNewList(df,GL_COMPILE);
	tree(270.0,1.0,0.0,0.0,size/4,size);
	glEndList();

//creation of tree 
	glPushMatrix();
	glTranslatef(100,0,10);

	glScalef(2,2,2);
	glRotatef(35.0,0,1,0);
	glCallList(df);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(150,200,10);
	glScalef(1.5,1.5,1.5);
	glRotatef(35.0,0,1,0);
	glCallList(df);
	glPopMatrix();
	//end of tree 
//Translating according to user's view
	
	glPushMatrix();
	call_from=1;
	height_decrement=2.5;
	glScalef(.5,.5,.5);
	int hang=35;int i=1;
	int st=700,lt=90,z=10;
	int ang=35;
	while(i<=3){

		for(int j=1;j<=6;j++){
		glPushMatrix();
	glTranslatef(st,lt,z);
	glRotatef(35,0,1,0);
	tree(270.0,1.0,0.0,0.0,size/4,size);
	ang+=2;
glColor3f(1.0,1.0,1.0);
glPushMatrix();
glTranslatef(0,-10,0);
glRotatef(100,1,0,0);
glBegin(GL_TRIANGLE_FAN);
glVertex3f(0,0,0);
 float x2,y2;
for (float angle=1.0f;angle<361.0f;angle+=30)
{
    x2 = sin(angle)*20;
    y2 = cos(angle)*20;
    glVertex3f(x2,y2,10);
}
glEnd();
 //Draw Circle
glColor3f(1.0, 1.0, 0.0);
			glBegin(GL_POLYGON);
					for(double i = 0; i < 2 * PI; i += PI / 12) 
 					glVertex3f(cos(i) * 10, sin(i) * 10,12);
			glEnd();
			glPopMatrix();
	
glPopMatrix();
st+=100;
}
		st=700;
lt+=100;
i++;
}
glPopMatrix();
//flower code ends here
glPushMatrix();
glTranslatef(160,84,0);
glColor3f(0.3019,0.3019,0);
glScalef(2,5,0);
	glBegin(GL_POLYGON);
					for(double i = PI; i <=PI*2+0.05; i += PI / 12) 
 					glVertex3f(cos(i) * 10, sin(i) * 10,10);
			glEnd();
			
	glPopMatrix();


	glPushMatrix();
	bee(600,300);
	glPopMatrix();
	


call_from=0;
height_decrement=1.5;
	glTranslatef(-300,-100,-10);
glColor3f(.23f, .94f, .36f);
		glBegin(GL_POLYGON);
		glVertex3f(-500,-100,-10);
		glVertex3f(-500,300,-10);
		glVertex3f(1500,300,-10);
		glVertex3f(1500,-100,-10);
		glEnd();
	glFlush(); 
	glutSwapBuffers();
}
void myReshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
		glOrtho(10.0,400.0,-50.0*(GLfloat)h/(GLfloat)w,500.0*(GLfloat)h/(GLfloat)w,-100.0,100.0);
	else
		glOrtho(10.0*(GLfloat)w/(GLfloat)h,400.0*(GLfloat)w/(GLfloat)h,-50.0,500.0,-100.0,100.0);
	glMatrixMode(GL_MODELVIEW);
}
void dd()
{
	
	
}

void main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1500,900);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Pollination");
	glEnable(GL_DEPTH_TEST);
	dd();
	glutReshapeFunc(myReshape);
	
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();
}