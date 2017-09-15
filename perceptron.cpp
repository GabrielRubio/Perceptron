#include <matrix>

/*
	ESTRUTURA
		matrix weight: linhas sao os neutonio e a coluna os pesos;


*/
class perceptron
{
private:
	std::size_t n;				//numero de entradas
	std::size_t neu;			//numero de neuronios
	// int bias;		//valor do bias
	double taxa;		//valor da taxa de aprendizagem
	matrix weight_;

	void updateWeight(matrix x, double t, double Sout){
		std::size_t l;
		std::size_t c;
		for(l=0; l<weight_.nrow(); l++){
			for(c = 0; c < weight_.ncol(); c++){
				weight_(l,c) = weight_(l,c) + taxa*(t-Sout)*x(l,c);
			}	
		}
	}

public:

	// construtor padrao com 1 neuronio, duas entradas e um bias
	perceptron() : n(3), neu(1), tax(0.5), weight_(1 , n, 0.0)
	{}

	bool learn(matrix m_input, matrix m_output)
	{	
		std::size_t ninput = input.nrow();
		double value = 0.0;
		for (int i = 0; i < ninput; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				value = (m_input(i,j)*weight_(i,j)) + value;	
			}
			if(value != m_output(i,1)){
				updateWeight(m_input.getLine(i), m_output(i,1), value);
			}
		}
	}

	
	matrix process(matrix input) const {
		weight(i, j) = 2;
	}
};