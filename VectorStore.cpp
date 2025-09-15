#include "VectorStore.h"

// ----------------- ArrayList Implementation -----------------

template <class T>
ArrayList<T>::ArrayList(int initCapacity = 10) : capacity(initCapacity), count(0) {
    //Cấp phát địa chỉ ô nhớ của ArrayList
    this->data = new T[initCapacity];
}

template <class T>
ArrayList<T>::ArrayList(const ArrayList<T>& other) {
    //Cấp phát địa chỉ ô nhớ của ArrayList, sao chép count và kích thước vùng nhớ
    this->count = other.count;
    this->capacity = other.capacity;
    this->data = new T[other.capacity];

    //Copy dữ liệu từ other sang
    for (int i = 0; i < other.count; i++) this->data[i] = other.data[i];
}   

template <class T>
ArrayList<T>::~ArrayList() {
    //Xóa vùng nhớ đã cấp phát
    delete[] this->data;
}

// TODO: implement other methods of ArrayList

template <class T>
void ArrayList<T>::ensureCapacity(int cap) {
    //Nếu cap bé hơn capacity ban đầu, ngừng chương trình
    if (this->capacity >= cap) return;
    
    //Tạo capacity mới đảm bảo lớn hơn cap
    int newCapacity = this->capacity*2;
    if (newCapacity == 0) newCapacity = 10;
    while (newCapacity < cap) newCapacity = newCapacity*2;

    //Tạo vùng nhớ mới
    T *newData = new T[newCapacity];
    
    //Copy từ vùng cũ qua
    for (int i = 0; i < this->count; i++) newData[i] = this->data[i];

    //Thay đổi ô nhớ
    T *temp = this->data;
    this->data = newData;
    this->capacity = newCapacity;

    //Xóa vùng nhớ cũ
    delete[] temp;
    temp = nullptr;
}


template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& other) {
    //Kiểm tra tự gán
    if (this == &other) return *this;

    //Nếu có bộ nhớ hiện tại thì xóa nó, tạo mới, rồi copy các biến của other
    delete[] this->data;
    this->data = new T[other.capacity];
    this->count = other.count;
    this->capacity = other.capacity;

    //Copy qua
    for (int i = 0; i < other.count; i++) this->data[i] = other.data[i];

    return *this;
}
    

template <class T>
void ArrayList<T>::add(T e) {
    //Kiểm tra capacity
    if (capacity < count + 1) ensureCapacity(count + 1);

    //Thêm vào cuối danh sách
    this->data[count] = e;
    count++;
}

// ----------------- Iterator of ArrayList Implementation -----------------
template <class T>
ArrayList<T>::Iterator::Iterator(ArrayList<T>* pList, int index) {
    // TODO
}

// TODO: implement other methods of ArrayList::Iterator



// ----------------- SinglyLinkedList Implementation -----------------
template <class T>
SinglyLinkedList<T>::SinglyLinkedList() {
    // TODO
}   

template <class T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    // TODO
}   

// TODO: implement other methods of SinglyLinkedList



// ----------------- Iterator of SinglyLinkedList Implementation -----------------
template <class T>
SinglyLinkedList<T>::Iterator::Iterator(Node* node) {
    // TODO
}   

// TODO: implement other methods of SinglyLinkedList::Iterator



// ----------------- VectorStore Implementation -----------------

VectorStore::VectorStore(int dimension = 512, EmbedFn embeddingFunction = nullptr) {
    // TODO
}

VectorStore::~VectorStore() {
    // TODO
}

// TODO: implement other methods of VectorStore


// Explicit template instantiation for char, string, int, double, float, and Point

template class ArrayList<char>;
template class ArrayList<string>;
template class ArrayList<int>;
template class ArrayList<double>;
template class ArrayList<float>;
template class ArrayList<Point>;

template class SinglyLinkedList<char>;
template class SinglyLinkedList<string>;
template class SinglyLinkedList<int>;
template class SinglyLinkedList<double>;
template class SinglyLinkedList<float>;
template class SinglyLinkedList<Point>;
