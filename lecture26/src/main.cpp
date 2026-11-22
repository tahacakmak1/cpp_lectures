template<typename T>
void func(T x) {}

int main() {
    int a = 4;
    int b = 5;
    func(&a);
}
