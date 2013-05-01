#include <iostream>
#include <vector>
#include "ras_io.hpp"
#include <boost/numeric/ublas/io.hpp>

int main(int argc, char *argv[])
{
  RASTER_FORMAT input;
  ras_read(&input, (char *)argv[1]);
  std::cout << input.image.size1() << std::endl;

  std::vector <int> hist_array (256);
  for (int i=0; i<(int)input.image.size1(); i++)
    for (int j=0; j<(int)input.image.size2(); j++)
      hist_array.at(input.image(i,j)) = 
	hist_array.at(input.image(i,j)) + 1;

  for (int i=0; i<256; i++)
    std::cout << i << ' ' << hist_array.at(i) << std::endl;

  return 0;
}
