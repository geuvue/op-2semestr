#include <iostream>
using namespace std;

class Node{
private:
    // число, яке є елементом дерева
    float data;
    // оператор, який є елементом дерево
    char action_operator;

    // лівий вузол дерева
    Node* left;
    // правий вузол дерева
    Node* right;

public:
    // конструктор введення числа
    Node(float data);
    // конструктор введення оператору
    Node(char action_operator);

    float get_data() const;
    char get_operator() const;
    Node* get_left();
    Node* get_right();

    void set_left(Node* new_left);
    void set_right(Node* new_right);
};

class Tree{
private:
    // корінь дерева
    Node* root;

    // рахуємо суму листків дерева (для підкореня)
    float calculate(Node* node);
    // обираємо підходящий оператор для листків дерева (для підкореня)
    float evaluate_operator(Node *node, float left_sum, float right_sum);
    // виводимо елементи дерева (для підкореня)
    void print(Node* node, int depth);
public:
    Tree(Node* root);

    // рахуємо суму листків дерева (для кореня)
    float calculate();
    // виводимо елементи дерева (для кореня)
    void print();
};