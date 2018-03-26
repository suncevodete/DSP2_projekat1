#include "processing.h"
#include "iir.h"

void calculateShelvingCoeff(float c_alpha, Int16* output)
{
	/* Your code here */
	output[0] = c_alpha	*32768); //A0
	output[1] = -1		*32768); //A1
	output[2] = 1		*32768); //B0
	output[3] =-c_alpha	*32768); //B1

}

void calculatePeekCoeff(float c_alpha, float c_beta, Int16* output)
{
	/* Your code here */
	//16384		32768

	output[0] = c_alpha						*32768; //A0
	output[1] = ((c_alpha + 1)*(-c_beta))	*16384; //A1
	output[2] =	1							*32768; //A2
	output[3] =	1							*32768; //B0
	output[1] = ((c_alpha + 1)*(-c_beta))	*16384; //B1
	output[5] = c_alpha						*32768; //B2

}

Int16 shelvingHP(Int16 input, Int16* coeff, Int16* x_history, Int16* y_history, Int16 k)
{
	/* Your code here */
	Int16 tmp;
	Int16 output;

	tmp = first_order_IIR(input, coeff, x_history, y_history);
	output = (input * k/2) + (input - buffer) * 1/2;

	return output;
}

Int16 shelvingLP(Int16 input, Int16* coeff, Int16* x_history, Int16* y_history, Int16 k)
{
	/* Your code here */
	Int16 tmp;
	Int16 output;

	tmp = first_order_IIR(input, coeff, x_history, y_history);
	output = (input * 1/2) + (input - tmp) * k/2;

	return output;
}

Int16 shelvingPeek(Int16 input, Int16* coeff, Int16* x_history, Int16* y_history, Int16 k)
{
	/* Your code here */
	Int16 tmp;
	Int16 output;

	tmp = second_order_IIR(input, coeff, x_history, y_history);
	output = (input * 1/2) + (input - tmp) * k/2;

	return 0;
}
