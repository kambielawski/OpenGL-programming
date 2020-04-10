executable:
	g++ -o executable main.cpp -lGL -lGLEW -lglfw

run:
	rm executable
	g++ -o executable main.cpp -lGL -lGLEW -lglfw
	./executable