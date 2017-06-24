using namespace std;

clock_t start;

void start_time() {
  start = clock();
}

void end_time(const char* str) {
  double duration = (clock() - start) / (double) CLOCKS_PER_SEC;

  cout << str << " se demoró: " << duration << " segundos." << endl;
}
