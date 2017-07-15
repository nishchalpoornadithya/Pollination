#include<stdlib.h>
#include<GL/glut.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#define PI 3.1415926535897932384626433832795
#define ENTER 32
static GLfloat theta[]={270.0,0.0,0.0};
static GLint axis=1;
int oddeven;int hivePosition;
float size=16.0;int call_from=0;int height_decrement=1.5;
int mouseX,mouseY;int x_change;int y_change;
float plant_xposition[18];
float plant_yposition[18];

int bee_xpos=200,bee_ypos=250;int flag=0;
GLuint df;int petal_radius=20;int then=0;

//Function that creates leaves on the twigs
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

void text()
{
	glViewport(0,0,1500,900);
	int k;
	void *font=GLUT_BITMAP_TIMES_ROMAN_24;
	glColor3f(0.0,0.0,1.0);
	char string1[]="REVA INSTITUTE OF TECHNOLOGY AND MANAGEMENT";

	glColor3f(0.0,0.0,0.0);
	glRasterPos3f(200-15,400,0);

	for(k=0;k<strlen(string1);k++)
		glutBitmapCharacter(font,string1[k]);
	char string2[]="POLLINATION BY BEES (ENTOMOPHILY)";

	glColor3f(0.0,0.0,0.0);
	glRasterPos3f(250-15,350,0);
	for(k=0;k<strlen(string2);k++)
		glutBitmapCharacter(font,string2[k]);

	char string3[]="BY";

	glColor3f(0.0,0.0,0.0);
	glRasterPos3f(350-15,300,0);
	for(k=0;k<strlen(string3);k++)
		glutBitmapCharacter(font,string3[k]);

	char string4[]="Shantanu Pandey  (1RE14CS098)";

	glColor3f(0.0,0.0,0.0);
	glRasterPos3f(300-15,200,0);
	for(k=0;k<strlen(string4);k++)
		glutBitmapCharacter(font,string4[k]);

	char string5[]="Nishchal Poornadithya.C  (1RE14CS068)";

	glColor3f(0.0,0.0,0.0);
	glRasterPos3f(280-15,150,0);
	for(k=0;k<strlen(string5);k++)
		glutBitmapCharacter(font,string5[k]);

	char string6[]="Press right arrow (->) to continue";

	glColor3f(0.0,0.0,0.0);
	glRasterPos3f(480+15,0,0);
	for(k=0;k<strlen(string6);k++)
		glutBitmapCharacter(font,string6[k]);

	

}

void text1()
{
	glViewport(0,0,1500,900);
	int k;
	void *font=GLUT_BITMAP_TIMES_ROMAN_24;
	glColor3f(0.0,0.0,1.0);
	char string6[]="Instructions:";

	glColor3f(0.0,0.0,0.0);
	glRasterPos3f(185,400,0);
	for(k=0;k<strlen(string6);k++)
		glutBitmapCharacter(font,string6[k]);

	char string7[]="-Press '<-' left arrow to start";

	glColor3f(0.0,0.0,0.0);
	glRasterPos3f(250,350,0);
	for(k=0;k<strlen(string7);k++)
		glutBitmapCharacter(font,string7[k]);

	char string8[]="-Press 'b' to activate the bees";

	glColor3f(0.0,0.0,0.0);
	glRasterPos3f(250,300,0);
	for(k=0;k<strlen(string8);k++)
		glutBitmapCharacter(font,string8[k]);
}


void bee(float x,float y)
{

	glPushMatrix();//+


	//
	glPushMatrix();//+
	glColor3f(0.0,0.0,0.0);
	if(flag==1)
		glTranslatef(x+15,y,20);
	else
		glTranslatef(x-12,y,20);
	glScalef(0.3,.3,0);
	glBegin(GL_POLYGON);
	for(double i = 0; i <=PI*2; i+= PI / 12) {
		glVertex3f(cos(i) * 10, sin(i) * 10,12);
	}
	glEnd();
	glPopMatrix();//-

	glPushMatrix();//+

	glTranslatef(x,y,20);
	glScalef(2,1,0);
	glColor3f(1.0,1.0,0);
	int flag1=0;
	glBegin(GL_POLYGON);
	for(double i = 0; i <=PI*2; i += PI / 12) {
		flag1++;
		glVertex3f(cos(i) * 10, sin(i) * 10,12);

		if(flag1==2)
		{
			glColor3f(0.0,0.0,0.0);	
		}
	}
	glEnd();

	glPopMatrix();//-

	glColor3f(.2392,.67588,.67588);
	glPushMatrix();//+

	glTranslatef(x-2,y+10,20);
	glRotatef(35,0,0,1);
	glScalef(.5,.5,0);
	glScalef(1,3,0);
	glBegin(GL_POLYGON);

	for(double i = 0; i <=PI+0.1; i += PI / 12) {

		glVertex3f(cos(i) * 10, sin(i) * 10,12);

	}
	glEnd();

	glPopMatrix();//-

	glPushMatrix();//+

	glTranslatef(x,y+10,20);
	glRotatef(-35,0,0,1);
	glScalef(.5,.5,0);

	glScalef(1,3,0);
	glBegin(GL_POLYGON);

	for(double i = 0; i <=PI; i += PI / 12) 
	{			
		glVertex3f(cos(i) * 10, sin(i) * 10,12);
	}
	glPopMatrix();//-

	glEnd();
	glScalef(1,1,1);
	glPopMatrix();//-


}
static void mykey( int Key, int x, int y )
{
	switch ( Key )
	{
	case GLUT_KEY_LEFT:  
		then=2;
		glutPostRedisplay();
		break; 

	case GLUT_KEY_RIGHT:
		then=1;
		glutPostRedisplay();
		break;
	
	}
}
void keyboard(unsigned char key, int x, int y)
{

	if( key == 'b' )
	{
		flag=1;
		bee_xpos=200;
		bee_ypos=250;
		petal_radius=20;
	}
	


}

void dispList()
{
	df=glGenLists(1);
	glNewList(df,GL_COMPILE);
	tree(270.0,1.0,0,0,size/4,size);
	glEndList();
}

void petal(float petal_radius)
{

	glTranslatef(0,-10,0);
	glRotatef(100,1,0,0);
	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(0,0,0);
	float x2,y2;
	for (float angle=1.0f;angle<361.0f;angle+=30)
	{
		x2 = sin(angle)*petal_radius;
		y2 = cos(angle)*petal_radius;
		glVertex3f(x2,y2,10);
	}
	petal_radius-=2;
	glEnd();

}

void river()
{
	glColor3f(0,0.3607,0.9019);
	glBegin(GL_POLYGON);
	glVertex3f(-50,300,0);
	glVertex3f(1850,300,0);
	glVertex3f(1850,230,0);
	glVertex3f(-50,230,0);
	glEnd();

}

void display()
{   
	if(then==0)
	{

		glClearColor(0.5273,0.8047,0.9700,1.0);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		text();	

	}
	else if(then==1)
	{
		glClearColor(0.1529,0.8392,0.1960,1.0);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		text1();
	}
	else if(then==2)
	{

		glClearColor(0.5273,0.8047,0.9700,1.0);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH);
		glLoadIdentity();

		oddeven=0;
		//creation of tree 1
		glPushMatrix();
		glTranslatef(100,0,10);
		glScalef(2,2,2);
		glRotatef(35.0,0,1,0);
		glCallList(df);
		glPopMatrix();

		//creation of tree 2
		glPushMatrix();
		glTranslatef(150,200,10);
		glScalef(1.5,1.5,1.5);
		glRotatef(35.0,0,1,0);
		glCallList(df);
		glPopMatrix();



		glPushMatrix();//#1

		call_from=1;//indicates the call is for plant 
		height_decrement=2.5;//plant branches reduced
		glScalef(.5,.5,.5);
		int hang=35, i=1, st=700, lt=90, z=10, ang=35, up=0;

		//creating plants 3 rows and 6 columns
		while(i<=3)
		{

			for(int j=1;j<=6;j++)
			{

				glPushMatrix();//#2
				glTranslatef(st,lt,z);
				glRotatef(35,0,1,0);
				tree(270.0,1.0,0.0,0.0,size/4,size);
				ang+=2;
				//petals creation
				glColor3f(1.0,1.0,1.0);
				glPushMatrix();//#3
				if(bee_xpos<=2200)
					petal(petal_radius);
				else if(bee_xpos>2200)
				{
					petal_radius=0;
					petal(petal_radius);
				}
				if(bee_xpos>=2450)
					glTranslatef(0,-150,0);
				//Center part of flower
				if(bee_xpos<=2350)
					glColor3f(1.0, 1.0, 0.0);
				else if(bee_xpos>2350)
					glColor3f(1.0, 0, 0);
				glBegin(GL_POLYGON);
				for(double i = 0; i < 2 * PI; i += PI / 12) 
					glVertex3f(cos(i) * 10, sin(i) * 10,12);
				glEnd();
				glPopMatrix();//#3

				glPopMatrix();//#2
				st+=100;
			}

			st=700;
			lt+=100;
			i++;
		}
		glPopMatrix();//#1

		//beehive Creation
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
		glTranslatef(50,300,0);
		glColor3f(0.5354, 0.3490,0.1764);
		glScalef(6,2,0);
		glBegin(GL_POLYGON);
		for(double i = 0; i <=PI+0.05; i += PI / 12) 
			glVertex3f(cos(i) * 30, sin(i) * 50,10);
		glEnd();
		glPopMatrix();	

		int si=12;
		glPushMatrix();
		glTranslatef(520,300,0);
		glColor3f(0.5354, 0.3490,0.1764);
		glScalef(25,12,0);
		glBegin(GL_POLYGON);
		for(double i = 0; i <=PI+0.1; i += PI / si)
		{
			glVertex3f(cos(i) * 10, sin(i) * 10,10);
			if(i>=(PI/4)&&i<=(3*PI/4))
				si=5;
			else
				si=12;
		}
		glEnd();
		glPopMatrix();	

		glPushMatrix();
		river();
		glPopMatrix();

		glPushMatrix();
		glTranslatef(300,400,0);
		glColor3f(1.0,1.0,0);
		glutSolidSphere(20,20,20);
		glPopMatrix();


		int inc=1, inc2=1, init_bee_xpos=bee_xpos, init_bee_ypos=bee_ypos;
		//calling bees
		glPushMatrix();

		glColor3f(.23f, .94f, .36f);
		glBegin(GL_POLYGON);
		glVertex3f(-500,-100,-10);
		glVertex3f(-500,300,-10);
		glVertex3f(2000,300,-10);
		glVertex3f(2000,-100,-10);
		glEnd();
		glPopMatrix();


		glPushMatrix();
		glPushMatrix();
		glScalef(0.4,0.4,0.4);
		if(flag==1)
		{
			for(inc=1;inc<=9;inc++)
			{
				for(inc2=1;inc2<9;inc2++)
				{
					bee(init_bee_xpos,init_bee_ypos);
					init_bee_xpos-=50;
				}
				init_bee_xpos=bee_xpos;
				init_bee_ypos+=50;
			}
		}
		else{

			glPushMatrix();

			init_bee_xpos=x_change;
			init_bee_ypos=y_change;

			for(inc=1;inc<=9;inc++)
			{
				for(inc2=1;inc2<9;inc2++)
				{
					bee(init_bee_xpos,init_bee_ypos);
					init_bee_xpos-=50;
				}
				init_bee_xpos=x_change;
				init_bee_ypos+=50;
			}
			glPopMatrix();
		}
		glPopMatrix();
		glPopMatrix();


		call_from=0;
		height_decrement=1.5;


		glPushMatrix();

		glColor3f(.23f, .94f, .36f);
		glBegin(GL_POLYGON);
		glVertex3f(-500,-100,-10);
		glVertex3f(-500,300,-10);
		glVertex3f(2000,300,-10);
		glVertex3f(2000,-100,-10);
		glEnd();glPopMatrix();



	}
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
void IdleFunc()
{
	if(flag==1&&bee_xpos<=2500){
		bee_xpos+=200;
		glutPostRedisplay();
	}
	else if(flag==1&&bee_xpos>=2500)
	{
		flag=0;
		bee_ypos-=200;
		x_change=bee_xpos;
		y_change=bee_ypos;
	}

	else if(flag==0&&x_change>=600)
	{
		x_change-=200;

		glutPostRedisplay();
	}	
}
void main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1500,900);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Pollination");
	glEnable(GL_DEPTH_TEST);

	dispList();
	glutReshapeFunc(myReshape);
	glutIdleFunc(IdleFunc);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(mykey);
	
	glutDisplayFunc(display);
	glutMainLoop();
}