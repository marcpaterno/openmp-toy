#include <omp.h>
#include <stdio.h>

int
main()
{
// omp_set_num_threads(10);
#pragma omp parallel num_threads(10)
  {
    auto ID = omp_get_thread_num();

    // Expect jumbled output!
    printf("hello(%d)", ID);
    printf(" world(%d)\n", ID);
  } // implicit barrier here
  printf("All the threads are done\n");
}
