#pragma once

namespace strukdat {

namespace priority_queue {

/**
 * @brief Implementasi struct untuk elemen, harus ada isi dan prioritas elemen.
 */
template <typename T>
struct Element {
  // Implementasikan di sini.
  T value;
  int priority;
  Element* next;
};

template <typename T>
using ElementPtr = Element<T> *;

/**
 * @brief implemetasi struct untuk queue.
 */
template <typename T>
struct Queue {
  // Implementasikan di sini.
  ElementPtr<T> head;
  ElementPtr<T> tail;
};

/**
 * @brief membuat queue baru
 *
 * @return  queue kosong
 */
template <typename T>
Queue<T> new_queue() {
  // Implementasikan di sini.
  Queue<T> q;
  q.head = nullptr;
  q.tail = nullptr;
  return q;
}

/**
 * @brief memasukan data sesuai priority elemen.
 *
 * @param q         queue yang dipakai.
 * @param value     isi dari elemen.
 * @param priority  prioritas elemen yang menentukan urutan.
 */
template <typename T>
void enqueue(Queue<T> &q, const T &value, int priority) {
  // Implementasikan di sini.
  ElementPtr<T> newElement = new Element<T>;
  newElement->value = value;
  newElement->priority = priority;
  ElementPtr<T> pRev = nullptr;
  ElementPtr<T> pHelp = q.head;
  if(q.head == nullptr && q.tail == nullptr){
    q.head = newElement;
    q.tail = newElement;
  }else{
    while(newElement->priority <= pHelp->priority){
      if(pHelp->next == nullptr){
        break;
      }
      pRev = pHelp;
      pHelp = pHelp->next;
    }
  if(pHelp == q.head && newElement->priority > pHelp->priority){
    newElement->next = pHelp;
    q.head = newElement;
  }else if(pHelp == q.tail && newElement->priority < pHelp->priority){
    pHelp->next = newElement;
    q.tail = newElement;
  }else{
    pRev->next = newElement;
    newElement->next = pHelp;
  }
  }
}

/**
 * @brief mengembalikan isi dari elemen head.
 *
 * @param q   queue yang dipakai.
 * @return    isi dari elemen head.
 */
template <typename T>
T top(const Queue<T> &q) {
  // Implementasikan di sini.
  return q.head->value;
}

/**
 * @brief menghapus elemen head queue (First in first out).
 *
 * @param q   queue yang dipakai.
 */
template <typename T>
void dequeue(Queue<T> &q) {
  // Implementasikan di sini.
  ElementPtr<T> delElement = new Element<T>;
  if(q.head == nullptr && q.tail == nullptr){
    delElement = nullptr;
  }else if(q.head->next == nullptr){
    delElement = q.head;
    q.head = nullptr;
    q.tail = nullptr;
  }else{
    delElement = q.head;
    q.head = q.head->next;
    delElement->next = nullptr;
  }
}

}  // namespace priority_queue

}  // namespace strukdat
