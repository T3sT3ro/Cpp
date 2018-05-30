//
// Created by Tooster on 23.05.2018.
//

#ifndef CPP_BST_BASE2_HPP
#define CPP_BST_BASE2_HPP


#include <functional>
#include <utility>
#include <type_traits>
#include <iostream>

namespace structs {

//    template<typename K>
//    struct less : public std::binary_function<K, K, bool> {
//        constexpr bool operator()(const K &x, const K &y) const { return x < y; }
//    };
//
//    template<>
//    struct less : public std::binary_function<const char *, const char *, bool> {
//        constexpr bool operator()(const char *x, const char *&y) const {
//            return std::string(x).compare(std::string(y)) < 0;
//        }
//    };

//    template<typename T>
//    struct less {
//        typedef typename std::remove_cv<T>::type K;
//        typename std::enable_if<std::is_same<char *, K>::value, bool>::type
//        operator()(T &x, T &y) const { return std::string(x).compare(std::string(y)) < 0; }
//    };

//
//    template<typename K>
//    struct greater : public std::binary_function<K, K, bool> {
//        constexpr bool operator()(const K &x, const K &y) const {
//            if (std::is_same<std::remove_cv<K>::type, char *>::value)
//                return std::string(x).compare(std::string(y)) > 0;
//            if (std::is_pointer<K>::value) return *x > *y;
//            return x > y;
//        }
//    };

    template<typename T, class Compare=std::less_equal<T>>
    class BST {
        struct Node {
            T _data;
            Node *_L = nullptr;
            Node *_R = nullptr;

            explicit Node(const T &data) : _data(data) {};

            Node(const Node &other) {
                _data(other._data);
                if (other._L) *_L = Node(*other._L);
                if (other._R) *_R = Node(*other._R);
            }; // copy subtree

            bool isLeaf() { return !_L && !_R; };

            ~Node() {
                delete _L;
                delete _R;
            }

            friend std::ostream &operator<<(std::ostream &out, Node *node) {
                if (node->_L != nullptr) out << "(" << node->_L << ")";
                out << node->_data;
                if (node->_R != nullptr) out << "(" << node->_R << ")";
                return out;
            };
        } *_root;


        size_t _size;

    public:

        BST();

        BST(const BST<T, Compare> &);

        BST(BST<T, Compare> &&);

        BST(std::initializer_list<T>);

        BST<T, Compare> &operator=(const BST<T, Compare> &);

        BST<T, Compare> &operator=(BST<T, Compare> &&);

        void insert(T elem);

        void remove(T elem);

        T find(T elem);

        T min();

        size_t size() { return _size; };

        bool isEmpty() { return _size == 0; };

        friend std::ostream &operator<<(std::ostream &out, const BST<T, Compare> &bst) {
            out << bst._root;
            return out;
        }

        virtual ~BST();

    private:
        bool _cmp(const T &x, const T &y) { return Compare()(x, y); };

        Node *_insert(T, Node *, Node *);

        Node *_remove(T, Node *);

        bool _find(T, Node *);

        T _min(Node *);

    };

//----------------------------------------------------------------------------------------------------------------------
    template<typename T, class Compare>
    BST<T, Compare>::BST() {
        _root = nullptr;
        _size = 0;
    }

    template<typename T, class Compare>
    BST<T, Compare>::BST(BST<T, Compare> &&other) {
        _root = other._root;
        _size = other._size;
        other._root = nullptr;
    }

    template<typename T, class Compare>
    BST<T, Compare>::BST(const BST<T, Compare> &other) {
        _size = other._size;
        if (!other._root) {
            _root = nullptr;
            return;
        }
        *_root = Node(*other._root);
    }

    template<typename T, class Compare>
    BST<T, Compare>::BST(std::initializer_list<T> list) {
        for (auto &x : list) this->insert(x);
    }

    template<typename T, class Compare>
    BST<T, Compare> &BST<T, Compare>::operator=(const BST<T, Compare> &other) {
        if (this == &other)
            return *this;

        delete this;
        BST tmp(other);
        *this = std::move(tmp);
        return *this;
    }

    template<typename T, class Compare>
    BST<T, Compare> &BST<T, Compare>::operator=(BST<T, Compare> &&other) {
        delete this;
        _root = other._root;
        other._root = nullptr;
        return *this;
    }

    template<typename T, class Compare>
    BST<T, Compare>::~BST() {
        delete _root;
    }

    template<typename T, class Compare>
    void BST<T, Compare>::insert(T elem) {
        ++_size;
        _insert(elem, _root, nullptr);
    }

    template<typename T, class Compare>
    void BST<T, Compare>::remove(T elem) {
        if (_root && _find(elem, _root)) {
            --_size;
            _root = _remove(elem, _root);
        }
    }

    template<typename T, class Compare>
    T BST<T, Compare>::find(T elem) { return _find(elem, _root); }

    template<typename T, class Compare>
    T BST<T, Compare>::min() { return _min(_root); }

    template<typename T, class Compare>
    typename BST<T, Compare>::Node *BST<T, Compare>::_insert(T elem, BST::Node *current, BST::Node *parent) {
        if (current == nullptr){
            Node n = new Node(elem);
            return current;
        }
        else {
            if (_cmp(elem, current->_data)) current->_L = _insert(elem, current->_L, current);
            else current->_R = _insert(elem, current->_R, current);
        }
        return current;
    }

    template<typename T, class Compare>
    typename BST<T, Compare>::Node *BST<T, Compare>::_remove(T elem, BST::Node *current) {
        if (current == nullptr)
            return nullptr;
        if (!_cmp(current->_data, elem)) // <
            current->_L = _remove(elem, current->_L);
        else if (!_cmp(elem, current->_data)) // >
            current->_R = _remove(elem, current->_R);
        else {
            if (current->_L == nullptr)
                return current->_R;
            else if (current->_R == nullptr)
                return current->_L;
            else {
                T value = _min(current);
                current->_data = value;
                current->_L = _remove(value, current->_L);
            }
        }
        return current;
    }

    template<typename T, class Compare>
    bool BST<T, Compare>::_find(T elem, BST::Node *current) {
        if(current == nullptr) return nullptr;
        if(_cmp(elem, current->_data) && _cmp(current->_data, elem)) return true;
        if(_cmp(elem, current->_data)) return _find(elem, current->_L);
        return _find(elem, current->_R);

    }

    template<typename T, class Compare>
    T BST<T, Compare>::_min(BST::Node *current) {
        if(current->_L==nullptr)return current->_data;
        return _min(current->_L);
    }


} // namespace structs


#endif //CPP_BST_BASE2_HPP
