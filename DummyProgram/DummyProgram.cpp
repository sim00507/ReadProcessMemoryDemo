#include <iostream>

int main() {
    static int varInt = 123456;  // 정적 변수
    std::cout << "varInt (0x" << std::hex << (uintptr_t)&varInt << std::dec << ") = " << varInt << std::endl;
    std::cin.get();  // 프로그램이 종료되지 않도록 대기
    return 0;
}
