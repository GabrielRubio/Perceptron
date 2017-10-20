#pragma once 
#include "matrix.hpp"
#include <iostream>

using namespace std;
template<typename T>
class perceptron
{
private:
	size_t n;				//number of entries per neuron
	size_t neu;				//number of neurons
	double rate;			//value of the learning rate
	matrix<double> weight_; //matrix of weights
	
	//calculo dos novos pesos da matriz de pesos
	void updateWeight(matrix<int> x, int t, int Sout, int r){
		for(size_t c = 0; c < weight_.ncol(); c++){
			weight_(r,c) = weight_(r,c) + rate * (t-Sout) * x(0,c);
		}	
	}

	//funcao de ativacao 
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
	
	// generic constructor
	perceptron(int n_, int neu_, double rate_ ) : n(n_), neu(neu_), rate(rate_), weight_(neu_ , n_, 0.0)
	{}
	
	//funcao de aprendizado
	bool learn(matrix<int> m_input, matrix<int> m_output)
	{	
		cout << "\n### Learning... ###" << endl;
		size_t ninput = m_input.nrow();
		double value;
		int Sout;
		for (int i = 0; i < ninput; i++) 
		{
			for(int out = 0; out < neu; out++) 
			{
				value = 0.0;
				for (int j = 0; j < n; j++) 
				{
					value = (m_input(i,j)*weight_(out,j)) + value;	
				}

				Sout = activationFunction(value);   
				if(Sout != m_output(i,out)){
					int t = m_output(i,out);
					updateWeight(m_input.getLine(i), t, Sout, out);
					i  = -1;					
				}	
			}
		
		}
		cout << "## Final weights ##";
		weight_.printMe();
	}
	
	//funcao de execucao
	matrix<int> execute(matrix<int> m_input) const {
		size_t ninput = m_input.nrow(); 
		double value;
		matrix<int> output(neu,1,0.0);
		for (int i = 0; i < neu; i++)
		{
			value = 0.0;
			for (int j = 0; j < n; ++j)
			{
				value = (m_input(0,j)*weight_(i,j)) + value;	
			}
			output(i,0) = activationFunction(value);
		}
	   
		return output;	
	}

};
