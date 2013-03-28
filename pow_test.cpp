#include <iostream>
#include <sys/time.h>
#include <math.h>

double gettimeofday_sec(){
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + (double)t.tv_usec *1e-6;
}

int main(){
  const int ITE = 99;
  const double TEI = 9.0;

  // Pow * 100
  for (int j=0; j<ITE; j++)
    {
      double p_tstart,p_tend;
      p_tstart = gettimeofday_sec();
      // Timer Start
      
      double a=TEI;
      double ex=2.0 + j;
      double b;
      for (int i=0; i<100; i++){
	b = pow(a,ex);	
      }
      //      std::cout << "Ans   : " << b << std::endl;

      // Timer End
      p_tend = gettimeofday_sec();
      std::cout << ex << " " << p_tend - p_tstart << std::endl;

    }
  
  std::cout << std::endl;

  
  for (int j=0; j<ITE; j++)
  {
    double t_tstart,t_tend;
    t_tstart = gettimeofday_sec();
    // Timer Start
    double a = TEI;
    double b;
    
    for (int i=0; i<100; i++){
      b = 1.0;
      for (int k=0; k<2+j; k++){
	b = b*a;
      }
    }
  
    //    std::cout << "Ans   : " << b << std::endl;
    
    // Timer End
    t_tend = gettimeofday_sec();
    std::cout << 2+j << " " <<  t_tend - t_tstart <<std::endl;

  }
  
}
