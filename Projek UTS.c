//PROJEK UTS
#include <stdio.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;
//variables
float x = -23.5;
float x2 = -23.5;
float x3 = -23.5;
float x4 = -23.5;
float x5 = -23.5;

float y = -0.5;
float y2 = 5.5;
float y3 = -6.5;
float y4 = -12.5;
float y5 = 5.5;

float x_m = 0;
float y_m = -15.5;

//car counter
int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
int counter4 = 0;
int counter5 = 0;

//moves
float i1 = 0;
float i2 = 0;
float i3 = 0;
float i4 = 0;
float i5 = 0;

//Function
void bg();
void jl();
void garisjl();

void car();
void car2();
void car3();
void car4();
void car5();

void move();
void move2();
void move3();
void move4();
void move5();

void chara();
void circle(float radius, float xMid, float yMid);
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

void setup_viewport(GLFWwindow* window) {
	float ratio;
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;
	glViewport(0, 0, width, height);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-22, 22, -17, 17, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main() {
	if (!glfwInit())
	{
		fprintf(stderr, "ERROR : Could not start GLFW3\n");
		return 1;
	}
	GLFWwindow* window = glfwCreateWindow(540, 480, "ProjectUTS", NULL, NULL);
	if (!window)
	{
		fprintf(stderr, "ERROR : could not open windows with GLFW3\n");
		glfwTerminate();
		return 1;
	}
	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();
	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer : %s\n", renderer);
	printf("OpenGL version supported %s\n", version);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	while (!glfwWindowShouldClose(window))
	{
		setup_viewport(window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glPushMatrix();
		chara();
		glPopMatrix();

		glPushMatrix();
		move();
		car();
	
		if ((y_m == y) && (x_m == x-1)) {
			std::cout << "Try Again!" << std::endl;
			break;
		}
		glPopMatrix();

		glPushMatrix();
		move2();
		car2();
		if ((y_m == y2) && (x_m == x2+1)) {
			std::cout << "Try Again!" << std::endl;
			break;
		}
		glPopMatrix();

		glPushMatrix();
		move3();
		car3();
		if ((y3 == y_m) && (x3-1 == x_m)) {
			std::cout << "Try Again!" << std::endl;
			break;
		}
		glPopMatrix();

		glPushMatrix();
		move4();
		car4();
		if ((y4 == y_m) && (x4-1 == x_m)) {
			std::cout << "Try Again!" << std::endl;
			break;
		}
		glPopMatrix();

		glPushMatrix();
		move5();
		car5();
		if ((y5 == y_m) && (x5+1 == x_m)) {
			std::cout << "Try Again!" << std::endl;
			break;
		}
		glPopMatrix();

		if ((y_m-1.5) > 7) {
			std::cout << "Congratulation, you win!" << std::endl;
			break;
		}

		garisjl();
		glPushMatrix();
		jl();
		glPushMatrix();
		
		
		bg();
		glPopMatrix();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}

//Tidak usah diubah 
void bg() {
	
	
	//bukit1
	glColor3ub(0, 153, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-25, 10.5);
	glVertex2f(-20, 15);
	glVertex2f(-18, 16);
	glVertex2f(-15, 14);
	glVertex2f(-13, 14);
	glVertex2f(-12, 13);
	glVertex2f(-9, 10.5);
	glEnd();

	//bukit2
	glColor3ub(0, 153, 0);
	glBegin(GL_POLYGON);
	glVertex2f(9, 10.5);
	glVertex2f(12, 15);
	glVertex2f(13, 16);
	glVertex2f(15.4, 14);
	glVertex2f(18, 14);
	glVertex2f(20, 13);
	glVertex2f(24, 10.5);
	glEnd();

	//
	glColor3ub(255, 255, 0);
	circle(1.5, 0, 15);
	//awan
	glColor3ub(255, 255, 255);
	circle(1.2, -15, 15);
	circle(1.8, -13, 15);
	circle(2, -11, 15);
	circle(1.6, -9, 15);
	circle(1.3, -8, 15);
	circle(1.0, -7, 15);

	circle(1.0, 5, 15);
	circle(1.2, 6, 15);
	circle(1.6, 7.5, 15);
	circle(1.3, 8.5, 15);
	circle(1.0, 9.4, 15);

	circle(1.0, 15, 15);
	circle(1.3, 16, 15);
	circle(0.5, 17, 15);

	glColor3ub(51, 187, 255);
	glBegin(GL_POLYGON);
	glVertex2f(25, 20);
	glVertex2f(-25, 20);
	glVertex2f(-25, 10.5);
	glVertex2f(25, 10.5);
	glEnd();

	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(25, 9.5);
	glVertex2f(-25, 9.5);
	glVertex2f(-25, 7);
	glVertex2f(25, 7);
	glEnd();

	glColor3ub(0, 153, 0);
	glBegin(GL_POLYGON);
	glVertex2f(25, 20);
	glVertex2f(-25, 20);
	glVertex2f(-25, -20);
	glVertex2f(25, -20);
	glEnd();

}
void garisjl() {
	//Garis Jalan
	//1 atas
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glVertex2f(25, -11.2); //kanan atas
	glVertex2f(25, -11.4); // kanan bawah
	glVertex2f(-25, -11.4); // kiri bawha
	glVertex2f(-25, -11.2); // kiri aatas 
	glEnd();
	//1 bawah
	glBegin(GL_POLYGON);
	glVertex2f(25, -13.8); //kanan atas
	glVertex2f(25, -13.6); // kanan bawah
	glVertex2f(-25, -13.6); // kiri bawha
	glVertex2f(-25, -13.8); // kiri aatas 
	glEnd();

	//2 atas
	glBegin(GL_POLYGON);
	glVertex2f(25, -5.2); //kanan atas
	glVertex2f(25, -5.4); // kanan bawah
	glVertex2f(-25, -5.4); // kiri bawha
	glVertex2f(-25, -5.2); // kiri aatas 
	glEnd();
	//2 bawah
	glBegin(GL_POLYGON);
	glVertex2f(25, -7.8); //kanan atas
	glVertex2f(25, -7.6); // kanan bawah
	glVertex2f(-25, -7.6); // kiri bawha
	glVertex2f(-25, -7.8); // kiri aatas 
	glEnd();

	//3 atas
	glBegin(GL_POLYGON);
	glVertex2f(25, 0.8); //kanan atas -0,2
	glVertex2f(25, 0.6); // kanan bawah -0,4
	glVertex2f(-25, 0.6); // kiri bawha -0,4
	glVertex2f(-25, 0.8); // kiri aatas -0,2 
	glEnd();
	//3 bawah
	glBegin(GL_POLYGON);
	glVertex2f(25, -1.8); //kanan atas
	glVertex2f(25, -1.55); // kanan bawah
	glVertex2f(-25, -1.55); // kiri bawha
	glVertex2f(-25, -1.8); // kiri aatas 
	glEnd();

	//4 atas
	glBegin(GL_POLYGON);
	glVertex2f(25, 6.8); //kanan atas -0,2
	glVertex2f(25, 6.6); // kanan bawah -0,4
	glVertex2f(-25, 6.6); // kiri bawha -0,4
	glVertex2f(-25, 6.8); // kiri aatas -0,2 
	glEnd();
	//4 bawah
	glBegin(GL_POLYGON);
	glVertex2f(25, 4.2); //kanan atas
	glVertex2f(25, 4); // kanan bawah
	glVertex2f(-25, 4); // kiri bawha
	glVertex2f(-25, 4.2); // kiri aatas 
	glEnd();
}
void jl() {

	glColor3ub(96, 96, 96);
	//JALAN 1
	glBegin(GL_POLYGON);
	glVertex2f(25, -14); //kanan atas
	glVertex2f(25, -11); // kanan bawah
	glVertex2f(-25, -11); // kiri bawha
	glVertex2f(-25, -14); // kiri aatas 
	glEnd();

	//JALAN 2
	glBegin(GL_POLYGON);
	glVertex2f(25, -8); //kanan atas
	glVertex2f(25, -5); // kanan bawah
	glVertex2f(-25, -5); // kiri bawha
	glVertex2f(-25, -8); // kiri aatas 
	glEnd();

	//JALAN 3
	glBegin(GL_POLYGON);
	glVertex2f(25, -2); //kanan atas
	glVertex2f(25, 1); // kanan bawah
	glVertex2f(-25, 1); // kiri bawha
	glVertex2f(-25, -2); // kiri aatas 
	glEnd();

	//JALAN 4
	glBegin(GL_POLYGON);
	glVertex2f(25, 4); //kanan atas
	glVertex2f(25, 7); // kanan bawah
	glVertex2f(-25, 7); // kiri bawha
	glVertex2f(-25, 4); // kiri aatas 
	glEnd();


}


//putih
void car() {
	glTranslatef(i1, 0.0f, 0.0f);
	//Car Wheels
	//kiri atas
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-26.2, 0.4);
	glVertex2f(-26.2, 0.2);
	glVertex2f(-25.8, 0.2);
	glVertex2f(-25.8, 0.4);
	glEnd();

	//kanan atas
	glBegin(GL_POLYGON);
	glVertex2f(-23.8, 0.4);
	glVertex2f(-23.8, 0.2);
	glVertex2f(-24.2, 0.2);
	glVertex2f(-24.2, 0.4);
	glEnd();

	//kiri bawah
	glBegin(GL_POLYGON);
	glVertex2f(-26.2, -1.2);
	glVertex2f(-26.2, -1.4);
	glVertex2f(-25.8, -1.4);
	glVertex2f(-25.8, -1.2);
	glEnd();

	//kanan bawah
	glBegin(GL_POLYGON);
	glVertex2f(-23.8, -1.4);
	glVertex2f(-23.8, -1.2);
	glVertex2f(-24.2, -1.2);
	glVertex2f(-24.2, -1.4);
	glEnd();

	//Kaca
	glColor3ub(153, 153, 255);
	glBegin(GL_POLYGON);
	glVertex2f(-23.8, 0.1);
	glVertex2f(-23.8, -0.9);
	glVertex2f(-24.5, -0.9);
	glVertex2f(-24.5, 0.1);
	glEnd();

	//Car Body
	glColor3ub(255, 255, 255);
	glBegin(GL_POLYGON);
	glVertex2f(-23.5, -0.1);
	glVertex2f(-23.8, 0.3);
	glVertex2f(-26.2, 0.3);
	glVertex2f(-26.4, 0.1);
	glVertex2f(-26.4, -1.1);
	glVertex2f(-26.2, -1.3);
	glVertex2f(-23.8, -1.3);
	glVertex2f(-23.5, -0.9);
	//glVertex2f(-23.0, y);
	glEnd();

}
//merah
void car2() {
	glTranslatef(-i2, 0.0f, 0.0f);
	//Car Wheels
		//kiri atas
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(23.8, 6.4);
	glVertex2f(23.8, 6.2);
	glVertex2f(24.2, 6.2);
	glVertex2f(24.2, 6.4);
	glEnd();

	//kanan atas
	glBegin(GL_POLYGON);
	glVertex2f(26.2, 6.4);
	glVertex2f(26.2, 6.2);
	glVertex2f(25.8, 6.2);
	glVertex2f(25.8, 6.4);
	glEnd();

	//kiri bawah
	glBegin(GL_POLYGON);
	glVertex2f(23.8, 4.8);
	glVertex2f(23.8, 4.6);
	glVertex2f(24.2, 4.6);
	glVertex2f(24.2, 4.8);
	glEnd();

	//kanan bawah
	glBegin(GL_POLYGON);
	glVertex2f(26.2, 4.8);
	glVertex2f(26.2, 4.6);
	glVertex2f(25.8, 4.6);
	glVertex2f(25.8, 4.8);
	glEnd();

	//Kaca
	glColor3ub(153, 153, 255);
	glBegin(GL_POLYGON);
	glVertex2f(23.8, 6.1);
	glVertex2f(23.8, 5.1);
	glVertex2f(24.5, 5.1);
	glVertex2f(24.5, 6.1);
	glEnd();

	//Car Body
	glColor3ub(179, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(23.5, 5.9);
	glVertex2f(23.8, 6.3);
	glVertex2f(26.2, 6.3);
	glVertex2f(26.4, 6.1);
	glVertex2f(26.4, 4.9);
	glVertex2f(26.2, 4.7);
	glVertex2f(23.8, 4.7);
	glVertex2f(23.5, 5.1);
	glEnd();
}
//hijau
void car3() {
	glTranslatef(-i3, 0.0f, 0.0f);
	//Car Wheels
		//kiri atas
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(23.8, -5.6);
	glVertex2f(23.8, -5.8);
	glVertex2f(24.2, -5.8);
	glVertex2f(24.2, -5.6);
	glEnd();

	//kanan atas
	glBegin(GL_POLYGON);
	glVertex2f(26.2, -5.6);
	glVertex2f(26.2, -5.8);
	glVertex2f(25.8, -5.8);
	glVertex2f(25.8, -5.6);
	glEnd();

	//kiri bawah
	glBegin(GL_POLYGON);
	glVertex2f(23.8, -7.2);
	glVertex2f(23.8, -7.4);
	glVertex2f(24.2, -7.4);
	glVertex2f(24.2, -7.2);
	glEnd();

	//kanan bawah
	glBegin(GL_POLYGON);
	glVertex2f(26.2, -7.4);
	glVertex2f(26.2, -7.2);
	glVertex2f(25.8, -7.2);
	glVertex2f(25.8, -7.4);
	glEnd();

	//Kaca
	glColor3ub(153, 153, 255);
	glBegin(GL_POLYGON);
	glVertex2f(23.8, -6.1);
	glVertex2f(23.8, -6.9);
	glVertex2f(24.5, -6.9);
	glVertex2f(24.5, -6.1);
	glEnd();

	//Car Body
	glColor3ub(76, 230, 0);
	glBegin(GL_POLYGON);
	glVertex2f(23.5, -6.1);
	glVertex2f(23.8, -5.7);
	glVertex2f(26.2, -5.7);
	glVertex2f(26.4, -5.9);
	glVertex2f(26.4, -7.1);
	glVertex2f(26.2, -7.4);
	glVertex2f(23.8, -7.4);
	glVertex2f(23.5, -6.9);
	glEnd();
}
//Biru
void car4() {
	glTranslatef(i4, 0.0f, 0.0f);
	//Car Wheels
		//kiri atas
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(-26.2, -11.6);
	glVertex2f(-26.2, -11.8);
	glVertex2f(-25.8, -11.8);
	glVertex2f(-25.8, -11.6);
	glEnd();

	//kanan atas
	glBegin(GL_POLYGON);
	glVertex2f(-23.8, -11.6);
	glVertex2f(-23.8, -11.8);
	glVertex2f(-24.2, -11.8);
	glVertex2f(-24.2, -11.6);
	glEnd();

	//kiri bawah
	glBegin(GL_POLYGON);
	glVertex2f(-26.2, -13.2);
	glVertex2f(-26.2, -13.4);
	glVertex2f(-25.8, -13.4);
	glVertex2f(-25.8, -13.2);
	glEnd();

	//kanan bawah
	glBegin(GL_POLYGON);
	glVertex2f(-23.8, -13.4);
	glVertex2f(-23.8, -13.2);
	glVertex2f(-24.2, -13.2);
	glVertex2f(-24.2, -13.4);
	glEnd();

	//Kaca
	glColor3ub(153, 153, 255);
	glBegin(GL_POLYGON);
	glVertex2f(-23.8, -12.1);
	glVertex2f(-23.8, -12.9);
	glVertex2f(-24.5, -12.9);
	glVertex2f(-24.5, -12.1);
	glEnd();

	//Car Body
	glColor3ub(25, 25, 255);
	glBegin(GL_POLYGON);
	glVertex2f(-23.5, -12.1);
	glVertex2f(-23.8, -11.7);
	glVertex2f(-26.2, -11.7);
	glVertex2f(-26.4, -11.9);
	glVertex2f(-26.4, -13.1);
	glVertex2f(-26.2, -13.4);
	glVertex2f(-23.8, -13.4);
	glVertex2f(-23.5, -12.9);
	glEnd();
}
//kuning
void car5() {
	glTranslatef(-i5, 0.0f, 0.0f);
	//Car Wheels
		//kiri atas
	glColor3ub(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex2f(23.8, 6.4);
	glVertex2f(23.8, 6.2);
	glVertex2f(24.2, 6.2);
	glVertex2f(24.2, 6.4);
	glEnd();

	//kanan atas
	glBegin(GL_POLYGON);
	glVertex2f(26.2, 6.4);
	glVertex2f(26.2, 6.2);
	glVertex2f(25.8, 6.2);
	glVertex2f(25.8, 6.4);
	glEnd();

	//kiri bawah
	glBegin(GL_POLYGON);
	glVertex2f(23.8, 4.8);
	glVertex2f(23.8, 4.6);
	glVertex2f(24.2, 4.6);
	glVertex2f(24.2, 4.8);
	glEnd();

	//kanan bawah
	glBegin(GL_POLYGON);
	glVertex2f(26.2, 4.8);
	glVertex2f(26.2, 4.6);
	glVertex2f(25.8, 4.6);
	glVertex2f(25.8, 4.8);
	glEnd();

	//Kaca
	glColor3ub(153, 153, 255);
	glBegin(GL_POLYGON);
	glVertex2f(23.8, 6.1);
	glVertex2f(23.8, 5.1);
	glVertex2f(24.5, 5.1);
	glVertex2f(24.5, 6.1);
	glEnd();

	//Car Body
	glColor3ub(247, 255, 0);
	glBegin(GL_POLYGON);
	glVertex2f(23.5, 5.9);
	glVertex2f(23.8, 6.3);
	glVertex2f(26.2, 6.3);
	glVertex2f(26.4, 6.1);
	glVertex2f(26.4, 4.9);
	glVertex2f(26.2, 4.7);
	glVertex2f(23.8, 4.7);
	glVertex2f(23.5, 5.1);
	glEnd();
}

void move() {
	if (counter1 > 90) {
		if (i1 > 50.0f) {
			i1 = 0.0f;
			x = -23.0;
		}
			
		else {
			i1 = i1 + 1.0f;
			x++;
		}
			

		counter1 = 0;
	}counter1++;

}
void move2() {
	if (counter2 > 100) {
		if (i2 > 50.0f) {
			i2 = 0.0f;
			x2 = 23.0;
		}
			
		else {
			i2 = i2 + 1.0f;
			x2--;
		}
			

		counter2 = 0;
	}counter2++;

}
void move3() {
	if (counter3 > 50) {
		if (i3 > 50.0f) {
			i3 = 0.0f;
			x3 = -23.0;
		}
			
		else {
			i3 = i3 + 1.0f;
			x3++;
		}
			
		counter3 = 0;
	}counter3++;

}
void move4() {
	if (counter4 > 80) {
		if (i4 > 50.0f) {
			i4 = 0.0f;
			x4 = -23.0;
		}
			
		else {
			i4 = i4 + 1.0f;
			x4++;
		}
			
		counter4 = 0;
	}counter4++;

}
void move5() {
	if (counter5 > 200) {
		if (i5 > 50.0f) {
			i5 = 0.0f;
			x5 = 24.0;
		}
			
		else {
			i5 = i5 + 1.0f;
			x5--;
		}
			
		counter5 = 0;
	}counter5++;

}

void chara() {
	int a = 360;
	int radius = 1;

	glColor3ub(250, 20, 0);

	glBegin(GL_POLYGON);
	int dots = 360;
	float x_mid = x_m;
	float y_mid = y_m;
	int angle, i;

	glVertex2f(x_mid, y_mid);
	for (i = 0; i <= a; i++)
	{
		float angle = i * (2 * 3.14 / dots);
		float x = x_mid + radius * cos(angle);
		float y = y_mid + radius * sin(angle);
		glVertex2f(x, y);
	}glVertex2f(x_mid, y_mid);
	glEnd();

}

void circle(float radius, float xMid, float yMid) {
	int a = 360;
	

	glBegin(GL_POLYGON);
	int dots = 360;
	float x_mid = xMid;
	float y_mid = yMid;
	int angle, i;

	glVertex2f(x_mid, y_mid);
	for (i = 0; i <= a; i++)
	{
		float angle = i * (2 * 3.14 / dots);
		float x = x_mid + radius * cos(angle);
		float y = y_mid + radius * sin(angle);
		glVertex2f(x, y);
	}glVertex2f(x_mid, y_mid);
	glEnd();

}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {

	if (key == GLFW_KEY_W && action == GLFW_PRESS) {
		y_m = y_m+1.0f;

	}
	if (key == GLFW_KEY_A && action == GLFW_PRESS) {
		x_m=x_m-1.0f;
	}
	if (key == GLFW_KEY_S && action == GLFW_PRESS) {
		y_m=y_m-1.0f;
	}
	if (key == GLFW_KEY_D && action == GLFW_PRESS) {
		x_m=x_m+1.0f;
	}
	//if (key == GLFW_KEY_R && action == GLFW_PRESS) {
	//	x_m = 0;
	//	y_m = -15.5;
	//}
}

