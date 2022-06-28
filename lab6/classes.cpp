#include "classes.h"

Node::Node(float data) {
    // ініціалізуємо число, яке є елементом дерева
    this->data = data;
    // ініціалізуємо оператор пустим символом
    // (так як вузол дерева може мати або число, або оператор)
    this->action_operator = '\000';
    left = nullptr;
    right = nullptr;
}

Node::Node(char action_operator) {
    // ініціалізуємо число
    this->data = 0;
    // ініціалізуємо оператор
    this->action_operator = action_operator;
    left = nullptr;
    right = nullptr;
}

float Node::get_data() const {
    return data;
}

char Node::get_operator() const {
    return action_operator;
}

Node *Node::get_left() {
    return left;
}

Node *Node::get_right() {
    return right;
}

void Node::set_left(Node *new_left) {
    left = new_left;
}

void Node::set_right(Node *new_right) {
    right = new_right;
}


Tree::Tree(Node *root) {
    this->root = root;
}

float Tree::evaluate_operator(Node *node, float left_sum, float right_sum) {
    // якщо оператор в вузлі дерева +, то додаємо значення
    if(node->get_operator() == '+'){
        float sum = left_sum + right_sum;
        return sum;
    }
        // якщо оператор в вузлі дерева -, то віднімаємо значення
    else if(node->get_operator() == '-'){
        float sub = left_sum - right_sum;
        return sub;
    }
        // якщо оператор в вузлі дерева *, то множимо значення
    else if(node->get_operator() == '*'){
        float mult = left_sum * right_sum;
        return mult;
    }
        // якщо оператор в вузлі дерева /, то ділимо значення
    else{
        float div = left_sum / right_sum;
        return div;
    }
}


float Tree::calculate() {
    // сума лівих вузлів дерева
    // (рахуємо рекурсивно)
    float left_sum = calculate(root->get_left());
    // сума правих вузлів дерева
    // (рахуємо рекурсивно)
    float right_sum = calculate(root->get_right());

    // загальна сума (обираємо правильний оператор для вузлів дерева)
    float sum = evaluate_operator(root, left_sum, right_sum);

    return sum;
}

float Tree::calculate(Node *node) {
    // якщо лівий листок вузла порожній і правий листок вузла порожній
    // (тобто вузол є листком (має нульовий степінь))
    if(node->get_left() == nullptr && node->get_right() == nullptr){
        // повертаємо значення вузла
        return node->get_data();
    }

    // сума лівих вузлів дерева
    // (рахуємо рекурсивно)
    float left_sum = calculate(node->get_left());
    // сума правих вузлів дерева
    // (рахуємо рекурсивно)
    float right_sum = calculate(node->get_right());

    // загальна сума (обираємо правильний оператор для вузлів дерева)
    float sum = evaluate_operator(node, left_sum, right_sum);

    return sum;
}

void print_node(Node *node, int depth){
    // виводимо пробіли (5 пробілів * глибину)
    for (int i = 0; i < depth; ++i) {
        cout << "     ";
    }

    // якщо оператор вузла не дорівнює пустому символу
    // (тобто у вузлі наявний оператор)
    if(node->get_operator() != '\000')
        cout << "-> " << node->get_operator() << endl;
        // інакше
        // (тобто у вузлі наявне число)
    else
        cout << "-> " << node->get_data() << endl;
}

void Tree::print() {
    // глибина обходу дерева
    int depth = 0;

    // виводимо ліві вузли кореня
    this->print(root->get_left(), depth + 1);
    // виводимо корінь дерева
    print_node(root, depth);
    // виводимо праві вузли кореня
    this->print(root->get_right(), depth + 1);
}

void Tree::print(Node *node, int depth) {
    // якщо вузол не порожній
    if(node != nullptr){
        // виводимо ліві вузли
        this->print(node->get_left(), depth + 1);
        // виводимо вузол дерева
        print_node(node, depth);
        // виводимо праві вузли
        this->print(node->get_right(), depth + 1);
    }
}