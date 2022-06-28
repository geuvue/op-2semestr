#include "functions.h"

float capture_value(char value){
    printf("Enter %c value: ", value);

    float a;
    cin >> a;

    return a;
}

float capture_d(){
    cout << "Enter d value: ";

    float d;
    cin >> d;

    while(d == 0){
        cout << "d value can't be 0. Enter again: ";
        cin >> d;
    }

    return d;
}

Tree build_tree(float a, float b, float c, float d){
    Node *root = new Node('/');

    Tree tree(root);

    // ініціалізуємо лівий вузол кореня
    Node *multiply_node = new Node('*');
    root->set_left(multiply_node);
    // ініціалізуємо правий вузол кореня
    Node *d_node = new Node(d);
    root->set_right(d_node);

    // ініціалізуємо лівий вузол вузла множення
    Node *a_node = new Node(a);
    multiply_node->set_left(a_node);
    // ініціалізуємо правий вузол вузла множення
    Node *plus_node = new Node('+');
    multiply_node->set_right(plus_node);

    // ініціалізуємо лівий вузол вузла додавання
    Node *b_node = new Node(b);
    plus_node->set_left(b_node);
    // ініціалізуємо правий вузол вузла додавання
    Node *c_node = new Node(c);
    plus_node->set_right(c_node);

    return tree;
}
