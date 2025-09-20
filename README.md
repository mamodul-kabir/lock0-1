# lock0-1  

Lightweight Windows app that shows the current **Caps Lock status** on screen — perfect for laptops without a physical Caps Lock LED.  

## Features  
- Displays Caps Lock state visually.  
- Exit the app anytime with **Alt + P**.  
- Can be added to **Windows startup** for automatic launch.  

## Usage  
You can either:  
1. Download and run the provided **`lock0-1.exe`** directly.  
2. Or build the project yourself (see below).  

## Dependencies  
- [GLFW 3.4](https://www.glfw.org/)  
- OpenGL (comes with Windows)  
- g++ (MinGW recommended)  

## Building from Source  
1. Download and build the **GLFW 3.4** library in the **same directory** (directions are on the [GLFW website](https://www.glfw.org/)).  
2. Compile the program with:  

```bash
   g++ main.cpp -o lock0-1.exe -mwindows -I .\glfw-3.4\include .\glfw-3.4\build\src\libglfw3.a -lopengl32 -lgdi32
```

## Adding to Windows Startup
If you want lock0-1 to run automatically when you log in:
1. Press **Win + R**, type **`shell:startup`**, and press **Enter**.
2. Copy the compiled **`lock0-1.exe`** (or a shortcut to it) into the opened folder.
3. It will now start automatically with Windows.
