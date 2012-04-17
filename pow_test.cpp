#include <iostream>
#include <sys/time.h>
#include <math.h>

double gettimeofday_sec(){
  struct timeval t;
  gettimeofday(&t, NULL);
  return (double)t.tv_sec + (double)t.tv_usec *1e-6;
}

int main(){
  double p_tstart,p_tend;
  double t_tstart,t_tend;

  // Pow * 100
  p_tstart = gettimeofday_sec();
  // Timer Start
  {
    double a=2.0;
    double b;
    for (int i=0; i<100; i++)
      b = pow(a,2.0);
    std::cout << "Ans   : " << b << std::endl;
  }
  // Timer End
  p_tend = gettimeofday_sec();
  std::cout << "Pow   : " << p_tstart - p_tend << std::endl;

  // times * 100
  t_tstart = gettimeofday_sec();
  // Timer Start
  {
    double a = 2.0;
    double b;
    for (int i=0; i<100; i++)
      b = a*a;
    std::cout << "Ans   : " << b << std::endl;
  }
  // Timer End
  t_tend = gettimeofday_sec();
  std::cout << "Times : " <<  t_tstart - t_tend <<std::endl;
  
}
