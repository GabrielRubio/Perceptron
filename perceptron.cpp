class perceptron
{
private:
	int n;				//numero de entradas
	int neu;			//numero de neuronios
	// int bias;		//valor do bias
	double taxa;		//valor da taxa de aprendizagem

public:
	perceptron(){
		int n = 3;				//numero de entradas
		int neu = 1;			//numero de neuronios
		// int bias = 1;		//valor do bias
		double taxa = 0.5;		//valor da taxa de aprendizagem
		double weight[3][1]=0;	//matriz de pesos
	}

	bool learn(int padrao[][], int saida[][]);

	void updateWeight();
	
};