#include <vector>

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
  T& operator()(std::size_t i, std::size_t j) { return values_[i * nrow_ + j]; }
  T operator()(std::size_t i, std::size_t j) const { return values_[i * nrow_ + j]; }

  //funcoes para retornar numero de linhas e numero de colunas
  std::size_t nrow() const { return nrow_; }
  std::size_t ncol() const { return ncol_; }

  //funcao para retornar uma linha especificada 
  std::vector<T> getLine() (std::size_t n) const {
  	std::vector<T> temp(ncol_); //linha da matrix
  	std::size_t i;
  	std::size_t start = n * nrow_;
  	std::size_t stop = n * nrow_ + ncol_;
  	for(i = start; i < stop; i++){
  		temp[i-start] = value_[i];
  	}
  	return temp;
  }

};