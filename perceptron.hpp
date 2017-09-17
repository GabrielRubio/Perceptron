#pragma once 
#include "matrix.hpp"
#include <iostream>
/*
	ESTRUTURA
		matrix weight: linhas sao os neutonio e a coluna os pesos;


*/
using namespace std;
class perceptron
{
private:
	size_t n;				//numero de entradas
	size_t neu;			//numero de neuronios
	// int bias;		//valor do bias
	double taxa;		//valor da taxa de aprendizagem
	matrix<double> weight_;

	void updateWeight(matrix<int> x, int t, int Sout){
		size_t l;
		size_t c;
		cout << "Peso antes: " << endl;
		weight_.printMe();
		cout << "Entrada Problematica: " << endl;
		x.printMe();
		for(l=0; l<weight_.nrow(); l++){
			for(c = 0; c < weight_.ncol(); c++){
				weight_(l,c) = weight_(l,c) + 0.5 * (t-Sout) * x(l,c);
			}	
		}
		cout << "pesos depois: "<< endl;
		weight_.printMe();
	}

	int funcaoAtivacao(double value) const{
		if(value < 0.5)
			return 0;
		else
			return 1;
	}
public:

	// construtor padrao com 1 neuronio, duas entradas e um bias
	perceptron() : n(3), neu(1), taxa(0.5), weight_(1 , 3, 0.0)
	{}

	bool learn(matrix<int> m_input, matrix<int> m_output)
	{	
		cout << "entrou em aprendizado" << endl;
		size_t ninput = m_input.nrow();
		double value;
		int Sout;

		for (int i = 0; i < ninput; i++)
		{
			cout << "ENTRADA >>>>>>" << i << endl;
			value = 0.0;
			for (int j = 0; j < n; j++)
			{
				value = (m_input(i,j)*weight_(0,j)) + value;	
			}

			Sout = funcaoAtivacao(value);   //funcao de ativacao
			if(Sout != m_output(i,0)){
				int t = m_output(i,0);
				cout << "## Mandando no atualizar pesos ##" << endl;
				updateWeight(m_input.getLine(i), t, Sout);
				i = -1;
			}
		}
		cout << "\n\n" << endl;
		cout << "## Pesos finais ##";
		weight_.printMe();
	}

	
	int execute(matrix<int> m_input) const {
		size_t ninput = m_input.nrow();
		double value = 0.0;
		for (int j = 0; j < n; ++j)
		{
			value = (m_input(0,j)*weight_(0,j)) + value;	
		}
		int output = funcaoAtivacao(value);   //funcao de ativacao
		return output;	
	}

};