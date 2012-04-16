#include <iostream>
#define FORMAT_OFFSET 44

int main(){

  char input_byte;
  int count = 0;

  while (std::cin.read(&input_byte,1) != 0)
    {
      if (count >= FORMAT_OFFSET)
	std::cout.write(&input_byte,1);
      count = count + 1;
    }

  

}
