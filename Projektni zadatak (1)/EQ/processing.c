#include "processing.h"
#include "iir.h"


//zadatak1
void calculateShelvingCoeff(float c_alpha, Int16* output)
{
	/* Your code here */
	//po formuli A1(z) = (alpha - z^-1) / (1-alpha * z^-1)
	output[0] = c_alpha * 32768;
	output[1] = -32768;
	output[2] = 32767;
	output[3] = c_alpha * (-32768);
}

void calculatePeekCoeff(float c_alpha, float c_beta, Int16* output)
{
	/* Your code here */
	output[0] = c_alpha * 32768;
	output[1] = (-c_beta * (1 + c_alpha)) / 2;
	output[2] = 32767;
	output[3] = 32767;
	output[4] = (-c_beta * (1 + c_alpha)) / 2;
	output[5] = -32768 * c_alpha;
}

//zadatak3
Int16 shelvingHP(Int16 input, Int16* coeff, Int16* x_history, Int16* y_history, Int16 k)
{
	/* Your code here */
	//ovde koristi smpy
	return 0;
}

//zadatak2
Int16 shelvingLP(Int16 input, Int16* coeff, Int16* x_history, Int16* y_history, Int16 k)
{
	/* Your code here */
	return 0;
}

//zadatak4
Int16 shelvingPeek(Int16 input, Int16* coeff, Int16* x_history, Int16* y_history, Int16 k)
{
	/* Your code here */
	return 0;
}
