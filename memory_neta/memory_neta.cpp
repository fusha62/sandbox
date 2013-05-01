#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int main(int argc, char *argv[])
{
  int n_sample;
  if (argc!=1) n_sample = std::stoi((std::string) argv[1]);
  std::srand(std::time(0));
  for (int i=0; i<n_sample; i++)
    std::cout << std::rand() << std::endl;
  
  return 0;
}
