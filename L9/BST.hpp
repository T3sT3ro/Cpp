//
// Created by i300791 on 23.05.18.
//

#ifndef CPP_BST_H
#define CPP_BST_H

#include <functional>

namespace structs {
    template<class T, class Compare=std::less<T>>
    class BST {
        class Node {
            T _data;
            Node *_L;
            Node *_R;

        public:
            Node();

            Node(const Node &);

            ~Node();

        } *_root;

        Compare _compare;
        size_t _size;

    public:
        BST();

        BST(const BST<T, Compare> &);

        BST(BST<T, Compare> &&);

        BST<T, Compare> &operator=(const BST<T, Compare> &);

        BST<T, Compare> &operator=(BST<T, Compare> &&);

        BST(std::initializer_list<T>);

        void insert(T elem);

        void remove(T elem);

        void find(T elem);

        size_t size();

        bool isEmpty();

        virtual ~BST();
    };

    template<class T, class Compare>
    BST<T, Compare>::Node::Node(): _L(nullptr), _R(nullptr) {}

    template<class T, class Compare>
    BST<T, Compare>::Node::Node(const Node &other) {
        _data(other._data);
        *_L = Node(*other._L);
        *_R = Node(*other._R);
    }

    template<class T, class Compare>
    BST<T, Compare>::Node::~Node() {
        _data.~T();
        _L->~T();
        _R->~T();
    }

    template<class T, class Compare>
    BST<T, Compare>::BST() {
        _root = nullptr;
        _size = 0;
    }

    template<class T, class Compare>
    BST<T, Compare>::BST(const BST<T, Compare> &other) {
        _size = other._size;
        _compare = other._compare;
        *_root = Node(*other._root);
    }

    template<class T, class Compare>
    BST<T, Compare>::BST(BST<T, Compare> &&other) {
        _root = other._root;
        _size = other._size;
        _compare = other._compare;
        other._root = nullptr;
    }

    template<class T, class Compare>
    BST<T, Compare>::~BST() {
        delete _root;
    }


} // namespace structs

#endif //CPP_BST_H
