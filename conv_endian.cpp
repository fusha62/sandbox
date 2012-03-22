#include <iostream>
#include <vector>

int main (){
  
  std::vector<char> inpt_vec(2);
  std::vector<char> outpt_vec(2);
  std::vector<char>::iterator ite_current;
  std::vector<char>::iterator ite_forword;
  std::vector<char>::iterator ite_backword;
  
  /* Input files and Conv endian*/
  while (std::cin.read(&inpt_vec[0],2) != 0)
    {
      /* Convert endian */
      ite_current = outpt_vec.begin();
      ite_forword = inpt_vec.begin();
      ite_backword = --inpt_vec.end();
      
      *ite_current = *ite_backword;
      ++ite_current;
      *ite_current = *ite_forword;
      
    
      /* Output files */
      std::cout.write(&outpt_vec[0],2);
      
    }
  
  return 0;
}
