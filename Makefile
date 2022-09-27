
output:
	g++ main.cpp src/*.cpp src/states/*.cpp -L dependencies/GLFW/lib -L dependencies/GLEW/lib -lGL -lm -lGLEW -lglfw -I dependencies/GLFW/include -I dependencies/GLEW/include -I dependencies/glm/include -o play

clean:
	rm *.o output
