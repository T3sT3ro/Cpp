//
// Created by i300791 on 23.05.18.
//

#ifndef CPP_BST_H
#define CPP_BST_H

#include <functional>
#include <utility>
#include <type_traits>

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
//        typename std::enable_if<std::is_same<char *, K>::value>::type
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

            Node(const Node &); // copy subtree
            bool isLeaf();

            void remove(Node *);

            ~Node();

            friend std::ostream &operator<<(std::ostream &out, Node *);
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

        size_t size();

        bool isEmpty();

        friend std::ostream &operator<<(std::ostream &, const BST<T, Compare> &);

        virtual ~BST();

    private:
        bool cmp(const T &x, const T &y);

        std::pair<Node *, Node *> findNode(Node *node, const T &elem, Node *parent = nullptr);

        void removeLeaf(Node *leaf, Node *parent);

        void removeNoLeft(Node *node, Node *parent);

        void removeBySwapMax(Node *node);
    };
//----------------------------------------------------------------------------------------------------------------------

    template<typename T, class Compare>
    BST<T, Compare>::Node::Node(const Node &other) {
        _data(other._data);
        if (other._L) *_L = Node(*other._L);
        if (other._R) *_R = Node(*other._R);
    }

    template<typename T, class Compare>
    bool BST<T, Compare>::Node::isLeaf() {
        return !_L && !_R;
    }

    template<typename T, class Compare>
    void BST<T, Compare>::Node::remove(BST::Node *removed) {
        if (removed == _L) {
            _L = removed->_R;
            removed->_R = nullptr;
            delete removed;
        } else if (removed == _R) {
            _R = removed->_R;
            removed->_R = nullptr;
            delete removed;
        }
    }

    template<typename T, class Compare>
    BST<T, Compare>::Node::~Node() {
        delete _L;
        delete _R;
    }

    std::ostream &operator<<(std::ostream &out, BST::Node *node) {
        if (node->_L != nullptr) out << "(" << node->_L << ")";
        out << node->_data;
        if (node->_R != nullptr) out << "(" << node->_R << ")";
        return out;
    }

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
    bool BST<T, Compare>::cmp(const T &x, const T &y) {
        return Compare()(x, y);
    }

    template<typename T, class Compare>
    std::pair<BST::Node *, BST::Node *> BST<T, Compare>::findNode(BST::Node *node, const T &elem, BST::Node *parent) {
        if (cmp(node->_data, elem) && cmp(elem, node->_data))  // elem == _data
            return std::make_pair(node, parent);

        if (cmp(elem, node->_data)) { // elem < _data
            if (node->_L)
                return findNode(node->_L, elem, node);
            return std::make_pair(nullptr, node);
        }

        if (cmp(node->_data, elem)) { // _data < elem
            if (node->_R)
                return findNode(node->_R, elem, node);
            return std::make_pair(nullptr, node);
        }

        return std::make_pair(nullptr, nullptr);
    }

} // namespace structs

#endif //CPP_BST_H
