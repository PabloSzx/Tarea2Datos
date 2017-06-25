#ifndef CLOCK_H
#define CLOCK_H

void start_time();
void start_time(clock_t n);
void end_time();
void end_time(const char* str);

clock_t start;

void start_time() {
  start = clock();
}

void start_time(clock_t n) {
  start = n;
}

void end_time() {
  double duration = (clock() - start) / (double) CLOCKS_PER_SEC;

  file_write(duration);
}

void end_time(const char* str) {
  double duration = (clock() - start) / (double) CLOCKS_PER_SEC;

  cout << str << " se demoró: " << duration << " segundos." << endl;
}

#endif
