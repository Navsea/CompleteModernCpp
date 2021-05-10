
struct A {
    A();
    ~A();
    A(const A &other);
    A(const A &&other) noexcept;
    A& operator=(const A &other);
    A& operator=(const A &&other) noexcept;
};

struct B {
    B();
    ~B();
    B(const B &other);
    B(const B &&other) noexcept;
    B& operator=(const B &other);
    B& operator=(const B &&other) noexcept;
};