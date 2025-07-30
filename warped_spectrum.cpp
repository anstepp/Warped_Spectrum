/*------------------

Sine-Wave generator -> Saw Wave generator -> Saw Wave Crusher


copyright Aaron Neal Stepp, PhD, 2025


------------------*/



#include <stdio.h>
#include <cassert>

#include <cmath>

#include "warped_spectrum.h"



float sine_calculator(int index){
	return sinf(index);
}

int main(){

	int partial_count;

	partial_count = 20;

	float partials[partial_count];

	for (int i = 0; i < partial_count; i++){
		partials[i] = sine_calculator(i);
	}

	return 0;
}