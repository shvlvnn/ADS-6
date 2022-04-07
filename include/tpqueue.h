// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
template<typename T, int size>
class TPQueue {
 private:
  T arr[size] = { 0 };
  int a;
  int b;
 public:
  void push(T x) {
    int k = b;
    for (; (k >= a) && arr[k % size].prior < x.prior; --k) {
      arr[(k+1) % size] = arr[k % size];
    }
    arr[(k + 1) % size] = x;
    ++b;
  }
  T pop() {
    return arr[(a++) % size];
  }
};
struct SYM {
  char ch;
  int prior;
};
#endif  // INCLUDE_TPQUEUE_H_
