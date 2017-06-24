#ifndef CLOCK_H
#define CLOCK_H

void start_time();
void end_time(const char* str, const char* file);

clock_t start;

void start_time() {
  start = clock();
}

void end_time(const char* str, const char* file) {
  double duration = (clock() - start) / (double) CLOCKS_PER_SEC;

  file_write(file, duration);
  cout << str << " se demoró: " << duration << " segundos." << endl;
}

#endif
