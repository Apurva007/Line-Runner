#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<math.h>
#define degtorad 3.14/180
int j,i;
double a=1000,count=0,flag=0,s=200.0,com=200,theta,down=0,downcount=0,downflag=0,rlegmov=200,stoprlegmov=0,rlegmovcount=0,upflag=0,llegmov=200,stopllegmov=0,lhandmov=200;
double rhandmov=200,ry=200;
int k,glitch=0,stoplhandmov=0,stoprhandmov=0,roll=0,showf=0;
double ly=200;
int score=0;
n=10;
void move(void);
int num[20];
int numlen=0;
int shift=0;
int mainpage=1;
int level;
int done=0;
int lost=0;
double buildmove=150;
double buildmove1=150;
int instruct=0;
int game=0;
void backbuild()
{
	glColor3f(0.0,0.0,1.0);//1
	glBegin(GL_LINE_LOOP);
	glVertex2f(buildmove1,150);
	glVertex2f(buildmove1,700);
	glVertex2f(buildmove1+250,700);
	glVertex2f(buildmove1+250,150);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(buildmove1+50,600);
	glVertex2f(buildmove1+50,650);
	glVertex2f(buildmove1+100,650);
	glVertex2f(buildmove1+100,600);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(buildmove1+150,600);
	glVertex2f(buildmove1+150,650);
	glVertex2f(buildmove1+200,650);
	glVertex2f(buildmove1+200,600);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(buildmove1+50,500);
	glVertex2f(buildmove1+50,550);
	glVertex2f(buildmove1+100,550);
	glVertex2f(buildmove1+100,500);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(buildmove1+150,500);
	glVertex2f(buildmove1+150,550);
	glVertex2f(buildmove1+200,550);
	glVertex2f(buildmove1+200,500);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(buildmove1+100,150);
	glVertex2f(buildmove1+100,350);
	glVertex2f(buildmove1+150,350);
	glVertex2f(buildmove1+150,150);
	glEnd();

	glColor3f(0.0,0.0,1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(buildmove+500,150);      //2
	glVertex2f(buildmove+500,700);
	glVertex2f(buildmove+750,700);
	glVertex2f(buildmove+750,150);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(buildmove+550,600);        
	glVertex2f(buildmove+550,650);
	glVertex2f(buildmove+600,650);
	glVertex2f(buildmove+600,600);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(buildmove+650,600);
	glVertex2f(buildmove+650,650);
	glVertex2f(buildmove+700,650);
	glVertex2f(buildmove+700,600);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(buildmove+550,500);
	glVertex2f(buildmove+550,550);
	glVertex2f(buildmove+600,550);
	glVertex2f(buildmove+600,500);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(buildmove+650,500);
	glVertex2f(buildmove+650,550);
	glVertex2f(buildmove+700,550);
	glVertex2f(buildmove+700,500);
	glEnd();

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(buildmove+600,150);
	glVertex2f(buildmove+600,350);
	glVertex2f(buildmove+650,350);
	glVertex2f(buildmove+650,150);
	glEnd();



}


void mplatform()
{
	glColor3f(0.3,1.0,0.3);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,200);
	glVertex2f(1000,200);
	glVertex2f(1000,0);
	glEnd();
}

void mainblock()
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(400,200);
	glVertex2f(400,250);
	glVertex2f(450,250);
	glVertex2f(450,200);
	glEnd();
}

void arrow()
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(218,390);//straight line
	glVertex2f(218,325);

	glVertex2f(210,380);
	glVertex2f(218,390);
	glVertex2f(218,390);
	glVertex2f(226,380);
	glEnd();
	

}

void mstickmanj()
{
	glColor3f(0.0,0.0,0.0);

	glLineWidth(5); 
//head
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(210,490);
	glVertex2f(226,489);
	glVertex2f(227,518);
	glVertex2f(211,518);
	glEnd();


	glBegin(GL_LINES);
	glColor3f(0.0,0.0,0.0);

    glVertex2f(220,500);//main body
	glVertex2f(215,440);

	glVertex2f(215,441);//left leg upper
	glVertex2f(200,408);
	glVertex2f(201,409);//left leg lower
	glVertex2f(188,414);

	glVertex2f(215,440);//right upper leg
	glVertex2f(225,415);
	glVertex2f(225,416);//right lower leg
	glVertex2f(218,400);


	glVertex2f(218,465);//right lower hand
	glVertex2f(228,468);
	glVertex2f(227,467);//right upper hand
	glVertex2f(235,480);


	glVertex2f(218,473);//left upper hand
	glVertex2f(201,462);
	glVertex2f(202,463);//left lower hand
	glVertex2f(208,445);
	glEnd();
}

void arrow2()
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(250,227);
	glVertex2f(400,227);

	glVertex2f(380,239);
	glVertex2f(400,227);
	glVertex2f(400,227);
	glVertex2f(380,215);
	glEnd();
}

void mstickman()
{
	glColor3f(0.0,0.0,0.0);

	glLineWidth(5); 
//head
	glBegin(GL_POLYGON);
	glColor3f(0.0,0.0,0.0);
	glVertex2f(210,290);
	glVertex2f(226,289);
	glVertex2f(227,318);
	glVertex2f(211,318);
	glEnd();


	glBegin(GL_LINES);
	glColor3f(0.0,0.0,0.0);

    glVertex2f(220,300);//main body
	glVertex2f(215,240);

	glVertex2f(215,241);//left leg upper
	glVertex2f(200,208);
	glVertex2f(201,209);//left leg lower
	glVertex2f(188,214);

	glVertex2f(215,240);//right upper leg
	glVertex2f(225,215);
	glVertex2f(225,216);//right lower leg
	glVertex2f(218,200);


	glVertex2f(218,265);//right lower hand
	glVertex2f(228,268);
	glVertex2f(227,267);//right upper hand
	glVertex2f(235,280);


	glVertex2f(218,273);//left upper hand
	glVertex2f(201,262);
	glVertex2f(202,263);//left lower hand
	glVertex2f(208,245);
	glEnd();
}

void circle_draw(int size)
{
	glBegin(GL_POLYGON);
	for(i=0;i<360;i++)
	glVertex2f(25*cos(i*degtorad)*size,25*sin(i*degtorad)*size);
	glEnd();

}

void sun()
{
	glPushMatrix();
	if(level==1)
		glColor3f(1.0,0.5,0.0);
	else
		glColor3f(1.0,1.0,1.0);

		glTranslatef(800.0,850.0,0);
		circle_draw(3);
		glPopMatrix();
}


/*void draw_pixel(GLint cx,GLint cy)
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POINTS);
	glVertex2f(cx,cy);
	glEnd();
}*/

/*void plotpixels(GLint h,GLint k,GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}*/

/*void circle_draw(GLint h,GLint k,GLint r)
{
	GLint d=1-r,x=0,y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0)
			d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}*/

void platform()
{
	glColor3f(0.7,0.5,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(0,0);
	glVertex2f(0,200);
	glVertex2f(1000,200);
	glVertex2f(1000,0);
	glEnd();
}

void stickman()
{
	
	glLineWidth(5); 
//head
	if(level==1)
	glColor3f(0.0,0.0,0.0);
else
glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(com+10,s+90);
	glVertex2f(com+26,s+89);
	glVertex2f(com+27,s+118);
	glVertex2f(com+11,s+118);
	glEnd();


	glBegin(GL_LINES);
	if(level==1)
	glColor3f(0.0,0.0,0.0);
else
glColor3f(1.0,1.0,1.0);
    glVertex2f(com+20,s+100);//main body
	glVertex2f(com+15,s+40);

	glVertex2f(com+15,s+41);//left leg upper
	glVertex2f(llegmov,s+8);
	glVertex2f(llegmov+1,s+9);//left leg lower
	glVertex2f(llegmov-12,s+14);

	glVertex2f(com+15,s+40);//right upper leg
	glVertex2f(rlegmov+25,s+15);
	glVertex2f(rlegmov+25,s+16);//right lower leg
	glVertex2f(rlegmov+18,s);


	glVertex2f(com+18,s+65);//right lower hand
	glVertex2f(rhandmov+28,ry+68);
	glVertex2f(rhandmov+27,ry+67);//right upper hand
	glVertex2f(rhandmov+35,ry+80);


	glVertex2f(com+18,s+73);//left upper hand
	glVertex2f(lhandmov+1,s+62);
	glVertex2f(lhandmov+2,s+63);//left lower hand
	glVertex2f(lhandmov+8,s+45);
	glEnd();

}

void eop(float x,float y,char *number)
{
	char *p;
	glRasterPos2f(x,y);
	for(p=number;*p!='\0';p++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*p);
	
}



//to make the stickman come down after jumpin
void move3(void)
{
	
	if(s>=200.0)
	
	{
			if(level==1)
	{
		if(((a+300<225)&&s<250&&(a+300>218))||(s<=250&&(a+300>162)&&(a+350<230)))//first block x-axis
		{
			lost=1;
         	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
			if(((a+500<225)&&s<250&&(a+500>218))||(s<=250&&(a+500>162)&&(a+550<230)))//first block x-axis
	{
                lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
			if(((a+750<225)&&s<250&&(a+750>218))||(s<=250&&(a+750>162)&&(a+800<230)))//first block x-axis
	{
                lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
			if(((a+1100<225)&&s>200&&(a+1100>208))||(s>=200&&(a+1100>162)&&(a+1100<230))&&!roll)
	{
				lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
					if(((a+1450<225)&&s>200&&(a+1450>208))||(s>=200&&(a+1450>162)&&(a+1450<230))&&!roll)
	{
						lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
						if(((a+1700<225)&&s<250&&(a+1700>218))||(s<=250&&(a+1700>162)&&(a+1750<230)))//first block x-axis
	{
               lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+1950<225)&&s>200&&(a+1950>208))||(s>=200&&(a+1950>162)&&(a+1950<230))&&!roll)
	{
		lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
		if(((a+2200<225)&&s<250&&(a+2200>218))||(s<=250&&(a+2200>162)&&(a+2250<230)))//first block x-axis
	{
                 lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
		a-=0.7;
		buildmove-=0.7;
		buildmove1-=0.7;
	}
		if(level==2)
		{
		if(((a+300<225)&&s<250&&(a+300>208))||(s<=250&&(a+300>162)&&(a+350<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
		if(((a+358<225)&&s<250&&(a+358>208))||(s<=250&&(a+358>162)&&(a+408<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
		if(((a+515<225)&&s<250&&(a+515>208))||(s<=250&&(a+515>162)&&(a+565<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
		if(((a+725<225)&&s>200&&(a+725>208))||(s>=200&&(a+725>162)&&(a+725<230))&&!roll)
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
		if(((a+935<225)&&s<250&&(a+935>208))||(s<=250&&(a+935>162)&&(a+985<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
		if(((a+1015<225)&&s<250&&(a+1015>208))||(s<=250&&(a+1015>162)&&(a+1065<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
		if(((a+1155<225)&&s>200&&(a+1155>208))||(s>=200&&(a+1155>162)&&(a+1155<230))&&!roll)
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
		if(((a+1305<225)&&s>200&&(a+1305>208))||(s>=200&&(a+1305>162)&&(a+1305<230))&&!roll)
	{
			lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
	}
			if(((a+1475<225)&&s<250&&(a+1475>208))||(s<=250&&(a+1475>162)&&(a+1525<230)))
		{
				lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
	}
			a-=0.86;
			buildmove-=0.86;
			buildmove1-=0.86;
		}
		
		s-=1.5;
		ry-=1.5;
		score+=1;

		}

	else
	{
		ry=200;
		downflag=0;
		flag=0;
		s=200;
		glutIdleFunc(move);
	}
	glutPostRedisplay();
}

//normal iteration of block
void move(void)
{
	
	score+=1;
	count++;
	glitch++;
	if(!upflag||!downflag)
	{
	if(glitch==40)
	{
		glitch=0;
		llegmov=200;
		rlegmov=200;
	}

	if(rhandmov+33>219&&stoprhandmov==0)
	{
		if(ry+73>250) 
			ry-=0.25;
		if(ry+73<=263)
		{
		rhandmov-=0.25;
		if(rhandmov+33<=220)
		{
			rhandmov=185;
			stoprhandmov=1;
		}
		}
	}
	else if(rhandmov+33<234&&stoprhandmov==1)
	{
		rhandmov+=0.35;
		if(rhandmov+33>=233)
		{
			rhandmov=200;
			if(ry+73<274)
			ry+=0.35;
			if(ry+73>=273)
				stoprhandmov=0;
		}
	}
	if(lhandmov+1<219&&stoplhandmov==0)
	{
		lhandmov+=0.35;
		if(lhandmov+1>=218)
		{
			lhandmov=218;
			stoplhandmov=1;
		}
	}
	else if(lhandmov+1>200&&stoplhandmov==1)
	{
		lhandmov-=0.35;
		if(lhandmov+1<=201)
		{
			lhandmov=200;
			stoplhandmov=0;
		}
	}


	if((llegmov<220)&&stopllegmov==0)
	{
	//	if(ly>182)
	//	ly-=0.02;
		llegmov+=0.5;
		if(llegmov>=219)
		{
			llegmov=220;
			stopllegmov=1;
		}
	}
	else if(llegmov>199&&stopllegmov==1)
	{
		//if(ly<200)
		//ly+=0.02;
		llegmov-=0.5;
		if(llegmov<=200)
		{
			
			llegmov=200.0;
			stopllegmov=0;
		}
	}
	if((rlegmov+25)>208.0&&stoprlegmov==0)
	{
		rlegmov-=0.5;
		if(rlegmov+25<=209.0)
		{
			rlegmov=184.0;
			stoprlegmov=1;
		}
	
	}
	else if((rlegmov+25)<226.0&&stoprlegmov==1)
	{
		rlegmov+=0.5;
		if(rlegmov+25>=225.0)
		{
			rlegmov=200.0;
			stoprlegmov=0;
		}
	}
	}
		if(level==1)
	{
		if(((a+300<225)&&s<250&&(a+300>218))||(s<=250&&(a+300>162)&&(a+350<230)))//first block x-axis
	{
          lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
			if(((a+500<225)&&s<250&&(a+500>218))||(s<=250&&(a+500>162)&&(a+550<230)))//first block x-axis
	{
                  lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
			if(((a+750<225)&&s<250&&(a+750>218))||(s<=250&&(a+750>162)&&(a+800<230)))//first block x-axis
	{
                lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
			if(((a+1100<225)&&s>200&&(a+1100>208))||(s>=200&&(a+1100>162)&&(a+1100<230))&&!roll)
	{
				lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+1450<225)&&s>200&&(a+1450>208))||(s>=200&&(a+1450>162)&&(a+1450<230))&&!roll)
	{
		lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
		if(((a+1700<225)&&s<250&&(a+1700>218))||(s<=250&&(a+1700>162)&&(a+1750<230)))//first block x-axis
	{
                  lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
			if(((a+1950<225)&&s>200&&(a+1950>208))||(s>=200&&(a+1950>162)&&(a+1950<230))&&!roll)
	{
				lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
				if(((a+2200<225)&&s<250&&(a+2200>218))||(s<=250&&(a+2200>162)&&(a+2250<230)))//first block x-axis
	{
               lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
				a-=0.7;
				buildmove-=0.7;
				buildmove1-=0.7;
	}
	if(level==2)
	{
	if(((a+300<225)&&s<250&&(a+300>208))||(s<=250&&(a+300>162)&&(a+350<230)))//first block x-axis
		{
		lost=1;
			glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();

		}
    if(((a+358<225)&&s<250&&(a+358>208))||(s<=250&&(a+358>162)&&(a+408<230)))
		{
		lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+515<225)&&s<250&&(a+515>208))||(s<=250&&(a+515>162)&&(a+565<230)))
		{
	            lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+725<225)&&s>200&&(a+725>208))||(s>=200&&(a+725>162)&&(a+725<230))&&!roll)
		{
                 lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+935<225)&&s<250&&(a+935>208))||(s<=250&&(a+935>162)&&(a+985<230)))
		{
		lost=1;

		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+1015<225)&&s<250&&(a+1015>208))||(s<=250&&(a+1015>162)&&(a+1065<230)))
	{
		lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+1155<225)&&s>200&&(a+1155>208))||(s>=200&&(a+1155>162)&&(a+1155<230))&&!roll)
	{
		lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+1305<225)&&s>200&&(a+1305>208))||(s>=200&&(a+1305>162)&&(a+1305<230))&&!roll)
	{
		lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
	}
	if(((a+1475<225)&&s<250&&(a+1475>208))||(s<=250&&(a+1475>162)&&(a+1525<230)))
		{
		lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
	}
	a-=0.86;
	buildmove-=0.86;
	buildmove1-=0.86;
	}
	if((s-50.0)==300.0&&count==35)
		glutIdleFunc(move3);
	glutPostRedisplay();
}

//to make the stickman go up while jumpin
void move2(void)
{
	downflag=1;
	if(level==1)
	{
		if(((a+300<225)&&s<250&&(a+300>218))||(s<=250&&(a+300>162)&&(a+350<230)))//first block x-axis
	{
                lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
		if(((a+500<225)&&s<250&&(a+500>218))||(s<=250&&(a+500>162)&&(a+550<230)))//first block x-axis
	{
                lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+750<225)&&s<250&&(a+750>218))||(s<=250&&(a+750>162)&&(a+800<230)))//first block x-axis
	{
               lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+1100<225)&&s>200&&(a+1100>208))||(s>=200&&(a+1100>162)&&(a+1100<230))&&!roll)
	{
		lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
		if(((a+1450<225)&&s>200&&(a+1450>208))||(s>=200&&(a+1450>162)&&(a+1450<230))&&!roll)
	{
			lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
		if(((a+1700<225)&&s<250&&(a+1700>218))||(s<=250&&(a+1700>162)&&(a+1750<230)))//first block x-axis
	{
			lost=1;

		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+1950<225)&&s>200&&(a+1950>208))||(s>=200&&(a+1950>162)&&(a+1950<230))&&!roll)
	{
		lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
		if(((a+2200<225)&&s<250&&(a+2200>218))||(s<=250&&(a+2200>162)&&(a+2250<230)))//first block x-axis
	{
			lost=1;

		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
}

	if(level==2)
	{
	if(((a+300<225)&&s<250&&(a+300>218))||(s<=250&&(a+300>162)&&(a+350<230)))//first block x-axis
	{
		lost=1;

		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+358<225)&&s<250&&(a+358>208))||(s<=250&&(a+358>162)&&(a+408<230)))
	{
		lost=1;
	
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+515<225)&&s<250&&(a+515>208))||(s<=250&&(a+515>162)&&(a+565<230)))
		{
		lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+725<225)&&s>200&&(a+725>208))||(s>=200&&(a+725>162)&&(a+725<230))&&!roll)
	{
		lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+935<225)&&s<250&&(a+935>208))||(s<=250&&(a+935>162)&&(a+985<230)))
	{
		lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+1015<225)&&s<250&&(a+1015>208))||(s<=250&&(a+1015>162)&&(a+1065<230)))
	{
		lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+1155<225)&&s>200&&(a+1155>208))||(s>=200&&(a+1155>162)&&(a+1155<230))&&!roll)
	{
		lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
		}
	if(((a+1305<225)&&s>200&&(a+1305>208))||(s>=200&&(a+1305>162)&&(a+1305<230))&&!roll)
	{
		lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
	}
		if(((a+1475<225)&&s<250&&(a+1475>208))||(s<=250&&(a+1475>162)&&(a+1525<230)))
		{
			lost=1;
		    	glutIdleFunc(NULL);
	        showf=1;
			glutPostRedisplay();
	}
	}
	if((s-50.0)<=300.0)
	{
		score+=1 ;
		ry+=1.5;
		s+=1.5;
		if(level==1)
		{
			a-=0.7;
			buildmove-=0.7;
			buildmove1-=0.7;
		}
		if(level==2)
		{
		a-=0.86;
		buildmove-=0.86;
		buildmove1-=0.86;
		}
		count=0;
	}
	else
	{
		ry=350;
		flag=1;
		s=350;
		glutIdleFunc(move);
	}
	glutPostRedisplay();
}

void blocklevel1()
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);             //block1
	glVertex2f(a+300,200);
	glVertex2f(a+300,250);
	glVertex2f(a+350,250);
	glVertex2f(a+350,200);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);             //block2
	glVertex2f(a+500,200);
	glVertex2f(a+500,250);
	glVertex2f(a+550,250);
	glVertex2f(a+550,200);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);             //block3
	glVertex2f(a+750,200);
	glVertex2f(a+750,250);
	glVertex2f(a+800,250);
	glVertex2f(a+800,200);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);             //block4
	glVertex2f(a+1100,270);
	glVertex2f(a+1100,320);
	glVertex2f(a+1150,320);
	glVertex2f(a+1150,270);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);             //block5
	glVertex2f(a+1450,270);
	glVertex2f(a+1450,320);
	glVertex2f(a+1500,320);
	glVertex2f(a+1500,270);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);             //block6
	glVertex2f(a+1700,200);
	glVertex2f(a+1700,250);
	glVertex2f(a+1750,250);
	glVertex2f(a+1750,200);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);             //block7
	glVertex2f(a+1950,270);
	glVertex2f(a+1950,320);
	glVertex2f(a+2000,320);
	glVertex2f(a+2000,270);
	glEnd();

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);             //block8
	glVertex2f(a+2200,200);
	glVertex2f(a+2200,250);
	glVertex2f(a+2250,250);
	glVertex2f(a+2250,200);
	glEnd();
}


void blocklevel2()
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);             //block1
	glVertex2f(a+300,200);
	glVertex2f(a+300,250);
	glVertex2f(a+350,250);
	glVertex2f(a+350,200);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(a+358,200);
	glVertex2f(a+358,250);            //block2
	glVertex2f(a+408,250);
	glVertex2f(a+408,200);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(a+515,200);
	glVertex2f(a+515,250);
	glVertex2f(a+565,250);          //block3
	glVertex2f(a+565,200);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(a+725,270);            //block 4
	glVertex2f(a+725,320);
	glVertex2f(a+775,320);
	glVertex2f(a+775,270);
	glEnd();

		glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(a+935,200);
	glVertex2f(a+935,250);          //block 5
	glVertex2f(a+985,250);
	glVertex2f(a+985,200);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(a+1015,200);
	glVertex2f(a+1015,250);          //block 6
	glVertex2f(a+1065,250);
	glVertex2f(a+1065,200);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(a+1155,270);           //block 7
	glVertex2f(a+1155,320);
	glVertex2f(a+1205,320);
	glVertex2f(a+1205,270);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(a+1305,270);           //block 8
	glVertex2f(a+1305,320);
	glVertex2f(a+1355,320);
	glVertex2f(a+1355,270);
	glEnd();

	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(a+1475,200);         //block 9
	glVertex2f(a+1475,250);
	glVertex2f(a+1525,250);
	glVertex2f(a+1525,200);
	glEnd();
}

void underline()
{
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(450,890);
	glVertex2f(568,890);
	glEnd();
}

void instructfunc()
{
	glColor3f(0.0,0.0,0.0);
		eop(450,900,"Instructions");
		glColor3f(0.0,0.0,0.0);
		eop(150,600,"Press W for Jump");
		glColor3f(0.0,0.0,0.0);
		eop(250,250,"Press S to Roll");
		glColor3f(0.0,0.0,0.0);
		eop(600,400,"Press B to Restart Game or Go Back");
		underline();
	mstickman();
	mstickmanj();
	mplatform();
	arrow();
    arrow2();
	glPushMatrix();
	glColor3f(0.0,0.0,0.0);
	glTranslatef(450.0,225.0,0);
	circle_draw(1);
	glPopMatrix();
}



void display(void)
{
	if(instruct==1)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(1.0,0.5,0.0,1.0);
		instructfunc();
	}
    else if(mainpage==0)
	{
	glClear(GL_COLOR_BUFFER_BIT);
	if(level==1)
		glClearColor(1.0,1.0,1.0,1.0);
	else
		glClearColor(0.0,0.0,0.0,1.0);
	backbuild();
	platform();
	sun();
	if(showf)
	{
		if(level==1)
		glColor3f(0.0,0.0,0.0);
		else
		glColor3f(1.0,1.0,1.0);
		eop(500,500,"Game Over");
		eop(500,450,"Score:");
		for(i=0;i<n;i++)
		{
			num[i]=score%10;
			score=score/10;
			if(score==0)
				break;
			numlen++;
		}
		for(i=numlen;i>=0;i--)
		{
			shift+=10;
			if(num[i]==1)
				eop(550+shift,450,"1");
			else if(num[i]==2)
				eop(550+shift,450,"2");
			else if(num[i]==3)
				eop(550+shift,450,"3");
			else if(num[i]==4)
				eop(550+shift,450,"4");
			else if(num[i]==5)
				eop(550+shift,450,"5");
			else if(num[i]==6)
				eop(550+shift,450,"6");
			else if(num[i]==7)
				eop(550+shift,450,"7");
            else if(num[i]==8)
				eop(550+shift,450,"8");
            else if(num[i]==9)
				eop(550+shift,450,"9");
			else if(num[i]==0)
				eop(550+shift,450,"0");
		}
					
}
	if(down==0)
	stickman();
	else
	{
		rlegmov=200;
		llegmov=200;
		downcount+=2;
		glPushMatrix();
		if(level==1)
		glColor3f(0.0,0.0,0.0);
		else
			glColor3f(1.0,1.0,1.0);
		glTranslatef(225.0,225.0,0);
		circle_draw(1);
		glPopMatrix();
		if(downcount==350)
		{
			roll=0;
			upflag=0;
			down=0;
			downcount=0;
		}
	}
	
	if(a+1475<=(-5)&&level==2)
	{
		done=0;
		level=3;
		glutIdleFunc(NULL);
		glColor3f(1.0,1.0,1.0);
		eop(350,900,"More Puzzles Under Construction");
		lost=1;

	}
	if(buildmove1+250<=(-5))
		buildmove1=1000;
	if(buildmove+750<=(-5))
		buildmove=1000;
	if(a+2250<=0&&level==1)
	{
		done=0;level=2;
	}
	if(level==2&&done==0)
	{
		done=1;
		a=1000;
	}
	if(level==1)
		blocklevel1();
	if(level==2)
	blocklevel2();
	}
	else
	{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0,0.5,0.0,1.0);
    glColor3f(0.0,0.0,0.0);
		eop(278,900,"Computer Graphics Mini Project--Line Runner");
		glColor3f(0.0,0.0,0.0);
		eop(500,850,"By");
		glColor3f(0.0,0.0,0.0);
		eop(370,800,"Apurva Telang-4VP10CS010");
		glColor3f(0.0,0.0,0.0);
		eop(370,770,"Nandan Hegde-4VP10CS033");
		glColor3f(0.0,0.0,0.0);
		eop(370,500,"Press UP to start the RUN");
		glColor3f(0.0,0.0,0.0);
		eop(370,470,"Press DOWN for Instructions");
		glColor3f(0.0,0.0,0.0);
		eop(370,440,"Press q to QUIT");

	mplatform();
	mstickman();
	mainblock();
	}
	glFlush();
}

void keyboard(unsigned char key,int x,int y)
{
	if(key=='w')
		if(flag!=1&&upflag!=1&&!showf)
		{
			rlegmov=200;
			llegmov=200;
		glutIdleFunc(move2);
		}
	if(key=='s'&&downflag!=1&&!showf)
	{
		roll=1;
		llegmov=200;
		rlegmov=200;
		upflag=1;
		down=1;
		display();
	
	}	
	if(key=='b')
		if(lost==1||instruct==1)
		{
			lost=0;
			numlen=0;
			for(i=0;i<n;i++)
				num[i]=0;
			instruct=0;
			buildmove=150;
			buildmove1=150;
			instruct=0;
			game=0;
 shift=0;
 mainpage=1;
 done=0;
 glClearColor(1.0,0.5,0.0,1.0);
			ly=200;
			glitch=0,stoplhandmov=0,stoprhandmov=0,roll=0,showf=0;
			rhandmov=200,ry=200;
			score=0;
			a=1000,count=0,flag=0,s=200.0,com=200,down=0,downcount=0,downflag=0,rlegmov=200,stoprlegmov=0,rlegmovcount=0,upflag=0,llegmov=200,stopllegmov=0,lhandmov=200;
			glutPostRedisplay();
		}
		if(key=='q')
		{
			if(mainpage==1)
				exit(0);
		}
		//else
		//	glutIdleFunc(NULL);
	
}


void myinit()
{
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,999.0,0.0,999.0);
}

void special(int key, int x, int y)
{
	switch(key)
	{
	case (GLUT_KEY_UP):
		if(game!=1)  //added on thurs 9-5-2013
{
		mainpage=0;
         score=0;
		level=1;
		game=1;
		glutIdleFunc(move);
		display();
}
		break;
	case (GLUT_KEY_DOWN):mainpage=0;
		if(game!=1)
		instruct=1;
		display();
		break;
	}
}

void main(int argc,char **argv)
{
    glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Line Runner");
	glutDisplayFunc(display);
	myinit();
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	glutIdleFunc(move);
	glutMainLoop();
}
