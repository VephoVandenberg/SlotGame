
output:
	g++ main.cpp src/*.cpp src/states/*.cpp  -L dependencies/GLEW/lib -lGL -lGLEW -lglfw -lm -I dependencies/GLFW/include -I dependencies/GLEW/include -I dependencies/glm -o play

clean:
	rm *.o output
