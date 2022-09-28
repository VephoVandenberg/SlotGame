
output:

	g++ main.cpp src/*.cpp src/states/*.cpp  -lglfw -lGL -lGLEW -lm  -I dependencies/glm -o play

clean:
	rm *.o output
