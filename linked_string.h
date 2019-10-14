#pragma once
class linked_string{

public:
    

private:
    struct _string_node {
        char c;
        _string_node* next;
    };
    typedef char* _array_string;
    typedef _string_node* _list_string;
    void _print_linked(_list_string string);
    void _linked_append(_list_string& target, _list_string added);


};

