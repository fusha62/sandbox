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
  
  int min = 0;
  
  for (int i=0; i<(int)input.image.size1(); i++)
    for (int j=0; j<(int)input.image.size2(); j++)
      {
	int sum = 0;
	for (int n=0; n<(int)input.image(i,j); n++) sum = sum + hist_array.at(n);
	input.image(i,j) = 
	  (int)((( (double)sum /(256.0*256.0)) -
		 (double)min) * (256.0 - 1.0) / (1.0 - (double)min));
      };
  
  ras_write(&input, (char *)argv[2]);

  return 0;
}
