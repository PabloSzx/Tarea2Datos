#ifndef CHRONO_H
#define CHRONO_H

using namespace std::chrono;

high_resolution_clock::time_point chrono_now();
void chrono_start();
void chrono_end();
void chrono_end(const char* str);
void chrono_get_time(high_resolution_clock::time_point t1);
void chrono_get_time(const char* str, high_resolution_clock::time_point t1);

high_resolution_clock::time_point t1 = high_resolution_clock::now();

high_resolution_clock::time_point chrono_now() {
  return high_resolution_clock::now();
}

void chrono_start() {
  t1 = high_resolution_clock::now();
}

void chrono_end() {
  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

  file_write(time_span.count());
}

void chrono_end(const char* str) {
  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

  std::cout << str << " se demoró: " << time_span.count() << " segundos." << endl;
}

void chrono_get_time(high_resolution_clock::time_point t) {
  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  duration<double> time_span = duration_cast<duration<double>>(t2 - t);

  file_write(time_span.count());
}


void chrono_get_time(high_resolution_clock::time_point t, const char* str) {
  high_resolution_clock::time_point t2 = high_resolution_clock::now();

  duration<double> time_span = duration_cast<duration<double>>(t2 - t);

  std::cout << str << " se demoró: " << time_span.count() << " segundos." << endl;
}


#endif
