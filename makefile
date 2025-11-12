all:
	g++ -Wall -fPIC -I/opt/homebrew/opt/portaudio -L/opt/homebrew/opt/portaudio/lib -lportaudio -o run_me warped_spectrum.cpp

debug:
	g++ -Wall -fPIC -g3 -I/opt/homebrew/opt/portaudio -L/opt/homebrew/opt/portaudio/lib -lportaudio -o run_me warped_spectrum.cpp

clean:
	rm run_me
