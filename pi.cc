#include <cstddef>
#include <limits>
#include <math.h>
#include <omp.h>
#include <stdio.h>

const double PI = 3.1415926535897932384626433;

int
main()
{
  const int num_steps = 1000 * 1000;
  const double step = 1.0 / static_cast<double>(num_steps);

  double sum(10.0); // (0.0);
  double x;
#pragma omp parallel for private(x) reduction(+ : sum)
  for (std::size_t i = 0; i < num_steps; ++i) {
    x = (i + 0.5) * step;
    sum = sum + 4.0 / (1.0 + x * x);
  }
  double pi = step * sum;
  printf("pi   = %.16f\n", pi);
  printf("diff = %.16f\n", (pi - PI));
}
