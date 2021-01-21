main: main.cpp RayTracer.cpp
	g++ main.cpp RayTracer.cpp -o raytracer
	./raytracer
	display sphere-image.ppm