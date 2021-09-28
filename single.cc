#include <iostream>
#include <omp.h>

int
main()
{
  int id;
  auto f = [](int i) { std::cout << "Hi " << i << std::endl; };
#pragma omp parallel private(id) num_threads(10)
  {
    id = omp_get_thread_num();
#pragma omp single
    f(id);
    // { // This block will be executed by only one thread, but
    //   // it is not specified which one.
    //   std::cout << "We choose thread: " << id << std::endl;
    //   f(id);
    // }
  }
}
