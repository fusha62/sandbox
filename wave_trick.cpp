#include <iostream>
#include <fstream>
#include <vector>

int main( int argc, char** argv){

  std::ifstream infile1;
  int length;

  infile1.open( argv[0], std::ifstream::binary );
  infile1.seekg(0, std::ios::end);
  length = infile1.tellg();
  infile1.seekg(44, std::ios::beg);
  std::cout << length << std::endl;

  std::vector<char> inpcm1;  
  infile1.read(&inpcm1[0],(length - 44));
    
  std::cout << inpcm1[0] << std::endl;
  
  infile1.close();

  return 0;

}
