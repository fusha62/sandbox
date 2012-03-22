#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define FORMAT_OFFSET 44

int main( int argc, char** argv){

  std::ifstream infile1,infile2;
  int length;
  int len_tmp1,len_tmp2;

  /* file open */
  infile1.open( argv[1], std::ifstream::binary );
  infile1.seekg(0, std::ios::end);
  len_tmp1 = infile1.tellg();
  infile1.seekg(FORMAT_OFFSET, std::ios::beg);

  infile2.open( argv[2], std::ifstream::binary );
  infile2.seekg(0, std::ios::end);
  len_tmp2 = infile2.tellg();
  infile2.seekg(FORMAT_OFFSET, std::ios::beg);

  /* set length */
  length = std::max(len_tmp1,len_tmp2);
  length = length - FORMAT_OFFSET;

  //std::cout << length << std::endl;


  /* Read Files */
  std::vector<char> inpcm1(length);
  std::vector<char> inpcm2(length);
  
  infile1.read(&inpcm1[0],length);
  infile2.read(&inpcm2[0],length);

  //std::cout.write(&inpcm1[0],length);
  

  /* Generate Output vector */
  std::vector<char> outpcm(length);
  for (int i=0; i<length-1; i++){
    if (i%2 == 0)
      outpcm[i]=inpcm1[i+1];
    else
      outpcm[i]=inpcm2[i];
  }
  std::cout.write(&outpcm[0],length);


  /* Close files  */
  infile1.close();
  infile2.close();

  return 0;

}
