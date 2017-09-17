#include "matrix.hpp"
#include "perceptron.hpp"
#include <iostream>

using namespace std;
int main(int argc, char const *argv[])
{
	matrix<int> input(4,3,0);

	input(0,0) = 1; input(0,1) = 0; input(0,2) = 0; 
	input(1,0) = 1; input(1,1) = 0; input(1,2) = 1;
	input(2,0) = 1; input(2,1) = 1; input(2,2) = 0;
	input(3,0) = 1; input(3,1) = 1; input(3,2) = 1;

	matrix<int> output(4,1,0);

	output(0,0) = 0; 
	output(1,0) = 0; 
	output(2,0) = 0; 
	output(3,0) = 1; 

	matrix<int> teste(1,3,0);

	teste(0,0) = 1; teste(0,1) = 1; teste(0,2) = 1; 

	perceptron p;

	input.printMe();
	output.printMe();
	teste.printMe();

	if(p.learn(input, output)){
		cout << "\n\n" << endl;
		cout << "## Run ##" << endl;
		cout << "Input: ";
		teste.printMe();
		int t = p.execute(teste);
		cout << "Perceptron output: " << t << endl;
	}

	return 0;
}