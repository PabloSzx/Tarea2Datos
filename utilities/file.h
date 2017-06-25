using namespace std;

#ifndef FILE_H
#define FILE_H

void file_open(const char* file);
void file_close();
void file_clear(const char* file);
void file_write(const char* str);
void file_write(double n);

ofstream myfile;

void file_open(const char* file) {
  myfile.open((string("./info/") + string(file) + string(".txt")).c_str(), ofstream::app);
}

void file_close() {
  myfile.close();
}

void file_clear(const char* file) {
  myfile.open((string("./info/") + string(file) + string(".txt")).c_str());
  myfile.close();
}

void file_write(const char* str) {
  myfile << str << "\n";
}

void file_write(double n) {
  myfile << n << "\n";
}

#endif
