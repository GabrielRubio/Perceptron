#include "matrix.hpp"
#include "perceptron.hpp"
#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
	//################### teste 1 ################################
	cout << "##### Teste simples AND #####" << endl;

	// criando a matriz para treinar o perceptron
	matrix<int> input(4,3,0);

	input(0,0) = 1; input(0,1) = 0; input(0,2) = 0; 
	input(1,0) = 1; input(1,1) = 0; input(1,2) = 1;
	input(2,0) = 1; input(2,1) = 1; input(2,2) = 0;
	input(3,0) = 1; input(3,1) = 1; input(3,2) = 1;

	// matriz de saida esperada
	matrix<int> output(4,1,0);

	output(0,0) = 0; 
	output(1,0) = 0; 
	output(2,0) = 0; 
	output(3,0) = 1; 

	// matriz para execucao apos treinamento
	matrix<int> teste(1,3,0);

	teste(0,0) = 1; teste(0,1) = 1; teste(0,2) = 0; 

	//inicializacao do perceptron
	perceptron<int> p;

	//mostrando as tabelas
	input.printMe();
	output.printMe();
	teste.printMe();

	//executando aprendizado e mostrando o retorno final
	if(p.learn(input, output)){
		cout << "\n\n" << endl;
		cout << "## Run ##" << endl;
		cout << "Input: ";
		teste.printMe();
		matrix<int> t = p.execute(teste);
		cout << "Perceptron output: " ;
		t.printMe();
	}

	//################### teste 2 ################################
	cout << "\n\n##### Teste com dois neuronios  #####" << endl;
	
	// criando a matriz para treinar o perceptron
	matrix<int> input2(4,3,0);

	input2(0,0) = 1; input2(0,1) = 0; input2(0,2) = 0; 
	input2(1,0) = 1; input2(1,1) = 0; input2(1,2) = 1;
	input2(2,0) = 1; input2(2,1) = 1; input2(2,2) = 0;
	input2(3,0) = 1; input2(3,1) = 1; input2(3,2) = 1;

	// matriz de saida esperada
	matrix<int> output2(4,2,0);

	output2(0,0) = 0; output2(0,1) = 1;
	output2(1,0) = 0; output2(1,1) = 0;
	output2(2,0) = 0; output2(2,1) = 0;
	output2(3,0) = 1; output2(3,1) = 0;

	// matriz para execucao apos treinamento
	matrix<int> teste2(1,3,0);

	teste2(0,0) = 1; teste2(0,1) = 1; teste2(0,2) = 1; 

	//inicializacao do perceptron
	perceptron<int> p2(3,2,0.5);

	//mostrando as tabelas
	input2.printMe();
	output2.printMe();
	teste2.printMe();

	//executando aprendizado e mostrando o retorno final
	if(p2.learn(input2, output2)){
		cout << "\n\n" << endl;
		cout << "## Run ##" << endl;
		cout << "Input: ";
		teste2.printMe();
		matrix<int> t = p2.execute(teste2);
		cout << "\nPerceptron output2: ";
		t.printMe();
	}
	return 0;
}
