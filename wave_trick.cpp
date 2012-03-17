#include <iostream>
#include <fstream>
#include <vector>
#define FORMAT_OFFSET 44

int main( int argc, char** argv){

  std::ifstream infile1;
  int length;

  infile1.open( argv[1], std::ifstream::binary );
  infile1.seekg(0, std::ios::end);
  length = infile1.tellg();
  length = length - FORMAT_OFFSET;
  infile1.seekg(FORMAT_OFFSET, std::ios::beg);
  //std::cout << length << std::endl;

  std::vector<char> inpcm1(length);
  infile1.read(&inpcm1[0],length);
  
  std::cout.write(&inpcm1[0],length);
  
  infile1.close();

  return 0;

}
