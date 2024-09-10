#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

#define CHAR_ARRAY_SIZE 128

int main()
{

    int choice;

    //DWORD processID = 28472; // 더미 프로세스

    DWORD processID = 0;
    std::cout << "PID: ";
    std::cin >> std::dec >> processID;


    HANDLE hProcess = OpenProcess(PROCESS_VM_READ, FALSE, processID); // PROCESS_ALL_ACCESS -> PROCESS_VM_READ
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

    std::cout << "Select the type of variable to read:\n";
    std::cout << "1. integer\n";
    std::cout << "2. string\n";
    std::cout << "3. char array\n";
    std::cin >> choice;

    BOOL rpmReturn = FALSE;

    switch (choice) {
    case 1: // integer
    {
        std::cout << "Memory address of the integer to read (in hexadecimal): 0x";
        std::cin >> std::hex >> baseAddress;
        std::cout << "Reading 0x" << std::hex << baseAddress << "..." << std::endl;

        int intRead = 0; // 더미 프로세스에서 ReadProcessMemory로 읽은 변수의 값을 저장할 버퍼

        rpmReturn = ReadProcessMemory(hProcess, (LPVOID)baseAddress, &intRead, sizeof(int), NULL);


        if (rpmReturn == FALSE) {
            std::cout << "ReadProcessMemory failed. GetLastError() = " << std::dec << GetLastError() << std::endl;
            system("pause");
            return EXIT_FAILURE;
        }
        else if (rpmReturn) {
            std::cout << "ReadProcessMemory Success.. \nintRead = " << std::dec << intRead << std::endl;
        }

        break;
    }

    case 2: // string gkTLqkf dho dkseho
    {
        std::cout << "Memory address of the string to read (in hexadecimal): 0x";
        std::cin >> std::hex >> baseAddress;
        std::cout << "Reading 0x" << std::hex << baseAddress << "..." << std::endl;

        //std::string stringRead2(100, 0);
        //std::vector<char> stringRead(100, 0);
        char stringRead[20];
        rpmReturn = ReadProcessMemory(hProcess, (LPVOID)baseAddress, &stringRead[0], 20, NULL);


        if (rpmReturn == FALSE) {
            std::cout << "ReadProcessMemory failed. GetLastError() = " << std::dec << GetLastError() << std::endl;
            system("pause");
            return EXIT_FAILURE;
        }
        else if (rpmReturn) {
            std::cout << "ReadProcessMemory Success.. \nstringRead = " << stringRead << std::endl;
        }

        break;
    }

    case 3: // char array
    {
        std::cout << "Memory address of the char array to read (in hexadecimal): 0x";
        std::cin >> std::hex >> baseAddress;
        std::cout << "Reading 0x" << std::hex << baseAddress << "..." << std::endl;

        char charRead[CHAR_ARRAY_SIZE] = { 0 };
        rpmReturn = ReadProcessMemory(hProcess, (LPVOID)baseAddress, charRead, sizeof(charRead), NULL);

        if (rpmReturn == FALSE) {
            std::cout << "ReadProcessMemory failed. GetLastError() = " << std::dec << GetLastError() << std::endl;
            system("pause");
            return EXIT_FAILURE;
        }
        else if (rpmReturn) {
            std::cout << "ReadProcessMemory Success.. \ncharRead = " << charRead << std::endl;
        }

        break;
    }
      
    default:
        std::cout << "Invaild choice." << std::endl;
        break;
    }

    
    std::cout << "Press ENTER to quit." << std::endl;
    system("pause > nul");
    CloseHandle(hProcess); // 리소스 누수 방지

    return EXIT_SUCCESS;
   
   
    
}

