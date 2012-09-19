#include <iostream>
#include <fstream>
#include <cstdlib>
#include <assert.h>

int main(){
  const int DATA_SIZE = 1024;
  double r_array[DATA_SIZE];
  std::ifstream data_file("r.csv"); 
  int i;

  if (data_file.fail()){
    std::cerr << "Error: Could not open \n";
    exit (8);
  }

  for (i = 0; i < DATA_SIZE; i++) {
    assert(i >= 0);
    assert(i < static_cast<double>(sizeof(r_array)/sizeof(r_array[0])));
    data_file >> r_array[i];
  }

  for (i = 0; i < DATA_SIZE; i++) {
    std::cout << r_array[i] << std::endl;
  }

  return 0;

}
