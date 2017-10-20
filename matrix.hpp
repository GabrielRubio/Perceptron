#pragma once
#include <vector>
#include <iostream>

template <typename T>
class matrix
{
private:
  std::vector<T> values_;
  std::size_t nrow_, ncol_;

public:
  //construtor da matrix
  matrix(std::size_t nrow, std::size_t ncol, const T& default_value)
    : values_(nrow * ncol, default_value), nrow_(nrow), ncol_(ncol)
  {}

  //operadores ( ) para selecionar um elemento da matrix
  T& operator()(std::size_t i, std::size_t j) { return values_[i * ncol_ + j]; }
  T operator()(std::size_t i, std::size_t j) const { return values_[i * ncol_ + j]; }

  //funcoes para retornar numero de linhas e numero de colunas
  std::size_t nrow() const { return nrow_; }
  std::size_t ncol() const { return ncol_; }

  //funcao para retornar uma linha especificada 
  matrix<T> getLine(std::size_t n) const{
  	matrix<T> temp(1, ncol_, 0); //linha da matrix
  	std::size_t i;
  	std::size_t start = n * ncol_;
  	std::size_t stop = n * ncol_ + ncol_;
  	for(i = start; i < stop; i++){
  		temp(0, i-start) = values_[i];
  	}
  	return temp;
  }

  // funcao para printar a matriz
  void printMe() const{
  	int stop = nrow_ * ncol_;
  	for (int i = 0; i < stop; ++i)
  	{	
  		if((i%ncol_) == 0 ){
  			std::cout << std::endl;
  		}
  		std::cout << "[" << values_[i] << "] ";
  	}
  	std::cout << std::endl;	
  }
 
}; //end class matrix

