/*------------------

Sine-Wave generator -> Saw Wave generator -> Saw Wave Crusher


copyright Aaron Neal Stepp, PhD, 2025


------------------*/



#include <stdio.h>
#include <cassert>
#include <vector>

#include <cmath>

#include "warped_spectrum.hpp"

#include "include/portaudio.h"

// Example callback function
static int paCallback( const void *inputBuffer, void *outputBuffer,
                           unsigned long framesPerBuffer,
                           const PaStreamCallbackTimeInfo* timeInfo,
                           PaStreamCallbackFlags statusFlags,
                           void *userData )
{
float *out = (float*)outputBuffer;
// In this example, we're just filling the output buffer with silence.
// In a real application, you would generate or process audio here.
for( unsigned long i=0; i<framesPerBuffer; i++ )
{
*out++ = 0.0f; // Left channel
*out++ = 0.0f; // Right channel
}
return paContinue; // Indicate that the stream should continue
}

float sine_calculator_f(int index){
	return sinf(index);
}

int main(int argc, char* argv[]) {
PaStream *stream;
PaError err = Pa_OpenDefaultStream( &stream,
					0,              // No input channels
					2,              // Stereo output
					paFloat32,      // 32-bit floating point samples
					44100,          // Sample rate
					256,            // Frames per buffer (or paFramesPerBufferUnspecified)
   					paCallback,     // Your callback function
					NULL );         // User data

	if(argv[1]){
		partial_count = (int)strtol(argv[1], NULL, 10);
	} else {
		partial_count = 10;
	}
	std::vector<float> partials;

	for (int i = 0; i < partial_count; i++){
		partials.push_back(sine_calculator_f(i));
	}

	return 0;
}
