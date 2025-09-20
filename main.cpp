#include <GLFW/glfw3.h>
#include <iostream> 
#include <windows.h>

using namespace std;
GLFWwindow* window;


bool isCapsLockOn() {
    return (GetKeyState(VK_CAPITAL) & 0x0001) != 0;
}

bool show = isCapsLockOn(); 

void change_state(){
    if(show) glfwSetWindowOpacity(window, 0.0f);
    else glfwSetWindowOpacity(window, 1.0f);
    show = !show;

    return; 
}

HHOOK ho; 

LRESULT CALLBACK keepCheck(int ncode, WPARAM wp, LPARAM lp){
	if(ncode >= HC_ACTION){
		KBDLLHOOKSTRUCT* pr = (KBDLLHOOKSTRUCT*) lp; 
		if(wp == WM_KEYDOWN && pr->vkCode == VK_CAPITAL){
			change_state(); 
		}
		if(wp == WM_SYSKEYDOWN && pr->vkCode == 0x50){
			PostQuitMessage(0); 
		}
	}

	return CallNextHookEx(NULL, ncode, wp, lp); 
}

int main(void)
{
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_FLOATING, GLFW_TRUE);
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    glfwWindowHint(GLFW_DECORATED, GLFW_FALSE); 
    window = glfwCreateWindow(7, 80, "", NULL, NULL);
    
    glfwSetWindowPos(window, 0, 0);
    glfwShowWindow(window);

    if (!window)
    {
        glfwTerminate();
        return -1;
    } 

    glfwMakeContextCurrent(window);
    float opa = (show ? 1.0f : 0.0f);
    glfwSetWindowOpacity(window, opa);
    glClearColor(0.2f, 0.8f, 0.2f, 1.0f);

    ho = SetWindowsHookEx(WH_KEYBOARD_LL, keepCheck, NULL, 0);
	MSG Msg; 
	while(GetMessage(&Msg, NULL, 0, 0) > 0){
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);

        glfwPollEvents();	
	}
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
