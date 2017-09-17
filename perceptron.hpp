#pragma once 
#include "matrix.hpp"
#include <iostream>

using namespace std;
class perceptron
{
private:
	size_t n;				//number of entries per neuron
	size_t neu;				//number of neurons
	double rate;			//value of the learning rate
	matrix<double> weight_; //matrix of weights

	void updateWeight(matrix<int> x, int t, int Sout){
		// cout << "\nWeight before: " << endl;
		// weight_.printMe();
		// cout << "\nWrong input: " << endl;
		// x.printMe();
		for(size_t r = 0 ; r < weight_.nrow(); r++){
			for(size_t c = 0; c < weight_.ncol(); c++){
				weight_(r,c) = weight_(r,c) + rate * (t-Sout) * x(r,c);
			}	
		}
		// cout << "\nWeight after: " << endl;
		// weight_.printMe();
	}

	int activationFunction(double value) const{
		if(value < 0.5)
			return 0;
		else
			return 1;
	}
public:

	// default constructor, 1 neuron with 3 inputs and learning rate 0.5
	perceptron() : n(3), neu(1), rate(0.5), weight_(1 , 3, 0.0)
	{}

	bool learn(matrix<int> m_input, matrix<int> m_output)
	{	
		cout << "\n### Learning... ###" << endl;
		size_t ninput = m_input.nrow();
		double value;
		int Sout;

		for (int i = 0; i < ninput; i++)
		{
			// cout << "\nINPUT >>>>>> " << i << endl;
			value = 0.0;
			for (int j = 0; j < n; j++)
			{
				value = (m_input(i,j)*weight_(0,j)) + value;	
			}

			Sout = activationFunction(value);   
			if(Sout != m_output(i,0)){
				int t = m_output(i,0);
				// cout << "\n## Updating weights ##" << endl;
				updateWeight(m_input.getLine(i), t, Sout);
				i = -1;
			}
		}
		// cout << "\n\n" << endl;
		cout << "## Final weights ##";
		weight_.printMe();
	}
	
	int execute(matrix<int> m_input) const {
		size_t ninput = m_input.nrow();
		double value = 0.0;
		for (int j = 0; j < n; ++j)
		{
			value = (m_input(0,j)*weight_(0,j)) + value;	
		}
		int output = activationFunction(value);   
		return output;	
	}

};