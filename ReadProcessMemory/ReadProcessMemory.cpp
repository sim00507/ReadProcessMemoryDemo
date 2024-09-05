#include <iostream>
#include <Windows.h>

int main()
{
    
    //DWORD processID = 28472; // 더미 프로세스

    DWORD processID = 0;
    std::cout << "PID: ";
    std::cin >> std::dec >> processID;


    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
    if (hProcess == NULL) {
        std::cout << "OpenProcess faild. GetLastError() = " << std::dec << GetLastError() << std::endl;
        system("pause");
        return EXIT_FAILURE;
    }
    else if (hProcess) {
        std::cout << "OpenProcess Success.." << std::endl;
    }


    //LPCVOID baseAddress = (LPCVOID)0x7ff69c59d000; // 더미 프로세스에 실제 존재하는 변수(varInt)의 메모리주소
    uintptr_t baseAddress = 0x0;
    std::cout << "Memory adress of the integer to read (in hexadecimal): 0x";
    std::cin >> std::hex >> baseAddress;
    std::cout << "Reading 0x" << std::hex << baseAddress << "..." << std::endl;

    int intRead = 0; // 더미 프로세스에서 ReadProcessMemory로 읽은 변수의 값을 저장할 버퍼

    BOOL rpmReturn = ReadProcessMemory(hProcess, (LPVOID)baseAddress, &intRead, sizeof(int), NULL);

    if (rpmReturn == FALSE) {
        std::cout << "ReadProcessMemory failed. GetLastError() = " << std::dec << GetLastError() << std::endl;
        system("pause");
        return EXIT_FAILURE;
    }
    else if (rpmReturn) {
        std::cout << "ReadProcessMemory Success.. \nintRead = " << std::dec << intRead << std::endl;
    }
    
    std::cout << "Press ENTER to quit." << std::endl;
    system("pause > nul");

    return EXIT_SUCCESS;
   
   
    
}

