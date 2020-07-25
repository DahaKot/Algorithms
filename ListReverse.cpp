#include <vector>
#include <iostream>

class Node {
public:
    Node(int x, Node* ptr) {
        data = x;
        next = ptr;
    }
    int data;
    Node* next;
};

class List {
public:
    void reverse();
    void insert(Node* x);
    void dump();
    Node* head;
    int len;
};

void List::insert(Node* x) {
    x->next = head;
    head = x;
    len++;
}

void List::reverse() {
    Node* a = head->next;
    Node* b = head;

    printf("a: %d %p\n", a->data, a->next);
    printf("b: %d %p\n", b->data, b->next);

    while (a != nullptr) {
        Node* tmp = a->next;
        a->next = b;
        b = a;
        a = tmp;
    }
    head->next = nullptr;

    head = b;
}

void List::dump() {
    FILE* Dump_f = fopen("Dump.txt", "w");
    fprintf(Dump_f, "digraph List {\nhead [label = \"List\\nList len = %d\"];\n", len);

    Node* elem = head;
    int i = 2;

    if (elem == nullptr) {
        fprintf(Dump_f, "}");
        fclose(Dump_f);

        system ("dot -Tpng Dump.txt -o Dump.png");
        //system("Dump.png");
        return ;
    }

    fprintf(Dump_f, "node1 [shape=record, label=\"{<name> node1\\n%p|"
            "<data> data:\\ %d|<next> next\\n%p}}\"];\n", elem, elem->data, elem->next);
    while (elem) {
        elem = elem->next;
        if (elem == nullptr) {
            break;
        }
        fprintf(Dump_f, "node%d [shape=record, label=\"{<name> node%d\\n%p|"
                "<data> data:\\ %d|<next> next\\n%p}}\"];\n", i, i, elem, elem->data, elem->next);
        i++;
    }

    i = 1;
    //fprintf(Dump_f, "node [style = filled color = red;\n");
    fprintf(Dump_f, "edge [color = deepskyblue];\n");
    i = 1;
    while (i < len && len != 1) {
        fprintf(Dump_f, "\"node%d\":next -> \"node%d\":name;\n", i, i+1);
        i++;
    }

    fprintf(Dump_f, "}");
    fclose(Dump_f);

    system ("dot -Tpng Dump.txt -o Dump.png");
    //system("Dump.png");
}

int main() {
    List l;
    Node f = {1, nullptr};
    l.head = &f;
    l.len = 1;

    Node a = {2, nullptr};
    l.insert(&a);
    Node b = {3, nullptr};
    l.insert(&b);
    Node c = {4, nullptr};
    l.insert(&c);
    Node d = {5, nullptr};
    l.insert(&d);
    Node e = {6, nullptr};
    l.insert(&e);

    l.reverse();

    l.dump();

    return 0;
}
