using namespace std;

#ifndef FILE_H
#define FILE_H

void file_clear(const char* file);
void file_write(const char* file, const char* str);
void file_write(const char* file, double n);

void file_clear(const char* file) {
  ofstream myfile;
  myfile.open(string("./info/") + string(file) + string(".txt"));
  myfile.close();
}

void file_write(const char* file, const char* str) {
  ofstream myfile;
  myfile.open(string("./info/") + string(file) + string(".txt"), ofstream::app);
  myfile << str << "\n";
  myfile.close();
}

void file_write(const char* file, double n) {
  ofstream myfile;
  myfile.open(string("./info/") + string(file) + string(".txt"), ofstream::app);
  myfile << n << "\n";
  myfile.close();
}

#endif
