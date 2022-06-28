#include "functions.h"

int main() {
    float a = capture_value('a');
    float b = capture_value('b');
    float c = capture_value('c');
    float d = capture_d();

    Tree tree = build_tree(a, b, c, d);

    float tree_value = tree.calculate();
    printf("Tree value: %.3f\n", tree_value);

    tree.print();
}