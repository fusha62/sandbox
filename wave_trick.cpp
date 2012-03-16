#include <iostream>
#include <fstream>
#include <vector>

int main( int argc, char** argv){
  //std::vector<char> inpcm1;
  std::ifstream infile1;
  char * inpcm1;
  int length;

  infile1.open( argv[0], std::ifstream::binary );
  infile1.seekg(0, std::ios::end);
  length = infile1.tellg();
  infile1.seekg(0, std::ios::beg);
  std::cout << length << std::endl;

  inpcm1 = new char [length];
  infile1.read(inpcm1,length);

  std::cout.write(inpcm1,length);
  
  infile1.close();

  return 0;

}
