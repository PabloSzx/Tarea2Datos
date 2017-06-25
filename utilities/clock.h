#ifndef CLOCK_H
#define CLOCK_H

void clock_start();
void clock_start(clock_t n);
void clock_end();
void clock_end(const char* str);

clock_t start;

void clock_start() {
  start = clock();
}

void clock_start(clock_t n) {
  start = n;
}

void clock_end() {
  double duration = (clock() - start) / (double) CLOCKS_PER_SEC;

  file_write(duration);
}

void clock_end(const char* str) {
  double duration = (clock() - start) / (double) CLOCKS_PER_SEC;

  cout << str << " se demoró: " << duration << " segundos." << endl;
}

#endif
